#ifndef OOP_TEMA2_REDONE_ASSIGN_ID_H
#define OOP_TEMA2_REDONE_ASSIGN_ID_H

#include <iostream>
#include <memory>
#include <typeinfo>

///o clasă șablon (template)
///o metodă șablon
///o metodă / clasă template specializată
///o clasă pentru generat IDuri pentru obiecte

template <typename T>
class ID
{
    static T Id;
public:
    static std :: string getId()
    {
        return "";
    }
};

template<> class ID<float>
{
    static float Id;
public:
    static std :: string getId()
    {
        return std :: to_string(Id++);
    }
};

template<> class ID<int>
{
    static int Id;
public:
    static std :: string getId()
    {
        return std :: to_string(Id++);
    }
};


#endif //OOP_TEMA2_REDONE_ASSIGN_ID_H
