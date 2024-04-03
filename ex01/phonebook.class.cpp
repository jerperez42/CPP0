/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:24:29 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/03 16:00:44 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include <sstream>
#include "phonebook.class.hpp"
#include "contact.class.hpp"

PhoneBook::PhoneBook(void)
{
	_used = 0;
}

void	PhoneBook::add(void)
{
	const char	*field_prompt[INF_NFLD] = {
		PRPT_F_F, PRPT_F_L, PRPT_F_N, PRPT_F_P, PRPT_F_D};
	t_field		index;
	char 		buff[CIN_BUFF] = {0};
	int			curr;


	curr = (PBK_SIZE == _used) ? PBK_SIZE - 1 : _used;
	std::cout << PRPT_MSG << std::endl;
	for (int i = 0; i < INF_NFLD; i++)
	{
		index = _phonebook[0].index_to_field("[", curr, "]");
		std::cout << field_prompt[i] << index << ADD_ISEP;
		std::cin.clear();
		std::cin.getline(buff, CIN_BUFF);
		_info[i] = buff;
		if (0 == _info[i].length())
		{
			std::cout << ADD_E_00 << std::endl;
			return ;
		}
	}
	_phonebook[curr].update_information(_info);
	std::cout << ADD_M_OK << std::endl;
	if (_used < PBK_SIZE)
		_used++;
}

void	PhoneBook::search(void)
{
	char				buff[CIN_BUFF] = {0};
	t_index				selection;
	std::stringstream	stream;

	stream.str();

	_phonebook[0].display_row_header();
	for (t_index i = 0; i < _used; i++)
		_phonebook[i].display_row(i);
	std::cout << std::endl;
	std::cout << PRPT_MSR << std::endl;
	std::cin.clear();
	std::cin.getline(buff, CIN_BUFF);
	std::istringstream(buff) >> selection;
	stream << selection;
	if (stream.str() != std::string(buff))
		std::cout << SRH_E_00 << std::endl;
	else if (selection < _used)
		_phonebook[selection].display_information();
	else if (selection < PBK_SIZE)
		std::cout << SRH_E_01 << std::endl;
	else
		std::cout << SRH_E_02 << std::endl;
}

void	PhoneBook::exit(void)
{
	return ;
}
