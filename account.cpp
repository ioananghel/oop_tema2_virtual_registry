#include "account.h"
#include <string>

Account :: Account(const std::string &lastName, const std::string &firstName, const std::string &cnp, const std::string &registrationNumber, char sex, const std :: string username, std :: string passwd) :
        Person(lastName, firstName, cnp, registrationNumber, sex), username(username), passwd(passwd) {}

const std::string &Account::getUsername() const
{
    return username;
}

const std::string &Account::getPasswd() const
{
    return passwd;
}

void Account::setUsername(const std::string &username)
{
    Account::username = username;
}

void Account::setPasswd(const std::string &passwd)
{
    Account::passwd = passwd;
}

Account :: Account(const Account &rhs) : Person(rhs.getLastName(), rhs.getFirstName(), rhs.getCnp(), rhs.getRegistrationNumber(), rhs.getSex())
{
    username = rhs.username;
    passwd = rhs.passwd;
}

void Account::Print(std::ostream &os) const
{
    os << "Account(" << getLastName() << ", " << getFirstName() << ", " << getCnp() << ", " << getRegistrationNumber() << ", " << getSex() << ", " << getUsername() << ", " << getPasswd() << ")";
}

Account::~Account() = default;

Account :: Account() = default;

