<?php
date_default_timezone_set("Asia/Kolkata");
$host = "localhost";
$user = "iot_user1";
$pass = "iot@1163";
$db = "mysensor";
$con = mysqli_connect($host,$user,$pass,$db);
if($con)
{
    if(isset($_GET['h']) && isset($_GET['t']))
 {
    echo "Connected to database";    
      $hum = $_GET['h'];
      $temp = $_GET['t'];
      echo $hum;
      echo "<br>";
      echo $temp;
      $date = date("d-m-Y");    // 06-01-2022
      $time = date("H:i:s");
 $sql = "insert into temphum(date,time,temp,hum) values('$date','$time','$temp','$hum')";
    if(mysqli_query($con,$sql)){
  echo "Data Inserted";
 }
 else{
  echo "Failed to Insert Data";
 }          
}
else{
  echo "No data";
 }
}
else
{
    echo "Connection failed";
}
?>
