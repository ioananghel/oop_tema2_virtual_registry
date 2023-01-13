#include "no_grades.h"

void NoGrades::Print(std::ostream &os) const
{
    os << this -> what();
}

const char *NoGrades::what() const noexcept
{
    return "\nNo grades registered to this student\n";
}
