Security System GUI - SFML

This is a simple Security System implemented with a graphical user interface (GUI) using SFML (Simple and Fast Multimedia Library). The system allows users to register, log in, and change passwords.
Features:

    Register: Allows users to create a new account with a username, password, age, and address.
    Login: Enables users to log into the system using their registered username and password.
    Change Password: Lets users change their password after logging in.
    End Program: Closes the program.

Prerequisites:

    C++17 or later
    SFML 2.5 (System, Window, and Graphics components)
    A Linux-based OS with access to DejaVuSans font or any alternative font.

Installation Instructions
1. Install SFML:

If SFML is not already installed on your system, you can install it by following the instructions on the SFML website.

    For Ubuntu/Debian-based systems:

sudo apt-get install libsfml-dev

For Fedora:

sudo dnf install sfml-devel

For macOS (using Homebrew):

    brew install sfml

2. Clone the Repository:

Clone the project repository to your local machine:

git clone <repository-url>
cd SecuritySystemGUI

3. Build the Project:

    Create the build directory:

mkdir build
cd build

Run CMake to configure the project:

cmake ..

Compile the project:

    make

4. Run the Application:

Once the project is built successfully, you can run the program using the following command:

./SecuritySystemGUI

5. Font Setup:

Ensure the font DejaVuSans-Bold.ttf is located at /usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf on your system. If not, you can modify the path in the code to a font available on your machine.
Project Structure:

SecuritySystemGUI/
│
├── CMakeLists.txt           # CMake build configuration
├── main.cpp                 # Main program file containing logic for the security system
├── README.md                # Project documentation
└── File.txt                 # A simple text file used for storing user credentials (username, password, etc.)

File Format (File.txt):

This file is used to store user credentials in the following format:

<username>
<password>
<age>
<address>

Notes:

    This project demonstrates basic SFML GUI components (e.g., buttons, text rendering) and simple file handling in C++.
    The current password handling is stored in plain text in File.txt. This is for demonstration purposes, and it's not recommended for production use. You should use encryption or hashing mechanisms for secure password storage in real-world applications.

License:

This project is open source and released under the MIT License.
