# accept strings of the form a^nb^2n

print "\nEnter your string: ";
$string = <STDIN>;
if($string =~ /^(a(?1)?bb)$/){
	print "String is of the form 'a^nb^2n'.\n";
} else {
	print "String is not of the form 'a^nb^2n'.\n";
        print "Lab by Utshav";
}
