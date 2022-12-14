#ifndef OOP_TEMA2_REDONE_CATALOG_H
#define OOP_TEMA2_REDONE_CATALOG_H

#include <memory>
#include "student.h"
#include "account.h"

class Catalog
{
private:
    static std :: vector <std :: shared_ptr <Person>> registry;

public:
    Catalog() = delete;

    static void AddPerson(std :: shared_ptr<Person> p);
    static std :: shared_ptr<Person> findStudentByCNP(const std :: string cnp);
    static std :: shared_ptr<Person> findAccountByUser(const std :: string username);
    static std :: shared_ptr<Person> findAccountByCNP(const std :: string cnp);
};

#endif //OOP_TEMA2_REDONE_CATALOG_H
