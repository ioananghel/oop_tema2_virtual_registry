#ifndef OOP_TEMA2_REDONE_PERSON_H
#define OOP_TEMA2_REDONE_PERSON_H

#include <string>
#include "newiostream.h"
#include "get_type.h"

class Person : public newiostream
{
private:
    std :: string last_name, first_name; ///last and first names of person
    std :: string cnp; ///unique identifier of identity
    std :: string registration_number; ///numar matricol
    char sex; ///the sex of the person - m (male) / f (female)

public:
    Person(const std::string &lastName, const std::string &firstName, const std::string &cnp, const std::string &registrationNumber, char sex);
    Person(){}

    Person(const Person &rhs);

    void setLastName(const std::string &lastName);
    void setFirstName(const std::string &firstName);
    void setCnp(const std::string &cnp);
    void setRegistrationNumber(const std::string &registrationNumber);
    void setSex(char sex);

    const std::string &getLastName() const;
    const std::string &getFirstName() const;
    const std::string &getCnp() const;
    const std::string &getRegistrationNumber() const;
    char getSex() const;

    virtual PersonType GetPersonType() const = 0;

    virtual ~Person();
};

#endif //OOP_TEMA2_REDONE_PERSON_H
