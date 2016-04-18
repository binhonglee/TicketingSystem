#include <string>
#include <iostream>
using namespace std;

class Person
{
  private :
  string name;
  string password;
  string email;
  string phoneNo;

  public :
  Person(string, string, string, string);
  void setName(string);
  string getName();
  void setEmail(string);
  string getEmail();
  void setPhoneNo(string);
  string getPhoneNo();
  void setPassword(string);
  bool checkPassword(string);
};
