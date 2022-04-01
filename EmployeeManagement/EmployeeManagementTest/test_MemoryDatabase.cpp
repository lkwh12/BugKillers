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
	auto ret = db.insert(e1);
	EXPECT_TRUE(true); // TODO: fix me
}
