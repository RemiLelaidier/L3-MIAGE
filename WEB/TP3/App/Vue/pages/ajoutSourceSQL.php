<div>
    <h3>BDD</h3>
    <form method="post" action="index.php?page=ajoutSource">
        <label for="hote">Hote</label>
        <input type="text" name="hote">
        <label for="bdd">Nom BDD</label>
        <input type="text" name="bdd">
        <label for="login">Login</label>
        <input type="text" name="login">
        <label for="mdp">Mot de passe</label>
        <input type="password" name="mdp">
        <input type="submit" value="Charger">
        <?php
        if(isset($BDDmessage))
            echo $BDDmessage;
        ?>
    </form>
</div>