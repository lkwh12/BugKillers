#include "pch.h"
#include "../EmployeeManagement/Employee.h"


//int addEmployee(const Employee& e) {
//
//	database.push_back(e);
//
//	return 0;
//}


class CommandTest : public ::testing::Test {
protected:
	void SetUp() override {
	
	}

	void TearDown() override {
		database.clear();
	}

public:
	vector<Employee> database;
};

TEST_F(CommandTest, BasicAddTest) {
	//To do : Database.insert() call

	Employee e("15120999", Name{ "VXIHXOTH", "JHOP" }, PhoneNum{ "3112", "2609"}, BirthDay{"1977","12","11"}, "CL3", "ADV");
	//EXPECT_EQ(addEmployee(e), 0);
}

TEST_F(CommandTest, BasicAddGetCount) {

	Employee e1("15120999", Name{ "VXIHXOTH", "JHOP" }, PhoneNum{ "3112", "2609" }, BirthDay{ "1977","12","11" }, "CL3", "ADV");
	Employee e2("17112609", Name{ "FB", "NTAWR" }, PhoneNum{ "5645", "6122" }, BirthDay{ "1986","12","03" }, "CL4", "PRO");
	Employee e3("18115050", Name{ "TTETHU", "HBO" }, PhoneNum{ "4581", "2050" }, BirthDay{ "2008","07","18" }, "CL3", "ADV");

	//EXPECT_EQ(getEmployee(), 3);
}

TEST_F(CommandTest, SameNoAddCase) {

	Employee e1("15120999", Name{ "VXIHXOTH", "JHOP" }, PhoneNum{ "3112", "2609" }, BirthDay{ "1977","12","11" }, "CL3", "ADV");
	//EXPECT_EQ(addEmployee(e1), 0);
	Employee e2("15120999", Name{ "FB", "NTAWR" }, PhoneNum{ "5645", "6122" }, BirthDay{ "1986","12","03" }, "CL4", "PRO");
	//EXPECT_EQ(addEmployee(e2), -1);
	Employee e3("15120999", Name{ "TTETHU", "HBO" }, PhoneNum{ "4581", "2050" }, BirthDay{ "2008","07","18" }, "CL3", "ADV");
	//EXPECT_EQ(addEmployee(e3), -1);
}

TEST_F(CommandTest, NullValueAddCase) {

	Employee e1("15120999", Name{ "", "JHOP" }, PhoneNum{ "3112", "2609" }, BirthDay{ "1977","12","11" }, "CL3", "ADV");
	//EXPECT_EQ(addEmployee(e1), -1);
	Employee e2("15120999", Name{ "FB", "" }, PhoneNum{ "5645", "6122" }, BirthDay{ "1986","12","03" }, "CL4", "PRO");
	//EXPECT_EQ(addEmployee(e2), -1);
	Employee e3("15120999", Name{ "TTETHU", "HBO" }, PhoneNum{ "", "2050" }, BirthDay{ "2008","07","18" }, "CL3", "ADV");
	//EXPECT_EQ(addEmployee(e3), -1);
}
