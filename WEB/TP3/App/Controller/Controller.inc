<?php

namespace App\Controller;

/**
 * Created by PhpStorm.
 * User: leetspeakv2
 * Date: 21/11/16
 * Time: 12:30
 */

use App\Donnees\XML;
use App\Donnees\MYSQL;


class Controller
{
    /**
     * @var string type de persistance XML ou MYSQL
     */
    protected static $typepersistance;

    /**
     * @var object le fournisseur de donnees
     */
    protected static $persistanceProvider;

    /**
     * @var string Chemin vers les vues
     */
    protected static $viewPath = "/App/Vue/";

    /**
     * @var
     */
    protected static $template = "layout";

    /**
     * Permet de choisir la source des donnees
     * mode XML par defaut
     */
    public static function checkPersistance(){
        // Par defaut en mode XML
        self::$typepersistance = "XML";
        if (isset($_SESSION["persistance"])) {
            if($_SESSION["persistance"] == "XML" || "MYSQL")
                self::$typepersistance = $_SESSION["persistance"];
        }
        $_SESSION["persistance"] = self::$typepersistance;
        self::$typepersistance = "\\App\\Donnees\\". self::$typepersistance;
        self::$persistanceProvider = new self::$typepersistance;
    }

    /**
     * @param $view La vue a afficher
     * @param array $variables les variables pour la vue
     */
    public function render($view, $variables = []){
        ob_start();
        extract($variables);
        $content = ob_get_clean();
        require (getcwd() . self::$viewPath ."pages/". $view. ".php");
    }
}