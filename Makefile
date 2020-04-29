TARGET: hello_gtest
all:hello_gtest
hello_gtest:hello.o hello_test.o lib/libgtest.a lib/libgtest_main.a
	g++ -isystem ./include -g -Wall -Wextra -pthread -lpthread $^ -o $@
hello.o:src/hello.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $< 
hello_test.o:test/hello_test.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $<
clean:
	rm -rf *.o ${TARGET}