/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:07:28 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/08/22 09:44:36 by agrotzsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

void	replace(char *filename, char *old, char *newStr)
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		str;
	std::string		tmp;
	char			cstr[256];
	size_t			pos = 0;
	char			*outfile;

	input.open(filename);
	if (input.fail())
	{
		std::cerr << "Error: can't open file" << std::endl;
		return;
	}
	while (!input.eof())
	{
		input.getline(cstr, 255);
		tmp = (std::string) cstr;
		str = str.append(tmp);
		str = str.append("\n");
		/*if (input.fail())
		{
			std::cout << "Error: Line too long" << std::endl;
			input.close();
			return;
		}*/
	}
	while (pos < str.length())
	{
		pos = str.find(old, pos);
		if (pos <= str.length())
		{
			str.erase(pos, strlen(old));
			str.insert(pos, newStr);
		}
	}
	outfile = strcat(filename, ".replace");
	output.open(outfile);
	output << str;
	input.close();
	output.close();
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		return(0);
	}
	replace(argv[1], argv[2], argv[3]);
}