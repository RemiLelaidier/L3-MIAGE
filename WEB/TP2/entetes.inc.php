<?php
    // Session
    require_once("class/UserManager.php");
    require_once("class/User.php");

    session_start();
    session_name("RemiL");

    require_once ("bandeau.inc.php");
    // Redirection si non connecte
    if(basename($_SERVER['PHP_SELF']) != "index.php" && basename($_SERVER['PHP_SELF']) != "creation.php"){
        if(!isset($_SESSION['user']) || $_SESSION['user']->isConnected() == FALSE){
            header("Location: index.php");
        }
    }

    // Fonction de generation des entetes communes a toutes les pages du projet
    function genEntete($title){
        echo "<!doctype html>";
        echo '<html lang="fr">';
        echo "<head>";
        echo "<title>TP2 - ".$title."</title>";
        echo '<meta charset="utf-8">';
        if(isset($_SESSION['style']))
            echo '<link rel="stylesheet" href="css/'.$_SESSION['style'].'">';
        echo '<link rel="stylesheet" href="css/nav.css">';
        echo "</head>";
        echo "<body>";
        $bandeau = new Bandeau();
        $headers = $bandeau->genererBarNav();
        echo $headers;
        echo "<div class='content' style='
            margin-left: auto;
            margin-right: auto;
            width: 95%;
            text-align: center;
            border-radius: 20px;
            background-color: darkgray;
            padding-top: 20px;
            padding-bottom: 20px;'>";
        echo "<h1>". $title ."</h1>";
    }

    // Fonction de generation des bas de page communes a toutes les pages du projet
    function genPiedPage(){
        echo "</div></body></html>";
    }