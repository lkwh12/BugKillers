#pragma once
#include <string>

using namespace std;

struct Name {
	string name;
	string firstName;
	string lastName;
};
struct PhoneNum {
	string phoneNum;
	string middlePhoneNum;
	string lastPhoneNum;
};
struct BirthDay {
	string birthDay;
	string year;
	string month;
	string day;
};

class Employee {
public:
	Employee(string employeeNum, Name name, PhoneNum phoneNum, BirthDay birthday, string cl, string certi) :
		employeeNum_(employeeNum), name_(name), phoneNum_(phoneNum), birthday_(birthday), cl_(cl), certi_(certi)
	{}

	string employeeNum_;
	Name name_;
	PhoneNum phoneNum_;
	BirthDay birthday_;

	string cl_;
	string certi_;
};
