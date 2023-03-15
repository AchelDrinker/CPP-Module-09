/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:40:47 by humartin          #+#    #+#             */
/*   Updated: 2023/03/15 14:42:13 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Tri avec vector
// Lors du tri d'un std::vector, les éléments sont échangés au sein du vecteur.
// La durée de la permutation des éléments dépend, entre autres, de la taille de l'élément.
// Ainsi, une taille d'élément plus importante entraîne une durée d'exécution plus élevée.

// Tri avec list
// Lors du tri d'une std::list, les éléments restent à leur place en mémoire,
// seuls les pointeurs précédent/suivant de la liste chaînée sont mis à jour.
// La durée de cette opération de mise à jour des pointeurs ne dépend pas de la taille des éléments du conteneur.

int main(int argc, char** argv)
{
    // Vérifie si l'utilisateur a entré des arguments
    if (argc < 2) {
        std::cerr << "Usage: PmergeMe <integer sequence>\n";
        return 1;
    }

    // Récupère la séquence d'entiers à partir des arguments de la ligne de commande
    std::vector<int> sequence;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int n;
        // Vérifie si chaque argument est un entier valide
        if (!(iss >> n) || n <= 0) {
            std::cerr << "Error: Invalid input sequence\n";
            return 1;
        }
        // Ajoute l'entier à la séquence
        sequence.push_back(n);
    }

    // Crée une instance de la classe PmergeMe avec la séquence d'entiers
    PmergeMe pmerge(sequence);

    // Trie la séquence en utilisant merge sort avec l'insertion sort pour les sous-séquences
    pmerge.sort();

    // Affiche la séquence d'origine avant le tri
    std::cout << "Before:";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << " " << sequence[i];
    }
    std::cout << std::endl;

    // Affiche la séquence triée
    std::cout << "After:";
    std::vector<int> sortedSeq = pmerge.getSortedSequence();
    for (size_t i = 0; i < sortedSeq.size(); ++i) {
        std::cout << " " << sortedSeq[i];
    }
    std::cout << std::endl;

    // Affiche le temps pris pour trier la séquence avec std::vector
    std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector: "
              << pmerge.getTimeUsedVector() << " millis" << std::endl;

    // Affiche le temps pris pour trier la séquence avec std::list
    std::cout << "Time to process a range of " << sequence.size() << " elements with std::list: "
              << pmerge.getTimeUsedList() << " millis" << std::endl;

    return 0;
}
