/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:24:29 by jerperez          #+#    #+#             */
/*   Updated: 2024/02/07 11:35:36 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
#include <iostream>
#include <sstream>

#include "contact.class.hpp"

Contact::Contact(void)
{
	t_field	field;

	_first = field;
	_last = field;
	_nick = field;
	_phone = field;
	_secret = field;
}

// Contact&	Contact::operator=(const Contact& other)
// {
// 	if (this != &other)
// 		std::copy(other._first, other._last, other._nick, other._phone, other._secret);
// 	return (*this);
// }

// void	Contact::update_field(char *field, std::string str)
// {
// 	typedef std::basic_string<char>::size_type	t_size;

// 	(void)field;
// 	(void)str;
// 	;
// }

void	Contact::update_information(t_field *value)
{
	t_field	*ptr_value[INF_NFLD] = {&_first, &_last, &_nick, &_phone, &_secret};
	int		k;

	k = 0;
	while (k < INF_NFLD)
	{
		*ptr_value[k] = value[k];
		k++;
	}
}

void	Contact::display_information(void)
{
	t_field	value[INF_NFLD] = {_first, _last, _nick, _phone, _secret};

	for (int i = 0; i < INF_NFLD; i++)
		std::cout << value[i] << std::endl;
}

void	Contact::display_row_header(void)
{
	const char	*field_prompt[INF_NFLD] = {
		PRPT_F_F, PRPT_F_L, PRPT_F_N, PRPT_F_P, PRPT_F_D};
	t_field		field;

	field = PRPT_F_I;
	Contact::display_col(field, true, FLD_CSEP);
	for (int i = 0; i < ROW_NFLD; i++)
	{
		field = field_prompt[i];
		Contact::display_col(field, ROW_NFLD != i + 1, FLD_CSEP);
	}
	std::cout << std::endl;
	for (int i = 0; i < ROW_NFLD + 1; i++)
	{
		field = std::string(FLD_NCHR, FLD_UNDR);
		Contact::display_col(field, 1, FLD_PADD);
	}
	std::cout << std::endl;
}

t_field	Contact::index_to_field(t_field before, t_index row_num, t_field after)
{
	std::stringstream	stream;

	stream << before;
	stream << row_num;
	stream << after;
	return (stream.str());
}

void	Contact::display_row(t_index row_num)
{
	t_field	value[ROW_NFLD] = {_first, _last, _nick};
	t_field	index = Contact::index_to_field("", row_num, "");

	Contact::display_col(index, true, FLD_CSEP);
	for (int i = 0; i < ROW_NFLD; i++)
		Contact::display_col(value[i], ROW_NFLD != i + 1, FLD_CSEP);
	std::cout << std::endl;
}

void	Contact::display_col(t_field value, bool add_sep, char delimiter)
{
	typedef std::basic_string<char>::size_type	t_size;

	const t_size	len = value.length();

	if (FLD_NCHR < len)
		std::cout << value.substr(0, FLD_NCHR - 1) + FLD_TRNC;
	else if (FLD_NCHR == len)
		std::cout << value.substr(0, FLD_NCHR);
	else
		std::cout << value.append(FLD_NCHR - len, FLD_PADD);
	if (add_sep)
		std::cout << delimiter;
}