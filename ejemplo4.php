<?php
recibirDatos();
function recibirDatos(){
    if($_POST){
        $valorA=$_POST["valorA"];
        $valorB=$_POST["valorB"];
        $suma=$valorA+$valorB;
        $resta=$valorA-$valorB;
        $producto=$valorA*$valorB;
        $division=$valorA/$valorB;
        if($valorA>$valorB){
            $max=$valorA;
            $min=$valorB;
        }else{
            $max=$valorB;
            $min=$valorA;
        }
        echo "EL resultado de las operanciones entre ".$valorA." y ".$valorB;
        echo"<br>El valor: ".$max." es mayor que ".$min." ";
        echo "<br>Suma: ".$suma;
        echo"<br>Resta: ".$resta;
        echo "<br>Producto: ".$producto;
        echo "<br>Division: ".$division;

    }
}

?>
<htm>
    <head>
    <link rel="stylesheet" type="text/css" href="formulario.css">
</head>
    <body>
        <p>Calculadora</p>
        <form action="ejemplo4.php" method="post">
            valor A:
            <input type="text" name="valorA" id="">
            <br>
            valor B:
            <input type="text" name="valorB" id="">
            <input type="submit" value="Calcular">
        </form>
    </body>
    </html>