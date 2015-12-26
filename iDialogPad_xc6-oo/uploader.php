<?php
$target = "upload/";
$target = $target . basename( $_FILES['uploaded']['name']) ;
$ok=1;
if (strstr($target , '.csv')==FALSE) {
	echo "NO";
	return;
}
if (strstr($target , 'Output')==FALSE) {
	echo "NO";
	return;
}

if(move_uploaded_file($_FILES['uploaded']['tmp_name'], $target))
{
	chmod($target,0604);
    echo "YES";
}
else {
   echo "NO";
}
?> 