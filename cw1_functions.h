#ifndef CW1_FUNCTIONS_H
#define CW1_FUNCTIONS_H

#include "apartment.h"

bool AllocateArray(Apartment* apartments, int amount);
void ShowApartments(Apartment* apartments, int amount);
void FillApartments(Apartment* apartments, int amount);
void GetFloorRange(int& upFloor, int& lowFloor);
bool IsFloorInRange(Apartment current, int upFloor, int lowFloor);
void SearchByRoomsCount(Apartment* List, int amount);
void SearchByRoomsCountAndFloorInRange(Apartment* List, int amount);
void SearchBySuperiorArea(Apartment* List, int amount);

#endif