package Tortue;

public class TestTortue {

	public static void main(String[] args) {
		Tortue t1 = new Tortue();
		System.out.println("Position : X : "+t1.getX()+" Y : "+t1.getY());
		
		t1.avance(50);
		System.out.println("Position : X : "+t1.getX()+" Y : "+t1.getY());
		
		t1.droite(90);
		t1.avance(50);
		System.out.println("Position : X : "+t1.getX()+" Y : "+t1.getY());
		
		t1.droite(90);
		t1.avance(50);
		System.out.println("Position : X : "+t1.getX()+" Y : "+t1.getY());
		
		t1.droite(90);
		t1.avance(50);
		System.out.println("Position : X : "+t1.getX()+" Y : "+t1.getY());
	}

}
