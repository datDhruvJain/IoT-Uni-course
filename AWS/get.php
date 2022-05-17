<!DOCTYPE html>
<html>
<head>
<meta http-equiv="refresh" content="5">
<title>Page Title</title>
</head>
<body>
<center>
<table border = "1" width="100%" cellspacing='0'>
<tr>
<th>ID</th>
<th>Date</th>
<th>Time</th>
<th>Humidity</th>
<th>Temperature</th>
</tr>
<?php
$host = "localhost";
$user = "iot_user1";
$pass = "iot@1163";
$db = "mysensor";
$con = mysqli_connect($host,$user,$pass,$db);
$sql = "select * from temphum order by id desc";
$result = mysqli_query($con,$sql);
while($row = mysqli_fetch_array($result)){
    echo "<tr>";
    echo "<td>".$row['id']."</td>";
    echo "<td>".$row['date']."</td>";
    echo "<td>".$row['time']."</td>";
    echo "<td>".$row['hum']."</td>";
    echo "<td>".$row['temp']."</td>";
    echo "</tr>";
}
?>
</table>
</center>
</body>
</html>
