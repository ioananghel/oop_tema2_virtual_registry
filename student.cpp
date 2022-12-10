#include <string>
#include <vector>
#include "person.h"
#include "student.h"

Student::Student(const std :: string &lastName, const std :: string &firstName, const std :: string &cnp, const std :: string &registrationNumber, char sex) :
    Person(lastName, firstName, cnp, registrationNumber, sex)
{
    grades.reserve(4);
}

Student::Student(const Student &rhs) : Person(rhs.getLastName(), rhs.getFirstName(), rhs.getCnp(), rhs.getRegistrationNumber(), rhs.getSex())
{
    grades = rhs.grades;
}

void Student::setGrades(const std::vector<int> &grades)
{
    Student :: grades = grades;
}

const std::vector<int> &Student::getGrades() const
{
    return grades;
}

void Student::Print(std::ostream &os) const
{
    os << "Student(" << getLastName() << ", " << getFirstName() << ", " << getCnp() << ", " << getRegistrationNumber() << ", " << getSex() << ", Grades: [";
    for(auto it : grades)
    {
        std :: cout << it << ", ";
    }
    std :: cout << "]";
}

Student::Student() = default;

Student::~Student() = default;
