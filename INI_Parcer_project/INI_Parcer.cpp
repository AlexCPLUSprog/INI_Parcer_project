#include "INI_Parcer.h"
#include <string>
void INI_Parcer::reader(const std::string& fileName) {
	std::ifstream in;
	in.open(fileName);
	std::string some_str, header;
	std::vector<std::pair<std::string, std::string>> KEY_VALUES;

	if (in.is_open()) {
		while (getline(in, some_str)) {
			bool value = true;
			std::pair<std::string, std::string> key_value;
			if (some_str[0] == '[') {
				header = some_str.substr(1, some_str.find(']') - 1);
				if (header != _header) {
					if (_header != "") {
						_section[_header] = KEY_VALUES;
					}
					_header = header;
					KEY_VALUES.clear();
				}
			}
			if (some_str[0] != ';' && some_str[0] != '#' && some_str[0] != '[' && some_str[0] != '\0' && some_str[0] != ' ') {
				for (int i = 0; i < some_str.size(); i++) {
					if (some_str[i] == '=') {
						value = false;
						continue;
					}
					if (value) {
						key_value.first += some_str[i];
					}
					else {
						if (some_str[i] != ';' && some_str[i] != '#') {
							key_value.second += some_str[i];
						}
						else
							break;
					}
				}
				KEY_VALUES.push_back(key_value);
			}
		}
		_section[_header] = KEY_VALUES;		
		in.close();
	}
	else
		throw "Такого файла нет!";
	
}

const std::string INI_Parcer::search_key_in_header(const std::string& key) {
	for (auto [header, value] : _section) {
		for (auto it = value.begin(); it != value.end(); it++) {
			if (it->first == key)
				return header;
		}
	}
}

bool INI_Parcer::search_header(const std::string& header) const {
	for (auto [header, value] : _section) {
		if (header == header)
			return true;
	}
	return false;
}

bool INI_Parcer::search_key(const std::string& key) const {
	for (auto [header, value] : _section) {
		for (auto it = value.begin(); it != value.end(); it++) {
			if (it->first == key)
				return true;
		}
	}
	return false;
}

bool INI_Parcer::search_value(const std::string& val) const {
	for (auto [header, value] : _section) {
		for (auto it = value.begin(); it != value.end(); it++) {
			if (it->second == val)
				return true;
		}
	}
	return false;
}

const std::string INI_Parcer::search_value_in_header(const std::string& header, const std::string& key) {
	for (auto it = _section[header].begin(); it != _section[header].end(); it++) {
		if (it->first == key) {
			return it->second;
		}
	}
}

void INI_Parcer::replace(const std::string& header, const std::string& key, const std::string& value) {
	if (this->search_header(header) && this->search_key(key)) {
		for (auto it = _section[header].begin(); it != _section[header].end(); it++) {
			if (it->first == key) {
				it->second = value;
				std::cout << "Параметры успешно заменены\n";
			}
		}
	}
	else {
		std::pair<std::string, std::string> key_value = { key,value };
		_section[header].push_back(key_value);
		std::cout << "Добавлен новый ключ со значением\n";
	}
}

const std::string INI_Parcer::get_file() const {
	std::string file;
	for (auto [header, value] : _section) {
		file += ("[" + header + "]\n");
		for (auto it = value.begin(); it != value.end(); it++) {
			file += (it->first + '=' + it->second + '\n');
		}
		file += '\n';
	}
	return file;
}