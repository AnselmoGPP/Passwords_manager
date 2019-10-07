#ifndef AUX_HPP
#define AUX_HPP

#include <iostream>
#include <cmath>

#include "man_engine.hpp"

#define PASS "mypass"
#define FILENAME "pass_data.bin"

char encryptor(char ch){
    //ch *= ch;
    //ch += 7;
    //ch *= 2;
    return ch;
}

char decryptor(char ch){
    //ch /= 2;
    //ch -= 7;
    //ch = std::sqrt(ch);
    return ch;
}

void passwords_manager(){

    std::cout << "\n>>>  Welcome to the Hans-Passwords-Manager  <<<\n" << std::endl;

    // Enter the password for being able to use the "passwords manager"
    std::string manager_pass;
    do
    {
        std::cout << "Enter password: ";
        std::getline(std::cin, manager_pass);
    }
    while(manager_pass != PASS);

    // Select an option from the main menu
    int selection = 0;
    std::string name, pass, user, mail;
    pass_manager_engine manager(FILENAME, &encryptor, &decryptor);

    while(1)
    {
        std::cout   << "\n\t1 - Retrieve register"
                    << "\n\t2 - Store new register"
                    << "\n\t3 - Erase existing register"
                    << "\n\t4 - Show all registers"
                    << "\n\t0 - Exit" << std::endl
                    << "\nEnter selection: ";

        std::cin >> selection;
        std::cin.ignore(); std::cin.clear();

        switch(selection)
        {
        case 0:
            return;
        case 1:
            std::cout << "Enter register name: ";
            std::getline(std::cin, name);
            manager.retrieve(name);
            break;
        case 2:
            std::cout << "Enter register name: ";
            std::getline(std::cin, name);   std::cout << name << std::endl;
            std::cout << "Enter password: ";
            std::getline(std::cin, pass);   std::cout << pass << std::endl;
            std::cout << "Enter user name: ";
            std::getline(std::cin, user);   std::cout << user << std::endl;
            std::cout << "Enter e-mail: ";
            std::getline(std::cin, mail);
            manager.store(name, pass, user, mail);
            manager.retrieve(name);
            break;
        case 3:
            std::cout << "Enter register name: ";
            std::getline(std::cin, name);
            manager.erase(name);
            break;
        case 4:
            manager.show_all();
            break;
        default:
            std::cout << "Option not available" << std::endl;
            break;
        }
    }
}

void testing()
{
    std::string name[4] =       {"name 1", "name 2", "name 3", "name 4" };
    std::string password[4] =   {"pass 1", "pass 2", "pass 3", "pass 4" };
    std::string user_name[4] =  {"user 1", "user 2", "user 3", "user 4" };
    std::string email[4] =      {"mail 1", "mail 2", "mail 3", "mail 4" };

    // Create a passwords manager object and pass the name of the file where to save your passwords, a pointer to the encrypter function and a pointer to the decrypter function (both functions encrypt one char).
    pass_manager_engine manager("pass.bin", &encryptor, &decryptor);

    // Store some registers (one register is composed of 4 elements: register name, password, user name, e-mail)
    for(int i = 0; i < 4; i++)
        manager.store(name[i], password[i], user_name[i], email[i]);

    // Show all the register that are in your file
    std::cout << "show_all():" << std::endl;
    manager.show_all();

    // Search for the register "name 3"
    std::cout << std::endl << "retrieve(\"name 3\"):" << std::endl;
    manager.retrieve("name 3");

    // Delete register "name 2"
    manager.erase("name 2");
    std::cout << std::endl << "erase(\"name 2\"):" << std::endl;
    manager.show_all();
}

#endif
