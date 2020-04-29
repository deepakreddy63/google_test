#include <limits.h>
#include "account.h"
#include "gtest/gtest.h"

class AccountTest : public testing::Test {
protected:
    AccountTest():a2(1001,"Lippman",5000.0),a3(a2) {
        ptr=new Account(1002,"Stanley",8000.0);
    }
    ~AccountTest() {
        delete ptr;
    }
    virtual void SetUp() {
        a2.credit(3000);
        a2.debit(2000);
        a3.debit(1200);
        a3.credit(1600);
    }
    virtual void TearDown() {

    }
    Account a1;
    Account a2;
    Account a3;
    Account *ptr;

};

namespace {

    TEST_F(AccountTest,DefaultConstructorTest) {
        EXPECT_EQ(0.0,a1.getBalance());
        EXPECT_EQ(0.0,a1.getCustomerId());
        EXPECT_EQ(0,a1.getCustomerName().length());
    }
    TEST_F(AccountTest,ParameterizedConstructorTest) {
        EXPECT_EQ(1001,a2.getCustomerId());
        EXPECT_STREQ("Lippman",a2.getCustomerName().c_str());
        EXPECT_EQ(7,a2.getCustomerName().length());
        EXPECT_EQ(6000.0,a2.getBalance());

    }
    TEST_F(AccountTest,CopyConstructorTest) {
        EXPECT_EQ(1001,a3.getCustomerId());
        EXPECT_STREQ("Lippman",a3.getCustomerName().c_str());
        EXPECT_EQ(7,a3.getCustomerName().length());
        EXPECT_EQ(5400.0,a3.getBalance());
    }
    TEST_F(AccountTest,CreditTest) {
        a2.credit(3000);
        EXPECT_EQ(9000.0,a2.getBalance());
    }
    TEST_F(AccountTest,DEBIT) {
        a2.debit(1200);            //not same a2 as in above test case
        EXPECT_EQ(4800.0,a2.getBalance());
    }
    TEST_F(AccountTest,TransactionTest) {
        a3.debit(1200);
        a3.credit(3400);
        a3.debit(2000);
        a3.credit(3000);
        EXPECT_EQ(8600.0,a3.getBalance());
    }
    TEST_F(AccountTest,DisplayTest) {
        std::string ExpectedOut="1001,Lippman,6000\n";
        testing::internal::CaptureStdout();
        a2.display();
        std::string ActualOut = testing::internal::GetCapturedStdout();
        EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
    }
    TEST_F(AccountTest,DynamicObjectTest) {
        std::string ExpectedOut="1002,Stanley,8000\n";
        testing::internal::CaptureStdout();
        ptr->display();
        std::string ActualOut = testing::internal::GetCapturedStdout();
        EXPECT_STREQ(ExpectedOut.c_str(), ActualOut.c_str());
    }
}
