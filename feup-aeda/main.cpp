#include <iostream>
#include <fstream>
#include <windows.h>
#include "header.h"
#include "utilities.h"
using namespace std;

Utilities util;
vector<string> districts;

//Testing main.cpp push.

void loadDistrictVector(){
	fstream f;

	f.open("src\\districts.txt");
	string token;

	while(!f.eof()){
		getline(f, token);
		districts.push_back(token);
	}
	f.close();
	return;
}

bool hasWhitespace(string s) {
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == ' ')
			return true;
	}
	return false;
}

string passwordMaker() {
	string password, test1, test2;
	bool loop = true;
	while (loop) {
		cin.clear();
		cout << "Password: ";
		cin >> test1;
		if (test1.size() < 5)
			cout << "ERROR: Passwords too short. Please try again\n";
		else if (hasWhitespace(test1))
			cout << "ERROR: Passwords do not support white spaces. Please try again\n";
		else {
			cout << "Confirm password: ";
			cin >> test2;
			if (test1 == test2) {
				password = test1;
				loop = false;
			} else {
				cout << "ERROR: Passwords do not match. Please try again\n";
			}
		}
	}
	return password;
}

int hostJourney(){
	bool loop = true;
	string stop;
	string username = "zepedrob16"; //test
	Route a(username);
	cout << "Please add the stops you intend to go through. Type in 'done' when you're finished. ";
	while (loop){
		getline(cin, stop);
		if (stop == "done") {
				loop = false;
				break;
		}
		for (size_t i = 0; i < districts.size(); i++) {
			if (districts[i] == stop) {
				a.addStops(stop);
			}
			else if (i + 1 == districts.size()){
				cout << "That stop does not exist in the system data, please try again";
			}
		}
	}
	return 0;
}


int login() { //Don't know how to check if the username and password are a match for a user - Guardar num ficheiro e procurar?
	string username, password;
	cout << "Type in your username: ";
	cin >> username;
	cout << "Type in your password: ";
	cin >> password;
	return 0;
}

int registration() {
	string name, username, password;
	unsigned int age;
	cout << "*Fancy introduction to our system*\n";
	cout << "Name: ";
	getline(cin, name);
	cout << "Age: ";
	cin >> age;
	cout << "Username: ";
	cin >> username;
	password = passwordMaker();
	cout << "User created with success!\n";
	Registered member(name, age, username, password);
	return 0;
}

unsigned int menu1(){
	unsigned int choice = 1;

	util.hideCursor();
	cout << "\n  "; util.whiteBG(); cout << "1. Register\n"; util.blackBG();
	cout << "  2. Login\n";
	cout << "  3. Login as guest\n";

	while (!GetAsyncKeyState(VK_RETURN) && !GetAsyncKeyState(VK_SPACE)){
		if (GetAsyncKeyState(VK_DOWN) && choice == 1){
			system("cls");

			cout << "\n  1. Register\n";
			cout << "  "; util.whiteBG(); cout << "2. Login\n"; util.blackBG();
			cout << "  3. Login as guest\n";
			choice = 2;
		}
		else if (GetAsyncKeyState(VK_UP) && choice == 2){
			system("cls");

			cout << "\n  "; util.whiteBG(); cout << "1. Register\n"; util.blackBG();
			cout << "  2. Login\n";
			cout << "  3. Login as guest\n";
			choice = 1;
		}
		else if (GetAsyncKeyState(VK_UP) && choice == 3){
			system("cls");

			cout << "\n  1. Register\n";
			cout << "  "; util.whiteBG(); cout << "2. Login\n"; util.blackBG();
			cout << "  3. Login as guest\n";
			choice = 2;
		}
		else if (GetAsyncKeyState(VK_DOWN) && choice == 2){
			system("cls");

			cout << "\n  1. Register\n";
			cout << "  2. Login\n";
			cout << "  "; util.whiteBG(); cout << "3. Login as guest\n"; util.blackBG();
			choice = 3;
		}
		Sleep(120);
	}
	util.showCursor();
	return choice;
}

int main() {
	menu1();
	registration();
	loadDistrictVector();

	return 0;
}
