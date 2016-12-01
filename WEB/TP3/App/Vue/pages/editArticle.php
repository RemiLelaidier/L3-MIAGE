<form method="post" action="index.php?page=<?php
        if(!is_numeric($article['creation']))
            echo strtotime($article['creation']);
        else
            echo $article['creation'];
    ?>">
    <label for="titre">Titre</label>
    <input name="titre" type="text" value="<?php echo $article['titre'] ?>">
    <label for="auteur">Auteur</label>
    <input name="auteur" type="text" value="<?php echo $article['auteur'] ?>">
    <label for="texte">Texte</label>
    <textarea name="texte"><?php echo $article['texte'] ?></textarea>
    <label for="categorie">Categorie</label>
    <select name="categorie">
        <?php
        foreach ($categories as $category){
            if($category->getNom() == $article['categorie'])
                echo "<option value='". $category->getNom() ."' selected >". $category->getNom() ."</option>";
            else
                echo "<option value='". $category->getNom() ."'>". $category->getNom() ."</option>";
        }
        ?>
    </select>
    <input type="submit" value="Ajouter">
    <?php echo $message ?>
</form>