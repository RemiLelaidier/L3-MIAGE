<?php

namespace App\Donnees;

use \App\Modele\Categorie;
use \App\Modele\Article;

class XML implements Persistance {

    /**
     * @var string Chemin vers le fichier XML
     */
    private $ficXML;

    /**
     * @var SimpleXMLElement Le fichier XML
     */
    private $XML;

    /**
     * @var Categorie Liste des categories
     */
    private $categories;


    /*-------------------------------------------------*/
    /**
     * Constructeur qui lit le fichier XML
     */
    public function __construct(){
        if(isset($_SESSION['ficXML'])) {
            $this->XML = simplexml_load_string($_SESSION['ficXML']);
        }
        else
            $this->XML = simplexml_load_file(RACINE.'/news/news.xml');
    }

    /**
     * permet de charger toutes les catégories et tous les articles
     * @return boolean : vrai en cas de succès, faux sinon
     */
    public function charger(){
        // On explore les categorie
        $k = 0;
        foreach ($this->XML->categorie as $categorie){
            $this->categories[$k] = new Categorie($categorie->nom->__toString());

            // Et les articles de la categorie
            foreach ($categorie->article as $a){
                $newa = new Article($a->creation->__toString(), $a->modification->__toString(), $a->titre->__toString(), $a->auteur->__toString(), $a->texte->__toString());
                $this->categories[$k]->addArticle($newa);
            }
            $k++;
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
     * @return array retourne un tableau de tous les articles lus de toutes les catégories lues
     */
    public function getArticle($id){
        foreach($this->XML->categorie as $category){
            foreach ($category->article as $art){
                if($art->creation->__toString() == $id){
                    $article = array();
                    $article['creation'] = $art->creation->__toString();
                    $article['modification'] = $art->modification->__toString();
                    $article['titre'] = $art->titre->__toString();
                    $article['auteur'] = $art->auteur->__toString();
                    $article['texte'] = $art->texte->__toString();
                    $article['categorie'] = $category->nom->__toString();
                }
            }
        }
        return $article;
    }

    /**
     * @param \App\Donnees\Article $article article a jouter
     * @return bool false si echec sinon true
     */
    public function addArticle($article){
        $done = false;
        foreach ($this->XML->categorie as $category){
            if($category->nom->__toString() === $article->getCategorie()->getNom()){
                $a = $category->addChild('article');
                $a->addChild('creation', time());
                $a->addChild('modification', time());
                $a->addChild('titre', $article->getTitre());
                $a->addChild('auteur', $article->getAuteur());
                $a->addChild('texte', $article->getTexte());
                $this->XML->asXML(RACINE."/news/news.xml");
                $done = true;
            }
        }
        return $done;
    }

    /**
     * @param $categorie
     * @return bool
     */
    public function addCategorie($categorie){
        $done = false;
        // On determine si la categorie existe deja
        $listeCategorie = array();
        foreach ($this->XML->categorie as $k => $category){
            $listeCategorie[$k] = $category->nom->__toString();
        }
        if(!in_array($categorie, $listeCategorie)){
            $cat = $this->XML->addChild('categorie');
            $cat->addChild('nom', $categorie);
            $this->XML->asXML(RACINE."/news/news.xml");
            $done = true;
        }
        return $done;
    }

    /**
     * @param $article
     * @return bool
     */
    public function updateArticle($article){
        $done = false;
        foreach ($this->XML->categorie as $category){
            if($category->nom->__toString() == $article->getCategorie()->getNom()){
                foreach($category->article as $oldArt){
                    if($oldArt->creation->__toString() == $article->getDateCrea()){
                        $oldArt->modification = time();
                        $oldArt->titre = $article->getTitre();
                        $oldArt->auteur = $article->getAuteur();
                        $oldArt->texte = $article->getTexte();
                        $done = true;
                    }
                }
            }
        }
        $this->XML->asXML(RACINE."/news/news.xml");
        return $done;
    }

    /**
     * @param $recherche
     * @return array
     */
    public function recherche($recherche)
    {
        $retour = array();
        foreach ($this->XML->categorie as $category){
            foreach ($category->article as $article){
                if(strstr($article->titre, $recherche) !== false || strstr($article->auteur, $recherche) !== false || strstr($article->texte, $recherche) !== false){
                    array_push($retour, new Article($article->creation->__toString(),
                        $article->modification->__toString(),
                        $article->titre->__toString(),
                        $article->auteur->__toString(),
                        $article->texte->__toString()));
                }
            }
        }
        return $retour;
    }
}