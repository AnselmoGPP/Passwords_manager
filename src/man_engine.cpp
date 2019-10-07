#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "man_engine.hpp"

// Public members ------------------------------------------------

pass_manager_engine::pass_manager_engine(const char *file, char(*encrypt)(char), char(*decrypt)(char)) : file_name(file), encryptor(encrypt), decryptor(decrypt) {}

void pass_manager_engine::store(std::string name, std::string password, std::string user_name, std::string email)
{
    for(int i = 0; i < name.size(); i++) name[i] = std::tolower(name[i]);

    encrypt_string(name);
    encrypt_string(password);
    encrypt_string(user_name);
    encrypt_string(email);

    std::string new_data_line = name + '\n' + password + '\n' + user_name + '\n' + email + '\n';

    std::ofstream ofile(file_name, std::ofstream::app | std::ofstream::binary );
    if(ofile.is_open())
    {
        ofile << new_data_line;
        ofile.close();
    }
    else std::cout << "Cannot open file " << file_name << std::endl;
}

void pass_manager_engine::retrieve(std::string name)
{
    for(int i = 0; i < name.size(); i++) name[i] = std::tolower(name[i]);
    int line_position = 0;

    std::ifstream ifile(file_name, std::ifstream::binary);
    if(ifile.is_open())
    {
        std::string line, pass_name;

        while(std::getline(ifile, line))
        {
            if(line_position % 4) { ++line_position; continue; }     // Examine only the lines reffering to register names
            ++line_position;

            decrypt_string(line);
//std::cout << line << std::endl;
            if(line == name)                    // Return the associated password, user_name and email
            {
                std::cout << line << "\t";

                std::getline(ifile, line);
                decrypt_string(line);
                std::cout << line << "\t";

                std::getline(ifile, line);
                decrypt_string(line);
                std::cout << line << "\t";

                std::getline(ifile, line);
                decrypt_string(line);
                std::cout << line << "\t";

                std::cout << std::endl;

                ifile.close();

                return;
            }
        }

        std::cout << "Cannot find entry \"" << name << '\"' << std::endl;
        ifile.close();
    }
    else std::cout << "Cannot open file " << file_name << std::endl;
}

void pass_manager_engine::erase(std::string name)
{
    for(int i = 0; i < name.size(); i++) name[i] = std::tolower(name[i]);
    int line_position = 0;

    // Open a temporary file
    std::ofstream temp_file("temp_file.bin", std::ofstream::binary);
    if(!temp_file.is_open())
    {
        std::cout << "Cannot open a temporary file (temp_file.bin)" << std::endl;
        return;
    }

    // Open the main file and copy the data to the temporary file, except the register you want to erase
    bool data_founded = false;

    std::ifstream ifile(file_name, std::ifstream::binary);
    if(ifile.is_open())
    {
        std::string data, data_complete;
        std::stringstream sstr;

        while(std::getline(ifile, data))
        {
            if(data == name){
                std::getline(ifile, data);
                std::getline(ifile, data);
                std::getline(ifile, data);
                data_founded = true;
                continue;
            }
            else temp_file << data << '\n';
        }
        ifile.close();

    // Remove the main file and rename the temporary file like the main file.
        std::remove(file_name.c_str());
        std::rename("temp_file.bin", file_name.c_str());
        temp_file.close();

        if(!data_founded) std::cout << "Register \"" << name << "\" not founded" << std::endl;
    }
    else std::cout << "Cannot open file " << file_name << std::endl;
}

void pass_manager_engine::show_all()
{
    int line_position = 0;

    std::ifstream ifile(file_name, std::ifstream::binary);
    if(ifile.is_open())
    {
        std::string data;
        while(std::getline(ifile, data))
        {
            if(!(line_position % 4) && line_position != 0) std::cout << std::endl;
            ++line_position;

            decrypt_string(data);
            std::cout << data << "\t";
        }

        std::cout << std::endl;
        ifile.close();
    }
    else std::cout << "Cannot open file " << file_name << std::endl;
}

// Private members -----------------------------------------------

void pass_manager_engine::encrypt_string(std::string &str)
{
    for(int i = 0; i < str.size(); i++) str[i] = encryptor(str[i]);
}

void pass_manager_engine::decrypt_string(std::string &str)
{
    for(int i = 0; i < str.size(); i++) str[i] = decryptor(str[i]);
}
