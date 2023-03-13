/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:42:01 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 13:18:20 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	checkDate( std::string date )
{
	if (date.length() != 11)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			return (false);
	}
	//we split day, month
	std::string day = date.substr(8, 2);
	std::string month = date.substr(5, 2);
	//we check they are valid
	if (std::stoi(day) > 31 || std::stoi(day) < 1)
		return (false);
	if (std::stoi(month) > 12 || std::stoi(month) < 1)
		return (false);
	return (true);
}

int main(int argc, char **argv) 
{
    if (argc != 2)
	{
        std::cerr << "Usage: btc <input_file>" << std::endl;
        return (1);
    }

    // Load Bitcoin prices from CSV file into a BitcoinExchange object
    BitcoinExchange exchange("BTC-USD.csv");

    // Process input file and calculate exchange rates
    std::ifstream input(argv[1]);
    if (input.fail())
	{
        std::cerr << "Error: Failed to open input file" << std::endl;
        return (1);
    }
    std::string inputLine;
    while (std::getline(input, inputLine))
	{
        std::istringstream ss(inputLine);
		if (inputLine.empty() || inputLine[0] == '#' || inputLine == "date | value")
			continue;
        std::string dateStr;
        double value;
        std::getline(ss, dateStr, '|');
        ss >> value;
		if (ss.fail())
		{
			std::cerr << "Error: bad input => " << inputLine << std::endl;
			continue;
		}
		else if (dateStr.empty())
		{
			std::cerr << "Error: bad input => " << inputLine << std::endl;
			continue;
		}
		else if (checkDate(dateStr) == false)
		{
			std::cerr << "Error: bad date format." << std::endl;
			continue;
		}
        else if ( value < 0 )
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		try
		{
			double exchangeRate = exchange.getExchangeRate(dateStr);
			double result = value * exchangeRate;
			std::cout << dateStr << " => " << value << " = " << result << std::endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			continue;
		}
	}
    return 0;
}