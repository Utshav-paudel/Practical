# example of pattern matching
$string = "This is an example of pattern matching.";
$string =~ m/example/; # binding operator

print "Before match: $`\n"; # string preceding a successful pattern match
print "Exact match: $&\n"; # substring that matched the pattern
print "After match: $'\n" # string after the successful pattern match
