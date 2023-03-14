/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:51:58 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 10:32:29 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <stdexcept>
# include <ctime>
# include <list>
# include <vector>
#include <algorithm>

# define MAXDISPLAY 10

class PmergeMe
{

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe	&operator=(PmergeMe const &rhs);

		void	takeArg(char **argv); // Prend en entrée des arguments sous forme de tableau de char
		void	sortValues(void); // Trie les valeurs dans la liste et le vecteur
		void	displayResults(void); // Affiche les résultats triés et les temps d'exécution

	private:
		std::vector<unsigned int>	_vector;
		std::list<unsigned int>		_list;
		double		_timeVector;
		double		_timeList;

};

#endif