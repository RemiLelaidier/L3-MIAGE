package code39;

import java.awt.Graphics;

public class Symbole{
	Epaisseur e;
	Nature n;
	private int posX = 25, posY = 25;
	private int width = 2;
	private int height = 100;
	private int ratioWid = 2;
	
	public Symbole(Nature nat, Epaisseur ep, Symbole previous){
		if(previous != null){
			this.newLocation(previous);
		}
		this.n = nat;
		this.e = ep;
	}
	
	public void trace(Graphics g){
		n.chooseColor(g);
		e.trace(g, posX, posY, width, height, ratioWid);
	}
	
	private void newLocation(Symbole previous){
		if(previous.e == Epaisseur.LARGE){
			this.posX = previous.getPosX() + (width*ratioWid);
		}
		else{
			this.posX = previous.getPosX() + width;
		}
	}
	
	public int getPosX(){
		return posX;
	}
	
	public void setPosX(int posX){
		this.posX = posX;
	}
	
	public int getposY(){
		return height;
	}
	
	public int getWidth(){
		return width;
	}
	
	public int getRatioWid(){
		return ratioWid;
	}
	
	public int getHeight(){
		return height;
	}
}
