#include <memory>
#include "catalog.h"
#include "no_student.h"

std :: vector <std :: shared_ptr<Person>> Catalog :: registry;

void Catalog::AddPerson(std::shared_ptr <Person> p)
{
    registry.push_back(p);
}

std::shared_ptr<Person> Catalog::findStudentByCNP(const std::string cnp)
{
    for(auto &it : Catalog :: registry)
    {
        if(it -> GetPersonType() == PersonType :: Student && it -> getCnp() == cnp)
        {
            return it;
        }
    }

    throw(NoSuchStudent());

    return std::shared_ptr<Person>();
    ///throw NoSuchStudent();
}

std::shared_ptr<Person> Catalog::findAccountByUser(const std::string username)
{
    for(auto &it : Catalog :: registry)
    {
        if(it -> GetPersonType() == PersonType :: Account)
        {
            auto acc = std ::dynamic_pointer_cast<Account>(it);
            if(acc -> getUsername() == username)
            {
                return it;
            }
        }
    }

    return std::shared_ptr<Person>();
}

std :: shared_ptr<Person> Catalog ::findAccountByCNP(const std::string cnp)
{
    for(auto &it : Catalog :: registry)
    {
        if(it -> GetPersonType() == PersonType :: Account)
        {
            auto acc = std::dynamic_pointer_cast<Account>(it);
            if(acc -> getCnp() == cnp)
            {
                return it;
            }
        }
    }

    return std :: shared_ptr<Person>();
}
