#ifndef APARTMENT_H
#define APARTMENT_H

#include <string>
#include <iostream>

struct Address
{
	std::string city{}, street{}, appart{}, flat{};	
};

class Apartment
{
private:
	Address _address{};
	int floor{};
	int rooms{};
	double area{};

public:
	void SetAddress();
	void SetAddressFromFile(std::istream& input);
	void SetFloor();
	void SetFloorFromFile(std::istream& input);
	void SetRooms();
	void SetRoomsFromFile(std::istream& input);
	void SetArea();
	void SetAreaFromFile(std::istream& input);
	Address GetAddress();
	int GetFloor();
	int GetRooms();
	double GetArea();
	void ShowApartment();
	bool IsEmpty();
};

#endif