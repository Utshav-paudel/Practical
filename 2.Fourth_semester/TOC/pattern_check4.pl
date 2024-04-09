# accept strings of the form a^nb^n

print "\nEnter your string: ";
$string = <STDIN>;
if($string =~ /^(a(?1)?b)$/){
	print "String is of the form 'a^nb^n'.\n";
} else {
	print "String is not of the form 'a^nb^n'.\n";
        print "Lab by Utshav Paudel";
}
