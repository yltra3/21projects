//
// Created by Chani Lornel on 9/30/22.
//
#include "scrappy.h"

int				scrappy::instances = 0;
const int		scrappy::first_field= 0;
const int		scrappy::last_field = 10;

const std::string	scrappy::fields[11] = {
		"first name",
		"last name",
		"nickname",
		"login",
		"postal address",
		"email address",
		"birthday",
		"date",
		"favorite meal",
		"underwear color",
		"darkest secret"
};

scrappy::scrappy() {
	this->index = scrappy::instances;
	scrappy::instances++;
	for(int i = scrappy::first_field; i <= scrappy::last_field; i++)
		this->info[i] = "(none)";
}
std::string	scrappy::tr_str(std::string s) {
	if (s.length() <= 10) {
		return s;
	} else {
		return s.substr(0, 9) + '.';
	}
}

void	scrappy::fill_contact() {
	for (int i = scrappy::first_field; i <= scrappy::last_field; i++) {
		std::cout << scrappy::fields[i] << ": ";
		getline(std::cin, this->info[i]);
		if (std::cin.eof())
			exit(0);
	}
}

void	scrappy::show_contact() {
	std::cout << "|";
	std::cout << std::setw(10) << this->index;
	std::cout << "|";
	std::cout << std::setw(10) << tr_str(this->info[0]);
	std::cout << "|";
	std::cout << std::setw(10) << tr_str(this->info[1]);
	std::cout << "|";
	std::cout << std::setw(10) << tr_str(this->info[2]);
	std::cout << "|" << std::endl;
}

void	scrappy::show_all_info() {
	for (int i = scrappy::first_field; i <= scrappy::last_field; i++) {
		std::cout << scrappy::fields[i] << ": " << this->info[i] << std::endl;
	}
}