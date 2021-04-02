<?php

session_start();
if (session_destroy()){
    setcookie('session','',time()-3600);
    unset($_COOKIE['session']);

    header("location: index.php");
}