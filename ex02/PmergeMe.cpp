/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:51:55 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 10:26:35 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructeur par défaut
PmergeMe::PmergeMe(void)
{
	return ;
}

// Constructeur de copie
PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return ;
}

// Destructeur
PmergeMe::~PmergeMe(void)
{
	return ;
}

// Opérateur d'assignation par copie
PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	// On copie ici les valeurs de l'objet rhs dans l'objet appelant
	this->_list = rhs._list;
	this->_vector = rhs._vector;

	return (*this);
}

// Fonction pour stocker les arguments dans le tableau
void	PmergeMe::takeArg(char **av)
{
	int i = 0;
	while (av[++i] != NULL)
	{
		_vector.push_back( std::atoi(av[i]) ); // On stocke la valeur dans un vecteur
		_list.push_back( std::atoi(av[i]) ); // On stocke la valeur dans une liste
	}
}

// Fonction pour trier les valeurs stockées dans le tableau
void	PmergeMe::sortValues(void)
{
	clock_t	start;
	clock_t	end;

	start = clock();
	_list.sort(); // On trie la liste
	end = clock();

	_timeList = (end - start) / (double)CLOCKS_PER_SEC; // On mesure le temps pris pour trier la liste

	start = clock();
	std::sort( _vector.begin(), _vector.end() ); // On trie le vecteur
	end = clock();

	_timeVector = (end - start) / (double)CLOCKS_PER_SEC; // On mesure le temps pris pour trier le vecteur
}

// Fonction pour afficher les résultats triés
void	PmergeMe::displayResults(void)
{
	std::cout << "After  : ";
	int i = 0;
	for (std::vector<unsigned int>::iterator it=_vector.begin();
			it!=_vector.end(); ++it)
	{
    	std::cout << *it << " "; // On affiche les valeurs triées du vecteur
		if (++i > MAXDISPLAY) // Si on atteint le nombre maximal d'affichages, on arrête
		{
			std::cout << "[...]";
			break ;
		}
	}
  	std::cout << '\n';

	std::cout << "Time to process a range of " << _list.size()
		<< " elements with std::list : " << std::fixed
		<< _timeList * 1000000 << " us" << std::endl; // On affiche le temps pris pour trier la liste en microsecondes
	
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << std::fixed
		<< _timeVector * 1000000 << " us" << std::endl; // On affiche le temps pris pour trier le vecteur en microsecondes
}
