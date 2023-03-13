/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:42:01 by humartin          #+#    #+#             */
/*   Updated: 2023/03/10 16:50:36 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    try
    {
        BitcoinExchange exchange;
        exchange.parse_csv_file(argv[1]);
        exchange.parse_input_file(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    return (0);
}
