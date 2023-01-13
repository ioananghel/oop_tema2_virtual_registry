#include <string>
#include <vector>
#include "student.h"
#include "no_grades.h"


Student::Student(const std :: string &lastName, const std :: string &firstName, const std :: string &cnp, const std :: string &registrationNumber, char sex) :
    Person(lastName, firstName, cnp, registrationNumber, sex)
{
    grades.reserve(4);

    id = "Stud" + ID<float> :: getId();
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
    if(grades.empty())
    {
        throw(NoGrades());
    }

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
