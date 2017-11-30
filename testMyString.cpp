#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "MyString.h"

/*!
 * @test 1) Testing MyString Constructor
 */
TEST_CASE("1) Testing MyString")
{
    INFO("1) Testing MyString");
    MyString ms("Hello99");
    SECTION("1.1 Test Constructor")
    {
        INFO("1.1 Test Constructor");
        cout<<"1.1 Test Constructor"<<endl;
        string s1 = ms.getInternalCString();
        REQUIRE(s1 == "Hello99");
    }
}

/*!
 * @test 2) Testing MyString Constructor Empty
 */


TEST_CASE("2) Testing MyString Empty")
{
    INFO("2) Testing MyString Empty");
    MyString ms("");
    SECTION("2.1 Test Empty Constructor")
    {
        INFO("2.1 Test Empty Constructor");
        std::cout<<"2.1 Test Empty Constructor"<<endl;
        string s1 = ms.getInternalCString();
        REQUIRE(s1 == "");
    }
}

/*!
 * @test 3) Testing MyString Compare Method
 */

TEST_CASE("3) Testing MyString Compare")
{
    INFO("3) Testing MyString Compare");
    MyString ms1("Hello123");
    MyString ms2("Hello123");
    MyString ms3("Fello123");
    MyString ms4("Hello12");
    SECTION("3.1 Test Compare ms1 > ms2")
    {
        INFO("3.1 Test Compare ms1 > ms2");
        std::cout<<"3.1 Test Compare ms1 > ms2"<<endl;
        REQUIRE(ms1.compareStr(ms1, ms4) == 1);
    }
    SECTION("3.2 Test Compare ms1 < ms2")
    {
        INFO("3.2 Test Compare ms1 < ms2");
        std::cout<<"3.2 Test Compare ms1 < ms2"<<endl;
        REQUIRE(ms1.compareStr(ms4, ms1) == -1);
    }
    SECTION("3.3 Test Compare ms1 == ms2")
    {
        INFO("3.3 Test Compare ms1 == ms2 (equal)");
        std::cout<<"3.3 Test Compare ms1 == ms2 (equal)"<<endl;
        REQUIRE(ms1.compareStr(ms1, ms2) == 0);
    }
    SECTION("3.4 Test Compare ms1 == ms2 (equal length, different string")
    {
        INFO("3.4 Test Compare ms1 == ms2 (equal length, different string");
        cout<<"3.4 Test Compare ms1 == ms2 (equal length, different string"<<endl;
        REQUIRE(ms1.compareStr(ms1, ms3) == -2);
    }
}
/*!
 * @test 4) Testing MyString Revert Method
 */

TEST_CASE("4) Testing MyString Revert")
{
    INFO("4) Testing MyString Revert");
    MyString ms("Hello123");
    SECTION("4.1 Test Revert")
    {
        INFO("4.1 Test Revert");
        cout<<"4.1 Test Revert"<<endl;
        CAPTURE(ms.getInternalCString());
        ms.reverseit();
       // cout << "\nAqui "<< endl;
        CAPTURE(ms.getInternalCString());
        //cout << "Lqui2 "<< endl;
        string s2 = ms.getInternalCString();
        REQUIRE(s2 == "321olleH");
    }
}

/*!
 * @test 5) Testing MyString << opeartor
 */

TEST_CASE("5) Testing MyString << operator")
{
    INFO("5) Testing MyString << operator");
    MyString ms("Hello123");
    SECTION("5.1 Test << Operator")
    {
        INFO("5.1 Test<< operator");
        std::cout<<"5.1 Test <<operator"<<endl;
        std::cout<<ms<<endl;
    }
}
