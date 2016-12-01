
public class Complexe {
	double re;
	double im;
	
	public Complexe(){
		
	}
	
	double norme(){
		return re*re + im*im;
	}
	
	double argument(){
		return Math.atan2(im, re);
	}
	
}
