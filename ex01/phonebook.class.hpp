/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:17:17 by jerperez          #+#    #+#             */
/*   Updated: 2024/02/07 13:43:18 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "contact.class.hpp"
# include <iostream>

# define PBK_SIZE 8

# define PRPT_W00 "My Awesome PhoneBook"

# define PRPT_MSR "Enter the index of the entry to display"
# define PRPT_MSG "Enter the information of the new contact"
# define ADD_M_OK "Contact added!"
# define ADD_ISEP ":"
# define ADD_E_00 "A saved contact can’t have empty fields."
# define SRH_E_00 "This contact index is invalid."
# define SRH_E_01 "This contact has not been added yet."
# define SRH_E_02 "This contact index is too large."

class PhoneBook
{
public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
	void	exit(void);
private:
	//void	display_row_header(void);
	Contact	_phonebook[PBK_SIZE];
	t_field	_info[INF_NFLD];
	t_index	_used;	
};

#endif