package VecteurGeneralise;

public class VecteurTest {

	public static void main(String[] args) {
		Vecteur v1 = new Vecteur(4, new int[]{});
		System.out.println(v1.toString());
		
		Vecteur v2 = new Vecteur(12, 45, 78, 1, 6);
		System.out.println(v2.toString());
		
		Vecteur v3 = v2.mulbyK(12);
		System.out.println(v3.toString());
		
		System.out.println("Sclaire = " + v2.obtenirScalaire(v3));
		
		Vecteur v4 = v2.transposer();
		System.out.println(v4.toString());
		
		Vecteur v5 = v2.ajouter(v4);
		System.out.println(v5.toString());
		
	}

}
