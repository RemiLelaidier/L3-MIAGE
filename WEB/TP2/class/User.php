<?php

/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 07/11/16
 * Time: 13:22
 */
class User
{
    /*  Attributs
     *      $nom : nom de l'utilisateur
     *      $prenom : prenom de l'utilisateur
     */
    private $nom;
    private $prenom;
    private $connected;

    // Constructeur
    public function User($nom, $prenom, $connected){
        $this->nom = $nom;
        $this->prenom = $prenom;
        $this->connected = $connected;
    }

    //  Recupere le nom
    public function getNom(){
        return $this->nom;
    }

    // Recupere le prenom
    public function getPrenom(){
        return $this->prenom;
    }

    // Enregistre un nom
    public function setNom($nom){
        $this->nom = $nom;
    }

    // Enregistre un prenom
    public function setPrenom($prenom){
        $this->prenom = $prenom;
    }

    public function isConnected(){
        return $this->connected;
    }

    public function deconnect(){
        $this->connected = FALSE;
    }

    public function connect(){
        $this->connected = TRUE;
    }
}