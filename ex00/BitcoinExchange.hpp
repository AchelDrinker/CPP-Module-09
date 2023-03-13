/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:14:16 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 16:50:13 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        void parse_csv_file(std::string filename);
        std::pair<std::string, double> parse_input_line(std::string line);
        void parse_input_file(std::string filename);

    private:
        std::unordered_map<std::string, double> bitcoin_prices;
};

#endif
