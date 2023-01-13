#ifndef OOP_TEMA2_REDONE_STUDENT_H
#define OOP_TEMA2_REDONE_STUDENT_H

#include <vector>
#include "person.h"
#include "get_type.h"
#include "cloning.h"
#include "assign_id.h"

class Student : public Person, public cloning
{
private:
    std :: string id;
    std :: vector<int> grades;

public:
    Student(const std::string &lastName, const std::string &firstName, const std::string &cnp, const std::string &registrationNumber, char sex);
    Student();

    Student(const Student &rhs);

    void setGrades(const std::vector<int> &grades);

    const std::vector<int> &getGrades() const;

    void Print(std::ostream&) const override;

    PersonType GetPersonType() const override { return PersonType::Student; }

    std::string getId() const override { return id; }

    virtual Student* clone() const
    {
        return (new Student(*this));
    }

    ~Student() override;
};

#endif
