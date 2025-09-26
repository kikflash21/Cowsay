#!/bin/bash

    clear  # Efface l'écran

    # Vérifie si le nombre d'arguments est correct
    if [ $# -ne 1 ]
    then 
        cowsay -d "Argument attendu"  
        exit 1  # Quitte le script
    fi
    # Verifie si le premier terme est un nombre premier
    if [ $1 -eq 0 -o $1 -eq 1 ]
    then
        cowsay -T "U " "Pas un nombre premier"
        exit 2;
    fi

    n=$1
    lastPrime=0  # Initialise la variable pour stocker le dernier nombre premier trouvé

    # Boucle pour vérifier si chaque nombre jusqu'à n est premier
    for ((i=2; i<=n; i++)) 
    do 
        isPrime=1
        # Boucle pour vérifier si i est premier
        for ((j=2; j*j<=i; j++))
        do
            mod=$(($i%$j))
            if [ $mod -eq 0 ]
            then 
                isPrime=0
                break  # Arrête la boucle dès qu'un diviseur est trouvé
            fi
        done
        # Si le nombre est premier, l'affiche et met à jour lastPrime
        if [ $isPrime -eq 1 ]
        then 
            cowsay $i  
            sleep 1s  
            clear 
            lastPrime=$i 
            clear 
        fi 
    done

    cowsay -T "U " $lastPrime  