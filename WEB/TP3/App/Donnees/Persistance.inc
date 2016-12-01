<?php

namespace App\Donnees;

interface Persistance {
	
	/**
	 * permet de charger toutes les catégories et tous les articles
	 * @return boolean : vrai en cas de succès, faux sinon
	 */
	public function charger();
	
	/**
	 * @return array retourne un tableau de toutes les catégories lues
	 */
	public function getCategories();

	/**
	 * @return array retourne un tableau de toutes les articles lus de toutes les catégories lues
	 */
	public function getArticle($id);

    /**
     * @param $article Article a ajouter
     * @return boolean
     */
    public function addArticle($article);

    /**
     * @param $categorie
     * @return boolean
     */
    public function addCategorie($categorie);

    /**
     * @param $article
     * @return mixed
     */
    public function updateArticle($article);

    /**
     * @param $recherche
     * @return mixed
     */
    public function recherche($recherche);
}
?>