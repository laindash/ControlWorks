#include "tests_cw1.h"
#include "apartment.h"
#include "cw1_functions.h"
#include "filefunctions_cw1.h"
#include <fstream>
#include <filesystem>
#include <iostream>

bool UnitTestCW1::TestCaseOne() // test search by rooms count
{
	const int amount(3);
	int rooms{};
	const int ansRooms(2);
	Apartment* apartments = nullptr;
	std::string test_file_path = "test1cw1.txt";

	if (!AllocateArray(apartments, amount))
	{
		std::cout << "���� 1 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		apartments = new Apartment[amount];
	
	if (!std::ifstream(test_file_path)) // check existing file
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	GetListFromFile(apartments, amount, test_file_path);
	int counter(0);

	for (int i = 0; i < amount; i++)
		if (apartments[i].GetRooms() == ansRooms)
			counter++;

	if (counter > 1)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "���������� �������: 1" << std::endl
			<< "��������: " << counter << std::endl;
		return false;
	}
	Apartment* listToCheck = new Apartment[counter];
	for (int i = 0, j = 0; i < amount && j < counter; i++)
		if (apartments[i].GetRooms() == ansRooms)
			listToCheck[j++] = apartments[i];	


	rooms = listToCheck[0].GetRooms();
	if (rooms != ansRooms)
	{
		std::cout
			<< "���� 1 ��������." << std::endl
			<< "���������: " << "���������� ������: " << ansRooms << std::endl
			<< "��������: " << rooms << std::endl;
		return false;
	}

	delete[] listToCheck;
	listToCheck = nullptr;

	return true;
}

bool UnitTestCW1::TestCaseTwo() // test search by rooms count and floor in range
{
	const int amount(3);
	int rooms1{}, rooms2{}, floor1{}, floor2{};
	const int ansFloor1(1), ansFloor2(14), ansRooms(4);
	Apartment* apartments = nullptr;
	std::string test_file_path = "test2cw1.txt";

	if (!AllocateArray(apartments, amount))
	{
		std::cout << "���� 2 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		apartments = new Apartment[amount];

	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	GetListFromFile(apartments, amount, test_file_path);
	int counter(0);
	int upFloor = 14, lowFloor = 1;
	for (int i = 0; i < amount; i++)
		if (IsFloorInRange(apartments[i], upFloor, lowFloor) && apartments[i].GetRooms() == ansRooms)
			counter++;
	if (counter > 2)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "���������� �������: 2" << std::endl
			<< "��������: " << counter << std::endl;
		return false;
	}

	Apartment* listToCheck = new Apartment[counter];
	for (int i = 0, j = 0; i < amount && j < counter; i++)
		if (IsFloorInRange(apartments[i], upFloor, lowFloor) && apartments[i].GetRooms() == ansRooms)
			listToCheck[j++] = apartments[i];

	rooms1 = listToCheck[0].GetRooms();
	rooms2 = listToCheck[1].GetRooms();

	floor1 = listToCheck[0].GetFloor();
	floor2 = listToCheck[1].GetFloor();


	if (rooms1 != ansRooms)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "���������� ������: " << ansRooms << std::endl
			<< "��������: " << rooms1 << std::endl;
		return false;
	}
	if (rooms2 != ansRooms)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "���������� ������: " << ansRooms << std::endl
			<< "��������: " << rooms2 << std::endl;
		return false;
	}

	if (floor1 != ansFloor1)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "����� �����: " << ansFloor1 << std::endl
			<< "��������: " << floor1 << std::endl;
		return false;
	}

	if (floor2 != ansFloor2)
	{
		std::cout
			<< "���� 2 ��������." << std::endl
			<< "���������: " << "����� �����: " << ansFloor2 << std::endl
			<< "��������: " << floor2 << std::endl;
		return false;
	}

	delete[] listToCheck;
	listToCheck = nullptr;

	return true;
}

bool UnitTestCW1::TestCaseThree() // test search by superior area
{
	const int amount(2);
	double area{};
	const double ansArea(14.1);
	Apartment* apartments = nullptr;
	std::string test_file_path = "test3cw1.txt";

	if (!AllocateArray(apartments, amount))
	{
		std::cout << "���� 3 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	else
		apartments = new Apartment[amount];

	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	GetListFromFile(apartments, amount, test_file_path);
	int counter(0);
	for (int i = 0; i < amount; i++)
		if (apartments[i].GetArea() > ansArea)
			counter++;

	if (counter > 1)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: " << "���������� �������: 1" << std::endl
			<< "��������: " << counter << std::endl;
		return false;
	}

	Apartment* listToCheck = new Apartment[counter];
	for (int i = 0, j = 0; i < amount && j < counter; i++)
		if (apartments[i].GetArea() > ansArea)
			listToCheck[j++] = apartments[i];

	area = listToCheck[0].GetArea();

	if (area <= ansArea)
	{
		std::cout
			<< "���� 3 ��������." << std::endl
			<< "���������: ������� > " << ansArea << std::endl
			<< "��������: " << area << std::endl;
		return false;
	}

	delete[] listToCheck;
	listToCheck = nullptr;

	return true;
}

bool UnitTestCW1::TestCaseFour() // test check apartment valid file
{
	std::string test_file_path = "test4cw1.txt";
	if (!std::ifstream(test_file_path))
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: ���� ������!" << std::endl
			<< "��������: ���� �� ������!" << std::endl;
		return false;
	}

	std::ifstream file(test_file_path);
	if (!IsDataCorrectCW1(file))
	{
		std::cout
			<< "���� 4 ��������." << std::endl
			<< "���������: ������ ��������� " << std::endl
			<< "��������: ������ �����������" << std::endl;
		return false;
	}
	file.close();
	return true;
}


bool UnitTestCW1::TestCaseFive() // zero apartments
{
	const int clients_amount(0);
	Apartment* apartments = nullptr;
	if (AllocateArray(apartments, clients_amount))
	{
		std::cout << "���� 5 ��������. ������ ��������� ������!" << std::endl;
		return false;
	}
	
	return true;
}

void UnitTestCW1::RunAllTests()
{
	UnitTestCW1 test{};

	if (test.TestCaseOne() && test.TestCaseTwo() && test.TestCaseThree() && test.TestCaseFour() && test.TestCaseFive())
	{
		system("cls");
		std::cout << "��� ��������� ����� ��������!" << std::endl;
	}
	else
		std::cout << "��������� ����� �� ��������." << std::endl;
}
