# google_test
## To install googletest framework

Steps to install and use  
git clone https://github.com/google/googletest  
cd googletest  
mkdir build && cd build  
cmake ..  
make  
\#Identify generated static libs in build/lib, which are libgtest.a, libgtest_main.a

## Setting up the first example:-

Place the files as follows

- Copy gtest subdir from googletest/googletest/include into include subdir (i.e. copy whole include subidr from googletest/googletest to current dir, which holds gtest subdir)
- Create a new dir lib and copy the generated libgtest.a, libgtest_main.a (from googletest/build/lib)
- Place your c++ code to be tested in src subdir
- Place your c++ code, with test cases in test subdir
- Place any header files supporting your source in include, i.e. parallel to gtest which is just copied.
- Create a simple Makefile and include libgtest.a, libgtest_main.a during test program compilation

## Setting up the second example with class 
- Apply the same steps as first example
- account\_test program is generated from account.cc and account\_test.cc source files
- This example tests a class and its member functions

## Setting up third example with test fixture 
- Apply the same steps as first example
- account\_test program is generated from account.cc and account\_testfixture.cc source files
- This example tests a class and its member functions using googletest test fixture feature

A __test fixture__ is a place to hold objects and functions shared by all tests in a test case. Using a test fixture *avoids duplicating the test code* necessary to initialize and clean up those common objects for each test.  It is also useful for defining sub-routines that your tests need to invoke a lot.

The tests share the test fixture in the sense of code sharing, not data sharing.  Each test is given its own fresh copy of the fixture.  You cannot expect the data modified by one test to be passed on to another test, which is a bad idea. 

The reason for this design is that tests should be independent and repeatable.  In particular, a test should not fail as a result of another test's failure.  If one test depends on the info produced by another test, then the two tests should really be one big test.

The macros for indicating the success/failure of a test  (EXPECT_TRUE, FAIL, etc) need to know what the current test is  (when Google Test prints the test result, it tells you which test each failure belongs to).  Technically, these macros invoke a  member function of the Test class. Therefore, you cannot use them in a global function.  That's why you should put test sub-routines in a test fixture.
