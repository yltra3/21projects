//
// Created by Chani Lornel on 9/29/22.
//
#include "phonebook.h"

std::string ft_getcommand()
{
	std::string	command;

	std::getline(std::cin, command);
	return command;
}

int	main()
{
	std::string	command;

	while (1)
	{
		command = ft_getcommand();
		if (command.empty())
			continue;
		if (command == "EXIT")
			break ;
		if (command == "ADD") { ;

		}
		if (command == "SEARCH")
			;
		else
			std::cout << "Unknown command, use these: ADD/EXIT/SEARCH" << std::endl;
	}
}