#### __* Work in progress__

# Bus Ticket Management System

This program is written solely on personal time with the purpose to pick up the C++ programming language once again after a long long time since I last wrote anything with it.

The original version of this program (as seen in the initial commit) was a version of my work years ago. I decided that starting from scratch might not be the best idea when it comes to a programming language that I haven't use for a long time. However, as years pass, there are different things that I've learn from other programming languages that I thought would be fun to see how that implementation works with C++ so it will eventually be very much different from what it was.

Thank you for your time in reading this. I sure hope someone would find this useful in someway someday.

## Person.hpp / Person.cpp

#### Constructors

| Parameters | Task |
|:-----------|:-----------------------------|
| `()` | Empty constructor. |
| `string newName`<br>`string newEmail`<br>`string newPhoneNo`<br>`string newPassword`<br>`int newId` | Constructor with all parameters to populate all data slots in the object. |

#### Functions

| Function | Task |
|:----------------------|:-------------------------|
| `void setName(string);` | Set `name` to the new given input. |
| `string getName();` | Return `name` to caller. |
| `void setEmail(string);` | Set `email` to the new given input. |
| `string getEmail();` | Return `email` to caller. |
| `void setPhoneNo(string);` | Set `phoneNo` to the new given input. |
| `string getPhoneNo();` | Return `phoneNo` to caller. |
| `void setPassword(string);` | Set `password` to the new given input. |
| `string getPassword();` | Return `password` to the caller. |
| `bool checkPassword(string);` | Return if the given string matches `password`. |
| `int getId();` | Return `id` to the caller. |

## LogInSystem.cpp

#### Functions

| Function | Task |
|:----------------------|:-------------------------|
| `Person getUser(string);` | Takes in a string parameter that will be used to searched for a matching username in the users vector. |
| `Person getUser(int);` | Takes in an int parameter that will be used to searched for a matching id in the users vector. |
| `void login();` |   |
| `void loggedIn(Person);` | Takes in a Person parameter after the user has logged in as that identity. It provides the user options to display and modify the information of that specific identity in the database (vector). |
| `Person registration();` | Request all the required information from the user to register for a new account and add them into the users vector. |
| `Person editCredentials(Person);` | Takes in a Person parameter and make edit to it according to the user's intention. It will then return the updated Person to the caller. |
| `void update(Person);` | Take in a Person parameter that is to be updated into the users vector. It will search for the Person in the vector with matching ID and replace it. |
