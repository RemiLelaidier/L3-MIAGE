
public class TestMoyenne1 {

	public static void main(String[] args) {
		Moyenne moy = new Moyenne();
		moy.ajouteNote(15);
		moy.ajouteNote(10);
		moy.ajouteNote(9);
		
		double res = moy.calculMoyenne();
		System.out.println("Resultat = " + res);
	}

}
