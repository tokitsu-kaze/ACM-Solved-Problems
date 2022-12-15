<?php

function read_int(){return trim(fgets(STDIN));}
function read_line_int(){return explode(" ", trim(fgets(STDIN)));}

$t=read_int();
while($t>0)
{
    $t--;
    $n=read_int();
    $a=read_line_int();
    $mp=array();
    $pos=array();
    for($i=0;$i<$n;$i++)
    {
        $mp[$a[$i]]++;
        $pos[$a[$i]]=$i+1;
    }
    $ans=-1;
    for($i=1;$i<=$n;$i++)
    {
        if($mp[$i]==1)
        {
            $ans=$pos[$i];
            break;
        }
    }
    print $ans."\n";
}

?>
