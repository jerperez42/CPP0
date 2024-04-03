/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:35:21 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/03 14:39:31 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.class.hpp"
#include <stdio.h>
#include <cstdlib>

# define PRPT "phonebook> "
# define MSG_CMD "Enter one of these three commands: "
# define SEP '|'
# define PRPT_CER "phonebook: expected ADD, SEARCH or EXIT: received "
# define CMD_CADD "ADD"
# define CMD_SRCH "SEARCH"
# define CMD_EXIT "EXIT"
# define EXIT_MSG "exit"

static void	_ui_clear(void)
{
	std::cout << "\033[2J" << "\033[H";
}

static void	_ui_prompt(void)
{
	std::cout << MSG_CMD;
	std::cout << CMD_CADD << SEP << CMD_SRCH << SEP << CMD_EXIT;
	std::cout << std::endl;
	std::cout << PRPT;
}

static void	_ui_write_error(std::string cmd)
{
	std::cout << PRPT_CER << '`' << cmd << "'";
}

static int	_ui_loop(PhoneBook book)
{
	std::string	cmd_cadd(CMD_CADD);
	std::string	cmd_srch(CMD_SRCH);
	std::string	cmd_exit(CMD_EXIT);
	std::string	cmd("");

	_ui_clear();
	while (false == std::cin.eof())
	{
		_ui_prompt();
		std::getline(std::cin, cmd);
		if (cmd_exit == cmd || true == std::cin.eof())
			return (EXIT_SUCCESS);
		else if (cmd_cadd == cmd)
			book.add();
		else if (cmd_srch == cmd)
			book.search();
		else
			_ui_write_error(cmd);
		std::cout << std::endl << std::endl;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	PhoneBook	book;

	(void)ac;
	(void)av;

	_ui_loop(book);
	std::cout << EXIT_MSG << std::endl;
	return (EXIT_SUCCESS);
}