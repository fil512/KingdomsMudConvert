use v6;

use Test;
plan 2;

use KM::KMDocument;

my $doc = KMDocument.new;
$doc.parsefile('t/data/eating_dinner.c');
my $parsed = $doc.parsed;

#test comments
is @($parsed<comment>).elems, 3, 'number of comments';

#test comment 2
my $comment2 = @($parsed<comment>)[2];
is $comment2, "test comment2";
