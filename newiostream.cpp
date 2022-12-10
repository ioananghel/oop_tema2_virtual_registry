#include "newiostream.h"

std::ostream& operator<<(std::ostream &os, const newiostream &obj) {
    obj.Print(os);
    return os;
}

std::ostream& operator<<(std::ostream &os, const newiostream *obj) {
    obj->Print(os);
    return os;
}

newiostream::~newiostream() = default;