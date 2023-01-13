#include <string>
#include "person.h"

Person::Person(const std :: string &lastName, const std :: string &firstName, const std :: string &cnp, const std :: string &registrationNumber, char sex) :
    last_name(lastName), first_name(firstName), cnp(cnp), registration_number(registrationNumber), sex(sex) {}

Person :: Person(const Person &rhs) : Person(rhs.last_name, rhs.first_name, rhs.cnp, rhs.registration_number, rhs.sex) {}

void Person::setLastName(const std::string &lastName)
{
    last_name = lastName;
}

void Person::setFirstName(const std::string &firstName)
{
    first_name = firstName;
}

void Person::setCnp(const std::string &cnp)
{
    Person::cnp = cnp;
}

void Person::setRegistrationNumber(const std::string &registrationNumber)
{
    registration_number = registrationNumber;
}

void Person::setSex(char sex)
{
    Person::sex = sex;
}

const std::string &Person::getLastName() const
{
    return last_name;
}

const std::string &Person::getFirstName() const
{
    return first_name;
}

const std::string &Person::getCnp() const
{
    return cnp;
}

const std::string &Person::getRegistrationNumber() const
{
    return registration_number;
}

char Person::getSex() const
{
    return sex;
}

Person::~Person() = default;
