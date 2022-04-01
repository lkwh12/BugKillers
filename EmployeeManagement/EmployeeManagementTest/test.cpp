#include "pch.h"
#include "../EmployeeManagement/Employee.h"

TEST(TestCaseName, TestName) {
	Employee KIM = { "20000000",
					Name{"SAMSUG KIM", "SAMSUG", "KIM"},
					PhoneNum{"010-1234-5678", "1234", "5678"},
					BirthDay{"20000101", "2000", "01", "01"},
					"CL1",
					"PRO" };
	EXPECT_EQ(1, 1);
}