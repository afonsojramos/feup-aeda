#pragma once

#include "User.h"
#include "Vehicle.h"
#include "Route.h"

class Session {
private:
	static Session* singleton_instance;

public:
	static Session* instance();
	/*
	Singleton, apenas uma instancia��o de Session permitida.
	Para aceder a uma fun��o desta classe, usar p.e., Session::instance()->importDistricts();
	*/
	
	vector<Registered> registered;
	vector<string> districts;
	string username;

	bool importUsers();
	bool importDistricts();
	
	void login();
	void registration();
	string passwordMaker();
};