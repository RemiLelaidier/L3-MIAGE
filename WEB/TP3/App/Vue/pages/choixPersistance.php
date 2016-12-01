<h3>Type de persistance actuel : <?php echo $_SESSION['persistance']; ?></h3>
<form method="post" action="index.php?page=choixPersistance">
    <label for="persistance">Type de persistance</label>
    <select name="persistance">
        <?php
        foreach ($typePossible as $type){
            if($type == $_SESSION['persistance'])
                echo "<option value='" . $type . "' selected >" . $type . "</option>";
            else
                echo "<option value='" . $type . "'>" . $type . "</option>";
        }
        ?>
    </select>
    <input type="submit" value="Changer">
</form>