package code39;

import java.awt.Graphics;

public class IterateurSymbole{
	private Symbole[] sym;
	private int tailleMax = 0;
	private int count = 0;
	
	public IterateurSymbole(String chaine){
		char[] chainCarac = chaine.toCharArray();
		tailleMax = chainCarac.length;
		sym = new Symbole[tailleMax];
		
		// Traitement
		for(int i = 0; i < tailleMax; i++){
			// Si c'est le premier symbole ...
			if(i == 0){
				// ...epaisse
				if(chainCarac[i] == '1')
					sym[i] = new Symbole(Nature.BARRE, Epaisseur.LARGE, null);
				// ...fine
				else
					sym[i] = new Symbole(Nature.BARRE, Epaisseur.ETROIT, null);
			}
			// Si c'est un espace
			else if(i % 2 != 0){
				// Epais
				if(chainCarac[i] == '1')
					sym[i] = new Symbole(Nature.ESPACE, Epaisseur.LARGE, sym[i-1]);
				// Fin
				else
					sym[i] = new Symbole(Nature.ESPACE, Epaisseur.ETROIT, sym[i-1]);
			}
			// si c'est une barre
			else{
				// epaisse
				if(chainCarac[i] == '1')
					sym[i] = new Symbole(Nature.BARRE, Epaisseur.LARGE, sym[i-1]);
				// fine
				else
					sym[i] = new Symbole(Nature.BARRE, Epaisseur.ETROIT, sym[i-1]);
			}
		}
	}
	
	public void printCodeBarre(Graphics g){
		for(int i = 0; i < tailleMax; i++){
			sym[i].trace(g);
		}
	}
	
	public int width() {
		int tWidth = 0;
		for(int i = 0; i < sym.length; i++){
			if(sym[i].e == Epaisseur.LARGE)
				tWidth += sym[i].getWidth() * sym[i].getRatioWid();
			else
				tWidth += sym[i].getWidth();
		}
		return tWidth;
	}
	
	public int height(){
		return sym[0].getHeight();
	}
}
