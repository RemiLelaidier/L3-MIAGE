<!DOCTYPE html>
<html>
<head>
    <title>TP3</title>
    <link rel="stylesheet" href="css/style.css">
    <meta charset="utf-8">
</head>
<body>
    <nav>
        <ul>
            <li><a href="index.php?page=accueil">Accueil</a></li>
            <li><a href="index.php?page=createart">Ajout d'article</a></li>
            <li><a href="index.php?page=createcat">Ajout de categorie</a></li>
            <li><a href="index.php?page=choixPersistance">Persistance</a></li>
            <li><a href="index.php?page=ajoutSource">Source</a></li>
            <li><a href="index.php?page=recherche">Rechercher</a></li>
        </ul>
    </nav>
    <div class="content">
        <?= $content; ?>
    </div>
</body>
</html>