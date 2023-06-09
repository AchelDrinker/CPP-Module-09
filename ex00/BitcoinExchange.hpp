/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:28:00 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 13:14:48 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <stdexcept>
# include <fstream>
# include <sstream>
# include <iostream>

class BitcoinExchange {
	
	public:
		BitcoinExchange(const std::string& bitcoinPricesFile);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& other);
		double getExchangeRate(const std::string& date) const;
	
	private:
		std::map<std::string, double>* m_prices;
		void copy(const BitcoinExchange& other);
		void clear();

};

#endif