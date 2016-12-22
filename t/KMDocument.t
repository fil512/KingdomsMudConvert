use v6;

use Test;
plan 9;

use KM::KMDocument;

my $doc = KMDocument.new;
$doc.parsefile('t/data/eating_dinner.c');
my $parsed = $doc.parsed;

#test keyval part
is @($parsed<keyval>).elems, 1, 'number of keyvals';
my $kv = @($parsed<keyval>).[0];
is $kv.<key>, "short_desc", "short_desc key";
is $kv.<val>, "Dinner Room", "short_desc val";
