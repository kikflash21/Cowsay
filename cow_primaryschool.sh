#!/bin/bash

clear # Rafraichit l'écran
# Vérifie si le nombre d'arguments est correct
if [ $# -ne 1 ]
    then 
        cowsay -d "Argument attendu"
        exit # Quitte le script
    fi

n=1
# Boucle while pour afficher les nombres de 1 à n ($1)
while [ $n -ne $1 ]
    do 
        cowsay $n
        sleep 1s
        ((n++))
        clear
    done 
cowsay -T "U " $1