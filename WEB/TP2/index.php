<?php
    require_once("entetes.inc.php");

    /*
     *    FONCTIONS
     */
    /*
     *  Fonction de generation du formulaire de connexion
     */
    function genFormConnect(){
        // Entete du formulaire
        $res = '<table style="margin-left: auto;
            margin-right: auto;
            width: 25%;
            text-align: center;">';
        $res .= '<form method="post" action="index.php">';
        $res .= '<tr>';

        // Si l'utilisateur est deja connecte, on genere le formulaire de deconnexion
        if(isset($_SESSION['user']) && $_SESSION['user']->isConnected() == TRUE){
            $res .= '<td><button type="submit" value="deco" name="deco" id="deco">Deconnexion</button></td>';
        }

        // Si l'utilisateur n'est pas connecte, on genere le formulaire de connexion
        else{
            $res .= '<td><label for="nom">Nom</label></td>';
            $res .= '<td><input id="nom" name="nom" type="text"></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><label for="prenom">Prenom</label></td>';
            $res .= '<td><input id="prenom" name="prenom" type="text"></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><label for="password">Mot de passe</label></td>';
            $res .= '<td><input id="password" name="password" type="password"></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td><button type="submit">Go !</button></td>';
            $res .= '<td><button type="reset">RAZ</button></td>';
            $res .= '</tr>';
            $res .= '<tr>';
            $res .= '<td colspan="2">';

            // Affichage des erreurs de connexion
            if(isset($_SESSION['user']) && $_SESSION['user']->isConnected() == FALSE) {
                $res .= "User/Password invalide";
            }
            $res .= '</td>';
        }
        $res .= '</tr>';
        $res .= '</form>';
        $res .= '</table>';
        echo $res;
    }

    /*
     *    FIN FONCTIONS
     */

    /*
     *   GENERATION DE LA PAGE
     */
    UserManager::checkConnect();
    genEntete("Connexion");
    genFormConnect();
    genPiedPage();
?>
