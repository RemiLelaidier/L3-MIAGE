<div>
    <h3>XML</h3>
    <form enctype="multipart/form-data" method="post" action="index.php?page=ajoutSource">
        <label for="ficXML">Fichier</label>
        <input name="ficXML" type="file">
        <input type="submit" value="Charger">
        <?php
        if(isset($XMLmessage))
            echo $XMLmessage;
        ?>
    </form>
</div>