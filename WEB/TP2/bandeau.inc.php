<?php

class Bandeau{
    // Plan du site
    public static $map = array(
        array("index.php", "Connexion"),
        array("tableau.php", "Tableau"),
        array("date.php", "Date"),
        array("preferences.php", "Choix du style"),
        array("creation.php", "Inscription")
    );

    /*
     *  Map des droits d'acces
     *      ALWAYS      = toujours accessible
     *      LIMITED     = si connecte
     *      DISCONNECT  = si deconnecte
     */
    public static $publicAccess = array(
        array("index.php", "ALWAYS"),
        array("tableau.php", "ALWAYS"),
        array("date.php", "DISCONNECT"),
        array("preferences.php", "LIMITED"),
        array("creation.php", "DISCONNECT")
    );

    // Fonction de generation des liens
    private function genererLien($href, $name){
        if($href == basename($_SERVER['PHP_SELF']))
            return '<a class="inlienactif" href="'.$href.'">'.$name.'</a>';
        else
            return '<a class="inlien" href="'.$href.'">'.$name.'</a>';
    }

    // Fonction de generation du menu
    public function genererBarNav(){

        // Menu de navigation
        $navBar = "<div class='lien'>";
        foreach(Bandeau::$map as $index => $menuItem){
            switch(Bandeau::$publicAccess[$index][1]){
                case "ALWAYS":
                    $navBar .= $this->genererLien($menuItem[0], $menuItem[1]);
                    break;
                case "DISCONNECT":
                    if(!isset($_SESSION['user']) || $_SESSION['user']->isConnected() == FALSE)
                        $navBar .= $this->genererLien($menuItem[0], $menuItem[1]);
                    break;
                case "LIMITED":
                    if(isset($_SESSION['user']) && $_SESSION['user']->isConnected() == TRUE)
                        $navBar .= $this->genererLien($menuItem[0], $menuItem[1]);
                    break;
            }
        }

        // Div droite
        $navBar .= '<div class="droite">';
        if(isset($_SESSION['user']) && $_SESSION['user']->isConnected() == TRUE){
            $navBar .= 'Bienvenu ' . $_SESSION['user']->getPrenom() . ' ' . $_SESSION['user']->getNom();
        }
        else{
            $navBar .= 'Bienvenu cher visiteur';
        }
        $navBar .= ', nous sommes le ' . date("d/m/Y, h:i:s");
        $navBar .= "</div></div>";
        return $navBar;
    }
}