/**
 * Classe Moyenne
 * @version 1.0
 * @author leetspeakv2
 *
 */
public class Moyenne {
	
	int notes = 0;
	int nombreDeNotes = 0;

	/**
	 * Methode qui ajoute une note
	 * @param note
	 */
	void ajouteNote(int note){
		notes += note;
		nombreDeNotes += 1;
	}
	
	/**
	 * Methode qui calcule la moyenne
	 * @return double
	 */
	double calculMoyenne(){
		return (/**(double)*/notes) / nombreDeNotes;
	}
}
