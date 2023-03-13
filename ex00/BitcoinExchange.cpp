/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:06:16 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 16:50:58 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::parse_csv_file(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Error : could not open file.");
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string date_str;
        double price;
        if (std::getline(iss, date_str, ',') && iss >> price)
        {
            bitcoin_prices[date_str] = price;
        }
    }
}

std::pair<std::string, double> BitcoinExchange::parse_input_line(std::string line)
{
    std::istringstream iss(line);
    std::string date_str, value_str;
    double value;
    if (!(std::getline(iss, date_str, '|') && std::getline(iss, value_str)))
    {
        throw std::invalid_argument("Error : bad input => " + line);
    }
    if (date_str.size() != 10 || value_str.empty())
    {
        throw std::invalid_argument("Error : bad input => " + line);
    }
    try
    {
        value = std::stod(value_str);
        if (value < 0 || value > 1000)
        {
            throw std::invalid_argument("Error : not a positive number.");
        }
    }
    catch (std::invalid_argument &e)
    {
        throw std::invalid_argument("Error : not a positive number.");
    }
    return std::make_pair(date_str, value);
}

void BitcoinExchange::parse_input_file(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Error : could not open file.");
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::pair<std::string, double> input = parse_input_line(line);
        std::cout << input.first << " | " << input.second << " | " << bitcoin_prices[input.first] << std::endl;
    }
}