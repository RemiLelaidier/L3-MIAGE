package LigneCommande;

public class Somme {
	
	// Attributs
	private int total = 0;
	
	public int calcule(String[] tab){
		for(String a : tab){
			int b = Integer.parseInt(a);
			total += b;
		}
		return total;
	}
}
