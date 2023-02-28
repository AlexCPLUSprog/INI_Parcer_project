#pragma once
#include <iostream>
#include "INI_Parcer.h"
class Parcer_funcs
{
public:
	Parcer_funcs(const std::string& path);	
	void save_file(const std::string& newPath, const std::string& file);
	void start_work(std::shared_ptr<INI_Parcer>& obj);
	
private:
	std::string _path;
};

