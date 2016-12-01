<?php
    require_once("entetes.inc.php");

    /*
     *  FONCTIONS
     */
    /*
     *  Fonction de generation du Tableau
     */
    function genereTableau($titre, $body){
        $strRes = "<table border='1' style='
                margin-left: auto;
                margin-right: auto;
                width: 27%;'>";
        $strRes .= "<caption>" . strval(count($body)) . "</caption>";
        $strRes .= "<thead><tr>";
        foreach ($titre as $cell){
            $strRes .= "<td>$cell</td>";
        }
        $strRes .= "</tr></thead>";
        $strRes .= "<tbody>";
        foreach ($body as $ligne){
            $strRes .= "<tr>";
            foreach ($ligne as $cell){
                $strRes .= "<td>$cell</td>";
            }
            $strRes .= "<tr>";
        }
        $strRes .= "</tbody>";
        $strRes .= "</table>";
        return $strRes;
    }

    /*
     *  Fonction de recuperation des fichiers
     */
    function getFichiers(){
        $tab = array();
        $fichiers = glob("*");
        foreach ($fichiers as $fichier){
            $descFich = array();
            if(is_file($fichier))
                array_push($descFich, "<a href='$fichier'>".$fichier."</a>", date("F d Y", filemtime($fichier)), filesize($fichier));
            else
                array_push($descFich, $fichier, date("F d Y", filemtime($fichier)), "-");
            array_push($tab, $descFich);
        }
        if(isset($_GET["tri"])){
            if($_GET["tri"] == "reverse")
                rsort($tab);
            elseif($_GET["tri"] == "nreverse")
                sort($tab);
        }
        return $tab;
    }

    /*
     * Fonction d'affichage de la page
     */
    function affPageTab(){
        echo '<p>Listage des fichiers</p>';
        $titre = array("Nom du Fichier", "Date de modification", "Taille");
        $tab = getFichiers();
        echo genereTableau($titre, $tab);
        echo '<a href="tableau.php?tri=nreverse">Tableau croissant</a><br/>';
        echo '<a href="tableau.php?tri=reverse">Tableau decroissant</a>';
    }

    /*
     *  FIN FONCTIONS
     */


    /*
     *  GENERATION DE LA PAGE
     */
    genEntete("Tableau");
    affPageTab();
    genPiedPage();