package VecteurGeneralise;

import java.util.Arrays;

import Vecteur.Vecteur2D;

public class Vecteur {
	
	//Attributs
	private int[] composantes;
	
	// Constructeur valeurs
	public Vecteur(int ... composantes){
		if(composantes.length > 1){
			this.composantes = new int[composantes.length];
			for(int i = 0; i < composantes.length; i++){
				this.composantes[i] = composantes[i];
			}
		}
		else{
			System.exit(-1);
		}
	}
	
	// Contructeur nbComp et tab
	public Vecteur(int nbComp, int[] composantes){
		if(nbComp >= composantes.length){
			this.composantes = new int[nbComp];
			for(int i = 0; i < composantes.length; i++){
				this.composantes[i] = composantes[i];
			}
			java.util.Arrays.fill(this.composantes, 0);
		}
		else{
			System.exit(-1);
		}
	}
	
	// Lires les composantes
		public int[] getComposantes(){
			return composantes;
		}
	
	// Multiplication par scalaire
	public Vecteur mulbyK(float k){
		int[] newComposantes = new int[composantes.length];
		for(int i = 0; i < composantes.length; i++){
			newComposantes[i] = composantes[i] * Math.round(k);
		}
		return new Vecteur(newComposantes);
	}
	
	
	// Obtenir un scalaire a partir d'un autre Vecteur
	public float obtenirScalaire(Vecteur v2){
		float scalaire = 0;
		int[] v2Comp = v2.getComposantes();
		if(composantes.length == v2Comp.length){
			for(int i = 0; i < composantes.length; i++){
				scalaire += composantes[i] * v2Comp[i];
			}
		}
		else{
			System.exit(2);
		}
		return scalaire;
	}
	
	// Transposition Vecteur
	public Vecteur transposer(){
		int[] newCompo = new int[composantes.length];
		for(int i = 0; i<composantes.length; i++){
			newCompo[composantes.length-i-1] = composantes[i];
		}
		return new Vecteur(newCompo);
	}
	
	// Ajouter avec un autre vecteur
	public Vecteur ajouter(Vecteur v2){
		int[] v2Comp = v2.getComposantes();
		int[] newComp = new int[composantes.length];
		if(composantes.length == v2Comp.length){
			for(int i = 0; i < composantes.length; i++){
				newComp[i] = composantes[i] + v2Comp[i];
			}
		}else{
			System.exit(0);
		}
		return new Vecteur(newComp);
	}
	
	// toString
	public String toString(){
		return new String("Composantes = " + Arrays.toString(composantes));
	}

}
