#include "mammal.h"
#include "input.h"
#include <vector>


void Mammal::SetHabitat()
{
	std::cout << "������� ����� ��������: ";
	GetLine(std::cin, _habitat, WITH_DIGITS, MANUAL_INPUT);
}

void Mammal::SetHabitatFromFile(std::istream& input)
{
	std::getline(input, _habitat);
}

void Mammal::SetWayOfEating()
{
	std::cout << "������� ������ �������: ";
	GetLine(std::cin, _wayOfEating, WITH_DIGITS, MANUAL_INPUT);
}

void Mammal::SetWayOfEatingFromFile(std::istream& input)
{
	std::getline(input, _wayOfEating);
}

void Mammal::SetWeight()
{
	std::cout << "������� ���: ";
	_weight = GetPosDouble();
}

void Mammal::SetWeightFromFile(std::istream& input)
{
	input >> _weight; input.get();
}

