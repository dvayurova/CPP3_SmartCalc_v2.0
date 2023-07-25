.PHONY: all test gcov_report check rebuild clean memcheck
CC = gcc -lstdc++
CFLAGS = -Wall -Werror -Wextra -std=c++17
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LC = lcov -c -d .
OS = $(shell uname -s)

all: gcov_report

clean:
	rm -rf *.o *.gcno *.gcda *.info test.out
	rm -rf ./report
	rm -rf *.dSYM
	rm -rf *.gch
	rm -rf test
	rm -rf gcov_test
	rm -rf gcov_report/

rebuild: clean all

test: clean
	$(CC) $(CFLAGS) $(GCOVFLAGS) -o test -lgtest -pthread unit_tests.cc
	./test

memcheck: test
ifeq ($(OS), Darwin)
	leaks -atExit -- ./test
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
endif

gcov_report: clean test
	$(LC) -t "gcov_report" --no-external -o report.info
	genhtml -o gcov_report --prefix src report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov test
	open ./gcov_report/index-sort-l.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cc
	clang-format -n *.h
	clang-format -n ./*/*/*.tpp
	clang-format -n ./*/*/*.h
	rm -rf .clang-format

