<?php

namespace App;

/**
 * Class Autoloader
 * Permet de charger automatique les classes/interfaces de l'application
 * @package App
 */
class Autoloader{
    /**
     * @var string $classDir : Dossier des classes
     */
    private static $classDir = 'App/';

    /**
     * Enregistre l'autoloader
     */
    static function register(){
        spl_autoload_extensions('.inc');
        spl_autoload_register(array(__CLASS__, 'autoload'));
    }

    /**
     * Autoload
     */
    static function autoload($class){
        $class = str_replace(__NAMESPACE__ . '\\', '', $class);
        $class = str_replace('\\', '/', $class);
        if(file_exists(self::$classDir.$class.'.inc')){
            require self::$classDir.$class . '.inc';
        }
    }
}