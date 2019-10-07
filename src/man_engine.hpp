#ifndef PASS_M_ENG
#define PASS_M_ENG

#include <string>

class pass_manager_engine{

    std::string file_name;
    char (*encryptor)(char ch);
    char (*decryptor)(char ch);
    void encrypt_string(std::string &str);
    void decrypt_string(std::string &str);

public:
    pass_manager_engine(const char *file, char(*encrypt)(char), char(*decrypt)(char));

    void store(std::string name, std::string password, std::string user_name, std::string email);
    void retrieve(std::string name);
    void erase(std::string name);
    void show_all();
};

#endif
