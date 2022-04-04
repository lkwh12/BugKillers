#include "pch.h"
#include "MemoryDatabase.h"
#include "MemoryDatabase.cpp"

TEST(MemoryDatabaseTest, AddToDatabase) {
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

TEST(MemoryDatabaseTest, DeleteTest) {
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
