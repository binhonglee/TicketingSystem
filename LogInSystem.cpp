/*
 *  Written by  : Bin Hong Lee
 *  Last edited : Dec 18, 2016
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Person.hpp"
using namespace std;

//Declaration of functions
Person getUser(string);
Person getUser(int);
void login();
void loggedIn(Person);
Person registration();
Person editCredentials(Person);
void update(Person);
string chgUsername();
string chgPassword();
string chgEmail();
string chgPhoneNo();

vector<Person> users;
static int wrongPass = 0;
static int globalId;

int main()
{
  ifstream fin("database.txt");
  while (!fin.eof())
  {
    string username;
    string password;
    string email;
    string phoneNo;
    int id;

    fin >> username >> password >> email >> phoneNo >> id;

    Person newPerson(username, password, email, phoneNo, id);
    users.push_back(newPerson);
  }

  users.pop_back();

  globalId = users.back().getId() + 1;
  int userOption = -1;

  while (userOption != 0)
  {
    cout << "Please choose one of the following options :" << endl;
  	cout << "Log In       - 1" << endl;
  	cout << "Registration - 2" << endl;
  	cout << "Exit         - 0" << endl;

    cin >> userOption;

    switch (userOption)
    {
      case 1:
        while (wrongPass < 3)
        {
          login();
        }
        break;
      case 2: loggedIn(registration()); break;
      default:
        cout << "Invalid input. Please try again." << endl;
    }
  }

  ofstream fout("database.txt");

  while (!users.empty())
  {
    fout << users.back().getName() << " " << users.back().getPassword() << " " << users.back().getEmail() << " " << users.back().getPhoneNo() << " " << users.back().getId() << endl;
    users.pop_back();
  }

  return 0;
}

Person getUser(string name)
{
  for (int i = 0; i < users.size(); i++)
  {
    if (users.at(i).getName() == name)
    {
      return users.at(i);
    }
  }

  throw invalid_argument("");
}

Person getUser(int toSearchId)
{
  for (int i = 0; i < users.size(); i++)
  {
    if (users.at(i).getId() == toSearchId)
    {
      return users.at(i);
    }
  }

  throw invalid_argument("");
}

void login()
{
  Person currentUser;
  string username;
  string password;
  //If the user already has 3 fail attempt to login
  if (wrongPass > 2)
  {
    //Print error message and exit
    cout << "Too much failed login attempt. The program will now be terminated." << endl;
    return;
  }

  try
  {
    //Ask for username
		cout << "Username:";
		cin >> username;

    //Ask for password
		cout << "Password:";
		cin >> password;

		//Get the user
		currentUser = getUser(username);
  }
  catch (invalid_argument ag)
  {
    cout << "Invalid username or password. Please try again.";

    wrongPass++;
    return;
  }

  if (!currentUser.checkPassword(password))
  {
    cout << "Invalid username or password. Please try again.";

    wrongPass++;
    return;
  }

  loggedIn(currentUser);
}

Person registration()
{
  bool available;
  string username;
  string password;
  string password2;
  string email;
  string phoneNo;

  do
  {
    try
    {
      cout << "Username: ";
      cin >> username;

      getUser(username);

      cout << "Username taken. Please try again." << endl;

      available = false;
    }
    catch (invalid_argument ag)
    {
      available = true;
    }
  } while (!available);

  cout << "Username is available." << endl;

  do
	{
		//Get password
		cout << "Password : ";
		cin >> password;

		//Confirm password
		cout << "Confirm password :";
		cin >> password2;

		//Print error message if both password is not the same
		if (password != password2)
			cout << "Password unmatched. Please try again.";
	//Loop until both password input is the same
	} while (password != password2);

  //Get email
	cout << "Email : ";
	cin >> email;

	//Get phone number
	cout << "Phone No. : ";
	cin >> phoneNo;

	//Create and push the new 'Person' into stack
	Person newUser(username, password, email, phoneNo, globalId);
  users.push_back(newUser);

  globalId++;

  //Print success message
  cout << "Account is successfully registered." << endl;

  return newUser;
}

void loggedIn(Person currentUser)
{
  int choice;

  do {
    cout << "Please choose one of the following options: " << endl;
    cout << "View credentials - 1" << endl;
    cout << "Edit credentials - 2" << endl;
    cout << "Exit             - 0" << endl;

    cin >> choice;

    switch(choice)
    {
      case 1:
        cout << "Username : " << currentUser.getName() << endl;
        cout << "Email    : " << currentUser.getEmail() << endl;
        cout << "Phone No.: " << currentUser.getPhoneNo() << endl;
        break;
      case 2:
        editCredentials(currentUser);
        break;
      case 0:
        return;
      default:
        cout << "Invalid option. Please try again." << endl;
        cout << endl;
    }
  } while(choice != 0);
}

Person editCredentials(Person currentUser)
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
		currentUser.setName(chgUsername());
    cout << "Username is updated." << endl;
		break;
	case 2:
		currentUser.setPassword(chgPassword());
    cout << "Password is updated." << endl;
		break;
	case 3:
		currentUser.setEmail(chgEmail());
    cout << "Email is updated." << endl;
		break;
	case 4:
		currentUser.setPhoneNo(chgPhoneNo());
    cout << "Phone number is updated." << endl;
		break;
	}

  return currentUser;
}

void update(Person newInfo)
{
  int position = users.size() / 2;

  while (position < users.size() && position >= 0)
  {
    if (users.at(position).getId() == newInfo.getId())
    {
      Person oldInfo = users.at(position);
      replace(users.begin(), users.end(), oldInfo, newInfo);
      return;
    }

    if (users.at(position).getId() < newInfo.getId())
    {
      position++;
    }
    else
    {
      position--;
    }
  }
}

string chgUsername()
{
  bool availablility;
  string newUsername;

  do
  {
    availablility = true;

    cout << "New Username: ";
    cin >> newUsername;

    for (int i = 0; i < users.size(); i++)
    {
      if (users.at(i).getName() == newUsername)
      {
        availablility = false;
        break;
      }
    }
  } while (!availablility);

  cout << "Username is available." << endl;
  return newUsername;
}

string chgPassword(Person currentUser)
{
  string password;
  string newPassword0;
  string newPassword1;

  cout << "Please input the current password : ";
	cin >> password;

	while (!currentUser.checkPassword(password) && wrongPass < 3)
	{
		cout << "Wrong password. Please try again." << endl;
		wrongPass++;

		cout << "Please input the current password : ";
		cin >> password;
	}

	do {
		cout << "Please input the new password : ";
		cin >> newPassword0;

		cout << "Please confirm your new password : ";
		cin >> newPassword1;
	} while(newPassword0 != newPassword1);

  return newPassword0;
}

string chgEmail()
{
  string newEmail;

  cout << "Please input the new email : ";
	cin >> newEmail;

  return newEmail;
}

string chgPhoneNo()
{
  string newPhoneNo;

  cout << "Please input the new phone no. : ";
	cin >> newPhoneNo;

  return newPhoneNo;
}
