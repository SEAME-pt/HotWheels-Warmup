#include <iostream>
#include <string.h>
#include <stdio.h>


int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Run with 2 or more arguments!" << std::endl;
		return (1);
	}
	else
	{

		if (!strcmp(argv[1], "up"))
		{
			for(int i = 2; i < argc; i++)
			{
				for(int j = 0; j < strlen(argv[i]); j++)
					std::cout << (char)toupper(argv[i][j]);
			}
		}
		else if (!strcmp(argv[1], "down"))
		{
			for(int i = 2; i < argc; i++)
			{
				for(int j = 0; j < strlen(argv[i]); j++)
					std::cout << (char)tolower(argv[i][j]);
			}
		}
		else
			std::cout << "Please write up or down!";
		std::cout << std::endl;
	}
	return (0);
}
