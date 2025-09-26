#!/bin/bash
    clear
    # Vérifie si le nombre d'arguments est correct
    if [ $# -ne 1 ]
    then 
        cowsay -d "Argument attendu"
        exit # Quitte le script
    fi

    if [ $1 -eq 0 ]
    then 
        cowsay -T "U " O
    elif [ $1 -eq 1 ]
    then
        cowsay 1
        sleep 1s  # Pause d'une seconde
        cowsay -T \U 1
    else 
        cowsay O
        sleep 1s
        clear
        cowsay 1
        sleep 1s
        clear
        lim=$1
        a=0
        b=1
        Z=0
        # Boucle pour générer les nombres de Fibonacci jusqu'à ce que la somme des deux nombres dépasse le nombre passé en argument 
        while [ $((a+b+Z)) -le $lim ]
        do 
            Z=$((a+b))
            cowsay $Z
            sleep 1s
            a=$b
            b=$Z
            clear
        done
        Z=$((a+b))
        # Affiche la langue avec le dernier nombre de Fibonacci
        cowsay -T "U " $Z 
    fi