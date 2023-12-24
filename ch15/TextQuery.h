#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

#include "QueryResult.h"

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &) const;
	void display_map();

private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;

	static std::string cleanup_str(const std::string &);
};
#endif