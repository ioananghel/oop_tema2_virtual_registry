#include <iostream>
#include <memory>
#include "person.h"
#include "student.h"
#include "account.h"
#include "catalog.h"

///de implementat no such student --> exeptie in catalog.cpp

void logged_in(std :: shared_ptr<Student> stud)
{
    std :: cout << "hai cu tataa" << stud -> getLastName();
    while(true)
    {
        std :: cout << "Alegeti o actiune:\n1.Vizualizare note\n2.Exit";
        int action;
        fflush(stdin);

        std :: cin >> action;
        switch (action)
        {
            case 1:
            {
                std :: vector<int>v = stud -> getGrades();
                for(auto it : v)
                {
                    std :: cout << it << " ";
                }
                break;
            }
            case 2:
            {
                return;
            }
            default:
            {
                std :: cout << "Alegeti o varianta din lista";
                break;
            }
        }
    }
}

void admin_logged_in()
{
    std :: cout << "\nBine ai venit, Admin01! ";
    while(true)
    {
        std::cout << "Ce actiune ai dori sa urmezi:\n1. Adaugare student;\n2. Adaugare Note;\n3. Vizualizare Note;" << std::endl;

        int action;
        std::cin >> action;

        switch (action)
        {
            case 1:
            {
                std::cout << "Introduceti urmatoarele date:\n";
                std::string buff_last_name, buff_first_name, buff_cnp, buff_reg_nr;
                char buff_sex;
                std::cout << "Nume: ";
                fflush(stdin);
                std::cin >> buff_last_name;

                std::cout << "Prenume: ";
                fflush(stdin);
                std::cin >> buff_first_name;

                std::cout << "CNP: ";
                fflush(stdin);
                std::cin >> buff_cnp;

                std::cout << "Numar matricol: ";
                fflush(stdin);
                std::cin >> buff_reg_nr;

                std::cout << "Sex (m/f): ";
                fflush(stdin);
                std::cin >> buff_sex;

                auto temp_stud = std ::make_shared<Student>(buff_last_name, buff_first_name, buff_cnp, buff_reg_nr, buff_sex);
                Catalog ::AddPerson(temp_stud);

                std :: shared_ptr<Person> yep = Catalog ::findAccountByUser("ioan");
                std :: cout << yep -> getCnp();
//                std :: shared_ptr<Student> p = std::dynamic_pointer_cast<Student>(yep);
//                std :: cout << int(p ->GetPersonType() == PersonType :: Student);
            }
        }
    }

}

