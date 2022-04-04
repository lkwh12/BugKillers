#include "pch.h"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/MemoryDatabase.cpp"

TEST(MemoryDatabaseTest, Insert) {
	MemoryDatabase db;
	Employee e1 = { "20000000",
					Name("SS1", "KIM"),
					PhoneNum("1234", "5678"),
					BirthDay("2000", "01", "01"),
					"CL1",
					"ADV" };
	EXPECT_TRUE(db.insert(e1));
	EXPECT_FALSE(db.insert(e1));
}

TEST(MemoryDatabaseTest, Remove) {
	MemoryDatabase db;
	Employee e1 = { "20000001",
					Name("SS1", "KIM"),
					PhoneNum("1234", "5678"),
					BirthDay("2000", "01", "01"),
					"CL1",
					"ADV" };
	Employee e2 = { "20000002",
					Name("SS2", "KIM"),
					PhoneNum("2234", "5678"),
					BirthDay("2001", "01", "01"),
					"CL2",
					"PRO" };
	db.insert(e1);
	db.insert(e2);
	EXPECT_EQ(1, db.remove({ "20000001" }));
	db.insert(e1);
	EXPECT_EQ(2, db.remove({ "20000001", "20000002" }));
}

TEST(MemoryDatabaseTest, Query) {
	MemoryDatabase db;
	Employee e1 = { "20000001",
					Name("SS1", "KIM"),
					PhoneNum("1234", "5678"),
					BirthDay("2000", "01", "01"),
					"CL1",
					"ADV" };
	Employee e2 = { "20000002",
					Name("SS2", "PARK"),
					PhoneNum("2234", "5678"),
					BirthDay("2001", "02", "01"),
					"CL2",
					"PRO" };
	Employee e3 = { "20000003",
					Name("SS3", "KIM"),
					PhoneNum("2235", "5678"),
					BirthDay("2001", "02", "01"),
					"CL3",
					"PRO" };
	db.insert(e1);
	db.insert(e2);
	db.insert(e3);

	auto val = "20000001";
	auto r1 = db.query(Filter(Filter::Column::EMPLOYEE_NUM, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->employeeNum_);

	val = "SS2";
	r1 = db.query(Filter(Filter::Column::FIRST_NAME, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->name_.firstName);

	val = "KIM";
	r1 = db.query(Filter(Filter::Column::LAST_NAME, val));
	EXPECT_EQ(2, r1.size());
	for (auto& r: r1) EXPECT_EQ(val, r->name_.lastName);

	val = "SS1 KIM";
	r1 = db.query(Filter(Filter::Column::NAME, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->name_.name);

	val = "010-2234-5678";
	r1 = db.query(Filter(Filter::Column::TEL, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->phoneNum_.phoneNum);

	val = "5678";
	r1 = db.query(Filter(Filter::Column::TEL_LAST, val));
	EXPECT_EQ(3, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->phoneNum_.lastPhoneNum);

	val = "2234";
	r1 = db.query(Filter(Filter::Column::TEL_MIDDLE, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->phoneNum_.middlePhoneNum);

	val = "20010201";
	r1 = db.query(Filter(Filter::Column::BIRTH, val));
	EXPECT_EQ(2, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->birthday_.birthDay);

	val = "2001";
	r1 = db.query(Filter(Filter::Column::BIRTH_YEAR, val));
	EXPECT_EQ(2, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->birthday_.year);

	val = "01";
	r1 = db.query(Filter(Filter::Column::BIRTH_MONTH, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->birthday_.month);

	val = "01";
	r1 = db.query(Filter(Filter::Column::BIRTH_DAY, val));
	EXPECT_EQ(3, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->birthday_.day);

	val = "CL3";
	r1 = db.query(Filter(Filter::Column::CL, val));
	EXPECT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->cl_);

	val = "PRO";
	r1 = db.query(Filter(Filter::Column::CERTI, val));
	EXPECT_EQ(2, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->certi_);
}
