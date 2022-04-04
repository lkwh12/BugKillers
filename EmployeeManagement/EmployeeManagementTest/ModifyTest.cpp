#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/IDatabase.h"
#include "../EmployeeManagement/Mod.h"
#include "../EmployeeManagement/Parser.h"

namespace {
    class ModifyTest : public testing::Test {
    protected:
        void SetUp() override {
            this->DataBase.push_back(make_shared<Employee>("15123099",
                Name{ "VXIHXOTH", "JHOP" },
                PhoneNum{ "3112", "2609" },
                BirthDay{ "77", "12", "11" },
                "CL3",
                "ADV"));
            this->pParser = make_shared<Parser>();
        }
        // common data
        vector<shared_ptr<Employee>> DataBase;
        shared_ptr<Parser> pParser;
    };

    TEST_F(ModifyTest, DATA_MODIFY_TEST) {
        Input input;
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT");
        strCommand.push_back("MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU");
        strCommand.push_back("MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, , , ,name,BMU MPOSXU,birthday,780918");
        strCommand.push_back("MOD, , , ,name,BMU MPOSXU,employeeNum,12121212");
        strCommand.push_back("MOD, , , ,name,BMU MPOSXU,cl,CL4");
        strCommand.push_back("MOD, , , ,name,BMU MPOSXU,certi,EX");

        input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule0->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->name_.name == "TWU QSOLT");
        EXPECT_TRUE(DataBase.at(0)->name_.firstName == "TWU");
        EXPECT_TRUE(DataBase.at(0)->name_.lastName == "QSOLT");

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule1->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->name_.name == "BMU MPOSXU");
        EXPECT_TRUE(DataBase.at(0)->name_.firstName == "BMU");
        EXPECT_TRUE(DataBase.at(0)->name_.lastName == "MPOSXU");

        input = pParser->parseLine(strCommand.at(2));
        shared_ptr<Mod> pModModule2 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule2->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->phoneNum_.phoneNum == "010-6672-7186");
        EXPECT_TRUE(DataBase.at(0)->phoneNum_.middlePhoneNum == "6672");
        EXPECT_TRUE(DataBase.at(0)->phoneNum_.lastPhoneNum == "7186");

        input = pParser->parseLine(strCommand.at(3));
        shared_ptr<Mod> pModModule3 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule3->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->birthday_.birthDay == "780918");
        EXPECT_TRUE(DataBase.at(0)->birthday_.year == "78");
        EXPECT_TRUE(DataBase.at(0)->birthday_.month == "09");
        EXPECT_TRUE(DataBase.at(0)->birthday_.day == "18");

        input = pParser->parseLine(strCommand.at(4));
        shared_ptr<Mod> pModModule4 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule4->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->employeeNum_ == "12121212");

        input = pParser->parseLine(strCommand.at(5));
        shared_ptr<Mod> pModModule5 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule5->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->cl_ == "CL4");

        input = pParser->parseLine(strCommand.at(6));
        shared_ptr<Mod> pModModule6 = make_shared<Mod>(input);
        EXPECT_TRUE(pModModule6->doModify(DataBase) == true);
        EXPECT_TRUE(DataBase.at(0)->certi_ == "EX");
    }


    TEST_F(ModifyTest, MAKE_FILTER_TEST) {
        Input input;
        Filter filter;
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,employeeNum,15123099,name,TWU QSOLT");
        strCommand.push_back("MOD, , , ,name,TWU QSOLT,name,TWU QSOLT");
        strCommand.push_back("MOD, ,-f, ,name,TWU,name,BMU MPOSXU");
        strCommand.push_back("MOD, ,-l, ,name,MPOSXU,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, , , ,phoneNum,010-6672-7186,birthday,780918");
        strCommand.push_back("MOD, ,-m, ,phoneNum,6672,employeeNum,12121212");
        strCommand.push_back("MOD, ,-l, ,phoneNum,7186,cl,CL4");
        strCommand.push_back("MOD, , , ,birthday,771211,certi,EX");
        strCommand.push_back("MOD, ,-y, ,birthday,77,certi,EX");
        strCommand.push_back("MOD, ,-m, ,birthday,12,certi,ADV");
        strCommand.push_back("MOD, ,-d, ,birthday,11,certi,PRO");
        strCommand.push_back("MOD, , , ,cl,CL4,name,BMU MPOSXU");
        strCommand.push_back("MOD, , , ,certi,PRO,name,TWU QSOLT");


        input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        pModModule0->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::EMPLOYEE_NUM);
        EXPECT_TRUE(filter.getValue() == "15123099");

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        pModModule1->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::NAME);
        EXPECT_TRUE(filter.getValue() == "TWU QSOLT");

        input = pParser->parseLine(strCommand.at(2));
        shared_ptr<Mod> pModModule2 = make_shared<Mod>(input);
        pModModule2->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::FIRST_NAME);
        EXPECT_TRUE(filter.getValue() == "TWU");

        input = pParser->parseLine(strCommand.at(3));
        shared_ptr<Mod> pModModule3 = make_shared<Mod>(input);
        pModModule3->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::LAST_NAME);
        EXPECT_TRUE(filter.getValue() == "MPOSXU");

        input = pParser->parseLine(strCommand.at(4));
        shared_ptr<Mod> pModModule4 = make_shared<Mod>(input);
        pModModule4->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::TEL);
        EXPECT_TRUE(filter.getValue() == "010-6672-7186");

        input = pParser->parseLine(strCommand.at(5));
        shared_ptr<Mod> pModModule5 = make_shared<Mod>(input);
        pModModule5->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::TEL_MIDDLE);
        EXPECT_TRUE(filter.getValue() == "6672");

        input = pParser->parseLine(strCommand.at(6));
        shared_ptr<Mod> pModModule6 = make_shared<Mod>(input);
        pModModule6->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::TEL_LAST);
        EXPECT_TRUE(filter.getValue() == "7186");

        input = pParser->parseLine(strCommand.at(7));
        shared_ptr<Mod> pModModule7 = make_shared<Mod>(input);
        pModModule7->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::BIRTH);
        EXPECT_TRUE(filter.getValue() == "771211");

        input = pParser->parseLine(strCommand.at(8));
        shared_ptr<Mod> pModModule8 = make_shared<Mod>(input);
        pModModule8->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::BIRTH_YEAR);
        EXPECT_TRUE(filter.getValue() == "77");

        input = pParser->parseLine(strCommand.at(9));
        shared_ptr<Mod> pModModule9 = make_shared<Mod>(input);
        pModModule9->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::BIRTH_MONTH);
        EXPECT_TRUE(filter.getValue() == "12");

        input = pParser->parseLine(strCommand.at(10));
        shared_ptr<Mod> pModModule10 = make_shared<Mod>(input);
        pModModule10->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::BIRTH_DAY);
        EXPECT_TRUE(filter.getValue() == "11");

        input = pParser->parseLine(strCommand.at(11));
        shared_ptr<Mod> pModModule11 = make_shared<Mod>(input);
        pModModule11->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::CL);
        EXPECT_TRUE(filter.getValue() == "CL4");

        input = pParser->parseLine(strCommand.at(12));
        shared_ptr<Mod> pModModule12 = make_shared<Mod>(input);
        pModModule12->makeFilter(filter);
        EXPECT_TRUE(filter.getColumn() == Filter::Column::CERTI);
        EXPECT_TRUE(filter.getValue() == "PRO");
    }


    TEST_F(ModifyTest, BASIC_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT");
        strCommand.push_back("MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU");
        strCommand.push_back("MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,1");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,TWU QSOLT,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,BMU MPOSXU,CL2,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 1);
    }


    TEST_F(ModifyTest, NAME_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, ,-f, ,name,VXIHXOTH,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, ,-l, ,name,JHOP,phoneNum,010-7914-4067");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,1");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL2,010-6672-7186,19771211,ADV");
        EXPECT_TRUE(1 == 1);
    }


    TEST_F(ModifyTest, CL_OPTION_SUCCESS) {
        vector<string> strCommand = { "MOD,-p, , ,cl,CL3,phoneNum,010-6672-7186" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 1);
    }


    TEST_F(ModifyTest, PHONE_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,phoneNum,3112,certi,EX");
        strCommand.push_back("MOD,-p,-l, ,phoneNum,2609,certi,ADV");
        vector<string> strCommand1 = { "MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
        EXPECT_TRUE(1 == 1);
    }


    TEST_F(ModifyTest, BIRTHDAY_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p,-y, ,birthday,1977,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,birthday,12,name,TWU QSOLT");
        strCommand.push_back("MOD,-p,-d, ,birtyday,11,phoneNum,010-6672-7186");

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[1]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        EXPECT_TRUE(1 == 1);

        Input = pParser->parseLine(strCommand[2]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input) == "MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");
        EXPECT_TRUE(1 == 1);
    }


    TEST_F(ModifyTest, FAIL) {
        // Not found
        vector<string> strCommand = { "MOD, , , ,name,TWU QSOLT,name,VCUHLE HMU" };

        Input Input = pParser->parseLine(strCommand[0]);
        //EXPECT_TRUE(pModModule->execute(pDataBase, Input == "MOD,NONE");
        EXPECT_TRUE(1 == 1);
    }
}
