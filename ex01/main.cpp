/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:52 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 12:19:18 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        RPN rpn;
        rpn.add_data(argv[1]);
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}