#include "Registaration.h"
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <fstream>
#include <list>

list<user>lisusers;
const string filname = "Uzers.txt";

int init()
{
	ifstream fin;
	fin.open(filname);

	bool isopen = fin.is_open();

	if (isopen == false) {

		//cout << "Error" << endl;
	}
	else {
		user tempuser;
		int count = 0;
		string temp;

		while (!fin.eof()) {
			count++;
			fin >> temp;

			if (count == 1) {

				tempuser.name = temp;
			}
			else if (count == 2) {

				tempuser.gmail = temp;
			}
			else if (count == 3) {

				tempuser.pasword = temp;
				lisusers.push_back(tempuser);
				count = 0;
			}
		}
	}

	return 0;
}

int center()
{
	init();
	int a;

	cout << "\n\t 1.Registration \n";
	cout << "\t 2.Login \n";
	cout << "\t 3.Exit \n";
	cout << "\n\t Selekt funktion -> ";
	do {
		cin >> a;
		switch (a)
		{
		case 1:
			registration();
			Login();
			break;
		case 2:
			Login();
			break;
		case 3:
			cout << "\n\t Bye! \n";
			break;
		}

	} while (a != 3);

	return 0;
}

int registration()
{
	system("cls");
	user newuser;

	cout << "\n\t Enter user name-> ";
	cin >> newuser.name;

	cout << "\n\t\t\t Enter user email-> ";
	cin >> newuser.gmail;

	cout << "\n\t\t Enter password-> ";
	cin >> newuser.pasword;
	system("cls");

	lisusers.push_back(newuser);
	cout << "\n\t Registrstion was secssesful! \n";
	ofstream fout;
	fout.open(filname, fstream::app);
	bool isopen = fout.is_open();

	if (isopen == false) {

		cout << "\n\t Eror file cant open... \n";
	}
	else {

		fout << newuser.name << endl;
		fout << newuser.gmail << endl;
		fout << newuser.pasword << endl;
		cout << endl;
	}

	return 0;
}

int Login()
{
	system("cls");
	int a;

	string login;
	string pasword;

	cout << "\n\t Enter your login-> ";
	cin >> login;
	cout << "\t --------------------------- \n\t\t Enter your pasword-> ";
	cin >> pasword;
	system("cls");

	for (user item : lisusers) {

		if (login == item.gmail && pasword == item.pasword) {

			cout << "\n\t Name-> " << item.name << endl;
			break;
		}
	}
	do {
		cout << "\n\t 1.Try agin \n";
		cout << "\t 2.Exit \n";
		cout << "\n\t Selekt funktion -> ";
		cin >> a;
		system("cls");

		switch (a)
		{
		case 1:
			Login();
			break;
		case 2:
			center();
			break;
		}

	} while (a != 2);

	return 0;
}