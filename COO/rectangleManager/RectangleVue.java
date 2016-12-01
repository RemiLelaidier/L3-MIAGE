package rectangleManager;/*
    Classe rectangleManager.RectangleVue
 */

import java.util.Scanner;

public class RectangleVue {

    // Tableau de Rectangle
    Rectangle[] rectangles = new Rectangle[2];

    public void run(){
        Scanner saisie = new Scanner(System.in);

        // Premier rectangle
        System.out.println("Donner la largeur du premier rectangle");
        int largueur = saisie.nextInt();
        System.out.println("Donner la longueur du premier rectangle");
        int longueur = saisie.nextInt();
        rectangles[0] = new Rectangle(longueur, largueur);

        // Deuxieme rectangle
        System.out.println("Donner la largeur du deuxieme rectangle");
        largueur = saisie.nextInt();
        System.out.println("Donner la longueur du deuxieme rectangle");
        longueur = saisie.nextInt();
        rectangles[1] = new Rectangle(longueur, largueur);

        // Surfaces
        System.out.println("La surface du premier rectangle est : " + rectangles[0].surface());
        System.out.println("La surface du deuxieme rectangle est : " + rectangles[1].surface());

        // Modifier le premier rectangle
        System.out.println("Modifier la longueur du premier rectangle");
        longueur = saisie.nextInt();
        rectangles[0].setLongueur(longueur);
        System.out.println("La surface du premier rectangle est : " + rectangles[0].surface());
    }

    // Methode main
    public static void main(String[] argv){
        new RectangleVue().run();
    }
}
