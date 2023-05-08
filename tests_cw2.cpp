#include "tests_cw2.h"
#include "herbivoress.h"
#include "cw2_functions.h"
#include "filefunctions_cw2.h"
#include <filesystem>
#include <fstream>


bool UnitTestCW2::TestCaseOne() // boot from valid file
{
	
	return true;
}

bool UnitTestCW2::TestCaseTwo() // set weight and speed from file loaded herbivoress
{

	return true;
}

bool UnitTestCW2::TestCaseThree() // check file where weight or speed is negative digit
{

	return true;
}

bool UnitTestCW2::TestCaseFour() // check file where weight or speed is not a digit
{
	std::string path = "test4cw2.txt";
	std::ifstream file(path);
	if (IsDataCorrectCW2(file))
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: " << "������ ����������� " << std::endl
			<< "��������: " << "������ ���������" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

bool UnitTestCW2::TestCaseFive() // check valid file
{
	std::string path = "test5cw2.txt";
	std::ifstream file(path);
	if (!IsDataCorrectCW2(file))
	{
		std::cout
			<< "���� 5 ��������." << std::endl
			<< "���������: " << "������ ��������� " << std::endl
			<< "��������: " << "������ �����������" << std::endl;
		return false;
	}
	file.close();
	system("cls");
	return true;
}

void UnitTestCW2::RunAllTests()
{
	UnitTestCW2 test{};
	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}
