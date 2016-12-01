package code39;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;

public enum Epaisseur {
	LARGE, ETROIT;
	
	// Methode de tracage
	public void trace(Graphics g, int x, int y, int width, int height, int ratioWid){
		if(this == LARGE){
			g.fillRect(x, y, width*ratioWid, height);
		}else{
			g.fillRect(x, y, width, height);
		}
	}
}
