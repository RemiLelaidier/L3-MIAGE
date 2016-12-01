<?php
    require_once("entetes.inc.php");

    /*
     *  FONCTIONS
     */
    /*
     *  Fonction d'affichage de la page
     */
    function genPageDate(){

        // Variables
        $date = date("j F Y h:i:s");
        $dateNow = strtotime(date("j F Y"));
        $dateNov = strtotime("01 November 2016");
        $timeToDate =  $dateNov - $dateNow;
        $jours = floor($timeToDate/(60*60*24));

        // Gestion du formulaire
        $mEng = array("January", "February", "March", "April", "May", "June", "July", "August", "September", "November", "December");
        $mFra = array("Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Novembre", "Decembre");
        if(!empty($_POST['date'])){
            $dateSaisie = $_POST['date'];
            for ($i = 0; $i< sizeof($mEng); $i++){
                $dateFr = str_replace($mEng[$i], $mFra[$i], $dateSaisie);
            }
            $dateSaisie = strtotime($dateSaisie);
            $timeToDate = $dateSaisie - $dateNow;
            $jRestants = floor($timeToDate/(60*60*24));
        }

        // Affichage
        $res = '<p>Affichage des dates</p>';
        $res .= $date;
        $res .= '<p>Il reste ' . $jours . ' jours avant le 01 Novembre 2016</p>';
        $res .= '<form method="post">';
        $res .= '<label for="date">Date a modifier (Format : 01 mois 2011): </label>';
        $res .= '<input type="text" name="date"/>';
        $res .= '<input type="submit"/>';
        $res .= '</form>';
        if(isset($dateFr)) {
            $res .= 'Date en francais = ' . $dateFr . '<br/>';
            $res .= 'Il reste ' . $jRestants . ' jours avant le ' . $dateFr;
        }
        echo $res;
    }

    /*
     *  FIN FONCTIONS
     */

    /*
     *  GENERATION DE LA PAGE
     */
    genEntete("Date");
    genPageDate();
    genPiedPage();