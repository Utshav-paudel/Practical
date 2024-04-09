# accept strings starting with a

print "\nEnter your string: ";
$string = <STDIN>;
if($string =~ /^a/){
	print "String starts with 'a'.\n"
} else {
	print "String does not start with 'a'.\n"
}
