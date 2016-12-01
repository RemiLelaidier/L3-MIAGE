package Polynome;


public class PolynomeTest {

	public static void main(String[] args) {
		Polynome P1 = new Polynome(5.0, 7.0, 8.0);
		// Evaluer
		System.out.println("P de x = "+P1.evaluer(10));
		P1.resoudre();
		
		Polynome P2 = new Polynome(1.0, -1.0, 0.0);
		// Evaluer
		System.out.println("P de x = "+P2.evaluer(10));
		P2.resoudre();
		
		Polynome P3 = new Polynome(1.0, 2.0, 1.0);
		// Evaluer
		System.out.println("P de x = "+P3.evaluer(10));
		P3.resoudre();
	}

}
