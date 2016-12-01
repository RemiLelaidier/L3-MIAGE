package Recherche;

public class ChercheurTest {

	public static void main(String[] args) {
		int[] i = {2, 5 ,18, 13, 4, 9, 14, 25, 10, 3, 6};
		
		Chercheur c1 = new Chercheur();
		System.out.println("Recherche = " + c1.recherche(i, 10));
		
		System.out.println("Recherche Dichotomique = " + c1.rechercheDichotomique(i, 5));
	}

}
