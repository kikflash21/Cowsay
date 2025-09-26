#!/bin/bash
    
    clear
    # Vérifie si le nombre d'arguments est correct
    if [ $# -eq 0 ] || [ $1 -eq 0 ]
    then 
        cowsay -d "Argument attendu"
        exit  # Quitte le script
    fi

    n=$1
    # Boucle pour générer la suite de Syracuse jusqu'à ce que n soit égal à 1
    while [ $n -ne 1 ]
    do 
        mod=$((n % 2))
        if [ $mod -eq 0 ]
            then n=$((n / 2))
        else 
            n=$((3 * n + 1))
        fi
        cowsay $n 
        # Vérifie si un délai personnalisé a été spécifié
        if [ $# -eq 2 ]
        then
            sleep $2
        else 
            sleep 1s
        fi
        clear
    done
    # Affiche le dernier nombre de la suite en tirant la langue
    cowsay -T "U " $n