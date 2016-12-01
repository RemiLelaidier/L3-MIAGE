package code39;

import java.awt.Color;
import java.awt.Graphics;

public enum Nature {
	BARRE, ESPACE;
	
	// Methode de choix de la couleur
	public void chooseColor(Graphics g){
		Color noire = new Color(0, 0, 0);
		Color blanc = new Color(255, 255, 255);
		if(this == BARRE){
			g.setColor(noire);
		}else{
			g.setColor(blanc);
		}
	}
}
