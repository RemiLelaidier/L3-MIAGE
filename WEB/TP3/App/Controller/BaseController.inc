<?php
/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 22/11/16
 * Time: 13:20
 */

namespace App\Controller;


use App\Modele\Article;
use App\Modele\Categorie;

class BaseController extends Controller
{

    public function __construct(){
        self::checkPersistance();
    }

    /**
     * Index
     */
    public function index(){
        $categories = self::$persistanceProvider->getCategories();
        $this->render("index", compact('categories'));
    }

    /**
     * Articles
     */
    public function addArticle(){
        if(!empty($_POST['titre']) && !empty($_POST['auteur']) && !empty($_POST['texte']) && !empty($_POST['categorie'])){
            $a = new Article(time(), time(),$_POST['titre'], $_POST['auteur'], $_POST['texte']);
            $a->setCategorie(new Categorie($_POST['categorie']));
            if(self::$persistanceProvider->addArticle($a)){
                $message = "Article ajoute";
            }
            else{
                $message = "Echec de l'ajout";
            }
        }
        else{
            $message = "Les champs sont a remplir";
        }
        $categories = self::$persistanceProvider->getCategories();
        $this->render("create", compact('message','categories'));
    }

    /**
     * Categories
     */
    public function addCategorie(){
        if(!empty($_POST['categorie'])){
            if(self::$persistanceProvider->addCategorie($_POST['categorie'])){
                $message = "Categorie ajoute";
            }
            else{
                $message = "Echec de l'ajout";
            }
        }
        else{
            $message = "Les champs sont a remplir";
        }
        $this->render("createcat", compact('message'));
    }

    /**
     * choix persistance
     */
    public function choixPersistance(){
        $typePossible = glob(RACINE . "/App/Donnees/*.inc");
        foreach ($typePossible as $k => $type){
            $type = basename($type);
            if($type != "Persistance.inc")
                $typePossible[$k] = str_replace('.inc', '', $type);
            else
                unset($typePossible[$k]);
        }
        if(!empty($_POST['persistance'])){
            if(in_array($_POST['persistance'], $typePossible)){
                $_SESSION['persistance'] = $_POST['persistance'];
                self::checkPersistance();
            }
        }
        $this->render("choixPersistance", compact('typePossible'));
    }

    /**
     * Ajout Source
     */
    public function addSource(){
        // XML
        if (isset($_FILES['ficXML'])){
            $_SESSION['ficXML'] = file_get_contents($_FILES['ficXML']['tmp_name']);
            $XMLmessage = 'Ajout effectue';
        }
        // SQL
        if(isset($_POST['hote']) && isset($_POST['bdd']) && isset($_POST['login']) && isset($_POST['mdp'])){
            $_SESSION['database']['host'] = $_POST['hote'];
            $_SESSION['database']['database'] = $_POST['bdd'];
            $_SESSION['database']['user'] = $_POST['login'];
            $_SESSION['database']['password'] = $_POST['mdp'];
            $BDDmessage = 'Ajout effectue';
        }
        if($_SESSION['persistance'] === "MYSQL")
            $this->render("ajoutSourceSQL", compact('BDDmessage'));
        else
            $this->render("ajoutSourceXML", compact('XMLmessage'));
    }

    /**
     * Editer un article
     */
    public function editArticle($id){
        $message = "";
        if(!empty($_POST['titre']) && !empty($_POST['auteur']) && !empty($_POST['texte']) && !empty($_POST['categorie'])){
            $a = new Article($id , time(),$_POST['titre'], $_POST['auteur'], $_POST['texte']);
            $a->setCategorie(new Categorie($_POST['categorie']));
            if(self::$persistanceProvider->updateArticle($a)){
                $message = "Article mis a jour";
            }
            else{
                $message = "Echec de l'edition";
            }
        }
        $categories = self::$persistanceProvider->getCategories();
        $article = self::$persistanceProvider->getArticle($id);
        $this->render("editArticle", compact('message', 'article', 'categories'));
    }

    /**
     * Recherche
     */
    public function rechercher(){
        if(isset($_POST['recherche'])){
            $recherche = $_POST['recherche'];
            $results = self::$persistanceProvider->recherche($recherche);
            $this->render("recherche", compact('recherche', 'results'));
        }
        else{
            $this->render("recherche");
        }
    }

    /**
     * Errors
     */
    public function error($code){
        switch ($code){
            case 404:
                $message = "404 : Page introuvable";
                break;
            case 403:
                $message = "403 : Acces refuse";
                break;
            default:
                $message = "Erreur inconnue";
        }
        $this->render("error", compact('message'));
    }
}