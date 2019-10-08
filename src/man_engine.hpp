#ifndef PASS_M_ENG
#define PASS_M_ENG

#include <string>

class pass_manager_engine{

    std::string file_name;
    char (*encryptor)(char ch);             // Callback encryptor
    char (*decryptor)(char ch);             // Callback decryptor
    void encrypt_string(std::string &str);
    void decrypt_string(std::string &str);

public:
    pass_manager_engine(const char *file, char(*encrypt)(char), char(*decrypt)(char));

    void store(std::string name, std::string password, std::string user_name, std::string email);
    void retrieve(std::string name);
    void erase(std::string name);
    void show_all();

    int existing_register(std::string str);      // 0: Register doesn't exist.   1: Register exists.   2: Cannot open file for checking register existence
};

#endif
