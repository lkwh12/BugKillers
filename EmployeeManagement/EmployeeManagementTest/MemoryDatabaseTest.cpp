#include "pch.h"
#include "MemoryDatabase.h"
#include "MemoryDatabase.cpp"

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
					PhoneNum("2234", "5678"),
					BirthDay("2001", "02", "01"),
					"CL3",
					"PRO" };
	db.insert(e1);
	db.insert(e2);
	db.insert(e3);

	auto val = "20000001";
	auto r1 = db.query(Filter(Filter::Column::EMPLOYEE_NUM, val));
	ASSERT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->employeeNum_);

	val = "SS2";
	r1 = db.query(Filter(Filter::Column::FIRST_NAME, val));
	ASSERT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->name_.firstName);

	val = "KIM";
	r1 = db.query(Filter(Filter::Column::LAST_NAME, val));
	ASSERT_EQ(2, r1.size());
	for (auto& r: r1) EXPECT_EQ(val, r->name_.lastName);

	val = "SS1 KIM";
	r1 = db.query(Filter(Filter::Column::NAME, val));
	ASSERT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->name_.name);

	val = "CL3";
	r1 = db.query(Filter(Filter::Column::CL, val));
	ASSERT_EQ(1, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->cl_);

	val = "PRO";
	r1 = db.query(Filter(Filter::Column::CERTI, val));
	ASSERT_EQ(2, r1.size());
	for (auto& r : r1) EXPECT_EQ(val, r->certi_);
}
