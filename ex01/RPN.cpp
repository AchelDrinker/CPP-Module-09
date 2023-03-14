/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: humartin <humartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:58:13 by humartin          #+#    #+#             */
/*   Updated: 2023/03/14 10:53:11 by humartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructeur par défaut de la classe RPN.
RPN::RPN()
{
}

// Destructeur de la classe RPN
RPN::~RPN()
{
}

// Constructeur de copie 
RPN::RPN(RPN const & src)
{
    *this = src;
}


// Opérateur d'assignation qui effectue une copie de l'objet source sur l'objet courant
RPN & RPN::operator=(RPN const & rhs)
{
    if (this != &rhs) {
        this->stack = rhs.stack;
    }
    return *this;
}


// La méthode add_data prend en entrée une chaîne de caractères représentant l'expression en notation polonaise inverse et calcule le résultat de l'expression.
// Pour ce faire, elle parcourt la chaîne de caractères et effectue les opérations selon les règles de la notation polonaise inverse.
// Si la chaîne contient une erreur, elle affiche "Error". Sinon, elle affiche le résultat final.
void RPN::add_data(std::string data)
{
    for (size_t i = 0;i < data.size(); i++)
    {
        if (data[i] == ' ')
            continue;
        else if (isdigit(data[i]))
            stack.push(data[i] - '0');
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