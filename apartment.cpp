#include "apartment.h"
#include "input.h"

void Apartment::SetAddress(void)
{
    std::cout << "������� �������� ������: ";
    GetLine(std::cin, _address.city, WITH_DIGITS, MANUAL_INPUT);
    std::cout << "������� �������� �����: ";
    GetLine(std::cin, _address.street, WITH_DIGITS, MANUAL_INPUT);
    std::cout << "������� ����� ����: ";
    GetLine(std::cin, _address.appart, ALMOST_ALL_DIGITS, MANUAL_INPUT);
    std::cout << "������� ����� ��������: ";
    GetLine(std::cin, _address.flat, ALMOST_ALL_DIGITS, MANUAL_INPUT);
}

void Apartment::SetAddressFromFile(std::istream& input)
{
    std::getline(input, _address.city);
    std::getline(input, _address.street);
    std::getline(input, _address.appart);
    std::getline(input, _address.flat);
}

void Apartment::SetFloor(void)
{
    std::cout << "������� ����: ";
    floor = GetPosInt();
}

void Apartment::SetRooms(void)
{
    std::cout << "������� ���������� ������: ";
    rooms = GetPosInt();
}

void Apartment::SetArea(void)
{
    std::cout << "������� �������: ";
    area = GetPosDouble();
}

void Apartment::SetFloorFromFile(std::istream& input)
{
    input >> floor;  input.get();
}

void Apartment::SetRoomsFromFile(std::istream& input)
{
    input >> rooms;  input.get();
}

void Apartment::SetAreaFromFile(std::istream& input)
{
    input >> area;  input.get();
}

Address Apartment::GetAddress()
{
    return _address;
};

int Apartment::GetFloor()
{
    return floor;
};

int Apartment::GetRooms()
{
    return rooms;
};

double Apartment::GetArea()
{
    return area;
};


void Apartment::ShowApartment()
{
    std::cout
        << std::endl
        << "************************************************" << std::endl
        << "| �����: " << _address.city << std::endl
        << "| �����: " << _address.street << std::endl
        << "| ���: " << _address.appart << std::endl
        << "| ��������: " << _address.flat << std::endl
        << "| ����: " << floor << std::endl
        << "| ���������� ������: " << rooms << std::endl
        << "| �������: " << area << std::endl
        << "************************************************" << std::endl
        << std::endl;
};

bool Apartment::IsEmpty()
{
    if (!_address.city.empty())
        return false;
    if (!_address.street.empty())
        return false;
    if (!_address.appart.empty())
        return false;
    if (!_address.flat.empty())
        return false;

    if (floor != 0)
        return false;
    if (rooms != 0)
        return false;
    if (area != 0)
        return false;

    return true;
}
