package LigneCommande;

public class Affichage {

	public static void main(String[] args) {
		// On tri les arguments
		java.util.Arrays.sort(args);
		
		// On les affiche
		for(String s : args){
			System.out.println(s);
		}
	}

}
