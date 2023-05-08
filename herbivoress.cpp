#include "herbivoress.h"
#include "input.h"
#include <iomanip>


void Herbivoress::Show(void) const
{
    std::cout
        << "************************************************" << std::endl
        << "| Способ питания: " << _wayOfEating << std::endl
        << "| Вес: " << std::fixed << std::setprecision(2) << _weight << " кг" << std::endl
        << "| Среда обитания: " << _habitat << std::endl
        << "| Пол: " << _gender << std::endl
        << "| Скорость передвижения: " << std::fixed << std::setprecision(2) << _movementSpeed << " км/ч" << std::endl
        << "************************************************" << std::endl;
}

void Herbivoress::SetGender(void)
{
    std::cout << "Введите пол: ";
    GetLine(std::cin, _gender, WITHOUT_DIGITS, MANUAL_INPUT);
}

void Herbivoress::SetGenderFromFile(std::istream& input)
{
    std::getline(input, _gender);
}

void Herbivoress::SetMovementSpeed()
{
    std::cout << "Введите скорость передвижения: ";
    _movementSpeed = GetPosDouble();
}

void Herbivoress::SetMovementSpeedFromFile(std::istream& input)
{
    input >> _movementSpeed; input.get();
}
