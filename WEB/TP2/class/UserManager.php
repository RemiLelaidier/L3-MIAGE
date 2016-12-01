<?php

require_once ('User.php');

/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 07/11/16
 * Time: 13:22
 */
class UserManager
{
    private static $usersfile = "/comptes/l/lr608594/www/TP2/users.csv";
    private $user;

    /* Methode qui verifie la demande de connexion d'un utilisateur
     *
     */
    public static function checkConnect(){
        // Si on cherche a se deconnecter
        if(isset($_POST['deco']) && $_POST['deco'] == TRUE){
            UserManager::stopSession();
        }

        // Sinon si on envoie un formulaire de connexion
        elseif(isset($_POST['nom']) && isset($_POST['prenom']) && isset($_POST['password'])){
            $csv = fopen(UserManager::$usersfile, "r");
            while (($row = fgetcsv($csv, 1000, ",")) !== FALSE) {
                if ($row[0] == $_POST['nom'] && $row[1] == $_POST['prenom'] && $row[2] == $_POST['password']) {
                    $_SESSION['user'] = new User($_POST['nom'], $_POST['prenom'], TRUE);
                } else {
                    $_SESSION['user'] = new User("", "", FALSE);
                }
            }
            fclose($csv);
        }
    }

    // Fonction qui deconnecte un utilisateur
    public static function stopSession(){
        session_destroy();
    }

    // Fonction qui enregistre l'utilisateur dans le CSV
    //  Retourne une chaine de cractere vide si rien est a faire
    //  Retourne une chaine de caractere si erreur
    //  Sinon renvoie TRUE
    public static function writeUser(){
        if(isset($_POST['nom']) && isset($_POST['prenom']) && isset($_POST['password1']) && isset($_POST['password2'])){
            if($_POST['password1'] != $_POST['password2'])
                return "Le mot de passe ne correspond pas";
            if(UserManager::userInCSV() == TRUE)
                return "Utilisateur deja enregistre";
            else {
                $user = array($_POST['nom'], $_POST['prenom'], $_POST['password1']);
                $csv = fopen(UserManager::$usersfile, "a");
                fputcsv($csv,$user);
                fclose($csv);
                return TRUE;
            }
        }
        else
            return "";
    }

    // Fonction qui verifie la presence de l'utilisateur dans le CSV
    //  Renvoie FALSE si l'utilisateur n'existe pas
    //  Sinon TRUE
    public static function userInCSV(){
        if(isset($_POST['nom']) && isset($_POST['prenom'])){
            $csv = fopen(UserManager::$usersfile, "r");
            while (($row = fgetcsv($csv, 1000, ",")) !== FALSE) {
                if ($row[0] == $_POST['nom'] && $row[1] == $_POST['prenom']) {
                    fclose($csv);
                    return TRUE;
                }
            }
            fclose($csv);
            return FALSE;
        }
    }


}