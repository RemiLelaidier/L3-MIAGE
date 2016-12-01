package Recherche;

public class Chercheur {
	
	// Methode recherche
	/*
	 * 1) Au pire, la recherche prendra la longueur du tableau - 1 de calcul
	 * 
	 * 2) Il est important que le tableau contienne des entier
	 * 
	 * */
	public int recherche(int[] tab, int recherche){
		int trouve = -1; // Tant que trouve est a -1, on a rien trouve
		int i = 0;
		while(trouve == -1 && i < tab.length){
			// Si on trouve
			if(tab[i] == recherche){
				trouve = i;
				break;
			}
			i++;
		}
		return trouve;
	}
	
	// Recherche Dichotomique
	public int rechercheDichotomique(int[] tab, int recherche){
		// Variables de positionnement
		int debut, milieu, fin;
		int trouve = -1;
		int i = 0;
		
		// Tri du tableau
		java.util.Arrays.sort(tab);
		
		// Initialisation des positions
		fin = tab.length-1;
		debut = 0;
		
		while(trouve == -1 && i < tab.length){
			milieu = (fin+debut) / 2;
			// Dichotomie
			if(tab[milieu] == recherche){
				trouve = milieu;
				break;
			}
			else if(tab[milieu] < recherche){
				debut = milieu;
			}
			else{
				fin = milieu;
			}
			i++;
		}
		return trouve;
	}
}
