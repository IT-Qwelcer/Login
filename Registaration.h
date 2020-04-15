#pragma once
#include <iostream>
#include<string>
#include<iostream>
#include<string>
#include <fstream>
#include <list>

using namespace std;

struct user {

	std::string name;
	std::string gmail;
	std::string pasword;
};

int registration();
int Login();
int init();
int center();