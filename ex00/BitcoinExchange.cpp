/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:14:30 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 12:31:10 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructeur de la classe qui lit les prix à partir d'un fichier CSV
BitcoinExchange::BitcoinExchange(const std::string& bitcoinPricesFile)
    : m_prices(new std::map<std::string, double>()) {
    std::ifstream bitcoinFile(bitcoinPricesFile.c_str());
    if (bitcoinFile.fail()) {
        throw std::runtime_error("Error: Failed to open " + bitcoinPricesFile);
    }
    std::string line;
    std::getline(bitcoinFile, line); // Ignore l'entete du fichier CSV
    while (std::getline(bitcoinFile, line)) {
        std::istringstream ss(line);
        std::string dateStr;
        double price;
        std::getline(ss, dateStr, ',');
        dateStr = dateStr + " ";
        ss >> price;
        (*m_prices)[dateStr] = price;
    }
}

// Constructeur de copie qui copie la map
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : m_prices(new std::map<std::string, double>()) {
    copy(other);
}

// Destructeur qui libère la mémoire
BitcoinExchange::~BitcoinExchange() {
    clear();
    delete m_prices;
}

// Opérateur d'affectation qui copie la map
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

// Méthode qui renvoie le prix à une date donnée
double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = m_prices->find(date);
    if (it == m_prices->end()) {
        throw std::runtime_error("Error: No Bitcoin price available for date " + date);
    }
    return it->second;
}

// Méthode qui copie la map
void BitcoinExchange::copy(const BitcoinExchange& other) {
    *m_prices = *other.m_prices;
}

// Méthode qui vide la map
void BitcoinExchange::clear() {
    m_prices->clear();
}
