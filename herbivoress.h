#ifndef HERBIVORESS_H
#define HERBIVORESS_H
#include "mammal.h"


class Herbivoress : public Mammal
{
private:
    std::string _gender{};
    double _movementSpeed{};

public:
    void Show() const override;

    void SetGender();
    void SetGenderFromFile(std::istream& input);
    void SetMovementSpeed();
    void SetMovementSpeedFromFile(std::istream& input);

    double GetMovementSpeed() const { return _movementSpeed; };
    std::string GetGender() const { return _gender; };

    ~Herbivoress() = default;
};

#endif