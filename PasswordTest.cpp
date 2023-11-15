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
TEST(PasswordTest, has_cap_first)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("Az");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, has_cap_second)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("zA");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, does_not_have_lower_mix)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("AA");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, does_not_have_upper_mix)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("aa");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, doesnt_have_two)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("A");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, empty_string_mixed)
{
    Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, space_in_pass)
{
    Password my_password;
	bool actual = my_password.has_mixed_case(" T");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, default_pass)
{
    Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, set_password)
{
    Password my_password;
	my_password.set("PotatoChamp");
	bool actual = my_password.authenticate("PotatoChamp");
	ASSERT_EQ(true,actual);
}
TEST(PasswordTest, set_few_character)
{
    Password my_password;
	my_password.set("Potato");
	bool actual = my_password.authenticate("Potato");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, set_reoccuring_characters)
{
    Password my_password;
	my_password.set("PPPPotato");
	bool actual = my_password.authenticate("PPPPotato");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, set_no_mix_case)
{
    Password my_password;
	my_password.set("potatomaster");
	bool actual = my_password.authenticate("potatomaster");
	ASSERT_EQ(false,actual);
}
TEST(PasswordTest, set_same_password)
{
    Password my_password;
	my_password.set("PotatoChamp");
	my_password.set("PotatoLoser");
	my_password.set("PotatoChamp");
	bool actual = my_password.authenticate("PotatoChamp");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set_empty_password)
{
    Password my_password;
	my_password.set("");
	bool actual = my_password.authenticate("");
	ASSERT_EQ(false,actual);
}