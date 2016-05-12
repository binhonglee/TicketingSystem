/*
 *	Written by   : BinHong Lee
 *	Last edited  : 5/12/2016
 */

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include "Person.cpp"
using namespace std;

//Declaration of functions
void getUser(string);
void login();
void adminLogin();
void loggedIn();
void registration();
void editCredentials();
void update(Person);
void chgUsername();
void chgPassword();
void chgEmail();
void chgPhoneNo();
void quit();

//Stacks to store the data
stack<Person> users;

//Declaration of place holding variables
Person currentUser;
string username;
string password;
string password2;
string email;
string phoneNo;
int wrongPass = 0;

int main()
{
	ifstream fin("database.txt");
	int choice;

	while (!fin.eof())
	{
		fin >> username >> password >> email >> phoneNo;
		Person temp(username, password, email, phoneNo);
		users.push(temp);
	}

	users.pop();

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

	while (!users.empty())
	{
		fout << users.top().getName() << " " << users.top().getPassword() << " " << users.top().getEmail() << " " << users.top().getPhoneNo() << " " << endl;
		users.pop();
	}

  return 0;
}

void getUser(string query)
{
	stack<Person> temp = users;
	while (!temp.empty())
	{
		Person x = users.top();
		if (x.getName() == query) currentUser = x;
		users.pop();
		cout << "User found";
	}

	throw std::invalid_argument("");
}

void login()
{

	if (wrongPass >= 3)
	{
		cout << "Too much failed login attempt. The program will now be terminated." << endl;
		quit();
	}

	try {
		cout << "Username:";
		cin >> username;

		cout << "Password:";
		cin >> password;

		getUser(username);

	} catch (invalid_argument inae) {
		cout << "Invalid username or password. Please try again.";
		wrongPass++;
		login();
	}

	if (!currentUser.checkPassword(password))
	{
		cout << "Invalid username or password. Please try again.";
		wrongPass++;
		login();
	}

	loggedIn();
}

void registration()
{
	bool available = true;

	do
	{
		cout << "Username : ";
		cin >> username;

		stack<Person> temp = users;

		while(!temp.empty())
		{
			Person currentPerson = temp.top();

			if (currentUser.getName() == username)
			{
				cout << "Username unavailable. Please try again." << endl;
				available = false;
				break;
			}

			temp.pop();
		}
	} while (available == false);

	cout << "Username is available." << endl;

	do
	{
		cout << "Password : ";
		cin >> password;

		cout << "Confirm password :";
		cin >> password2;

		if (password != password2)
			cout << "Password unmatched. Please try again.";
	} while (password != password2);

	cout << "Email : ";
	cin >> email;

	cout << "Phone No. : ";
	cin >> phoneNo;

	Person newUser(username, password, email, phoneNo);
	users.push(newUser);

	cout << "Account is successfully registered." << endl;

	currentUser = newUser;
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
		cout << "Username : " << currentUser.getName() << "\nEmail : " << currentUser.getEmail() << "\nPhone No. : " << currentUser.getPhoneNo() << endl;
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

void update(Person newUser)
{
	stack<Person> newUsers;

	while (!users.empty())
	{
		if (users.top().getName() == currentUser.getName())
		{
			cout << "replaced" << endl;
			newUsers.push(newUser);
		}
		else
		{
			newUsers.push(users.top());
		}

		users.pop();
	}

	users = newUsers;
	currentUser = newUser;
}

void chgUsername()
{
	bool available;
	Person newUsers;

	do
	{
		available = true;
		cout << available << endl;
		cout << "Username : ";
		cin >> username;

		stack<Person> temp = users;

		while (!temp.empty())
		{
			if (temp.top().getName() == username)
			{
				cout << "Username unavailable. Please try again." << endl;
				cout << temp.top().getName() << " " << temp.top().getPhoneNo() << endl;
				available = false;
				break;
			}

			temp.pop();
		}
	}	while (available == false);

	cout << "Username is available." << endl;
	Person newPerson(username, currentUser.getPassword(), currentUser.getEmail(), currentUser.getPhoneNo());
	update(newPerson);

	cout << "Username is updated." << endl;
}

void chgPassword()
{
	cout << "Please input the current password : ";
	cin >> password;

	while (!currentUser.checkPassword(password))
	{
		cout << "Wrong password. Please try again." << endl;
		wrongPass++;

		cout << "Please input the current password : ";
		cin >> password;
	}

	do {
		cout << "Please input the new password : ";
		cin >> password;

		cout << "Please confirm your new password : ";
		cin >> password2;
	} while(password2 != password);

	currentUser.setPassword(password);
	update(currentUser);
}

void chgEmail()
{
	cout << "Please input the new email : ";
	cin >> email;

	currentUser.setEmail(email);
	update(currentUser);
}

void chgPhoneNo()
{
	cout << "Please input the new phone no. : ";
	cin >> phoneNo;

	currentUser.setPhoneNo(phoneNo);
	update(currentUser);
}

void quit()
{
	ofstream fout("database.txt");

	while (!users.empty())
	{
		fout << users.top().getName() << " " << users.top().getPassword() << " " << users.top().getEmail() << " " << users.top().getPhoneNo() << " " << endl;
		users.pop();
	}

	exit (EXIT_SUCCESS);
}
