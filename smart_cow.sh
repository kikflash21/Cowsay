#!/bin/bash

    # Vérifie si le nombre d'arguments est correct
    if [ $# -ne 1 ]
    then 
        cowsay -d "Un seul argument attendu"
        exit # Quitte le script
    fi

    result=Erreur
    # Extraction de l'opérateur de l'argument
    ope=$(echo $* | tr -d [:digit:])

    # Extraction des deux nombres de l'argument en utilisant l'opérateur comme délimiteur
    a=$(echo $* | cut -d "$ope" -f 1)
    b=$(echo $* | cut -d "$ope" -f 2)

    # Effectue l'opération en fonction de l'opérateur
    if [ "$ope" == "+" ]
    then
        result=$(($a + $b))
    elif [ "$ope" == "-" ]
    then 
        result=$(($a - $b))
    elif [ "$ope" == "/" -a $b != 0 ]
    then
        result=$(($a / $b)) 
    elif [ "$ope" == "*" ]
    then 
        result=$(($a * $b))
    fi

    # Affichage du résultat 
    if [ $result -ge 10 ]
    then 
        cowsay -e $result "$*"
    else 
        cowsay -e "$result " "$*"
    fi