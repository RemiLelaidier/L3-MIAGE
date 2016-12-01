package Tortue;

public class Tortue {
	// Champs static
	static private double orientationDefault = 0;
	static private boolean styloDefault = false;
	
	// Attribut
	// Repere cartesien
	private int x = 0;
	private int y = 0;
	
	// Orientation en radians
	private double orientation;
	
	// Stylo true = baisse et false = levee
	private boolean stylo = false;
	
	// Accesseurs
	public int getX(){
		return this.x;
	}
	
	public int getY(){
		return this.y;
	}
	
	// Constructeurs
	public Tortue(int x, int y, double orientation, boolean stylo){
		this.x = x;
		this.y = y;
		this.orientation = orientation;
		this.stylo = stylo;
	}
	
	public Tortue(int x, int y){
		this(x, y, orientationDefault, styloDefault);
	}
	
	public Tortue(){
		this(0, 0, orientationDefault, styloDefault);
	}
	// Fin Constructeurs
	
	// Methode pour lever le stylo
	public void leveStylo(){
		if(stylo == true){
			this.stylo = false;
		}
	}
	
	// Methode pour baisser le stylo
	public void baisseStylo(){
		if(stylo == false){
			this.stylo = true;
		}
	}
	
	// Methode pour tourner a gauche
	public void gauche(double degre){
		if(degre <= 360.0){
			this.orientation -= Math.toRadians(degre);
		}
	}
	
	// Methode pour tourner a droite
	public void droite(double degre){
		if(degre <= 360.0){
			this.orientation += Math.toRadians(degre);
		}
	}
	
	// Methode pour avancer
	public void avance(int pixel){
		this.x += pixel * Math.cos(orientation);
		this.y += pixel * Math.sin(orientation);
	}
	
	// Methode pour reculer
	public void recule(int pixel){
		this.x -= pixel * Math.cos(orientation);
		this.y -= pixel * Math.sin(orientation);
	}
}
