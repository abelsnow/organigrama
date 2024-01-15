<?php
$nombre=comprobarNombre();
$apellido =comprobarApellido();
if($nombre!="" and $apellido!=""){
echo "<h1>Bienvenido ".$nombre." ".$apellido."</h1>";
}else{
    echo"<h1>Error faltan datos";
}
function comprobarNombre(){
    if(isset($_POST["nombre"])){
        $nombre=$_POST["nombre"];
        
    
    }return $nombre;
    
}
function comprobarApellido(){
    if(isset($_POST["apellido"])){
        $apellido=$_POST["apellido"];
   
    }return $apellido;
}
?>
<html>
<heaad>
    <link rel="stylesheet" type="text/css" href="formulario2.css">
</head>


</html>