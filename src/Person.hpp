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
  int id;

  public :
  Person(int id);
  Person(string, string, string, string, int);
  void setName(string);
  string getName();
  void setEmail(string);
  string getEmail();
  void setPhoneNo(string);
  string getPhoneNo();
  void setPassword(string);
  string getPassword();
  bool checkPassword(string);
  int getId();
};
