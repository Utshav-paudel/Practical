# accept strings starting with a and ending with b

print "\nEnter your string: ";
$string = <STDIN>;
if($string =~ /^a.*b/){
	print "String starts with 'a' and ends with 'b'.\n"
} else {
	print "String does not meet the criteria.\n"
}

print "Lab by Utshav Paudel";