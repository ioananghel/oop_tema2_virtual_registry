#include "no_student.h"

void NoSuchStudent :: Print(std :: ostream &os) const
{
    os << this -> what();
}

const char *NoSuchStudent ::what() const noexcept
{
    return "\nThere is no student matching the description\n";
}