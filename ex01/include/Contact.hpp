/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:45:56 by stopp             #+#    #+#             */
/*   Updated: 2024/10/08 16:08:28 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
	private:
		static std::string	_fields_name[5];
		std::string			_info[5];

	public:
		Contact();
		~Contact();

		void	init_contact(void);
		void	show_contact(int id) const;
		void	full_contact(int id) const;
};

#endif
