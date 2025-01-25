# Security System

This is a simple console-based Security System program implemented in C++. The program allows users to register, log in, and change their passwords, storing user data in a text file.

## Features

1. **Register**: Create a new account by providing a username, password, age, and address.
2. **Login**: Access the system by verifying credentials stored in the file.
3. **Change Password**: Update the password for an existing account after verifying the old password.
4. **Exit**: Safely terminate the program.

## Prerequisites

- A C++ compiler (e.g., g++, MSVC, etc.).
- Basic understanding of C++ and file handling.

## Files Used

- `File.txt`: Stores user credentials (username and password) in plaintext format.

## How to Run

1. Copy the code into a file named `security_system.cpp`.
2. Compile the program using a C++ compiler:
   ```bash
   g++ -o security_system security_system.cpp
   ```
3. Run the compiled program:
   ```bash
   ./security_system
   ```

## Program Workflow

1. **Main Menu**:
   - Displays options to register, log in, change password, or exit the program.
2. **Register**:
   - Prompts the user to enter a username, password, age, and address.
   - Saves the username and password to `File.txt`.
   - Displays a success message.
3. **Login**:
   - Prompts the user to enter a username and password.
   - Validates credentials against the data in `File.txt`.
   - If successful, displays the user's details.
   - If unsuccessful, provides options to retry or change the password.
4. **Change Password**:
   - Prompts the user to enter their old password.
   - If the old password matches, allows the user to set a new password.
   - Updates the password in `File.txt`.
5. **Exit**:
   - Ends the program with a thank-you message.

## Code Structure

### Libraries Used

- `#include <iostream>`: For input/output operations.
- `#include <fstream>`: For file handling.
- `#include <sstream>`: For processing strings.
- `#include <string>`: For working with string variables.

### Core Functions

- **Registration**:
  - Captures user data and saves it to a file.
  - Ensures the file opens successfully before writing.

- **Login**:
  - Reads credentials from the file and validates them against user input.

- **Change Password**:
  - Validates the old password.
  - Ensures the new password matches the confirmation.
  - Updates the file with the new password.

- **Main Menu**:
  - Displays available options and processes user input.

## Example Usage

### Registration
```
Enter your choice:- 1
Please enter username:- JohnDoe
Please enter the password:- password123
Please enter your age:- 25
Please enter your address:- 123 Main St
Registration successful
```

### Login
```
Enter your choice:- 2
Please enter the username:- JohnDoe
Please enter the password:- password123
---Log in successful----
Details:
Username: JohnDoe
Password: password123
Age: 25
Address: 123 Main St
```

### Change Password
```
Enter your choice:- 3
Enter the old password: password123
Enter your new password: newpassword456
Enter your password again: newpassword456
Password change successful
```

## Notes

- Ensure the `File.txt` file is writable in the program's directory.
- The program does not currently encrypt or hash passwords, so avoid using sensitive data.

## Future Improvements

1. Encrypt stored passwords for better security.
2. Add functionality to handle multiple user accounts.
3. Implement better error handling and input validation.
4. Enhance the user interface for better usability.

---

Developed with 💻 and 🧠 by Diptendu Nandi.
