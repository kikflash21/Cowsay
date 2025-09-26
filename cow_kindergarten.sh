#!/bin/bash

# Boucle for pour afficher les nombres de 1 à 9 avec cowsay
for i in {1..9} 
    do  
        clear
        cowsay $i 
        sleep 1s
    done 
# Utilisation de cowsay avec l'option -T pour tirer la langue a la fin
clear
cowsay -T "U " 10