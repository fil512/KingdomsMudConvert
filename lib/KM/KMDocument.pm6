use strict;

=begin comment
grammar KMScript {

    rule TOP        { <header> <body> }
    rule header       { }
    rule body     :w  { <block> }
    rule block { \{ [ <- [\{\}\"\'\/] >* | <comment> | <string> | <block> ]* \} }

    rule comment { <single_line_comment> | <multi_line_comment> }

    rule single_line_comment { \/\/ \N* }

    rule multi_line_comment { \/\* [ <- [*] >* | <before \*\/ > | \* ]* \*\/ }

    rule quoted_string ($type) { $type [ <- [$type] >+ | [ <after \\ > $type ] ]* $type }
	
    rule string { <quoted_string \"> | <quoted_string \'> }
}
=end comment

grammar KMScript {
	token TOP { [ <blob> ]+ }
	
	token blob {
		[ <comment> |
		<string> |
		  <- [\"/]>+ ]
	}
	
	token comment {
		<single_line_comment> |
		<multi_line_comment>
	}
	
    token single_line_comment {
		'//' \N* \n
	}
	
	rule multi_line_comment {
		'/*' .* '*/'
	}
	
#	token string { <quote> {} <quotebody($<quote>)> $<quote> }
#   token quote { '"' | "'" }
	token string { '"' <quotebody('"')> '"' }

    token quotebody($quote) { ( <escaped($quote)> | <!before $quote> . )* }
    token escaped($quote) { '\\' ( $quote | '\\' ) }
}	

class KMDocument {
	has $.parsed;
	
	method parsefile(Str $filename) {
		$!parsed = KMScript.parsefile($filename);
	}
}

