#include "Parcer_funcs.h"
#include <Windows.h>
Parcer_funcs::Parcer_funcs(const std::string& path) :_path(path) {}

void Parcer_funcs::save_file(const std::string& newPath, const std::string& file) {
	std::ofstream out{ newPath + ".ini" };
	out << file;
	out.close();
}

void Parcer_funcs::start_work(std::shared_ptr<INI_Parcer>& obj) {
	obj->reader(_path);
	bool end = true;
	std::string value, key, header;
	int num;
	while (end) {
		system("CLS");		
		std::cout << "1. Поиск ключа в заголовке\n";
		std::cout << "2. Проверить существование заголовка\n";
		std::cout << "3. Проверить существование ключа\n";
		std::cout << "4. Проверить существование значения\n";
		std::cout << "5. Найти значение ключа в заголовке\n";
		std::cout << "6. Присвоить значение в заголовке по ключу\n";
		std::cout << "7. Сохранить файл\n";
		std::cout << "Введите номер нужной функции: ";
		std::cin >> value;
		num = std::stoi(value);
		std::cin.ignore();
		switch (num) {
		case 1:
			std::cout << "Введите ключ: ";
			getline(std::cin, key);
			if (obj->search_key(key))
				std::cout << "Заголовок: " << obj->search_key_in_header(key) << '\n';
			else
				std::cout << "Такого ключа не существует в файле!\n";
			break;
		case 2:
			std::cout << "Введите название заголовка: ";
			getline(std::cin, header);
			if (obj->search_header(header)) 
				std::cout << "Заголовок существует в файле!\n";		
			
			else {
				std::cout << "Такого заголовка несуществует в файле!\n";
			}
			break;
		case 3:
			std::cout << "Введите ключ: ";
			getline(std::cin, key);
			if (obj->search_key(key))
				std::cout << "Такой ключ присутствует в файле\n";
			else {
				std::cout << "Такого ключа не существует в файле\n";
			}
			break;
		case 4:
			std::cout << "Введите значение: ";
			getline(std::cin, value);
			if (obj->search_value(value))
				std::cout << "Такое значение есть в файле!\n";
			else {
				std::cout << "Такого значения не существует в файле!\n";
			}
			break;
		case 5:
			std::cout << "Введите ключ: ";
			getline(std::cin, key);
			std::cout << "Введите заголовок: ";
			getline(std::cin, header);
			if (obj->search_key(key) && obj->search_header(header))
				std::cout << obj->search_value_in_header(header, key) << '\n';
			else
				std::cout << "Вы ввели неверные параметры!\n";
			break;
		case 6:
			std::cout << "Введите ключ: ";
			getline(std::cin, key);
			std::cout << "Введите заголовок: ";
			getline(std::cin, header);
			std::cout << "Введите новое значение: ";
			getline(std::cin, value);
			obj->replace(header, key, value);
			break;
		case 7:
			std::cout << "Введите название нового файла: ";
			getline(std::cin, value);
			save_file(value, obj->get_file());
			end = false;
		default: continue;
		}
		system("Pause");
	}

}

