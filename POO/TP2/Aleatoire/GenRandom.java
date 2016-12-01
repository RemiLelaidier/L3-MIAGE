package Aleatoire;

abstract class GenRandom {
	
	// Generer aletoire positif entre min et max
	public int genRandomPos(int min, int max){
		return (int) (Math.random() * ((max - (min)) + 1));
	}

}
