/**
 * Classe MoyennePOO
 * @author leetspeakv2
 *
 */
public class MoyennePOO {
	
	// Attributs
	int notesEcrites = 0;
	int notesTP = 0;
	int noteComp = 0;
	int nombresNotesEcrit = 0;
	int nombresNotesTP = 0;
	int nombresNotesComp = 0;
	double coefficientEcrit = 0.3;
	double coefficientTP = 0.15;
	double coefficientComp = 0.1;
	double coefficientPresence = 0.1;
	int presence = 0;
	
	/**
	 * Methode d'ajout du nombre de presence
	 * @param nbPresence
	 */
	void ajoutPresence(int nbPresence){
		presence = nbPresence;
	}
	
	/**
	 * Methode d'ajout d'une note ecrite
	 * @param noteEcrite
	 */
	void ajouteNoteEcrite(int noteEcrite){
		notesEcrites += noteEcrite;
		nombresNotesEcrit += 1;
	}
	
	/**
	 * Methode d'ajout d'une note de TP
	 * @param noteTP
	 */
	void ajouteNoteTP(int noteTP){
		notesTP += noteTP;
		nombresNotesTP += 1;
	}
	
	/**
	 * Methode d'ajout d'une note de comportement
	 * @param noteComp
	 */
	void ajouteNoteComp(int noteComp){
		noteComp += noteComp;
		nombresNotesComp += 1;
	}
	
	/**
	 * Methode de calcul de la moyenne
	 * @return double
	 */
	double calculMoyenne(){
		double res;
		res = ((double)notesEcrites) * coefficientEcrit;
		res += ((double)notesTP) * coefficientTP;
		res += ((double)noteComp) * coefficientComp;
		res = res * (presence * coefficientPresence);
		res = res / ((nombresNotesEcrit * coefficientEcrit) + (nombresNotesTP * coefficientTP) + (nombresNotesComp * coefficientComp));
		return res;
	}
}
