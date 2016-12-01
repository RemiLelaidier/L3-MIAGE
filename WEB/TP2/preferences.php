<?php
    require_once("entetes.inc.php");

    /*
     *  FONCTIONS
     */

    /*
     *  Fonction de modification du style
     */
    function modStyle(){
        if(isset($_POST['style']))
            $_SESSION['style'] = $_POST['style'];
    }


    /*
     *  Fonction de generation du formulaire de style
     */
    function genFormStyle(){
        $res = '<form action="preferences.php" method="post">';
        $res .= '<p>Selctionner un style</p>';
        $res .= '<select name="style" id="style">';
        if(isset($_SESSION['style'])){
            switch($_SESSION['style']){
                case "blue.css":
                    $res .= '<option value="blue.css" selected>Blue</option>';
                    $res .= '<option value="italic.css">Italic</option>';
                    $res .= '<option value="vertetjaune.css">V et J</option>';
                    break;
                case "italic.css":
                    $res .= '<option value="blue.css">Blue</option>';
                    $res .= '<option value="italic.css" selected>Italic</option>';
                    $res .= '<option value="vertetjaune.css">V et J</option>';
                    break;
                case "vertetjaune.css":
                    $res .= '<option value="blue.css">Blue</option>';
                    $res .= '<option value="italic.css">Italic</option>';
                    $res .= '<option value="vertetjaune.css" selected>V et J</option>';
                    break;
            }
        }
        else{
            $res .= '<option value="blue.css">Blue</option>';
            $res .= '<option value="italic.css">Italic</option>';
            $res .= '<option value="vertetjaune.css">V et J</option>';
        }
        $res .= '</select>';
        $res .= '<button value="submit">Go !</button>';
        $res .= '</form>';
        echo $res;
    }
    /*
     *  FIN FONCTIONS
     */


    /*
     *  GENERATION DE LA PAGE
     */
    genEntete("Preferences");
    modStyle();
    genFormStyle();
    genPiedPage();