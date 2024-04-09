# accept strings having substring 101

print "\nEnter your string: ";
$string = <STDIN>;
if($string =~ /.*101.*/){
	print "String contains substring '101'.\n";
} else {
	print "String does not contain substring '101'.\n";
        print "Lab by Utshav Paudel";
}
