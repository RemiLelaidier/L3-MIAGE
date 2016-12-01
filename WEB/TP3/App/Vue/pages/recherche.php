<form method="post" action="index.php?page=recherche">
    <label for="recherche"></label>
    <input type="text" name="recherche" value="<?php
        if(isset($recherche))
            echo $recherche;
    ?>">
    <input type="submit" value="Rechercher">
</form>
<?php
    if(isset($results)){
        if(!empty($results)){
            echo "<h1>Resultats de la recherche</h1>";
            foreach ($results as $article){
                echo $article->getHtml();
            }
        }
        else{
            echo "<h1>Aucun resultat pour la recherche ". $recherche ."</h1>";
        }
    }
?>