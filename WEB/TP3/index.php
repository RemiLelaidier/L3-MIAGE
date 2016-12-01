<?php
/**
 * POINT D'ENTREE DE L'APPLICATION
 */
    session_start();
    define("RACINE", __DIR__);

    // Affichage des erreurs
    ini_set('display_errors', 1);
    error_reporting(E_ALL);

    // Autoloader
    use App\Controller\BaseController;
    use App\Autoloader;

    require (RACINE."/App/__autoload.inc");
    Autoloader::register();

    ob_start();

    // Definir le controlleur a appeller
    if(isset($_GET['page']))
        $p = $_GET['page'];

    if($p == 'accueil'){
        $controleur = new BaseController();
        $controleur->index();
    }
    elseif($p == 'createart'){
        $controleur = new BaseController();
        $controleur->addArticle();
    }
    elseif($p == 'createcat'){
        $controleur = new BaseController();
        $controleur->addCategorie();
    }
    elseif($p == 'choixPersistance'){
        $controleur = new BaseController();
        $controleur->choixPersistance();
    }
    elseif($p == 'ajoutSource'){
        $controleur = new BaseController();
        $controleur->addSource();
    }
    elseif(is_numeric($p)){
        $controleur = new BaseController();
        $controleur->editArticle($p);
    }
    elseif ($p == 'recherche'){
        $controleur = new BaseController();
        $controleur->rechercher();
    }
    else{
        $controleur = new BaseController();
        $controleur->error(404);
    }

    $content = ob_get_clean();

    require ("App/Vue/layout.php");
?>