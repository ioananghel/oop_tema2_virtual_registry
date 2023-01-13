#ifndef OOP_TEMA2_REDONE_ACCOUNT_H
#define OOP_TEMA2_REDONE_ACCOUNT_H

#include <string>
#include "person.h"
#include "get_type.h"
#include "cloning.h"
#include "assign_id.h"

class Account: public Person
{
private:
    std :: string id;
    std :: string username, passwd;

public:
    Account(const std::string &lastName, const std::string &firstName, const std::string &cnp, const std::string &registrationNumber, char sex, const std :: string username, std :: string passwd);
    Account();

    Account(const Account &rhs);

    void setUsername(const std::string &username);
    void setPasswd(const std::string &passwd);

    const std::string &getUsername() const;
    const std::string &getPasswd() const;

    void Print(std::ostream&) const override;

    PersonType GetPersonType() const override { return PersonType::Account; }

    std::string getId() const override { return username; }

    virtual Account* clone() const
    {
        return (new Account(*this));
    }

    ~Account() override;
};

#endif //OOP_TEMA2_REDONE_ACCOUNT_H
