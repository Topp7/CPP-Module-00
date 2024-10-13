/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:45:53 by stopp             #+#    #+#             */
/*   Updated: 2024/10/09 18:10:23 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

std::string Contact::_fields_name[5] =
{
	"First Name ",
	"Last Name ",
	"Nickname ",
	"Phone Number ",
	"Darkest Secret "
};

Contact::Contact()
{
}
Contact::~Contact()
{
}

void	Contact::init_contact(void)
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Please enter your " << _fields_name[i] << ":\n";
		while(!(std::getline(std::cin, _info[i])) || _info[i].length() == 0)
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Exiting PhoneBook!\n" << std::endl;
				std::exit(0);
			}
			else if (_info[i].length() == 0)
			{
				_info[i].clear();
				std::cout << "No empty informations allowed" << std::endl;
				std::cout << "Please enter your " << _fields_name[i] << ":\n";
			}
		}
		while (i == 3 && !(std::all_of(_info[i].begin(), _info[i].end(), [](char c){return std::isdigit(c) || std::isspace(c);})))
		{
			_info[i].clear();
			std::cout << "Number can only contain spaces and numbers!" << std::endl;
			if (!(std::getline(std::cin, _info[i])))
			{
				if (std::cin.eof() == true)
				{
					std::cout << "Exiting PhoneBook!\n" << std::endl;
					std::exit(0);
				}
			}
		}
		while ((i == 0 || i == 1) && !(std::all_of(_info[i].begin(), _info[i].end(), [](char c){return std::isalpha(c) || std::isspace(c);})))
		{
			_info[i].clear();
			std::cout << "There cant be numbers in your first and last name!" << std::endl;
			if (!(std::getline(std::cin, _info[i])))
			{
				if (std::cin.eof() == true)
				{
					std::cout << "Exiting PhoneBook!\n" << std::endl;
					std::exit(0);
				}
			}
		}
	}
	std::cout << "\033[0;32mContact added!\033[0m" << std::endl;
}

void	Contact::show_contact(int id) const
{
	std::cout << std::setw(10) << id;
	for (int i = 0; i < 3; i++)
	{
		std::cout << " | ";
		if (_info[i].length() > 10)
			std::cout << _info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << _info[i];
	}
	std::cout << std::endl;
}

void	Contact::full_contact(int id) const
{
	std::cout << "ID : " << id << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << _fields_name[i] << ": " << _info[i] << std::endl;
}
