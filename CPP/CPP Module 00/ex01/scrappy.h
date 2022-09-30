//
// Created by Chani Lornel on 9/30/22.
//

#ifndef SCRAPPY_H
# define SCRAPPY_H
# include <iostream>
# include <string.h>
# include <iomanip>

class scrappy{
public:
	scrappy();

	void show_contact();
	void show_all_info();
	void fill_contact();

private:
	std::string tr_str(std::string s);

	std::string 				info[11];
	int 						index;
	static int 					instances;
	static const int			first_field;
	static const int 			last_field;
	static const std::string	fields[11];
};
#endif //SCRAPPY_H
