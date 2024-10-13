/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:45:58 by stopp             #+#    #+#             */
/*   Updated: 2024/10/09 17:26:34 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

int main(void)
{
	PhoneBook	PhoneBook;
	std::string	command;
	bool		running = true;

	PhoneBook.show_instructions();
	while (running)
	{
		if (!(std::getline(std::cin, command)))
		{
			if (std::cin.eof() == true)
			{
				std::cout << "Exiting PhoneBook!\n" << std::endl;
				std::exit(0);
			}
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.add_contact();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.search_contact();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << "\033[0;31mPhoneBook will be deleted when exiting!\nare you sure? [y/n]\033[0m" << std::endl;
			command.clear();
			while (1)
			{
				if (!(std::getline(std::cin, command)))
				{
					if (std::cin.eof() == true)
					{
						std::cout << "Exiting PhoneBook!\n" << std::endl;
						std::exit(0);
					}
				}
				if (command.compare("y") == 0)
				{
					std::cout << "Goodbye :)" << std::endl;
					running = false;
					break;
				}
				else if (command.compare("n") != 0)
					std::cout << "Enter y to quit and delete the PhoneBook or n and keep using it!" << std::endl;\
				else
					break;
			}
		}
		command.clear();
		if (running)
			PhoneBook.show_instructions();
	}
}
