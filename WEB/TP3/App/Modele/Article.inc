<?php

namespace App\Modele;

class Article {
	
	/**
	 * 
	 * @var Categorie
	 */
	private $categorie ; 
	
	/**
	 * 
	 * @var string
	 */
	private $titre;
	/**
	 * 
	 * @var string
	 */
	private $auteur;
	/**
	 *
	 * @var string
	 */
	private $texte;

    /**
     * @var timestamp
     */
    private $dateModif;

    /**
     * @var timestamp
     */
    private $dateCrea;
	
	/**
	 * constructeur
	 * @param string $titre
	 * @param string $auteur
	 * @param string $texte
	 */
	public function __construct($dateCrea, $dateModif, $titre, $auteur, $texte) {
	    if(!is_numeric($dateCrea))
	        $this->dateCrea = strtotime($dateCrea);
        else
	        $this->dateCrea = $dateCrea;
        if(!is_numeric($dateModif))
            $this->dateModif = strtotime($dateModif);
        else
            $this->dateModif = $dateModif;
        $this->dateModif = $dateModif;
		$this->auteur =$auteur;
		$this->texte = $texte;
		$this->titre = $titre;
	}

    /**
     * @return mixed
     */
    public function getDateCrea()
    {
        return $this->dateCrea;
    }

    /**
     * @param $dateCrea
     */
    public function setDateCrea($dateCrea)
    {
        $this->dateCrea = $dateCrea;
    }

    /**
     * @return timestamp
     */
    public function getDateModif()
    {
        return $this->dateModif;
    }

    /**
     * @param $dateModif
     */
    public function setDateModif($dateModif)
    {
        $this->dateModif = $dateModif;
    }

	/**
	 * retourne la catégorie, si elle existe, de l'article
	 * @return Categorie
	 */
	public function getCategorie()
	{
		return $this->categorie;
	}
	
	/**
	 * pour affecter ou changer de catégorie
	 * @param Categorie $cat
	 */
	public function setCategorie(Categorie $cat)
	{
		$this->categorie = $cat;
	}

	/**
	 * retourne le titre de l'article
	 * @return string
	 */
	public function getTitre()
	{
		return $this->titre;
	}
	
	/**
	 * pour affecter ou changer de titre
	 * @param string $titre
	 */
	public function setTitre($titre)
	{
		$this->titre = titre;
	}

    /**
     * @return string
     */
	public function getAuteur(){
	    return $this->auteur;
    }

    /**
     * @param $auteur
     */
    public function setAuteur($auteur){
        $this->auteur = $auteur;
    }

    /**
     * @return string
     */
    public function getTexte(){
        return $this->texte;
    }

    /**
     * @param $texte
     */
    public function setTexte($texte){
        $this->texte = $texte;
    }
	
	/**
	 * pour obtenir une vue html de l'article
	 */
	public function getHtml()
	{
	    $crea = date('d/m/Y', intval($this->dateCrea));
	    $modif = date('d/m/Y', intval($this->dateModif));
		$result = <<<EOR
		<fieldset>
			<legend>{$this->titre} par {$this->auteur} le {$crea} | <a href="index.php?page={$this->dateCrea}">EDITER</a></legend>
			{$this->texte}
			<legend>Derniere modification le {$modif}</legend>
		</fieldset>
EOR;
		return $result;
	}
}
?>