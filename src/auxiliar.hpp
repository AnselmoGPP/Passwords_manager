#ifndef AUX_HPP
#define AUX_HPP

#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

#include "man_engine.hpp"

#define PASS "mypass"
#define FILENAME "pass_data.bin"

/*
unsigned char uchar_values[256] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255 };
signed char schar_valued[256] = { -128, -127, -126, -125, -124, -123, -122, -121, -120, -119, -118, -117, -116, -115, -114, -113, -112, -111, -110, -109, -108, -107, -106, -105, -104, -103, -102, -101, -100, -99, -98, -97, -96, -95, -94, -93, -92, -91, -90, -89, -88, -87, -86, -85, -84, -83, -82, -81, -80, -79, -78, -77, -76, -75, -74, -73, -72, -71, -70, -69, -68, -67, -66, -65, -64, -63, -62, -61, -60, -59, -58, -57, -56, -55, -54, -53, -52, -51, -50, -49, -48, -47, -46, -45, -44, -43, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33, -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127 };
*/
signed char schar_encryption_table[256] = { 10, 11, 12, -105, -99, -98, -26, -114, 17, 112, 107, -44, 20, 113, 65,  41, 66, 108, -101, 109, -47, 114, -6, 67, -38, -11, 64, -88, 14, -116, -4, -115, -97, -96, -36, -117, -33, 23, 61, -20, -55, -1, -58, -106, -67, -21, -122, -14, -54, 123, -18, 22, -112, 9, -92, -107, 75, -95,  -104, -79, 104, -32, -94, -29, 69, -28, -73, -72, -41, 24, -19, 0, -23, 15, -37, -31,  76, -110, -35, -25, 53, 84, 18, -77, -3, -81, -15, 116, -60, -126, 95, 60, 3, 117, 98, 54, 68, 57, -80, 1, 118, -5, -40, -27, 2, 121, 25, 85, -22, 127, 51, -83, 49, 36, 126, 31, 19, 91, 56, 93, -52, 50, 27, -71, 28, -17, -9, 26, 48, -84, 34, 105, 29, 70, -56, 30, 122, 35, -64, 96, 102, -78, 82, -89, 124, 125, -76, 52, 62, 63, 88, 6, -50, -111, -48, 5, 89, 33, -59, 55, 97, 38, 100, 40, -127, -43, 59, -103, -12, 106, 21, 58, 110, -49, 111, 42, -125, -124, -86, 115, -109, -10, -102, -100, -93, -74, -53, 92, -51, -46, 119, 72, 37, 73, -63, 77, 83, -91, 44, -70, -69, 43, 79, 45, 94, -68, -120, -66, -108, -34, 86, -121, 87, -16, -65, -128, 32, -62, 39, 120, -45, 71, -123, -119, -61, 80, -57, -42, -39, 78, 81, -87, -13, -7, 103, 4, 8, -90, -85, -82, -75, 101, -118, 46, 7, -113, 99, 47, 90, 13, 74, -2, -24, -30, -8, 16 };

char encryptor(char ch)
{
    return ch = schar_encryption_table[ch];
}

char decryptor(char ch)
{
    for(size_t i = 0; i < 256; i++)
    {
        if(ch == schar_encryption_table[i]) return i;
    }

    return '-';
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
    int reg_existence = 0;
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
            std::getline(std::cin, name);
            if(manager.existing_register(name)) break;
            std::cout << "Enter password: ";
            std::getline(std::cin, pass);
            std::cout << "Enter user name: ";
            std::getline(std::cin, user);
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

void testing_getArray()
{
    std::ofstream ofile("array.txt");
    std::stringstream stream;
    for(int i = -128; i < 128; i++) stream << i << ", ";
    ofile << stream.str();
    ofile.close();
}

#endif
