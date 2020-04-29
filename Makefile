TARGET = hello_gtest account_gtest account_gtestfixture
TARGET: hello_gtest account_gtest account_gtestfixture
all:hello_gtest account_gtest account_gtestfixture
hello_gtest:hello.o hello_test.o lib/libgtest.a lib/libgtest_main.a
	g++ -isystem ./include -g -Wall -Wextra -pthread -lpthread $^ -o $@
hello.o:src/hello.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $< 
hello_test.o:test/hello_test.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $<

account_gtest:account.o account_test.o lib/libgtest.a lib/libgtest_main.a
	g++ -isystem ./include -g -Wall -Wextra -pthread -lpthread $^ -o $@
account_gtestfixture:account.o account_testfixture.o lib/libgtest.a lib/libgtest_main.a
	g++ -isystem ./include -g -Wall -Wextra -pthread -lpthread $^ -o $@
account.o:src/account.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $< 
account_test.o:test/account_test.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $<
account_testfixture.o:test/account_testfixture.cc
	g++ -isystem ./include -g -Wall -Wextra -pthread -c $<

.PHONY: clean
clean:
	rm -rf *.o ${TARGET}
