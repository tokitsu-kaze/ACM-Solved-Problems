<?php

function readint()
{
    return trim(fgets(STDIN));
}

$t=readint();
while($t>0)
{
    $t--;
    $n=readint();
    print $n." ";
    for($i=1;$i<$n;$i++)
    {
        print $i;
        if($i==$n-1) print "\n";
        else print " ";
    }
}

?>
