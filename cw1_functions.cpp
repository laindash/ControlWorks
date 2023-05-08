#include "input.h"
#include "filefunctions_cw1.h"
#include <algorithm>

bool AllocateArray(Apartment* apartments , int amount)  // checking the possibility of adding a house
{
    if (amount == 0)
    {
        std::cout << "������ ��������� ������: ������ �������� ������ ��� 0 ���������" << std::endl; 
        return false;
    }

    try
    {
        apartments = new Apartment[amount];
    }
    catch (const std::bad_alloc& error)
    {
        std::cout
            << "������ ��������� ������: " << error.what() << std::endl
            << "���������� �������� ���������� �������" << std::endl;
        return false;
    }
    return true;
}

void ShowApartments(Apartment* apartments, int amount)
{
    int id = 1;
    for (int i = 0; i < amount; i++, id++)
    {
        std::cout << "�������� # " << id << std::endl;
        apartments[i].ShowApartment();
    }
}

void FillApartments(Apartment* apartments, int amount)
{
    std::cout << std::endl;
    int apartment_id = 1;
    for (int i = 0; i < amount; i++, apartment_id++) 
    {
        if (!apartments[i].IsEmpty())
            continue;
        std::cout << "��������� ���������� � �������� # " << apartment_id << "." << std::endl;
        apartments[i].SetAddress();
        apartments[i].SetFloor();
        apartments[i].SetRooms();
        apartments[i].SetArea();
        std::cout << std::endl;
    }
}

void GetFloorRange(int& upFloor, int& lowFloor)
{
    bool isCorrectRange{};
    do
    {
        std::cout << "������� ������ ����." << std::endl;
        lowFloor = GetPosInt();

        std::cout << "������� ������� ����." << std::endl;
        upFloor = GetPosInt();

        std::cout << std::endl;
        if (lowFloor > upFloor)
        {
            std::cout << "������ ���� �� ����� ���� ���� ��������!" << std::endl;
            continue;
        }
        else
            isCorrectRange = true;
    } while (!isCorrectRange);
    std::cout << std::endl;
}

bool IsFloorInRange(Apartment current, int upFloor, int lowFloor)
{
    int floor = current.GetFloor();
    if ((lowFloor <= floor) && (floor <= upFloor))
        return true;
    else
        return false;
}

void SearchByRoomsCount(Apartment* apartments, int amount)
{
    bool isThereAtLeastOne = false;
    std::cout << "������� ���������� ������, �� �������� ���������� ���������� �����." << std::endl;
    int rooms = GetPosInt(), counter(0);
    for (int i = 0; i < amount; i++)
    {
        if (apartments[i].GetRooms() == rooms)
        {
            isThereAtLeastOne = true;
            apartments[i].ShowApartment();
            counter++;           
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "������� � �������� ��������� ���!" << std::endl;
    if (isThereAtLeastOne)
    {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = GetKey(YES, NO);
        if (user_choice == YES)
        {
            Apartment* listToSave = new Apartment[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (apartments[i].GetRooms() == rooms)
                    listToSave[j++] = apartments[i];

            SaveToFile(listToSave, counter);
            delete[] listToSave;
            listToSave = nullptr;
        }
        else if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    }
}

void SearchByRoomsCountAndFloorInRange(Apartment* apartments, int amount)
{
    int counter(0);
    int upFloor{}, lowFloor{};
    GetFloorRange(upFloor, lowFloor);
    std::cout << "������� ���������� ������, �� �������� ���������� ���������� �����." << std::endl;
    int rooms = GetPosInt();
    bool isThereAtLeastOne = false;
    std::cout << "��������, ���� ������� ��������� � ��������� �� " << lowFloor << " �� " << upFloor << std::endl;
    for (int i = 0; i < amount; i++)
    {
        if (IsFloorInRange(apartments[i], upFloor, lowFloor) && apartments[i].GetRooms() == rooms)
        {
            isThereAtLeastOne = true;
            apartments[i].ShowApartment();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "������� � �������� ��������� ���!" << std::endl;
    if (isThereAtLeastOne)
    {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = GetKey(YES, NO);
        if (user_choice == YES)
        {
            Apartment* listToSave = new Apartment[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (IsFloorInRange(apartments[i], upFloor, lowFloor) && apartments[i].GetRooms() == rooms)
                    listToSave[j++] = apartments[i];

            SaveToFile(listToSave, counter);
            delete[] listToSave;
            listToSave = nullptr;
        }
        else if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    }
}

void SearchBySuperiorArea(Apartment* apartments, int amount)
{
    std::cout << "������� �������, ���� ������� ���������� ���������� �����." << std::endl;
    double area = GetPosDouble();
    int counter(0);
    bool isThereAtLeastOne = false;
    for (int i = 0; i < amount; i++)
    {
        if (apartments[i].GetArea() > area)
        {
            isThereAtLeastOne = true;
            apartments[i].ShowApartment();
            counter++;
        }
    }
    if (!isThereAtLeastOne)
        std::cout << "������� � �������� ��������� ���!" << std::endl;
    if (isThereAtLeastOne)
    {
        std::cout << "�������� ��������� � ����?" << std::endl;
        std::cout << "1 - ��, 2 - ���. ESC - ����� �� ���������." << std::endl;
        int user_choice = GetKey(YES, NO);
        if (user_choice == YES)
        {
            Apartment* listToSave = new Apartment[counter];

            for (int i = 0, j = 0; i < amount && j < counter; i++)
                if (apartments[i].GetArea() > area)
                    listToSave[j++] = apartments[i];

            SaveToFile(listToSave, counter);
            delete[] listToSave;
            listToSave = nullptr;
        }
        else if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    }
}
