#include "filefunctions_cw1.h"
#include "filefunctions_cw2.h"
#include "input.h"
#include "cw_info.h"
#include "cw1_functions.h"
#include "tests_cw1.h"
#include "cw2_functions.h"
#include "tests_cw2.h"


void StartCW1(void)
{
    int user_choice{};
    do
    {
        int apartments_amount{};
        std::string file_path{};
        Apartment* apartments = nullptr;
        UnitTestCW1 tests{};

        InfoCW1();
        ShowMainMenuCW1();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
            {
                do
                {
                    file_path = CheckFile();
                    apartments_amount = (CountStrings(file_path) / 7);

                    std::cout << "Загружено квартир: " << apartments_amount << std::endl;
                    if (AllocateArray(apartments, apartments_amount))
                        apartments = new Apartment[apartments_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(apartments, apartments_amount));

                GetListFromFile(apartments, apartments_amount, file_path);
                break;
            }

            case MANUAL_INPUT:
            {
                do
                {
                    std::cout << "Введите число квартир: ";
                    apartments_amount = GetPosInt();
                    if (AllocateArray(apartments, apartments_amount))
                        apartments = new Apartment[apartments_amount];
                    else
                        std::cout << "Произошла ошибка. попробуйте ещё раз!" << std::endl;
                }
                while (!AllocateArray(apartments, apartments_amount));

                FillApartments(apartments, apartments_amount);
                break;
            }

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT: 
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW1();
            switch (user_choice = GetKey(SEARCHbyRoomsCount, SHOW_ALL))
            {
            case SEARCHbyRoomsCount:
                SearchByRoomsCount(apartments, apartments_amount);
                break;

            case SEARCHbyRoomsCountAndFloorInRange:
                SearchByRoomsCountAndFloorInRange(apartments, apartments_amount);
                break;

            case SEARCHbySuperiorArea:
                SearchBySuperiorArea(apartments, apartments_amount);
                break;
            
            case SHOW_ALL:
                ShowApartments(apartments, apartments_amount);
                break;

            case QUIT:
                break;
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW2(void)
{
    int user_choice{};
    do
    {
        std::vector<Mammal*> herbivoress{};
        int herbivoress_amount{};
        std::string file_path{};
        UnitTestCW2 tests{};

        InfoCW2();
        ShowMainMenuCW2();
        switch (user_choice = GetKey(FILE_INPUT, MODUL_TESTS))
        {
            case FILE_INPUT:
                file_path = CheckFileCW2();
                herbivoress_amount = (CountStringsCW2(file_path) / 5);
                std::cout << "Загружено травоядных: " << herbivoress_amount << std::endl;
                GetHerbivoressFromFile(herbivoress, herbivoress_amount, file_path);
                break;

            case MANUAL_INPUT:
                std::cout << "Введите число травоядных: ";
                herbivoress_amount = GetPosInt();
                FillHerbivoress(herbivoress, herbivoress_amount);
                break;

            case MODUL_TESTS:
                tests.RunAllTests();
                break;

            case QUIT:
                break;
        }

        while (user_choice != QUIT)
        {
            ShowMenuCW2();
            switch (user_choice = GetKey(SHOW, SAVECW2))
            {
                case SHOW:
                    ShowHerbivoress(herbivoress);
                    break;

                case SAVECW2:
                    SaveToFile(herbivoress);
                    break;

                case QUIT:
                    break;
            }
        }
        std::cout << "1 - Запустить эту КР ещё раз, 2 - Выбрать другую КР, ESC - Завершить работу программы." << std::endl;
        user_choice = GetKey(YES, NO);
        if (user_choice == QUIT)
            exit(EXIT_SUCCESS);
    } 
    while (user_choice != NO);
}

void StartCW3(void)
{
    int user_choice{};
    do
    {
        InfoCW3();
        ShowMainMenuCW3();
    } 
    while (user_choice != NO);
}

void StartCW4(void)
{
    int user_choice{};
    do
    {
        InfoCW4();
        ShowMainMenuCW4();
    } 
    while (user_choice != NO);
}
