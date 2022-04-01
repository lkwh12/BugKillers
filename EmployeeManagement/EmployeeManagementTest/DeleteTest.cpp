#include "pch.h"
#include "../EmployeeManagement/Employee.h"

using namespace std;

// name, phone, birth
TEST(DeleteTest, TestNoOption)
{
	vector<string> cmd_id = { "DEL, , , ,id, 20000000" };
	vector<string> cmd_name = { "DEL, , , ,name, SAMSUNG KIM" };
	vector<string> cmd_phone = { "DEL, , , ,phone, 01012345678" };
	vector<string> cmd_birth = { "DEL, , , ,birth, 20200101" };
	vector<string> cmd_cl = { "DEL, , , ,cl, CL1" };
	vector<string> cmd_certi = { "DEL, , , ,certi, PRO" };


	// Return the number of deleted data
//	EXPECT_EQ(1, deleteById(cmd_id));
//	EXPECT_EQ(2, deleteByName(cmd_name));
//	EXPECT_EQ(4, deleteByPhone(cmd_phone));
//	EXPECT_EQ(8, deleteByBirth(cmd_birth));
//	EXPECT_EQ(16, deleteByCl(cmd_cl));
//	EXPECT_EQ(50, deleteByCerti(cmd_certi));
}

// name, phone, birth
TEST(DeleteTest, TestName)
{
	vector<string> cmd = { "DEL, , , ,name, SAMSUNG KANG" };
	vector<string> cmd_n = { "DEL,-p, , ,name, SAMSUNG KIM" };
	vector<string> cmd_f = { "DEL,-p,-f, ,name, SAMSUNG" };
	vector<string> cmd_l = { "DEL,-p,-l, ,name, KIM" };

	// Return the number of deleted data
//	EXPECT_EQ(NONE, deleteByName(cmd));
//	EXPECT_EQ(1, deleteByName(cmd_n));

	// Return the set of delete data which has parameter's name
	vector<string>result_f;
	//	EXPECT_EQ(result_f, deleteByName(cmd_f));
	vector<string>result_l;
	//	EXPECT_EQ(result_l, deleteByName(cmd_l));

}

TEST(DeleteTest, TestPhone)
{
	vector<string> cmd = { "DEL, , , ,phone, 01098765432" };
	vector<string> cmd_p = { "DEL, , , ,phone, 01012345678" };
	vector<string> cmd_m = { "DEL,-p,-m, ,phone, 1234" };
	vector<string> cmd_l = { "DEL,-p,-l, ,phone, 5678" };

	// Return the number of deleted data
//	EXPECT_EQ(NONE, deleteByPhone(cmd));
//	EXPECT_EQ(3, deleteByPhone(cmd_p));

	// Return the set of delete data which has parameter's name
	vector<string>result_m;
	//	EXPECT_EQ(result_m, deleteByPhone(cmd_m));
	vector<string>result_l;
	//	EXPECT_EQ(result_l, deleteByPhone(cmd_l));
}

TEST(DeleteTest, TestBirth)
{
	vector<string> cmd = { "DEL, , , ,birth, 20200131" };
	vector<string> cmd_b = { "DEL, , , ,birth, 20200101" };
	vector<string> cmd_y = { "DEL,-p,-y, ,birth, 2020" };
	vector<string> cmd_m = { "DEL,-p,-m, ,birth, 01" };
	vector<string> cmd_d = { "DEL,-p,-d, ,birth, 01" };

	// Return the number of deleted data
//	EXPECT_EQ(NONE, deleteByBirth(cmd));
//	EXPECT_EQ(11, deleteByBirth(cmd_b));

	// Return the set of delete data which has parameter's name
	vector<string>result_y;
	//	EXPECT_EQ(result_y, deleteByBirth(cmd_y));
	vector<string>result_m;
	//	EXPECT_EQ(result_m, deleteByBirth(cmd_m));
	vector<string>result_d;
	//	EXPECT_EQ(result_d, deleteByBirth(cmd_d));
}