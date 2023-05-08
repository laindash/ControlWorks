#include <filesystem>
#include <fstream>
#include "apartment.h"
#include "input.h"

bool IsDataCorrectCW1(std::ifstream& file) //The function checks if the data loaded from the file is valid
{
    std::string test_string{};
    int test_int{};
    double test_double{};

    if (!file.eof())
    {
        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //city
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������!" << std::endl;
            return false;
        }

        GetLine(file, test_string, WITH_DIGITS, FILE_INPUT); //street
        if (test_string.empty())
        {
            std::cout << "������ ���������� �����!" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //appart
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ ����!" << std::endl;
            return false;
        }

        GetLine(file, test_string, ALMOST_ALL_DIGITS, FILE_INPUT); //flat
        if (test_string.empty())
        {
            std::cout << "������ ���������� ������ ��������!" << std::endl;
            return false;
        }

        file >> test_int; //floor
        if (test_int > INT_MAX)
        {
            std::cout << "������ ���������� ������ �����, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� ������ �����!" << std::endl;
            return false;
        };
        
        file >> test_int; //rooms
        if (test_int > INT_MAX)
        {
            std::cout << "������ ���������� ���������� ������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� ���������� ������!" << std::endl;
            return false;
        };

        file >> test_double; //area
        if (test_double > DBL_WRONG)
        {
            std::cout << "������ ���������� �������, ��������� ������������ ��������!" << std::endl;
            return false;
        }
        if (file.fail())
        {
            std::cout << "������ ���������� �������!" << std::endl;
            return false;
        };

        while (file.get() != EOF); //to clean up possible residual information
    }
    else
        std::cout << "���� ����!" << std::endl;

    file.seekg(0, std::ios::beg);  //If everything went well, then return the pointer to the beginning of the file
    return true;
}

std::string CheckFile()
{
    std::error_code error{};

    std::string path{};
    bool isLoaded = false;

    std::ifstream file;

    do
    {
        std::cout << "������� ���� � �����: ";
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (!std::ifstream(path))
        {
            std::cout << "��������� ���� �� ������!" << std::endl;
            continue;
        }

        if (!std::filesystem::is_regular_file(path, error))
        {
            std::cout << "������, ������������ ����� �����!" << std::endl;
            continue;
        }

        file.open(path);

        if (!file)
        {
            std::cout << "������ �������� �����!" << std::endl;
            file.close();
        }
        else if (!IsDataCorrectCW1(file))
        {
            std::cout << "������ �����������!" << std::endl;
            file.close();
        }
        else
            isLoaded = true;
    } 
    while (!isLoaded);

    std::cout << "���� ������!" << std::endl;
    file.close();

    return path;
}

void GetListFromFile(Apartment* List, int amount, std::string path = CheckFile())
{
    std::ifstream file(path);

    for (int i = 0; i < amount && !file.eof(); i++)
    {
        if (List[i].IsEmpty())
        {
            List[i].SetAddressFromFile(file);
            List[i].SetFloorFromFile(file);
            List[i].SetRoomsFromFile(file);
            List[i].SetAreaFromFile(file);
        }
    }

    std::cout << "������ ��������!" << std::endl;

    file.close();
}

void SaveToFile(Apartment* List, int amount)
{
    std::ofstream file;
    std::string path{};
    bool isOpened = false;

    std::error_code error{};

    do
    {
        std::cout 
            << "������� ���� � ����� ��� ����������. "
            << "���� ������� ������ ��� � ���������� �����, ����������� ���� ����� �������� ���� � ��������� ���� ���������." << std::endl;
        GetLine(std::cin, path, WITH_DIGITS, MANUAL_INPUT);

        if (std::ifstream(path))
        {
            if (!std::filesystem::is_regular_file(path, error))
            {
                std::cout << "������, ������������ ����� �����!" << std::endl;
                continue;
            }

            std::cout 
                << "������ ���� ��� ����������!." << std::endl
                << "1 - ������������." << std::endl
                << "2 - ������� ������." << std::endl;

            if (GetKey(YES, NO) == NO)
                continue;
        }

        file.open(path, std::ios::trunc);

        if (!file)
            std::cout << "������ �������� �����!" << std::endl;
        else
            isOpened = true;
    } 
    while (!isOpened);

    Address outputAddress{};
    int outputFloor{}, outputRooms{};
    double outputArea{};

    for (int i = 0; i < amount && !List[i].IsEmpty(); i++)
    {
        outputAddress = List[i].GetAddress();
        outputFloor = List[i].GetFloor();
        outputRooms = List[i].GetRooms();
        outputArea = List[i].GetArea();

        if (i != 0) //separator between different apartments
            file << std::endl;

        file 
            << outputAddress.city << std::endl 
            << outputAddress.street << std::endl 
            << outputAddress.appart << std::endl 
            << outputAddress.flat << std::endl
            << outputFloor << std::endl 
            << outputRooms << std::endl
            << outputArea;
    }
    std::cout << "������� ��������� � " << path << std::endl;
}

int CountStrings(std::string path)
{
    int stringsAmount{};

    std::ifstream file;
    file.open(path);
    std::string tmp{};

    while (!file.eof())
    {
        std::getline(file, tmp);
        stringsAmount++;
    }

    return stringsAmount;
}