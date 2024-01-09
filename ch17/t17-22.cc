#include <iostream>
#include <regex>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_search;
using std::smatch;
using std::sregex_iterator;
using std::string;

bool valid(const std::smatch &m);

void find_phone()
{
	std::string phone("(\\()?(\\d{3})(\\))?([ ]*)([.- ])?([ ]*)(\\d{4})");
	std::regex r(phone);
	std::smatch m;
	std::string s;

	if (std::getline(std::cin, s))
		for (std::sregex_iterator it(s.begin(), s.end(), r), endit; it != endit; ++it)
			if (valid(*it))
				std::cout << "valid: " << it->str() << std::endl;
			else
				std::cout << "not valid: " << it->str() << std::endl;
}

bool valid(const std::smatch &m)
{
	if (m[1].matched)
		return m[3].matched && (m[5].matched == 0 || m[4].str() == " ");
	else
		return !m[3].matched && m[5].str() == m[8].str();
}