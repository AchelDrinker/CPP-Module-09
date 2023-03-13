/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:32 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 12:24:12 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private :
        std::stack<int> stack;

    public :
        RPN();
        ~RPN();
        RPN(RPN const & src);
        RPN &   operator=(RPN const & rhs);
        void    add_data(std::string data);
};
#endif