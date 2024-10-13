/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:46:01 by stopp             #+#    #+#             */
/*   Updated: 2024/10/09 18:11:57 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	_index = -1;
	_full = false;
}
PhoneBook::~PhoneBook()
{
}

void	PhoneBook::show_instructions(void)
{
	std::cout << "\033[0;34mPlease enter one of three PhoneBook commands: ADD, SEARCH or EXIT\033[0m" << std::endl;
}

void	PhoneBook::add_contact(void)
{
	if (_index < 0)
		_index++;
	if (_index >= 8)
	{
		_full = true;
		_index = 0;
	}
	_contacts[_index].init_contact();
	_index++;
}
void	PhoneBook::search_contact(void)
{
	if(_index < 0)
	{
		std::cout << "Add a Contact before searching" << std::endl;
		return ;
	}
	std::string input_ID;
	int			intput_ID;
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "        ID | First Name |  Last Name |   Nickname" << std::endl;
	std::cout << "-------------------------------------------------" << std::endl;
	if (_full == true)
		for (int i = 0; i < 8; i++)
			_contacts[i].show_contact(i + 1);
	else
		for (int i = 0; i < _index; i++)
			_contacts[i].show_contact(i + 1);
	std::cout << "-------------------------------------------------" << std::endl;
	std::cout << "\nPlease enter the ID of the Contact you are looking for:" << std::endl;
	while (true)
	{
		if (!(std::getline(std::cin, input_ID)))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Exiting PhoneBook!\n" << std::endl;
				std::exit(0);
			}
		}
		intput_ID = std::atoi(input_ID.c_str());
		if (intput_ID <= 8 && intput_ID > 0)
		{
			if ((_index >= intput_ID && _full == false) || _full == true)
			{
				_contacts[intput_ID - 1].full_contact(intput_ID);
				break;
			}
			else
				std::cout << "ID not given yet!" << std::endl;
		}
		else
			std::cout << "not a valid ID!" << std::endl;
	}
	input_ID.clear();
}
