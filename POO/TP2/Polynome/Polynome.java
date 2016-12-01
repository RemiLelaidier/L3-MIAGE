package Polynome;


public class Polynome {
	double a,b,c;
	double x1,x2;
	Complexe r1, r2;
	private double delta;
	
	// Constructeurs
	public Polynome(double a, double b, double c){
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public Polynome(double a, double b){
		this(a, b, 0.0);
	}
	
	public Polynome(double a){
		this(a, 0.0, 0.0);
	}
	
	// Methodes
	public double evaluer(double x){
		double pdeX = a*x*x + b*x + c;
		return pdeX;
	}
	
	public void calculDelta(){
		this.delta = b*b -(4*a*c);
	}
	
	public void racineReele1(){
		if(delta < 0){
			this.x1 = Double.NaN;
		}else if(delta == 0){
			this.x1 = -b / (2*a);
		}else{
			this.x1 = (-b + Math.sqrt(delta))/(2*a);
		}
	}
	
	public void racineReele2(){
		if(delta < 0){
			this.x2 = Double.NaN;
		}else if(delta == 0){
			this.x2 = -b / (2*a);
		}else{
			this.x2 = (-b + Math.sqrt(delta))/(2*a);
		}
	}
	
	public void racine1(){
		// todo
	}
	
	public void racine2(){
		// todo
	}
	
	public void resoudre(){
		this.calculDelta();
		this.racineReele1();
		this.racineReele2();
		if(delta < 0){
			System.out.println("Pas de solution");
		}else if(delta == 0){
			System.out.println("Une solution x1 = x2 = "+x1);
		}else{
			System.out.println("Deux solutions");
			System.out.println(" x1 = "+x1);
			System.out.println(" x2 = "+x2);
		}
	}
}
