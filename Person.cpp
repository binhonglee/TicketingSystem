#include <string>
#include "Person.h"
using namespace std;

Person::Person(string name, string password, string email, string phoneNo)
{
  this->name = name;
  this->password = password;
  this->email = email;
  this->phoneNo = phoneNo;
}

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

bool Person::checkPassword(string password)
{
  return (this->password == password);
}

void Person::setPassword(string password)
{
  this->password = password;
}
