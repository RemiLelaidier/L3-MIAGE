package Vecteur;

public class Vecteur2DTest {

	public static void main(String[] args) {
		// Creation de deux vecteurs
		Vecteur2D v1 = new Vecteur2D(1, 2);
		Vecteur2D v2 = new Vecteur2D(3, -1);
		Vecteur2D v3;
		Vecteur2D v4;
		Vecteur2D v5;
		
		// toString
		System.out.println("Vecteur 1 :\n" + v1.toString());
		System.out.println("Vecteur 2 :\n" + v2.toString());
		
		// mulByK
		v3 = v1.mulByK((float)2.0);
		System.out.println("Vecteur 3 :\n" + v3.toString());
		
		// obtenirScalaire
		System.out.println("Scalaire = " + v1.obtenirScalaire(v2));
		
		// transposer
		v4 = v1.transposer();
		System.out.println("Vecteur 4 :\n" + v4.toString());
		
		// ajouter
		v5 = v1.ajouter(v2);
		System.out.println("Vecteur 5 :\n" + v5.toString());
	}

}
