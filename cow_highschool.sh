#!/bin/bash
clear
# Vérifie si le nombre d'arguments est correct
if [ $# -ne 1 ]
    then 
        cowsay -d "Argument attendu"
        exit # Quitte le script
    fi

lim=$(( $1 ** 2)) 
n=1
p=1
# Boucle pour afficher les carrés des nombres jusqu'au carré de l'argument
while [ $n -lt $lim ]
    do 
        cowsay $n
        sleep 1s
        ((p++))
        ((n = p**2 ))
        clear
    done 
cowsay -T "U " $lim