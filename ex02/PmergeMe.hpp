/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:19:15 by humartin          #+#    #+#             */
/*   Updated: 2023/03/15 12:57:11 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>

class PmergeMe {
public:
    PmergeMe(const std::vector<int>& sequence);
    void sort();
    std::vector<int> getSortedSequence() const;
    double getTimeUsedVector() const;
    double getTimeUsedList() const;
    void mergeInsertionSort(std::list<int>& sequence);
    void mergeInsertionSort(std::vector<int>& sequence);
private:
    std::vector<int> m_sequence;
    std::vector<int> m_sortedVector;
    std::list<int> m_sortedList;
    double m_timeUsedVector;
    double m_timeUsedList;
};

#endif


