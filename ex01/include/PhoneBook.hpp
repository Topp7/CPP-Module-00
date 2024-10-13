/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:46:03 by stopp             #+#    #+#             */
/*   Updated: 2024/10/08 16:53:50 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_index;
		bool		_full;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	show_instructions(void);
		void	search_contact(void);
		void	add_contact(void);
};

#endif
