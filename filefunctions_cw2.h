#ifndef FILEFUNCTIONS_CW2_H
#define FILEFUNCTIONS_CW2_H
#include "herbivoress.h"
#include "input.h"

bool IsDataCorrectCW2(std::ifstream& file);

std::string CheckFileCW2();

void GetHerbivoressFromFile(std::vector<Mammal*>& herbivoress, int amount, std::string path = CheckFileCW2());

void SaveToFile(std::vector<Mammal*>& herbivoress);

int CountStringsCW2(std::string path);


#endif
