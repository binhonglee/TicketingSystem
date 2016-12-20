#### __* Currently not working as intended__
#### __* Work in progress__

# Bus Ticket Management System

This program is written solely on personal time with the purpose to pick up the C++ programming language once again after a long long time since I last wrote anything with it.

The original version of this program (as seen in the initial commit) was a version of my work years ago. I decided that starting from scratch might not be the best idea when it comes to a programming language that I haven't use for a long time. However, as years pass, there are different things that I've learn from other programming languages that I thought would be fun to see how that implementation works with C++ so it will eventually be very much different from what it was.

Thank you for your time in reading this. I sure hope someone would find this useful in someway someday.

## LogInSystem.cpp

### Person getUser(string);
This function will take in a string parameter that will be used to searched for a matching username in the users vector.

### Person getUser(int);
This function will take in an int parameter that will be used to searched for a matching id in the users vector.

### void login();

### void loggedIn(Person);
This function takes in a Person parameter after the user has logged in as that identity. It provides the user options to display and modify the information of that specific identity in the database (vector).

### Person registration();
This function request all the required information from the user to register for a new account and add them into the users vector.

### Person editCredentials(Person);
This function will take in a Person parameter and make edit to it according to the user's intention. It will then return the updated Person to the caller.

### void update(Person);
This function will take in a Person parameter that is to be updated into the users vector. It will search for the Person in the vector with matching ID and replace it.

## Person.hpp / Person.cpp
