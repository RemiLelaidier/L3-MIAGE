
public class TestMoyennePOO {

	public static void main(String[] args) {
		MoyennePOO moy = new MoyennePOO();
		
		moy.ajouteNoteEcrite(12);
		moy.ajouteNoteEcrite(15);
		
		moy.ajouteNoteTP(11);
		moy.ajouteNoteTP(14);
		
		moy.ajouteNoteComp(20);
		
		moy.ajoutPresence(12);
		
		double res = moy.calculMoyenne();
		
		System.out.println("Resultat = " + res);

	}

}
