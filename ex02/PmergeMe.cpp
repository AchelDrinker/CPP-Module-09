/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:00:22 by humartin          #+#    #+#             */
/*   Updated: 2023/03/15 14:35:49 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>


// Constructor that takes a sequence as argument
// Initializes the member variables m_sequence, m_sortedVector and m_sortedList
PmergeMe::PmergeMe(const std::vector<int>& sequence)
    : m_sequence(sequence), m_sortedVector(sequence)
{
    // Convert the sequence vector into a list and assign it to m_sortedList
    std::list<int> sequenceList(sequence.begin(), sequence.end());
    m_sortedList = sequenceList;
    // Sort the two data structures using the merge-insertion sort algorithm
    mergeInsertionSort(m_sortedVector);
    mergeInsertionSort(m_sortedList);
}

// Sorts the data structures m_sortedVector and m_sortedList and stores the time used in member variables
void PmergeMe::sort()
{
    // Time the vector merge-insert sort algorithm
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


// Recursive function that sorts a vector using the merge-insertion sort algorithm
void PmergeMe::mergeInsertionSort(std::vector<int>& sequence)
{
    // Base case: if the sequence has 1 or 0 elements, it is already sorted
    if (sequence.size() <= 1) {
        return;
    }

    // Divide the sequence into two halves
    int middle = sequence.size() / 2;
    std::vector<int> left(sequence.begin(), sequence.begin() + middle);
    std::vector<int> right(sequence.begin() + middle, sequence.end());

    // Sort the left and right halves recursively
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Merge the two sorted halves into one sorted sequence
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

// Recursive function that sorts a list using the merge-insertion sort algorithm
void PmergeMe::mergeInsertionSort(std::list<int>& sequence)
{
    // Base case: if the sequence has 1 or 0 elements, it is already sorted
    if (sequence.size() <= 1) {
        return;
    }

    // Divide the sequence into two halves
    std::list<int> left, right;
    int middle = sequence.size() / 2;
    for (std::list<int>::iterator it = sequence.begin(); it != sequence.end(); ++it) {
        // Add each element to the left or right half depending on its position
        if (std::distance(sequence.begin(), it) < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
    }

    // Sort the left and right halves recursively
    mergeInsertionSort(left);
    mergeInsertionSort(right);

    // Clear the input sequence to merge the two halves
    sequence.clear();

    // Merge the two sorted halves
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

    // Append any remaining elements from the left or right halves
    while (it_left != left.end()) {
        sequence.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) {
        sequence.push_back(*it_right);
        ++it_right;
    }
}

// Return the sorted sequence stored in m_sortedVector
std::vector<int> PmergeMe::getSortedSequence() const
{
    return m_sortedVector;
}

// Return the time used for sorting using a vector in milliseconds
double PmergeMe::getTimeUsedVector() const
{
    return (m_timeUsedVector * 1000);
}

// Return the time used for sorting using a list in milliseconds
double PmergeMe::getTimeUsedList() const
{
    return (m_timeUsedList * 1000);
}
