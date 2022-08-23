/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrotzsc <agrotzsc@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:07:28 by agrotzsc          #+#    #+#             */
/*   Updated: 2022/08/23 11:57:21 by agrotzsc         ###   ########.fr       */
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
	char			cstr[2];
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
		input.read(cstr, 1);
		if (input.eof())
			break;
		tmp = (std::string) cstr;
		str = str.append(tmp);
	}
	tmp = newStr;
	while (pos < str.length())
	{
		pos = str.find(old, pos);
		if (pos <= str.length())
		{
			str.erase(pos, strlen(old));
			str.insert(pos, newStr);
			pos += tmp.length();
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