/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:14:30 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 13:14:31 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& bitcoinPricesFile)
    : m_prices(new std::map<std::string, double>()) {
    std::ifstream bitcoinFile(bitcoinPricesFile.c_str());
    if (bitcoinFile.fail()) {
        throw std::runtime_error("Error: Failed to open BitcoinPrices.csv");
    }
    std::string line;
    std::getline(bitcoinFile, line);
    while (std::getline(bitcoinFile, line)) {
        std::istringstream ss(line);
        std::string dateStr;
        double price;
        std::getline(ss, dateStr, '|');
        ss >> price;
        (*m_prices)[dateStr] = price;
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : m_prices(new std::map<std::string, double>()) {
    copy(other);
}

BitcoinExchange::~BitcoinExchange() {
    clear();
    delete m_prices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = m_prices->find(date);
    if (it == m_prices->end()) {
        throw std::runtime_error("Error: No Bitcoin price available for date " + date);
    }
    return it->second;
}

void BitcoinExchange::copy(const BitcoinExchange& other) {
    *m_prices = *other.m_prices;
}

void BitcoinExchange::clear() {
    m_prices->clear();
}