//
// Created by Chani Lornel on 9/29/22.
//
#include "iostream"

char	ft_toupper(char c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

int	main (int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j]; j++)
			{
				std::cout << ft_toupper(argv[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}