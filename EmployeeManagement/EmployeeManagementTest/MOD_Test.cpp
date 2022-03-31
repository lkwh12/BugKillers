#include "pch.h"
#include "../EmployeeManagement/Employee.h"

TEST(CMD_Test, MOD_TEST) {
	Employee KIM = { "20000000",
					Name{"SAMSUG", "KIM"},
					PhoneNum{"1234", "5678"},
					BirthDay{"20", "01", "01"},
					"CL1",
					"PRO" };
	EXPECT_EQ(1, 1);
}

namespace {
    class CMD_Test : public testing::Test {
    protected:
        void SetUp() override {
            dataBase = make_shared<Employee>();
            // 최초 Command를 ADD로 하여 Record 정보 입력
            //vector<string> strCommand = { "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV };
            //shared_ptr<EmployeeManager> EmployeeManager = Parser::parsingFileToCommands(strCommand);
            //EmployeeManager->excuteAdd(dataBase);
        }
        // common data
        shared_ptr<Employee> dataBase;
    };


    TEST_F(CMD_Test, MOD_BASIC_SUCCESS) {
        vector<string> strCommand1 = { "MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT" };
        //shared_ptr<EmployeeManager> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,1");

        vector<string> strCommand2 = { "MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU" };
        //shared_ptr<Parser> EmployeeManager2 = Parser::parsingFileToCommands(strCommand2);
        //EXPECT_TRUE(EmployeeManager2->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager2->executeAndWriteOutput() == "MOD,15123099,TWU QSOLT,CL3,010-3112-2609,19771211,ADV");

        vector<string> strCommand3 = { "MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186" };
        //shared_ptr<Parser> EmployeeManager3 = Parser::parsingFileToCommands(strCommand3);
        //EXPECT_TRUE(EmployeeManager3->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager3->executeAndWriteOutput() == "MOD,15123099,BMU MPOSXU,CL2,010-3112-2609,19771211,ADV");
    }


    TEST_F(CMD_Test, MOD_NAME_OPTION_SUCCESS) {
        vector<string> strCommand1 = { "MOD, ,-f, ,name,VXIHXOTH,phoneNum,010-6672-7186" };
        //shared_ptr<Parser> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,1");

        vector<string> strCommand2 = { "MOD, ,-l, ,name,JHOP,phoneNum,010-7914-4067" };
        //shared_ptr<Parser> EmployeeManager2 = Parser::parsingFileToCommands(strCommand2);
        //EXPECT_TRUE(EmployeeManager2->excuteModify(db));
        //EXPECT_TRUE(EmployeeManager2->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL2,010-6672-7186,19771211,ADV");
    }


    TEST_F(CMD_Test, MOD_CL_OPTION_SUCCESS) {
        vector<string> strCommand1 = { "MOD,-p, , ,cl,CL3,phoneNum,010-6672-7186" };
        //shared_ptr<Parser> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
    }


    TEST_F(CMD_Test, MOD_PHONE_OPTION_SUCCESS) {
        vector<string> strCommand1 = { "MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO" };
        //shared_ptr<Parser> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");

        vector<string> strCommand2 = { "MOD,-p,-m, ,phoneNum,3112,certi,EX" };
        //shared_ptr<Parser> EmployeeManager2 = Parser::parsingFileToCommands(strCommand2);
        //EXPECT_TRUE(EmployeeManager2->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager2->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");

        vector<string> strCommand3 = { "MOD,-p,-l, ,phoneNum,2609,certi,ADV" };
        //shared_ptr<Parser> EmployeeManager3 = Parser::parsingFileToCommands(strCommand3);
        //EXPECT_TRUE(EmployeeManager3->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager3->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
    }


    TEST_F(CMD_Test, MOD_BIRTHDAY_OPTION_SUCCESS) {
        vector<string> strCommand1 = { "MOD,-p,-y, ,birthday,1977,certi,PRO" };
        //shared_ptr<Parser> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");

        vector<string> strCommand2 = { "MOD,-p,-m, ,birthday,12,name,TWU QSOLT" };
        //shared_ptr<Parser> EmployeeManager2 = Parser::parsingFileToCommands(strCommand2);
        //EXPECT_TRUE(EmployeeManager2->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager2->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");

        vector<string> strCommand3 = { "MOD,-p,-d, ,birtyday,11,phoneNum,010-6672-7186" };
        //shared_ptr<Parser> EmployeeManager3 = Parser::parsingFileToCommands(strCommand3);
        //EXPECT_TRUE(EmployeeManager3->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager3->executeAndWriteOutput() == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
    }


    TEST_F(CMD_Test, MOD_FAIL) {
        // Not found
        vector<string> strCommand1 = { "MOD, , , ,name,TWU QSOLT,name,VCUHLE HMU" };
        //shared_ptr<Parser> EmployeeManager1 = Parser::parsingFileToCommands(strCommand1);
        //EXPECT_TRUE(EmployeeManager1->excuteModify(dataBase));
        //EXPECT_TRUE(EmployeeManager1->executeAndWriteOutput() == "MOD,NONE");
    }
}
