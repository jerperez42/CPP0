/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:21:53 by jerperez          #+#    #+#             */
/*   Updated: 2024/02/06 11:18:45 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <algorithm>

# define MSG_NO_ARGS "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int ac, char **av)
{
	if (1 == ac)
		std::cout << MSG_NO_ARGS;
	for (int i = 1; i < ac; i++)
	{
		std::string str = av[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout << str;
		if ((i + 1) != ac)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return (0);
}