#ifndef OOP_TEMA2_REDONE_NEWIOSTREAM_H
#define OOP_TEMA2_REDONE_NEWIOSTREAM_H

#include <iostream>

class newiostream {
protected:
    virtual void Print(std::ostream &) const = 0;

    friend std::ostream& operator<<(std::ostream &, const newiostream&);
    friend std::ostream& operator<<(std::ostream &, const newiostream*);

    virtual ~newiostream();
};

#endif //OOP_TEMA2_REDONE_NEWIOSTREAM_H
