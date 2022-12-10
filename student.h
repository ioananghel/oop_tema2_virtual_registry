#ifndef OOP_TEMA2_REDONE_STUDENT_H
#define OOP_TEMA2_REDONE_STUDENT_H

#include <vector>
#include "person.h"
#include "get_type.h"

class Student : public Person
{
private:
    std :: vector<int> grades;

public:
    Student(const std::string &lastName, const std::string &firstName, const std::string &cnp, const std::string &registrationNumber, char sex);
    Student();

    Student(const Student &rhs);

    void setGrades(const std::vector<int> &grades);

    const std::vector<int> &getGrades() const;

    void Print(std::ostream&) const override;

    PersonType GetPersonType() const override { return PersonType::Student; }

    ~Student() override;
};

#endif
