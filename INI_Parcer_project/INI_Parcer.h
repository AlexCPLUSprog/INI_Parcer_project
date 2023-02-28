#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <map>
#include "IParcer.h"

class INI_Parcer : public IParcer
{
public:
	void reader(const std::string& name_file) override;	
	bool search_header(const std::string& header)const override;
	bool search_key(const std::string& key)const override;
	bool search_value(const std::string& value)const override;	
	void replace(const std::string& header, const std::string& key, const std::string& value)override;
	const std::string get_file() const override;

	const std::string search_value_in_header(const std::string& header, const std::string& key);
	const std::string search_key_in_header(const std::string& key);

private:
	std::map<std::string, std::vector<std::pair<std::string, std::string>>> _section;
	std::string _header;

};

