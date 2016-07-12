/*
 *	Written by   : BinHong Lee
 *	Last edited  : 7/7/2016
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
//void quit();

//Stacks to store the users' personal data
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
	//Reading from file to build the database
	ifstream fin("database.txt");
	while (!fin.eof())
	{
		//Reading in line-by-line into the placeholding variables
		fin >> username >> password >> email >> phoneNo;

		//Create the Person and push it into the stack
		Person temp(username, password, email, phoneNo);
		users.push(temp);
	}

	//Pop off the additional data added into the stack due to the empty line
	users.pop();

	getOption:
	//Display user input options
	cout << "Please choose one of the following options :" << endl;
	cout << "Log In       - 1" << endl;
	cout << "Registration - 2" << endl;
	cout << "Exit         - 0" << endl;

	//Get user input
	int choice;
	cin >> choice;

	//Switch according to user input
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
	default:
		//Display error message
		cout << "Invalid input. Please try again." << endl;
		goto getOption;
	}

	//Saving data into file
	ofstream fout("database.txt");

	//Check if the stack is empty
	while (!users.empty())
	{
		//Move the data into the files each Person per line
		fout << users.top().getName() << " " << users.top().getPassword() << " " << users.top().getEmail() << " " << users.top().getPhoneNo() << " " << endl;
		//Pop the Person out of stack after the data is moved
		users.pop();
	}

	//End the program
  return 0;
}

void getUser()
{
	//Duplicate the current stack to be checked through
	stack<Person> temp = users;

	//Loop while the temporary stack is not empty
	while (!temp.empty())
	{
		//Check if the username match the query
		//If so, set it as the currentUser
		if (users.top().getName() == username) currentUser = users.top();

		//Pop the checked user
		users.pop();
	}

	//Throw invalid_argument error to be caught if the person is not found
	throw std::invalid_argument("");
}

void login()
{
	//If the user already has 3 fail attempt to login
	if (wrongPass >= 3)
	{
		//Print error message and exit
		cout << "Too much failed login attempt. The program will now be terminated." << endl;
		return;
	}

	try {
		//Ask for username
		cout << "Username:";
		cin >> username;

		//Ask for password
		cout << "Password:";
		cin >> password;

		//Get the user
		getUser();

	} catch (invalid_argument inae) {
		//Print error message
		cout << "Invalid username or password. Please try again.";
		//Increase wrongPass count that indicate the amount of times of invalid
		//credentials input by the user
		wrongPass++;
		login();
	}

	//Check if the password is correct
	if (!currentUser.checkPassword(password))
	{
		//Print error message
		cout << "Invalid username or password. Please try again.";
		//Increase wrongPass count that indicate the amount of times of invalid
		//credentials input by the user
		wrongPass++;
		login();
	}

	//User is successfully logged in
	loggedIn();
}

void registration()
{
	//Initialize boolean
	bool available;

	do
	{
		try
		{
			//Get username
			cout << "Username: ";
			cin >> username;

			//Check if username is already in use
			//If not, it will throw an invalid_argument error to be caught
			getUser();

			//Print error message
			cout << "Username unavailable. Please try again." << endl;
			//Set available as false and continue the loop
			available = false;
		//Catch the invalid_argument error thrown by getUser()
		} catch (invalid_argument inae)
		{
			//Set available to true and quit the loop
			available = true;
		}
	} while (available == false);

	//Print success message
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
	Person newUser(username, password, email, phoneNo);
	users.push(newUser);

	//Print success message
	cout << "Account is successfully registered." << endl;

	//Automatically login user
	currentUser = newUser;
	loggedIn();
}

void loggedIn()
{
	//Declare space to save user's option
	int choice;

	//Print options
	cout << "Please choose one of the following option :" << endl;
	cout << "View credentials - 1" << endl;
	cout << "Edit credentials - 2" << endl;
	cout << "Exit             - 0" << endl;
	//Get user selection
	cin >> choice;

	switch (choice)
	{
	case 1:
		//Print out user credentials
		cout << "Username : " << currentUser.getName() << "\nEmail : " << currentUser.getEmail() << "\nPhone No. : " << currentUser.getPhoneNo() << endl;
		//Nested call back into the menu
		loggedIn();
		break;
	case 2:
		editCredentials();
		//Nested call back into the menu
		loggedIn();
		break;
	case 0:
		break;
	default:
		cout << "Invalid option. Please try again." << endl;
		cout << endl;
		loggedIn();
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

/*
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
*/
