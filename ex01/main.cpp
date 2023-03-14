/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:52 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 10:49:48 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    // Vérifie le nombre d'argument
    if (argc == 2)
    {
        // Lance une instance et lance la méthode add_data
        RPN rpn;
        rpn.add_data(argv[1]);
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}