# google_test
## To try googletest framework\

Steps to install and use\
    git clone https://github.com/google/googletest\
    cd googletest\
    mkdir build && cd build\
    cmake ..\
    make\
    #Identify generated static libs in build/lib, \
    #which are libgtest.a, libgtest_main.a\

## Setting up the first example:-

Place the files as follows

    Copy gtest subdir from googletest/googletest/include into include subdir (i.e. copy whole include subidr from googletest/googletest to current dir, which holds gtest subdir)
    Create a new dir lib and copy the generated libgtest.a, libgtest_main.a (from googletest/build/lib)
    Place your c++ code to be tested in src subdir
    Place your c++ code, with test cases in test subdir
    Place any header files supporting your source in include, i.e. parallel to gtest which is just copied.
    Create a simple Makefile with the following contents
