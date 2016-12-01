package rectangleManager;

/* Classe rectangleManager.Rectangle
 * Representation d'un rectangleManager.Rectangle
 */
public class Rectangle {

    // Longueur et largueur de notre rectangleManager.Rectangle
    private int longueur;
    private int largeur;

    // Constructeur
    public Rectangle(int longueur, int largeur){
        this.longueur = longueur;
        this.largeur = largeur;
    }

    // Accesseurs
    public int getLongueur(){
        return longueur;
    }

    public int getLargeur(){
        return largeur;
    }

    public void setLongueur(int longueur){
        this.longueur = longueur;
    }

    public void setLargeur(int largeur){
        this.largeur = largeur;
    }

    // Calcul de la surface
    public int surface(){
        return longueur * largeur;
    }
}
