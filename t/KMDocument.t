use v6;

use Test;
plan 4;

use KM::KMDocument;

my $doc = KMDocument.new;
$doc.parsefile('t/data/eating_dinner.c');
my $parsed = $doc.parsed;

#test comments
is @($parsed<blob>).elems, 31, 'number of comments';

#test comment 2
is @($parsed<blob>)[0], "// comment 1\n";
is @($parsed<blob>)[1], "// comment 2\n";
#is @($parsed<blob>)[8], "/*\nmulti line\ncomment\n*/\n\n";
is @($parsed<blob>)[20], "    short_desc = \"Dinner Room\";\n";


