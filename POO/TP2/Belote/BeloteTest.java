package Belote;

public class BeloteTest {

	public static void main(String[] args) {
		// Variable de mesure
		int indexMax;
		
		// Creation de 4 Cartes
		Couleur atout = Couleur.CARREAU;
		Carte[] c = new Carte[4];
		c[0] = new Carte(Couleur.CŒUR, Valeur.DAME, atout);
		c[1] = new Carte(Couleur.CARREAU, Valeur.ROI, atout);
		c[2] = new Carte(Couleur.CARREAU, Valeur.VALET, atout);
		c[3] = new Carte(Couleur.TREFLE, Valeur.SEPT, atout);
		
		System.out.println("Les Cartes sont " + "\n"
				+ c[0].toString() + "\t= " + c[0].valeurWithAtout() + "(Atout)\t "+ c[0].valeurWithoutAtout() + "(Sans Atout)\n"
				+ c[1].toString() + "\t= " + c[1].valeurWithAtout() + "(Atout)\t "+ c[1].valeurWithoutAtout() + "(Sans Atout)\n"
				+ c[2].toString() + "\t= " + c[2].valeurWithAtout() + "(Atout)\t "+ c[2].valeurWithoutAtout() + "(Sans Atout)\n"
				+ c[3].toString() + "\t= " + c[3].valeurWithAtout() + "(Atout)\t "+ c[3].valeurWithoutAtout() + "(Sans Atout)\n"
				+ "L'atout est le " + atout.toString());
		
		// Compare valeurs sans atout
		indexMax = 0;
		c[indexMax].valeurWithoutAtout();
		for(int i = 1; i < 4; i++){
			if(c[indexMax].valeurWithoutAtout() < c[i].valeurWithoutAtout()){
				indexMax = i;
			}
		}
		System.out.println("La meilleure carte sans Atout est " + c[indexMax].toString());
		
		// Compare valeurs avec atout
		indexMax = 0;
		c[indexMax].valeurWithAtout();
		for(int i = 1; i < 4; i++){
			if(c[indexMax].valeurWithAtout() < c[i].valeurWithAtout()){
				indexMax = i;
			}
		}
		System.out.println("La meilleure carte avec Atout est " + c[indexMax].toString());
	}

}
