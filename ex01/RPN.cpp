/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:13 by humartin          #+#    #+#             */
/*   Updated: 2023/03/13 12:24:40 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(RPN const & src)
{
    *this = src;
}

RPN & RPN::operator=(RPN const & rhs)
{
    if (this != &rhs) {
        this->stack = rhs.stack;
    }
    return *this;
}

void RPN::add_data(std::string data)
{
    for (size_t i = 0;i < data.size(); i++)
    {
        if (data[i] == ' ')
            continue;
        else if (isdigit(data[i]))
            stack.push(data[i] - '0');
        else if(!isdigit(data[i]))
        {
            std::cout << "Error" << std::endl;
            return;
        }
        else
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            if (data[i] == '+')
                stack.push(a + b);
            else if (data[i] == '-')
                stack.push(a - b);
            else if (data[i] == '*')
                stack.push(a * b);
            else if (data[i] == '/')
                stack.push(a / b);
        }
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
        std::cout << "Error" << std::endl;
}