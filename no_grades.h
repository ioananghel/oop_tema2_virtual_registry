#ifndef OOP_TEMA2_REDONE_NO_GRADES_H
#define OOP_TEMA2_REDONE_NO_GRADES_H

#include <exception>
#include "newiostream.h"

class NoGrades : public std :: exception, public newiostream
{
public:
    NoGrades() = default;

    const char *what() const noexcept override;

    void Print(std :: ostream&) const;
};

#endif //OOP_TEMA2_REDONE_NO_GRADES_H
