/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:32 by humartin          #+#    #+#             */
/*   Updated: 2023/03/15 10:10:27 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN
{
    private :
    // Membre privé qui est une pile qui sera utilisée pour stocker les données et les opérandes.
        std::stack<int> stack;

    public :
        RPN();
        ~RPN();
        RPN(RPN const & src);
        RPN &   operator=(RPN const & rhs);
        void    add_data(std::string data);
        int    precedence(char op);
};
#endif