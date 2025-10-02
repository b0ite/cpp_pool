/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igilbert <igilbert@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:57:25 by igilbert          #+#    #+#             */
/*   Updated: 2025/07/21 09:38:38 by igilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
	protected:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void setFirstName(const std::string &name) {
			firstName = name;
		}
		void setLastName(const std::string &name) {
			lastName = name;
		}
		void setNickname(const std::string &name) {
			nickname = name;
		}
		void setPhoneNumber(const std::string &number) {
			phoneNumber = number;
		}
		void setDarkestSecret(const std::string &secret) {
			darkestSecret = secret;
		}

		const std::string& getFirstName() const { return firstName; }
		const std::string& getLastName() const { return lastName; }
		const std::string& getNickname() const { return nickname; }
		const std::string& getPhoneNumber() const { return phoneNumber; }
		const std::string& getDarkestSecret() const { return darkestSecret; }
};

class PhoneBook {
	private:
		Contact contacts[8];
		int currentIndex;
		int count;

	public:
		PhoneBook() : currentIndex(0), count(0) {}
		
		void addContact(const Contact& contact) {
			contacts[currentIndex] = contact;
			currentIndex = (currentIndex + 1) % 8;
			if (count < 8) {
				count++;
			}
		}

		void getContact() {
			Contact newContact;
			std::string input;
			
			do {
				std::cout << "Enter first name: ";
				std::getline(std::cin, input);
				if (input.empty()) {
					std::cout << "Error: First name cannot be empty!" << std::endl;
				}
			} while (input.empty());
			newContact.setFirstName(input);
			
			do {
				std::cout << "Enter last name: ";
				std::getline(std::cin, input);
				if (input.empty()) {
					std::cout << "Error: Last name cannot be empty!" << std::endl;
				}
			} while (input.empty());
			newContact.setLastName(input);

			do {
				std::cout << "Enter nickname: ";
				std::getline(std::cin, input);
				if (input.empty()) {
					std::cout << "Error: Nickname cannot be empty!" << std::endl;
				}
			} while (input.empty());
			newContact.setNickname(input);

			do {
				std::cout << "Enter phone number: ";
				std::getline(std::cin, input);
				if (input.empty()) {
					std::cout << "Error: Phone number cannot be empty!" << std::endl;
				}
			} while (input.empty());
			newContact.setPhoneNumber(input);
			
			do {
				std::cout << "Enter his/her darkest secret 🤫: ";
				std::getline(std::cin, input);
				if (input.empty()) {
					std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
				}
			} while (input.empty());
			newContact.setDarkestSecret(input);

			addContact(newContact);
			std::cout << "Contact added successfully!" << std::endl;
		}
		
		Contact getContact(int index) const {
			if (index >= 0 && index < count)
				return contacts[index];
			return Contact();
		}

		std::string formatString(const std::string &input) const {
			if (input.length() > 10) {
				return input.substr(0, 9) + ".";
			}
			return input;
		}

		void printSearch() const {
			std::cout << std::setw(10) << "Index" << "|"
					  << std::setw(10) << "First Name" << "|"
					  << std::setw(10) << "Last Name" << "|"
					  << std::setw(10) << "Nickname" << std::endl;
			
			for (int i = 0; i < count; i++) {
				std::cout << std::setw(10) << i << "|"
						  << std::setw(10) << formatString(contacts[i].getFirstName()) << "|"
						  << std::setw(10) << formatString(contacts[i].getLastName()) << "|"
						  << std::setw(10) << formatString(contacts[i].getNickname()) << std::endl;
			}
		}
		
		void displayContact(int index) const {
			if (index >= 0 && index < count) {
				const Contact& contact = contacts[index];
				std::cout << "First Name: " << contact.getFirstName() << std::endl;
				std::cout << "Last Name: " << contact.getLastName() << std::endl;
				std::cout << "Nickname: " << contact.getNickname() << std::endl;
				std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
			} else {
				std::cout << "Invalid index!" << std::endl;
			}
		}
		
		int getCount() const {
			return count;
		}	
};

int main(){
	PhoneBook repertoire;
	std::string command;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		
		if (command == "ADD") {
			repertoire.getContact();
		}
		else if (command == "SEARCH") {
			if (repertoire.getCount() == 0) {
				std::cout << "No contacts available!" << std::endl;
			} else {
				repertoire.printSearch();
				std::cout << "Enter index to display: ";
				std::string indexStr;
				std::getline(std::cin, indexStr);
				
				try {
					int index = std::stoi(indexStr);
					repertoire.displayContact(index);
				} catch (const std::exception& e) {
					std::cout << "Invalid index!" << std::endl;
				}
			}
		}
		else if (command == "EXIT") {
			break;
		}
	}
	return (0);
}