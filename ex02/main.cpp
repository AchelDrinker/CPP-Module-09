/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:51:51 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 10:55:58 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>    // bibliothèque pour les tableaux dynamiques
#include <list>      // bibliothèque pour les listes chaînées

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)  // si le nombre d'arguments est inférieur à 2, affiche un message d'erreur
    {
        std::cout << "usage : ./PmergeMe [ints to sort]\n";
        return (1);
    }
    
    int i = 0;
    while (argv[++i] != NULL)
    {
        int j = std::atoi(argv[i]);  // convertit l'argument en entier
        if (j < 0 && 2147483647 > j)  // si l'entier est négatif, affiche un message d'erreur
        {
            std::cout << "We can only sort positive integer\n";
            return (1);
        }
    }

    PmergeMe sorter;  // crée une instance de la classe PmergeMe
    
    sorter.takeArg(argv);  // appelle une méthode de cette instance pour stocker les arguments
    
    i = 0;

	// affiche les arguments en int
    std::cout << "Before : ";
    while (argv[++i] != NULL)
    {
        std::cout << std::atoi(argv[i]) << " ";
        if (i > MAXDISPLAY)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout <<std::endl;

    sorter.sortValues();  // appelle une méthode de l'instance pour trier les entiers
    
    sorter.displayResults();  // appelle une méthode de l'instance pour afficher les résultats du tri

    return (0);
}
