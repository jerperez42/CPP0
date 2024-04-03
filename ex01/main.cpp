/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:21 by jerperez          #+#    #+#             */
/*   Updated: 2024/02/07 13:16:08 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <stdio.h>

# define PRPT_CMD "Enter one of the three commands:"
# define PRPT_CER "The program only accepts ADD, SEARCH and EXIT\nYou entered:"
# define CMD_CADD "ADD"
# define CMD_SRCH "SEARCH"
# define CMD_EXIT "EXIT"

static void	main_cls(void)
{
	std::cout << "\033[2J" << "\033[H";
}

static int	main_loop(PhoneBook book)
{
	char		buff[CIN_BUFF] = {0};
	std::string	cmd_cadd(CMD_CADD);
	std::string	cmd_srch(CMD_SRCH);
	std::string	cmd_exit(CMD_EXIT);
	std::string	cmd;

	main_cls();
	while (1)
	{
		std::cout << PRPT_CMD;
		std::cin.clear();
		std::cin.getline(buff, CIN_BUFF);
		std::cout << std::endl;
		cmd = buff;
		if (0 == cmd.compare(cmd_cadd))
			book.add();
		else if (0 == cmd.compare(cmd_srch))
			book.search();
		else if (0 == cmd.compare(cmd_exit))
			return (0);
		else
			std::cout << PRPT_CER << cmd << std::endl;
		std::cout << std::endl;
	}
}

int	main(int ac, char **av)
{
	PhoneBook	book;

	(void)ac;
	(void)av;

	return (main_loop(book));
}