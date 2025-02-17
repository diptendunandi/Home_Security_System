#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class SecuritySystemGUI {
public:
    SecuritySystemGUI() : window(sf::VideoMode(800, 600), "Security System") {
        // Set up font (using DejaVuSans from system font path)
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Failed to load font!" << std::endl;
        }

        // Title text
        title.setFont(font);
        title.setString("Security System");
        title.setCharacterSize(30);
        title.setFillColor(sf::Color::White);
        title.setPosition(300, 20);

        // Menu buttons
        registerButton.setFont(font);
        registerButton.setString("1. Register");
        registerButton.setCharacterSize(20);
        registerButton.setFillColor(sf::Color::Green);
        registerButton.setPosition(50, 100);

        loginButton.setFont(font);
        loginButton.setString("2. Login");
        loginButton.setCharacterSize(20);
        loginButton.setFillColor(sf::Color::Green);
        loginButton.setPosition(50, 150);

        changePassButton.setFont(font);
        changePassButton.setString("3. Change Password");
        changePassButton.setCharacterSize(20);
        changePassButton.setFillColor(sf::Color::Green);
        changePassButton.setPosition(50, 200);

        endButton.setFont(font);
        endButton.setString("4. End Program");
        endButton.setCharacterSize(20);
        endButton.setFillColor(sf::Color::Green);
        endButton.setPosition(50, 250);

        // Initialize the system
        initializeSystem();
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Handle mouse clicks
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (registerButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        handleRegister();
                    }
                    else if (loginButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        handleLogin();
                    }
                    else if (changePassButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        handleChangePassword();
                    }
                    else if (endButton.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                        window.close();
                    }
                }
            }

            window.clear();
            window.draw(title);
            window.draw(registerButton);
            window.draw(loginButton);
            window.draw(changePassButton);
            window.draw(endButton);
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text title, registerButton, loginButton, changePassButton, endButton;

    void initializeSystem() {
        // Initialize any necessary variables here
    }

    void handleRegister() {
        string name, password0, age, address;
        sf::Text inputText;
        inputText.setFont(font);
        inputText.setCharacterSize(20);
        inputText.setFillColor(sf::Color::White);
        inputText.setPosition(50, 300);

        // Collect registration details (dummy input prompt for simplicity)
        cout << "Enter username: ";
        cin >> name;
        cout << "Enter password: ";
        cin >> password0;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter address: ";
        cin >> address;

        // Save user details to file
        ofstream file("File.txt");
        if (file.is_open()) {
            file << name << "\n" << password0 << "\n" << age << "\n" << address;
            file.close();
            cout << "Registration Successful!" << endl;
        }
    }

    void handleLogin() {
        string name, password, storedName, storedPassword;
        cout << "Enter username: ";
        cin >> name;
        cout << "Enter password: ";
        cin >> password;

        // Read the file to get stored credentials
        ifstream file("File.txt");
        if (file.is_open()) {
            getline(file, storedName);
            getline(file, storedPassword);
            file.close();

            if (name == storedName && password == storedPassword) {
                cout << "Login successful!" << endl;
                cout << "Welcome, " << storedName << "!" << endl;
            } else {
                cout << "Invalid credentials!" << endl;
            }
        } else {
            cout << "Error reading file!" << endl;
        }
    }

    void handleChangePassword() {
        string oldPassword, newPassword, newPasswordConfirm;
        string storedPassword;
        
        cout << "Enter your old password: ";
        cin >> oldPassword;

        ifstream file("File.txt");
        if (file.is_open()) {
            // Read the stored password from the file
            string tempName;
            getline(file, tempName);
            getline(file, storedPassword);
            file.close();

            if (oldPassword == storedPassword) {
                cout << "Enter your new password: ";
                cin >> newPassword;
                cout << "Confirm your new password: ";
                cin >> newPasswordConfirm;

                if (newPassword == newPasswordConfirm) {
                    // Save the new password
                    ofstream file("File.txt");
                    if (file.is_open()) {
                        file << tempName << "\n" << newPassword;
                        file.close();
                        cout << "Password changed successfully!" << endl;
                    }
                } else {
                    cout << "Passwords do not match!" << endl;
                }
            } else {
                cout << "Old password is incorrect!" << endl;
            }
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

int main() {
    SecuritySystemGUI gui;
    gui.run();
    return 0;
}

