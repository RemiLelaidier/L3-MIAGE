package Aleatoire;

import java.util.Random;

public class GenRandomClass {

	// Generer aletoire positif entre min et max
	public int genRandomPos(int min, int max){
		Random random=new Random();
		return random.nextInt(max+1);
	}
	
	// Generer aletoire negatif ou positif entre min et max
}
