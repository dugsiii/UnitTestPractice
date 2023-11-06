/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, case_sensitive)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Zz");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, count_repition)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ZZZ");
	ASSERT_EQ(3,actual);
}
TEST(PasswordTest, count_repition_between)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ZaZaZ");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, count_repition_endofstring)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z\nZ");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, non_ascii)
{
    Password my_password;
	int actual = my_password.count_leading_characters("ÃÃÃ");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, empty_string)
{
    Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0,actual);
}
TEST(PasswordTest, has_atleast_two)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, has_capital)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(true,actual);
}