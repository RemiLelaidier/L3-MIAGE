<?php
    require_once("class/UserManager.php");
    require_once("entetes.inc.php");

    // Fonction de genration  du formulaire
    function genFormCrea($message){
        if(is_string($message))
        {
            $res = '<form action="creation.php" method="post" style="
                margin-left: auto;
                margin-right: auto;
                width: 27%;">';
            $res .= '<table>';
            $res .= '<tr>';
            $res .= '<td><label for="nom">Nom</label></td>';
            $res .= '<td><input type="text" name="nom"></td>'; //TODO
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><label for="prenom">Prenom</label></td>';
            $res .= '<td><input type="text" name="prenom"></td>'; //TODO
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><label for="password1">Mot de passe</label></td>';
            $res .= '<td><input type="password" name="password1"></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><label for="password2">Repeter mot de passe</label></td>';
            $res .= '<td><input type="password" name="password2"></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td colspan="2">' . $message . '</td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td colspan="2"><button type="submit">Go !</button></td>';
            $res .= '</tr>';
            $res .= '</table>';
            $res .= '</form>';
            echo $res;
        }
        else{
            echo '<h1>Creation reussie</h1>';
            header("Location: index.php");
        }
    }
    /*
     *  FIN FONCTION
     */

    /*
     *  GENERATION DE LA PAGE
     */
    genEntete("Inscription");
    UserManager::writeUser();
    genFormCrea($message);
    genPiedPage();