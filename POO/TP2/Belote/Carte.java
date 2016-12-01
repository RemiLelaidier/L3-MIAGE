package Belote;

public class Carte {
	
	//**********
	// Attributs
	//**********

	Couleur c;
	Valeur v;
	Couleur atout;
	
	//**********
	// Constructeur
	//**********
	public Carte(Couleur c, Valeur v, Couleur atout){
		this.c = c;
		this.v = v;
		this.atout = atout;
	}
	
	public int valeurWithAtout(){
		if(v == Valeur.SEPT || v == Valeur.HUIT)
			return 0;
		else{
			if (atout == c){
				switch(v){
					case VALET :
						return 20;
					case NEUF :
						return 14;
					case AS :
						return 11;
					case DIX :
						return 10;
					case ROI :
						return 4;
					case DAME :
						return 3;
				default:
					break;
				}
			}
			else{
				switch(v){
					case AS :
						return 11;
					case DIX :
						return 10;
					case ROI :
						return 4;
					case DAME :
						return 3;
					case VALET :
						return 2;
					case NEUF :
						return 0;
				default:
					break;
				}
			}
		}
		return -1;
	}
	
	public int valeurWithoutAtout(){
		switch(v){
		case AS :
			return 11;
		case DIX :
			return 10;
		case ROI :
			return 4;
		case DAME :
			return 3;
		case VALET :
			return 2;
		case NEUF :
			return 0;
		case HUIT :
			return 0;
		case SEPT :
			return 0;
		default:
			break;
		}
		return -1;
	}
	
	public String toString(){
		return v.toString() + " " + c.toString();
	}
}
