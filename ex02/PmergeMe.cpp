/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:00:22 by humartin          #+#    #+#             */
/*   Updated: 2023/03/15 14:07:09 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(const std::vector<int>& sequence)
    : m_sequence(sequence), m_sortedVector(sequence)
{
    std::list<int> sequenceList(sequence.begin(), sequence.end());
    m_sortedList = sequenceList;
    mergeInsertionSort(m_sortedVector);
    mergeInsertionSort(m_sortedList);
}


void PmergeMe::sort()
{
    // Time the vector sort algorithm
    clock_t start = clock();
    mergeInsertionSort(m_sortedVector);
    clock_t end = clock();
    m_timeUsedVector = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC;

    // Time the list merge-insert sort algorithm
    start = clock();
    mergeInsertionSort(m_sortedList);
    end = clock();
    m_timeUsedList = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& sequence)
{
    if (sequence.size() <= 1) {
        return;
    }

    int middle = sequence.size() / 2;
    std::vector<int> left(sequence.begin(), sequence.begin() + middle);
    std::vector<int> right(sequence.begin() + middle, sequence.end());

    mergeInsertionSort(left);
    mergeInsertionSort(right);

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < static_cast<int>(left.size()) && j < static_cast<int>(right.size())) {
        if (left[i] < right[j]) {
            sequence[k++] = left[i++];
        } else {
            sequence[k++] = right[j++];
        }
    }

    while (i < static_cast<int>(left.size())) {
        sequence[k++] = left[i++];
    }

    while (j < static_cast<int>(right.size())) {
        sequence[k++] = right[j++];
    }
}

void PmergeMe::mergeInsertionSort(std::list<int>& sequence)
{
    if (sequence.size() <= 1) {
        return;
    }

    std::list<int> left, right;
    int middle = sequence.size() / 2;
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        if (std::distance(sequence.begin(), it) < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
    }

    mergeInsertionSort(left);
    mergeInsertionSort(right);

    sequence.clear();

    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) {
        if (*it_left < *it_right) {
            sequence.push_back(*it_left);
            ++it_left;
        } else {
            sequence.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) {
        sequence.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        sequence.push_back(*it_right);
        ++it_right;
    }
}

std::vector<int> PmergeMe::getSortedSequence() const
{
    return m_sortedVector;
}

double PmergeMe::getTimeUsedVector() const
{
    return (m_timeUsedVector * 1000);
}

double PmergeMe::getTimeUsedList() const
{
    return (m_timeUsedList * 1000);
}
