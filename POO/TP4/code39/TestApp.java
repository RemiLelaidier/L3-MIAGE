package code39;

import java.applet.Applet;
import java.awt.Graphics;

public class TestApp extends Applet{

	public void paint(Graphics g){
		String mess = "012345678910";
		Code39 codeur = new Code39();
		String messCode = codeur.encodeMess(mess);
		IterateurSymbole ite = new IterateurSymbole(messCode);
		ite.printCodeBarre(g);
		mess = "*" + mess + "*";
		g.drawString(mess, (ite.width()/2 - mess.length()/2), ite.height()+50);
	}
}
