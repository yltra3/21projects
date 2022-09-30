//
// Created by Chani Lornel on 9/29/22.
//

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include <iostream>
# include <string.h>
# include <iomanip>
# include "scrappy.h"
class phonebook{

	public:
		phonebook();

		bool	add_new_contact();
		void	show_contacts();
		void	search_contact();
	private:
		int			contacts_number;
		scrappy		contacts[8];
};
#endif //PHONEBOOK_H
