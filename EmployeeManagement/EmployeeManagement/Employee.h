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
	static constexpr auto LEN_EMP_NAME = (15);
	static constexpr auto CHUNK_CNT_NAME = (2);
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
	static constexpr auto LEN_EMP_PHONE_NUMBER = (13);
	static constexpr auto LEN_EMP_PHONE_NUMBER_MID = (4);
	static constexpr auto LEN_EMP_PHONE_NUMBER_LAST = (4);
	static constexpr auto CHUNK_CNT_PHONE_NUMBER = (3);
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
	static constexpr auto LEN_EMP_BIRTHDAY = (8);
	static constexpr auto LEN_EMP_BIRTHDAY_YEAR = (4);
	static constexpr auto LEN_EMP_BIRTHDAY_MONTH = (2);
	static constexpr auto LEN_EMP_BIRTHDAY_DAY = (2);
};

class Employee {
public:
	Employee(string employeeNum, Name name, PhoneNum phoneNum, BirthDay birthday, string cl, string certi) :
		employeeNum_(employeeNum), name_(name), phoneNum_(phoneNum), birthday_(birthday), cl_(cl), certi_(certi)
	{}
	Employee(const Employee& o) : Employee(o.employeeNum_, o.name_, o.phoneNum_, o.birthday_, o.cl_, o.certi_) { }

	string employeeNum_;
	Name name_;
	PhoneNum phoneNum_;
	BirthDay birthday_;

	string cl_;
	string certi_;
	static constexpr auto LEN_EMP_NO = (8);
};
