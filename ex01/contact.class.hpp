/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:24:29 by jerperez          #+#    #+#             */
/*   Updated: 2024/02/07 11:56:59 by jerperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# define CIN_BUFF 100
# define FLD_NCHR 10
# define FLD_TRNC '.'
# define FLD_CSEP '|'
# define FLD_PADD ' '
# define FLD_UNDR '^'
# define PRPT_F_I "index"
# define PRPT_F_F "first name"
# define PRPT_F_L "last name"
# define PRPT_F_N "nickname"
# define PRPT_F_P "phone number"
# define PRPT_F_D "darkest secret"

# define ROW_NFLD 3
# define INF_NFLD 5

# include <string>
typedef unsigned int	t_index;
typedef std::string		t_field;

class Contact
{
public:
	Contact (void);
	void	display_information(void);
	void	display_row_header(void);
	void	display_row(t_index);
	void	update_information(t_field *);
	t_field	index_to_field(t_field before, t_index row_num, t_field after);
private:
	void	display_col(t_field, bool, char);
	t_field	_first;
	t_field	_last;
	t_field	_nick;
	t_field	_phone;
	t_field	_secret;
};

#endif
