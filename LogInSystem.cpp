/*
 *	Written by   : Lee Bin Hong
 *	Last edited  : 4/12/2016
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Person.cpp"
using namespace std;

int getUsernameCounter(string, int);
void login();
void loggedIn();
void registration();
void editCredentials();
void chgUsername();
void chgPassword();
void chgEmail();
void chgPhoneNo();
void quit();

const int size = 10000;
Person person[size];
string username[size];
string password[size];
string email[size];
string phoneNo[size];
int counter;
int x = 0;
int wrongPass = 0;

int main()
{
	ifstream fin("database.txt");
	int choice;

	while (!fin.eof())
	{
		fin >> username[x] >> password[x] >> email[x] >> phoneNo[x];
		x++;
	}

	cout << "Please choose one of the following options :" << endl;
	cout << "Log In       - 1" << endl;
	cout << "Registration - 2" << endl;
	cout << "Exit         - 0" << endl;

	cin >> choice;
	switch (choice)
	{
	case 1:
		login();
		break;
	case 2:
		registration();
		break;
	case 0:
		break;
	}

	ofstream fout("database.txt");

	for (int i = 0; i <= x; i++)
	{
		fout << username[i] << " " << password[i] << " " << email[i] << " " << phoneNo[i] << " " << endl;
	}
  return 0;
}

int getUsernameCounter(string query, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (query == username[i]) return i;
	}
	return -1;
}

void login()
{
	if (wrongPass >= 3)
	{
		cout << "Too much failed login attempt. The program will now be terminated." << endl;
		quit();
	}

	string usrnme, pswd;
	cout << "Username:";
	cin >> usrnme;

	counter = getUsernameCounter(usrnme, x);

	cout << "Password:";
	cin >> pswd;

	if (pswd != password[counter])
	{
		cout << "Invalid username or password. Please try again.";
		wrongPass++;
		login();
	}

	loggedIn();
}

void registration()
{
	string usrnme;
	string pswd = "2";
	string pswd2 = "3";
	bool available = false;

	while (available == false)
	{
		available = true;

		cout << "Username : ";
		cin >> usrnme;

		for (int i = 0; i < x; i++)
		{
			if (username[i] == usrnme)
			{
				cout << "Username unavailable. Please try again." << endl;
				available = false;
			}
		}
	}

	cout << "Username is available." << endl;
	username[x] = usrnme;

	while (pswd != pswd2)
	{
		cout << "Password : ";
		cin >> pswd;

		cout << "Confirm password :";
		cin >> pswd2;

		if (pswd != pswd2)
			cout << "Password unmatched. Please try again.";
	}

	password[x] = pswd;

	cout << "Email : ";
	cin >> email[x];

	cout << "Phone No. : ";
	cin >> phoneNo[x];

	cout << "Account is successfully registered." << endl;

	counter = x;

	x++;

	loggedIn();
}

void loggedIn()
{
	int choice;

	cout << "Please choose one of the following option :" << endl;
	cout << "View credentials - 1" << endl;
	cout << "Edit credentials - 2" << endl;
	cout << "Exit             - 0" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Username : " << username[counter] << "\nEmail : " << email[counter] << "\nPhone No. : " << phoneNo[counter] << endl;
		loggedIn();
		break;
	case 2:
		editCredentials();
		loggedIn();
		break;
	case 0:
		quit();
	}

}

void editCredentials()
{
	int choice;

	cout << "Which of the following to edit?" << endl;
	cout << "Username  - 1" << endl;
	cout << "Password  - 2" << endl;
	cout << "Email     - 3" << endl;
	cout << "Phone No. - 4" << endl;
	cout << "Exit      - 0" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
		chgUsername();
		break;
	case 2:
		chgPassword();
		break;
	case 3:
		chgEmail();
		break;
	case 4:
		chgPhoneNo();
		break;
	}
}

void chgUsername()
{
	bool available = false;
	string usrnme;

	while (available == false)
	{
		available = true;

		cout << "Username : ";
		cin >> usrnme;

		for (int i = 0; i < x; i++)
		{
			if (username[i] == usrnme)
			{
				cout << "Username unavailable. Please try again." << endl;
				available = false;
			}
		}
	}

	username[counter] = usrnme;

	loggedIn();
}

void chgPassword()
{
	string pass;

	cout << "Please input the current password : ";
	cin >> pass;

	if (pass != password[counter])
	{
		cout << "Wrong password. Please try again.";
		wrongPass++;
		chgPassword();
	}
}

void chgEmail()
{
	cout << "Please input the new email : ";
	cin >> email[counter];

	loggedIn();
}

void chgPhoneNo()
{
	cout << "Please input the new phone no. : ";
	cin >> phoneNo[counter];

	loggedIn();
}

void quit()
{
	ofstream fout("database.txt");

	for (int i = 0; i <= x; i++)
	{
		fout << username[i] << " " << password[i] << " " << email[i] << " " << phoneNo[i] << " " << endl;
	}

	exit (EXIT_SUCCESS);
}
