/*
 *	Written by   : BinHong Lee
 *	Last edited  : 4/22/2016
 */

#include <string>
#include "Person.h"
using namespace std;

//Empty constructor
Person::Person()
{
  name = "unknown";
  password = "";
  email = "unknown";
  phoneNo = "555-5555";
}

//Complete comstructor
Person::Person(string name, string password, string email, string phoneNo)
{
  this->name = name;
  this->password = password;
  this->email = email;
  this->phoneNo = phoneNo;
}

//Getters and setters
void Person::setName(string name)
{
  this->name = name;
}

string Person::getName()
{
  return name;
}

void Person::setEmail(string email)
{
  this->email = email;
}

string Person::getEmail()
{
  return email;
}

void Person::setPhoneNo(string phoneNo)
{
  this->phoneNo = phoneNo;
}

string Person::getPhoneNo()
{
  return phoneNo;
}

void Person::setPassword(string password)
{
  this->password = password;
}

string Person::getPassword()
{
  return password;
}

//"password" do not have getter but only a checker instead
bool Person::checkPassword(string password)
{
  return (this->password == password);
}
