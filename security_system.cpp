#include <iostream>  // Includes standard input-output library
#include <fstream>   // Includes file handling library
#include <sstream>   // Includes string stream library for processing strings
#include <string>    // Includes string library for string handling

using namespace std;  // Standard namespace for convenience

int main() {
    int a, i = 0;  // `a` for user choice, `i` for indexing arrays
    string text, old, password1, password2, pass, name, password0, age, address, user, word, word1;
    // Variables for user inputs, file processing, and temporary storage
    string creds[2], cp[2];  // Arrays to store username and password from file

    // Display the system title
    cout << "    Security System " << endl;

    // Display the menu options
    cout << "_____________________________" << endl;
         
    cout << "|          1.Register        |" << endl;
    cout << "|          2.Login           |" << endl;
    cout << "|          3.Change password |" << endl;
    cout << "|_________ 4.End Program_____|" << endl;
        

    do {
        cout << endl;
             
        cout << "Enter your choice:- ";
        cin >> a;  // Takes user's choice as input

        switch (a) {
            case 1: {  // Register case
                cout << "_________________________________" << endl;
                   
                cout << "|-----------Register-------------" << endl;
                cout << "|________________________________" << endl;
                cout << "Please enter username:- ";
                cin >> name;  // Takes username input
                cout << "Please enter the password:- " << "\n";
                cin >> password0;  // Takes password input
                cout << "Please enter your age:- " << "\n";
                cin >> age;  // Takes age input
                cout << "Please enter your address:- " << "\n";
                cin >> address;  // Takes address input

                // Open file to save registration details
                ofstream of1;
                of1.open("File.txt");
                if (of1.is_open()) {  // Checks if file is successfully opened
                    of1 << name << "\n";  // Write username to file
                    of1 << password0;  // Write password to file
                    cout << "Registration successful" << endl;  // Confirmation message
                }
                of1.close();  // Close the file
                break;
            }
            case 2: {  // Login case
                i = 0;  // Reset index
                cout << "_________________________________|" << endl;
             
                cout << "|-----------Login----------------|" << endl;
                 
                cout << "|________________________________|" << endl;
                 
                ifstream of2;  // Input file stream
                of2.open("File.txt");
                cout << "Please enter the username:-  ";
                cin >> user;  // Takes username input
                cout << "Please enter the password:- ";
                cin >> pass;  // Takes password input
                if (of2.is_open()) {  // Checks if file is successfully opened
                    while (getline(of2, text)) {  // Read file line by line
                        istringstream iss(text);  // Create string stream from line
                        iss >> word;  // Extract word from the line
                        creds[i] = word;  // Store in array
                        i++;  // Increment index
                    }
                    of2.close();  // Close the file

                    if (user == creds[0] && pass == creds[1]) {  // Validate credentials
                        cout << "---Log in successful----";
                        cout << endl << endl;

                        // Display user details
                        cout << " Details: " << endl;
                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                        cout << "Address: " + address << endl;
                    } else {
                        cout << endl << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "|    1.Press 2 to login              |" << endl;
                        cout << "|    2.Press 3 to Change password    |" << endl;
                    }
                } else {
                    cout << "Error opening file!" << endl;  // Error if file can't be opened
                }
                break;
            }
            case 3: {  // Change password case
                i = 0;  // Reset index
                cout << "-----------Change password----------------" << endl;
                ifstream of0;  // Input file stream
                of0.open("File.txt");
                cout << "Enter the old password: ";
                cin >> old;  // Takes old password input
                if (of0.is_open()) {  // Checks if file is successfully opened
                    while (getline(of0, text)) {  // Read file line by line
                        istringstream iss(text);  // Create string stream from line
                        iss >> word1;  // Extract word from the line
                        cp[i] = word1;  // Store in array
                        i++;  // Increment index
                    }
                    of0.close();  // Close the file

                    if (old == cp[1]) {  // Validate old password
                        cout << "Enter your new password: ";
                        cin >> password1;  // Takes new password input
                        cout << "Enter your password again: ";
                        cin >> password2;  // Takes new password confirmation
                        if (password1 == password2) {  // Check if new passwords match
                            ofstream of1;  // Output file stream
                            of1.open("File.txt");
                            if (of1.is_open()) {  // Checks if file is successfully opened
                                of1 << cp[0] << "\n";  // Write username
                                of1 << password1;  // Write new password
                                of1.close();  // Close the file
                                cout << "Password change successful" << endl;
                            }
                        } else {
                            cout << "Passwords do not match!" << endl;
                        }
                    } else {
                        cout << "Old password is incorrect!" << endl;  // Error if old password is wrong
                    }
                } else {
                    cout << "Error opening file!" << endl;  // Error if file can't be opened
                }
                break;
            }
            case 4: {  // End program case
                cout << "_____________Thank you______________" << endl;
                break;
            }
            default:
                cout << "Enter a valid choice" << endl;  // Invalid input case
        }
    } while (a != 4);  // Continue until user chooses to end program
    return 0;  // Program terminates successfully
}
