#include "input.h"
#include "filefunctions_cw2.h"
#include "herbivoress.h"
#include <vector>
#include <iostream>


void FillHerbivoress(std::vector<Mammal*>& herbivoress, int amount)
{
    std::cout << std::endl;
    int Herbivoress_id = 1;
    for (int i = 0; i < amount; i++, Herbivoress_id++)
    {
        std::cout << "Заполните информацию о травоядном # " << Herbivoress_id << std::endl;
        Herbivoress* new_herbivoress = new Herbivoress;
        new_herbivoress->SetWayOfEating();
        new_herbivoress->SetWeight();
        new_herbivoress->SetHabitat();
        new_herbivoress->SetGender();
        new_herbivoress->SetGender();
        new_herbivoress->SetMovementSpeed();
        herbivoress.push_back(new_herbivoress);
    }
}


void ShowHerbivoress(std::vector<Mammal*>& herbivoress)
{
    int Herbivoress_id = 1;
    for (std::vector<Mammal*>::const_iterator it = herbivoress.cbegin(); it != herbivoress.cend(); it++, Herbivoress_id++)
    {
        std::cout << "Травоядное # " << Herbivoress_id << std::endl;
        (*it)->Show();
    }
}