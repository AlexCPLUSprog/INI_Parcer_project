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
		std::cout << "1. ����� ����� � ���������\n";
		std::cout << "2. ��������� ������������� ���������\n";
		std::cout << "3. ��������� ������������� �����\n";
		std::cout << "4. ��������� ������������� ��������\n";
		std::cout << "5. ����� �������� ����� � ���������\n";
		std::cout << "6. ��������� �������� � ��������� �� �����\n";
		std::cout << "7. ��������� ����\n";
		std::cout << "������� ����� ������ �������: ";
		std::cin >> value;
		num = std::stoi(value);
		std::cin.ignore();
		switch (num) {
		case 1:
			std::cout << "������� ����: ";
			getline(std::cin, key);
			if (obj->search_key(key))
				std::cout << "���������: " << obj->search_key_in_header(key) << '\n';
			else
				std::cout << "������ ����� �� ���������� � �����!\n";
			break;
		case 2:
			std::cout << "������� �������� ���������: ";
			getline(std::cin, header);
			if (obj->search_header(header)) 
				std::cout << "��������� ���������� � �����!\n";		
			
			else {
				std::cout << "������ ��������� ������������ � �����!\n";
			}
			break;
		case 3:
			std::cout << "������� ����: ";
			getline(std::cin, key);
			if (obj->search_key(key))
				std::cout << "����� ���� ������������ � �����\n";
			else {
				std::cout << "������ ����� �� ���������� � �����\n";
			}
			break;
		case 4:
			std::cout << "������� ��������: ";
			getline(std::cin, value);
			if (obj->search_value(value))
				std::cout << "����� �������� ���� � �����!\n";
			else {
				std::cout << "������ �������� �� ���������� � �����!\n";
			}
			break;
		case 5:
			std::cout << "������� ����: ";
			getline(std::cin, key);
			std::cout << "������� ���������: ";
			getline(std::cin, header);
			if (obj->search_key(key) && obj->search_header(header))
				std::cout << obj->search_value_in_header(header, key) << '\n';
			else
				std::cout << "�� ����� �������� ���������!\n";
			break;
		case 6:
			std::cout << "������� ����: ";
			getline(std::cin, key);
			std::cout << "������� ���������: ";
			getline(std::cin, header);
			std::cout << "������� ����� ��������: ";
			getline(std::cin, value);
			obj->replace(header, key, value);
			break;
		case 7:
			std::cout << "������� �������� ������ �����: ";
			getline(std::cin, value);
			save_file(value, obj->get_file());
			end = false;
		default: continue;
		}
		system("Pause");
	}

}

