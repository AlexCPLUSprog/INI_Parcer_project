#include <iostream>
#include "INI_Parcer.h"
#include "Parcer_funcs.h"

int main(int args, char** argv) {
	setlocale(LC_ALL, "ru");

	std::shared_ptr<INI_Parcer> ini = std::make_shared<INI_Parcer>();
	// Пришлось добавить try catch для обработки исключения в случае, когда файла не существует
	try {
		if (args > 1) {
			Parcer_funcs mainProgramm(argv[1]);
			mainProgramm.start_work(ini);
		}
		else {
			std::cout << "Введите название файла: ";
			std::string path;
			std::cin >> path;
			Parcer_funcs anotherMainProgramm(path);
			anotherMainProgramm.start_work(ini);
		}
	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
		std::cout << "\nВведите название файла: ";
		std::string path;
		std::cin >> path;
		Parcer_funcs anotherMainProgramm(path);
		anotherMainProgramm.start_work(ini);
	}

}