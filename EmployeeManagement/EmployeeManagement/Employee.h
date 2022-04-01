#pragma once
#include <string>

using namespace std;

struct Name {
	Name(string firstName, string lastName) {
		this->name = firstName + " " + lastName;
		this->firstName = firstName;
		this->lastName = lastName;
	}
	string name;
	string firstName;
	string lastName;
};
struct PhoneNum {
	PhoneNum(string middlePhoneNum, string lastPhoneNum) {
		this->phoneNum = "010-" + middlePhoneNum + '-' + lastPhoneNum;
		this->middlePhoneNum = middlePhoneNum;
		this->lastPhoneNum = lastPhoneNum;
	}
	string phoneNum;
	string middlePhoneNum;
	string lastPhoneNum;
};
struct BirthDay {
	BirthDay(string year, string month, string day) {
		this->birthDay = year + month + day;
		this->year = year;
		this->month = month;
		this->day = day;
	}
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
