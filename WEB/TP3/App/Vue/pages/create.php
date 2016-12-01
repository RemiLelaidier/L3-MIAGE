<form method="post" action="index.php?page=createart">
    <label for="titre">Titre</label>
    <input name="titre" type="text">
    <label for="auteur">Auteur</label>
    <input name="auteur" type="text">
    <label for="texte">Texte</label>
    <textarea name="texte"></textarea>
    <label for="categorie">Categorie</label>
    <select name="categorie">
        <?php
        foreach ($categories as $category){
            echo "<option value='". $category->getNom() ."'>". $category->getNom() ."</option>";
        }
        ?>
    </select>
    <input type="submit" value="Ajouter">
    <?php echo $message ?>
</form>