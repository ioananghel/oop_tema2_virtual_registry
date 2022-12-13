#ifndef OOP_TEMA2_REDONE_NO_STUDENT_H
#define OOP_TEMA2_REDONE_NO_STUDENT_H

#include <exception>
#include "newiostream.h"

class NoSuchStudent : public std :: exception, public newiostream
{
public:
    NoSuchStudent() = default;

    const char *what() const noexcept override;

    void Print(std :: ostream&) const;
};

#endif //OOP_TEMA2_REDONE_NO_STUDENT_H
