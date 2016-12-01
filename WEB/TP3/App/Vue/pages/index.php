<?php
mb_internal_encoding("UTF-8");
foreach ($categories as $category){
    echo "<div class='categorie'>";
    echo "<h1>" . mb_strtoupper($category->getNom()) . "</h1>";
    echo $category->getHtml();
    echo "</div>";
}