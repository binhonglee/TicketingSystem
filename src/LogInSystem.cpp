/*
 *  Written by  : Bin Hong Lee
 *  Last edited : Dec 29, 2016
 *
 */

#include <iostream>
#include <fstream>
#include <json/json.h>
#include <string>
#include <vector>
#include "LogInSystem.hpp"
using namespace std;

LogInSystem::LogInSystem()
{
  wrongPass = 0;
}

LogInSystem::LogInSystem(string filename)
{
  wrongPass = 0;
  ifstream fin(filename.c_str());
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
  globalUserId = users.back().getId() + 1;
}

Person LogInSystem::getUser(string name)
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

Person LogInSystem::getUser(int toSearchId)
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

int LogInSystem::getWrongPass()
{
  return wrongPass;
}

int LogInSystem::login()
{
  Person currentUser(-1);
  string username;
  string password;
  //If the user already has 3 fail attempt to login
  if (wrongPass > 2)
  {
    //Print error message and exit
    cout << "Too many failed login attempt. The program will now be terminated." << endl;
    return -1;
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
    cout << "Invalid username or password. Please try again." << endl;

    wrongPass++;
    return -1;
  }

  if (!currentUser.checkPassword(password))
  {
    cout << "Invalid username or password. Please try again." << endl;

    wrongPass++;
    return -1;
  }

  return currentUser.getId();
}

Person LogInSystem::registration()
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
	Person newUser(username, password, email, phoneNo, globalUserId);
  users.push_back(newUser);

  globalUserId++;

  //Print success message
  cout << "Account is successfully registered." << endl;

  return newUser;
}

void LogInSystem::loggedIn(Person currentUser)
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
        currentUser = editCredentials(currentUser);
        break;
      case 0:
        return;
      default:
        cout << "Invalid option. Please try again." << endl;
        cout << endl;
    }
  } while(choice != 0);
}

Person LogInSystem::editCredentials(Person currentUser)
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
    update(currentUser);
    cout << "Username is updated." << endl;
		break;
	case 2:
		currentUser.setPassword(chgPassword(currentUser));
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

void LogInSystem::update(Person newInfo)
{
  int position = users.size() / 2;

  while (position < users.size() && position >= 0)
  {
    if (users.at(position).getId() == newInfo.getId())
    {
      users.erase(users.begin() + position);
      users.insert(users.begin() + position, newInfo);
      cout << users.at(position).getName() << endl;
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

string LogInSystem::chgUsername()
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

string LogInSystem::chgPassword(Person currentUser)
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

string LogInSystem::chgEmail()
{
  string newEmail;

  cout << "Please input the new email : ";
	cin >> newEmail;

  return newEmail;
}

string LogInSystem::chgPhoneNo()
{
  string newPhoneNo;

  cout << "Please input the new phone no. : ";
	cin >> newPhoneNo;

  return newPhoneNo;
}

void LogInSystem::toTxtFile(string filename)
{
  ofstream fout(filename.c_str());

  while (!users.empty())
  {
    fout << users.begin()->getName() << " " << users.begin()->getPassword() << " " << users.begin()->getEmail() << " " << users.begin()->getPhoneNo() << " " << users.begin()->getId() << endl;
    users.erase(users.begin());
  }
}
