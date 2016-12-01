<?php

namespace App\Donnees;

use App\Bdd\Database;
use App\Modele\Article;
use App\Modele\Categorie;

class MYSQL implements Persistance {

    private $host = "localhost";

    private $database = "TP3a";

    private $user = "root";

    private $password = "root";

    private $objetbdd;

    private $categories;

    /*-------------------------------------------------*/

    /*
     * Constructeur
     */
    public function __construct(){
        if(isset($_SESSION['database'])){
            $this->objetbdd = new Database(
                    $_SESSION['database']['host'],
                    $_SESSION['database']['database'],
                    $_SESSION['database']['user'],
                    $_SESSION['database']['password']);
        }
        else{
            $this->objetbdd = new Database($this->host, $this->database, $this->user, $this->password);
        }
    }

    /**
     * permet de charger toutes les catégories et tous les articles
     * @return boolean : vrai en cas de succès, faux sinon
     */
    public function charger(){
        $this->objetbdd->query("SELECT * FROM categories");
        if($this->objetbdd != null){
            foreach ($this->objetbdd->fetchAll() as $k => $cat){
                $this->categories[$k] = new Categorie($cat['nom']);
                $this->objetbdd->query("SELECT * FROM articles WHERE articles.categorie = :categorie");
                $this->objetbdd->bindParam(':categorie', $cat['nom']);
                foreach ($this->objetbdd->fetchAll() as $art){
                    $this->categories[$k]->addArticle(new Article(
                            strtotime($art['creation']),
                            strtotime($art['modification']),
                            $art['titre'],
                            $art['auteur'],
                            $art['texte']));
                }
            }
        }
    }

    /**
     * @return array retourne un tableau de toutes les catégories lues
     */
    public function getCategories(){
        if(count($this->categories) == 0)
            $this->charger();
        return $this->categories;
    }

    /**
     * @return array retourne un article identifier par son id
     */
    public function getArticle($id){
        $this->objetbdd->query("SELECT * FROM articles WHERE creation = :creation");
        $this->objetbdd->bindParam(":creation", date("Y-m-d H:i:s", $id));
        return $this->objetbdd->fetch();
    }

    /**
     * @param $article Article a ajouter
     * @return boolean
     */
    public function addArticle($article){
        $done =false;
        $this->objetbdd->query("SELECT * FROM categories");
        foreach ($this->objetbdd->fetchAll() as $category){
            if($category['nom'] === $article->getCategorie()->getNom()){
                $this->objetbdd->query("INSERT INTO articles VALUES (CURRENT_TIMESTAMP, CURRENT_TIMESTAMP , :categorie, :titre, :auteur, :texte)");
                $this->objetbdd->bindParam(":categorie", $article->getCategorie()->getNom());
                $this->objetbdd->bindParam(":titre", $article->getTitre());
                $this->objetbdd->bindParam(":auteur", $article->getAuteur());
                $this->objetbdd->bindParam(":texte", $article->getTexte());
                $this->objetbdd->exec();
                $done =true;
            }
        }
        return $done;
    }

    /**
     * @param $categorie
     * @return boolean
     */
    public function addCategorie($categorie){
        $done = false;
        $this->objetbdd->query("SELECT * FROM categories");
        $listeCategorie = array();
        foreach ($this->objetbdd->fetchAll() as $k => $category){
            $listeCategorie[$k] = $category['nom'];
        }
        if(!in_array($categorie, $listeCategorie)){
            $this->objetbdd->query("INSERT INTO categories VALUES (:nom)");
            $this->objetbdd->bindParam(":nom", $categorie);
            $this->objetbdd->exec();
            $done = true;
        }
        return $done;
    }

    /**
     * @param $article
     */
    public function updateArticle($article)
    {
        $done = false;
        $this->objetbdd->query("SELECT * FROM categories");
        foreach ($this->objetbdd->fetchAll() as $category){
            if($category['nom'] === $article->getCategorie()->getNom()){
                $this->objetbdd->query("UPDATE articles SET modification = :modification, categorie = :categorie, titre = :titre, auteur = :auteur, texte = :texte WHERE creation = :creation");
                $this->objetbdd->bindParam(":creation", date("Y-m-d H:i:s", $article->getDateCrea()));
                $this->objetbdd->bindParam(":modification", date("Y-m-d H:i:s", $article->getDateModif()));
                $this->objetbdd->bindParam(":categorie", $article->getCategorie()->getNom());
                $this->objetbdd->bindParam(":titre", $article->getTitre());
                $this->objetbdd->bindParam(":auteur", $article->getAuteur());
                $this->objetbdd->bindParam(":texte", $article->getTexte());
                $this->objetbdd->exec();
                $done =true;
            }
        }
        return $done;
    }

    /**
     * @param $recherche
     * @return array
     */
    public function recherche($recherche)
    {
        $retour = array();
        $this->objetbdd->query("SELECT * FROM articles WHERE titre LIKE CONCAT(:recherche, '%') OR auteur LIKE CONCAT(:recherche, '%') OR texte LIKE CONCAT(:recherche, '%')");
        $this->objetbdd->bindParam(':recherche', $recherche);
        $articles = $this->objetbdd->fetchAll();
        foreach ($articles as $article){
            array_push($retour, new Article($article['creation'],$article['modification'], $article['titre'], $article['auteur'], $article['texte']));
        }
        return $retour;
    }
}