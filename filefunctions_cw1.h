#ifndef filefunctions_cw1_H
#define filefunctions_cw1_H

#include "apartment.h"

bool IsDataCorrectCW1(std::ifstream& file);

std::string CheckFile(void);

void GetListFromFile(Apartment *List, int amount, std::string path = CheckFile());

void SaveToFile(Apartment *List, int amount);

int CountStrings(std::string path);


#endif
