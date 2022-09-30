//
// Created by Chani Lornel on 9/29/22.
//
#include "phonebook.h"
#include "scrappy.h"

std::string ft_getcommand()
{
	std::string	command;

	std::getline(std::cin, command);
	return command;
}

int	main()
{
	std::string	command;
	phonebook phonebook;

	while (1)
	{
		command = ft_getcommand();
		if (command.empty())
			continue;
		if (command == "EXIT")
			break ;
		if (command == "ADD") {
			if (!phonebook.add_new_contact())
				std::cout << "Error: too many contacts" << std::endl;
		}
		if (command == "SEARCH") {
			phonebook.show_contacts();
			phonebook.search_contact();
		}
		else
			std::cout << "Unknown command, use these: ADD/EXIT/SEARCH" << std::endl;
	}
	return 0;
}