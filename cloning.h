#ifndef OOP_TEMA2_REDONE_CLONING_H
#define OOP_TEMA2_REDONE_CLONING_H

///clasa virtuala cloning

struct cloning
{
    virtual ~cloning() {}
    virtual cloning* clone() const = 0;
};

#endif //OOP_TEMA2_REDONE_CLONING_H
