#pragma once
#include <string>
class IParcer
{
public:
	virtual void reader(const std::string& file) = 0;
	virtual const std::string get_file() const = 0;
	virtual bool search_key(const std::string& key) const = 0;
	virtual bool search_value(const std::string& value) const = 0;
	virtual bool search_header(const std::string& header) const = 0;
	virtual void replace(const std::string& head, const std::string& key, const std::string& var) = 0;
	virtual ~IParcer() {}
};