int main()
{
//    Person p("anghel", "ioan", "404", "7/2021", 'm');
//
//    std :: cout << p.getLastName() << " " << p.getFirstName() << " " << p.getCnp() << " " << p.getRegistrationNumber() << " " << p.getSex();
//
//    std :: vector<int> v = {10, 10};
//
//    Student stud("anghel", "ioan", "404", "7/2021", 'm');
//    stud.setGrades(v);
//
//    Student st;
//
//    st = stud;
//
//    std :: cout << st.getLastName() << " " << st.getFirstName() << " " << st.getCnp() << " " << st.getRegistrationNumber() << " " << st.getSex();
//    std :: cout << "woah\n";
//    std :: cout << st;
//
//    std :: vector<int> check;
//    check = st.getGrades();

//    for(auto it : check)
//    {
//        std :: cout << it << " ";
//    }
//
//    Account eu("anghel", "ioan", "404", "7/2021", 'm', "ioan_anghel", "pass");
//
//    std :: cout << eu.getLastName() << " " << eu.getFirstName() << " " << eu.getCnp() << " " << eu.getRegistrationNumber() << " " << eu.getSex() << " " << eu.getUsername() << " " << eu.getPasswd();
//    std :: cout << "\nwoaj\n";
//    std :: cout << eu;
//
//    std :: cout << "siu\n";

//    Account cop;
//    cop = eu;
//    std :: cout << cop.getLastName() << " " << cop.getFirstName() << " " << cop.getCnp() << " " << cop.getRegistrationNumber() << " " << cop.getSex() << " " << cop.getUsername() << " " << cop.getPasswd();
//    Student stud;
//    Account acc;
//
//    if(stud.GetPersonType() == PersonType :: Student)
//    {
//        std :: cout << "siu";
//    }
//    else
//    {
//        std :: cout << "nono";
//    }
//
//    if(acc.GetPersonType() == PersonType :: Account)
//    {
//        std :: cout << "yeye";
//    }
//    else
//    {
//        std :: cout << "bruh";
//    }

    int stud_nr;
    std :: cout << "Introduceti numarul de studenti: ";
    fflush(stdin);
    std :: cin >> stud_nr;

    std :: cout << "================CATALOG VIRTUAL================\n";

    while(true)
    {
        int action;
        std :: cout << "\nCe actiune ati dori sa urmati?\n1. Log in;\n2. Creare cont;\n3.Exit" << std :: endl; ///automatic fflush with endl
        std :: cin >> action;

        switch(action)
        {
            case 1:
            {
                std :: string buff_user, buff_pass;
                std :: cout << "Username: ";
                fflush(stdin);
                std :: cin >> buff_user;
                std :: cout << "Password: ";
                fflush(stdin);
                std :: cin >> buff_pass;

                if(buff_user == "Admin01" && buff_pass == "Admin01pa55")
                {
                    std :: cout << "\nBine ai venit, Admin01! ";
                    while(true)
                    {
                        std::cout << "Ce actiune ai dori sa urmezi:\n1. Adaugare student;\n2. Adaugare Note;\n3. Vizualizare Note;\n4. Exit;" << std::endl;

                        int action;
                        std::cin >> action;

                        switch (action)
                        {
                            case 1:
                            {
                                std::cout << "Introduceti urmatoarele date:\n";
                                std::string buff_last_name, buff_first_name, buff_cnp, buff_reg_nr;
                                char buff_sex;
                                std::cout << "Nume: ";
                                fflush(stdin);
                                std::cin >> buff_last_name;

                                std::cout << "Prenume: ";
                                fflush(stdin);
                                std::cin >> buff_first_name;

                                std::cout << "CNP: ";
                                fflush(stdin);
                                std::cin >> buff_cnp;

                                std::cout << "Numar matricol: ";
                                fflush(stdin);
                                std::cin >> buff_reg_nr;

                                std::cout << "Sex (m/f): ";
                                fflush(stdin);
                                std::cin >> buff_sex;

                                auto temp_stud = std ::make_shared<Student>(buff_last_name, buff_first_name, buff_cnp, buff_reg_nr, buff_sex);
                                Catalog ::AddPerson(temp_stud);
                                break;
                            }
                            case 2:
                            {
                                std :: cout << "Introduceti CNP-ul studentului caruia doriti sa ii aplicati modificarile: ";
                                fflush(stdin);

                                std :: string buff_cnp;
                                std :: cin >> buff_cnp;

                                std :: shared_ptr<Person> pers = Catalog ::findStudentByCNP(buff_cnp);
                                std :: shared_ptr<Student> stud = std ::dynamic_pointer_cast<Student>(pers);

                                std :: cout << "Introduceti numarul de note si acestea: ";
                                fflush(stdin);

                                int n;
                                std :: vector<int> v;

                                std :: cin >> n;

                                for(int i = 0; i < n; i++)
                                {
                                    int a;
                                    std :: cin >> a;
                                    v.push_back(a);
                                }

                                stud -> setGrades(v);

//                                v = stud -> getGrades();
//
//                                for(auto it : v)
//                                {
//                                    std :: cout  << it;
//                                }
                                break;
                            }
                            case 3:
                            {
                                std :: cout << "Introduceti CNP-ul studentului pentru care doriti sa vizualizati notele: ";
                                fflush(stdin);

                                std :: string buff_cnp;
                                std :: cin >> buff_cnp;

                                std :: shared_ptr<Person> pers = Catalog ::findStudentByCNP(buff_cnp);
                                std :: shared_ptr<Student> stud = std ::dynamic_pointer_cast<Student>(pers);

                                std :: vector<int> v = stud -> getGrades();

                                for(auto it : v)
                                {
                                    std :: cout << it << " ";
                                }

                                break;
                            }
                            case 4:
                                goto exit;
                        }
                    }
                    exit:
                        continue;
                }

                else
                {
                    std::shared_ptr<Person> pers = Catalog::findAccountByUser(buff_user);
                    std::shared_ptr<Account> acc = std::dynamic_pointer_cast<Account>(pers);
                    std::cout << "\nacc cnp: " << acc->getCnp();

                    if (acc->getPasswd() == buff_pass) {
                        pers = Catalog::findStudentByCNP(acc->getCnp());
                        std::shared_ptr<Student> stud = std::dynamic_pointer_cast<Student>(pers);

                        std::cout << "\nstud cnp" << stud->getCnp() << "\n";

                        logged_in(stud);
                    }
                }
                break;
            }
            case 2:
            {
                std :: cout << "Buna ziua! Pentru a va creea un cont, introduceti va rog urmatoarele date:\n";
                std :: string buff_last_name, buff_first_name;
                std :: cout << "Nume: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_last_name);
                std :: cout << "Prenume: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_first_name);
                fflush(stdin);

                std :: string buff_cnp, buff_registration_number, buff_user, buff_passwd;
                char buff_sex;
                std :: cout << "CNP: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_cnp);
                std :: cout << "Numar matricol: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_registration_number);
                std :: cout << "Sex (m/f): ";
                fflush(stdin);
                std :: cin >> buff_sex;
                std :: cout << "User Name: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_user);
                std :: cout << "Parola: ";
                fflush(stdin);
                std :: getline(std :: cin, buff_passwd);
                fflush(stdin);

                auto temp_acc = std ::make_shared<Account>(buff_last_name, buff_first_name, buff_cnp, buff_registration_number, buff_sex, buff_user, buff_passwd);
                Catalog :: AddPerson(temp_acc);
                break;

//                std :: shared_ptr<Person> yep = Catalog ::findAccountByUser("ioan");
//                std :: cout << yep -> getCnp();
//                std :: shared_ptr<Account> p = std::dynamic_pointer_cast<Account>(yep);
//                std :: cout << p ->getPasswd();
            }
            case 3:
            {
                return 0;
            }
            default:
                std :: cout << "Alegeti una dintre optiunile afisate!";
        }
    }

    return 0;
}