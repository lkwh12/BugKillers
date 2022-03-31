#include "pch.h"
#include "../EmployeeManagement/Employee.h"

TEST(TestCaseName, TestName) {
	Employee KIM = { "20000000",
					Name{"SAMSUG", "KIM"},
					PhoneNum{"1234", "5678"},
					BirthDay{"20", "01", "01"},
					"CL1",
					"PRO" };
	EXPECT_EQ(1, 1);
}