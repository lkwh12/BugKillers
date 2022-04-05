#include "pch.h"
#include "../EmployeeManagement/Employee.h"
#include "../EmployeeManagement/IDatabase.h"
#include "../EmployeeManagement/Mod.h"
#include "../EmployeeManagement/Parser.h"
#include "../EmployeeManagement/Add.h"
#include "../EmployeeManagement/MemoryDatabase.h"
#include "../EmployeeManagement/FileLogger.h"

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

            initCommands.push_back("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
            initCommands.push_back("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
            initCommands.push_back("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
            initCommands.push_back("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO");
            initCommands.push_back("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO");
            initCommands.push_back("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");
            initCommands.push_back("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");
            initCommands.push_back("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO");
            initCommands.push_back("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
            initCommands.push_back("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO");
            initCommands.push_back("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV");
            initCommands.push_back("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO");
            initCommands.push_back("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV");
            initCommands.push_back("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV");
            initCommands.push_back("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
            initCommands.push_back("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
            initCommands.push_back("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO");
            initCommands.push_back("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO");
            initCommands.push_back("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO");
            initCommands.push_back("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO");
        }
        // common data
        vector<shared_ptr<Employee>> DataBase;
        shared_ptr<Parser> pParser;
        vector<string> initCommands;
    };

    TEST_F(ModifyTest, DATA_MODIFY_TEST) {
        Input input;
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT");
        strCommand.push_back("MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU");
        strCommand.push_back("MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, , , ,name,BMU MPOSXU,birthday,19780918");
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
        EXPECT_TRUE(DataBase.at(0)->birthday_.birthDay == "19780918");
        EXPECT_TRUE(DataBase.at(0)->birthday_.year == "1978");
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


    TEST_F(ModifyTest, BASIC_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,VXIHXOTH JHOP,name,TWU QSOLT");
        strCommand.push_back("MOD,-p, , ,name,TWU QSOLT,name,BMU MPOSXU");
        strCommand.push_back("MOD,-p,-f, ,name,BMU,phoneNum,010-6672-7186");

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,1");
        strExpectOutput.push_back("MOD,15123099,TWU QSOLT,CL3,010-3112-2609,19771211,ADV");
        strExpectOutput.push_back("MOD,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");
        strExpectOutput.push_back("MOD,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
        strExpectOutput.push_back("MOD,15123099,BMU MPOSXU,CL3,010-3112-2609,19771211,ADV");
        strExpectOutput.push_back("MOD,18117906,BMU MPOSXU,CL4,010-6672-7186,20030413,PRO");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule1->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule2 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule2->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(2));
        shared_ptr<Mod> pModModule3 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule3->execute(db, fileLogger);


        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }


    TEST_F(ModifyTest, NAME_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD, ,-f, ,name,VXIHXOTH,phoneNum,010-6672-7186");
        strCommand.push_back("MOD, ,-l, ,name,JHOP,phoneNum,010-7914-4067");

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,1");
        strExpectOutput.push_back("MOD,1");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule0->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule1->execute(db, fileLogger);

        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }


    TEST_F(ModifyTest, CL_OPTION_SUCCESS) {
        vector<string> strCommand = { "MOD,-p, , ,cl,CL3,phoneNum,010-6672-7186" };

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
        strExpectOutput.push_back("MOD,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        strExpectOutput.push_back("MOD,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule0->execute(db, fileLogger);

        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }


    TEST_F(ModifyTest, PHONE_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p, , ,phoneNum,010-3112-2609,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,phoneNum,3112,certi,EX");
        strCommand.push_back("MOD,-p,-l, ,phoneNum,2609,certi,ADV");

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,EX");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule0->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule1->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule2 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule2->execute(db, fileLogger);

        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }


    TEST_F(ModifyTest, BIRTHDAY_OPTION_SUCCESS) {
        vector<string> strCommand;
        strCommand.push_back("MOD,-p,-y, ,birthday,1977,certi,PRO");
        strCommand.push_back("MOD,-p,-m, ,birthday,12,name,TWU QSOLT");
        strCommand.push_back("MOD,-p,-d, ,birtyday,11,phoneNum,010-6672-7186");

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
        strExpectOutput.push_back("MOD,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,PRO");
        strExpectOutput.push_back("MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
        strExpectOutput.push_back("MOD,15123099,TWU QSOLT,CL3,010-3112-2609,19771211,PRO");
        strExpectOutput.push_back("MOD,17112609,TWU QSOLT,CL4,010-5645-6122,19861203,PRO");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule0->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule1 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule1->execute(db, fileLogger);

        input = pParser->parseLine(strCommand.at(1));
        shared_ptr<Mod> pModModule2 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule2->execute(db, fileLogger);

        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }


    TEST_F(ModifyTest, FAIL) {
        // Not found
        vector<string> strCommand;
        strCommand.push_back("MOD, , , ,name,LFIS QSOLT,name,VCUHLE HMU");

        vector<string> strExpectOutput;
        strExpectOutput.push_back("MOD,NONE");

        FileIO outputfile("../EmployeeManagement/modify_result.txt", FileType::OUTPUT);
        MemoryDatabase db;
        FileLogger fileLogger(outputfile);
        Parser parser;

        outputfile.open();

        for (const auto& cmd : initCommands) {
            Add addCommand(parser.parseLine(cmd));
            addCommand.execute(db, fileLogger);
        }

        Input input = pParser->parseLine(strCommand.at(0));
        shared_ptr<Mod> pModModule0 = make_shared<Mod>(input);
        fileLogger.setPrintDetail(input.getFirstOption() == "-p");
        pModModule0->execute(db, fileLogger);

        ifstream resultFile("../EmployeeManagement/modify_result.txt");
        string outputLine;
        vector<string> strResultOutput;
        while (getline(resultFile, outputLine)) {
            if (outputLine == "") continue;
            strResultOutput.push_back(outputLine);
        }

        EXPECT_TRUE(strExpectOutput.size() == strResultOutput.size());
        for (register int index = 0; index < strExpectOutput.size(); index++) {
            EXPECT_TRUE(strExpectOutput.at(index) == strResultOutput.at(index));
        }

        outputfile.close();
    }
}
