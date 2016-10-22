#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Vehicle;

class User{
protected:
	string name;
	unsigned int age; //Age is needed to know if the user is old enough to drive(host a trip)
public:
	User(string name, unsigned int age);
	unsigned int getAge();
	string getName();
};

class Registered : public User{
private:
	string username, password;//, name
	unsigned int age;
	bool ownership; //has registered car
	vector<Vehicle> garage;
	vector<vector<string>> trips; //vector with all registered trips.
	vector<Registered> users;
public:
	Registered(string name, unsigned int age, string username, string password);
	string getUsername();
	string getPassword();
	void addUser(Registered a);
	vector <Registered> getUsers();
};

class Guest : public User{
};
