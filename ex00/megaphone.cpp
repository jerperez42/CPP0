/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:53 by jerperez          #+#    #+#             */
/*   Updated: 2024/04/03 12:59:52 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <algorithm>

# define MEGA_DFLT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
# define MEGA_SEP ' '

static void	_write_default_msg(void)
{
	std::cout << MEGA_DFLT_MSG;
}

static void	_write_newline(void)
{
	std::cout << std::endl;
}

static void	_write_toupper(std::string str)
{
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	std::cout << str;
}

static void	_write_words(char *words[])
{
	while (*words)
	{
		_write_toupper(*words);
		if (*(++words))
			std::cout << MEGA_SEP;
	}
}

int	main(int ac, char *av[])
{
	if (1 == ac)
		_write_default_msg();
	else
		_write_words(++av);
	_write_newline();
	return (EXIT_SUCCESS);
}