package Vecteur;

public class Vecteur2D {
	
	// Attributs
	private int x;
	private int y;

	// Constructeur
	public Vecteur2D(int x, int y){
		this.x = x;
		this.y = y;
	}
	
	// Accesseurs
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	// Methodes
	// Multiplication par scalaire k
	public Vecteur2D mulByK(float k){
		int x = this.x*Math.round(k);
		int y = this.y*Math.round(k);
		return new Vecteur2D(x, y);
	}
	
	// Obtenir un scalaire a partir d'un autre Vecteur
	public float obtenirScalaire(Vecteur2D v2){
		return (this.x * v2.getX() + this.y * v2.getY());
	}
	
	// Transposition Vecteur
	public Vecteur2D transposer(){
		return new Vecteur2D(this.y, this.x);
	}
	
	// Ajouter avec un autre vecteur
	public Vecteur2D ajouter(Vecteur2D v2){
		return new Vecteur2D((this.x + v2.getX()), (this.y + v2.getY()));
	}
	
	// Afficher en chaine de caractere
	public String toString(){
		return new String("x = " + Integer.toString(this.x) +"\n"
				+ "y = " + Integer.toString(this.y));
	}
}
