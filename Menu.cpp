#include "menu.h"

void logged_in(std :: shared_ptr<Student> stud)
{
    std :: cout << "\nBine ai venit, " << stud -> getLastName() << "\n";
    while(true)
    {
        std :: cout << "\nAlegeti o actiune:\n1.Vizualizare note\n2.Exit";
        int action;
        fflush(stdin);

        std :: cin >> action;
        switch (action)
        {
            case 1:
            {
                try
                {
                    std::vector<int> v = stud->getGrades();
                    for(auto it : v)
                    {
                        std :: cout << it << " ";
                    }
                }
                catch(const NoGrades &err)
                {
                    std :: cout << err;
                    continue;
                }

                break;
            }
            case 2:
            {
                return;
            }
            default:
            {
                std :: cout << "\nAlegeti o varianta din lista\n";
                break;
            }
        }
    }
}

void Menu ::Start()
{
    int stud_nr;
    std :: cout << "\nIntroduceti numarul de studenti: ";
    fflush(stdin);
    std :: cin >> stud_nr;

    std :: cout << "\n================CATALOG VIRTUAL================\n";

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
                    std :: cout << "\nBine ai venit, Admin01! \n";
                    while(true)
                    {
                        std::cout << "\nCe actiune ai dori sa urmezi:\n1. Adaugare student;\n2. Adaugare Note;\n3. Vizualizare Note;\n4. Exit;" << std::endl;

                        int action;
                        std::cin >> action;

                        switch (action)
                        {
                            case 1:
                            {
                                std::cout << "\nIntroduceti urmatoarele date:\n";
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
                                std :: cout << "\nIntroduceti CNP-ul studentului caruia doriti sa ii aplicati modificarile: ";
                                fflush(stdin);

                                std :: string buff_cnp;
                                std :: cin >> buff_cnp;

                                std :: shared_ptr<Person> pers = Catalog ::findStudentByCNP(buff_cnp);
                                std :: shared_ptr<Student> stud = std ::dynamic_pointer_cast<Student>(pers);

                                std :: cout << "\nIntroduceti numarul de note si acestea: \n";
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

                                break;
                            }
                            case 3:
                            {
                                std :: cout << "\nIntroduceti CNP-ul studentului pentru care doriti sa vizualizati notele: ";
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
//                    std::cout << "\nacc cnp: " << acc->getCnp();

                    if (acc->getPasswd() == buff_pass) {
                        try
                        {
                            pers = Catalog::findStudentByCNP(acc->getCnp());
                            std::shared_ptr<Student> stud = std::dynamic_pointer_cast<Student>(pers);
                            std :: string buff_cnp = stud ->getCnp();
//                            std::cout << "\nstud cnp" << stud->getCnp() << "\n";
                            logged_in(stud);
                        }
                        catch(const NoSuchStudent &err)
                        {
                            std :: cout << err;
                            continue;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                std :: cout << "\nBuna ziua! Pentru a va creea un cont, introduceti va rog urmatoarele date:\n";
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
            }
            case 3:
            {
                return;
            }
            default:
                std :: cout << "\nAlegeti una dintre optiunile afisate!\n";
                fflush(stdin);
                break;
        }
    }
}