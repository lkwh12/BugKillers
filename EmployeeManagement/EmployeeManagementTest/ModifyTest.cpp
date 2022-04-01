#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/IDatabase.h"
#include "../EmployeeManagement/Mod.h"
#include "../EmployeeManagement/Parser.h"

namespace {
    class ModifyTest : public testing::Test {
    protected:
        void SetUp() override {
            this->pDataBase = make_shared<Employee>("15123099",
                                                   Name{ "VXIHXOTH", "JHOP" },
                                                   PhoneNum{ "3112", "2609" },
                                                   BirthDay{ "77", "12", "11" },
                                                   "CL3",
                                                   "ADV");
            this->pModModule = make_shared<Mod>();
            this->pParser = make_shared<Parser>();
        }
        // common data
        shared_ptr<Employee> pDataBase;
        shared_ptr<Mod> pModModule;
        shared_ptr<Parser> pParser;
    };


    TEST_F(ModifyTest, BASIC_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT");
        strCommand.push_back("MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU");
        strCommand.push_back("MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,1");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,TWU QSOLT,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,BMU MPOSXU,CL2,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 0);
    }


    TEST_F(ModifyTest, NAME_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, ,-f, ,name,VXIHXOTH,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, ,-l, ,name,JHOP,phoneNum,010-7914-4067");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,1");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL2,010-6672-7186,19771211,ADV");
        EXPECT_TRUE(1 == 0);
    }


    TEST_F(ModifyTest, CL_OPTION_SUCCESS) {
        vector<string> strCommand = { "MOD,-p, , ,cl,CL3,phoneNum,010-6672-7186" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 0);
    }


    TEST_F(ModifyTest, PHONE_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,phoneNum,3112,certi,EX");
        strCommand.push_back("MOD,-p,-l, ,phoneNum,2609,certi,ADV");
        vector<string> strCommand1 = { "MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
        EXPECT_TRUE(1 == 0);
    }


    TEST_F(ModifyTest, BIRTHDAY_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p,-y, ,birthday,1977,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,birthday,12,name,TWU QSOLT");
        strCommand.push_back("MOD,-p,-d, ,birtyday,11,phoneNum,010-6672-7186");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        EXPECT_TRUE(1 == 0);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
        EXPECT_TRUE(1 == 0);
    }


    TEST_F(ModifyTest, FAIL) {
        // Not found
        vector<string> strCommand = { "MOD, , , ,name,TWU QSOLT,name,VCUHLE HMU" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input == "MOD,NONE");
        EXPECT_TRUE(1 == 0);
    }
}
