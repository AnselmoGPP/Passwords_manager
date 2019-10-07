# Passwords manager

This is a "passwords manager" software for storing your passwords and the associated user names and emails (In reality, you can store whatever data you want). The thing is that each register is made of 4 strings (let's call them identifier, password, user name, and email). The first string serves as the identifier for that register. All these data are encrypted and saved in a file. 

In the main menu of the manager you will find 5 options:

- Retrieve existing register: Enter an identifier and get the other 3 associated data (password, user name, email) from the file.
- Store new register: Store a new register in the file. You have to specify the identifier, password, user name, and email.
- Erase existing register: Delete an existing register from the file. You have to specify the identifier.
- Show all data: Show all the data from the file.
- Exit: Close the passwords manager.

This program uses a "passwords manager engine" with is in the man_engine.hpp source file (class pass_manager_engine). You can use this engine for making your own passwords manager program if you want. Check the testing() function, in auxiliar.hpp, to learn more about this.

There are a set of elements in the source code (especifically, in auxiliar.hpp) that you can modify in order to personalize this passwords manager:

- Change the password of this manager: Modifiy the macro PASS
- Modify the name of the file where the data is stored: Modify the macro FILENAME
- Change the way each character is encrypted and decrypted: Modify the functions encryptor() (line 9) and decryptor() (line 16)
