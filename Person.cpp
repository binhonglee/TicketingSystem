/*
 *	Written by   : BinHong Lee
 *	Last edited  : 5/11/2016
 */

#include <string>
#include "Person.hpp"
using namespace std;

//Empty constructor
Person::Person(int id)
{
  this->id = id;
}

//Complete comstructor
Person::Person(string name, string password, string email, string phoneNo, int id)
{
  this->name = name;
  this->password = password;
  this->email = email;
  this->phoneNo = phoneNo;
  this->id = id;
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

int Person::getId()
{
  return id;
}
