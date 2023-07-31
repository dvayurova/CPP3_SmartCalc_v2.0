.PHONY: all install uninstall clean dvi dist tests check memcheck test
CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
LC = lcov -c -d .
OS = $(shell uname -s)
SOURCES = Model/*.cc  Model/*/*.cc 
all: install

clean:
	rm -rf *.o
	rm -rf test

rebuild: clean all

tests: clean
	$(CC) $(CFLAGS) $(GCOVFLAGS) $(SOURCES) unit_tests.cc -lgtest -pthread -o test 
	 ./test
test: tests

memcheck: test
ifeq ($(OS), Darwin)
	leaks -atExit -- ./test
else
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
endif

check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.cc
	clang-format -n *.h
	clang-format -n ./*/*/*.tpp
	clang-format -n ./*/*/*.h
	rm -rf .clang-format

install: uninstall
	make clean
	mkdir build
	cd View && qmake && make && make clean && rm Makefile && cd ../ && mv View/Calc.app build

uninstall:
	rm -rf build*

dist:
	rm -rf Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/
	mkdir Archive_SmartCalc_v2.0/src
	mv ./build/Calc.app Archive_SmartCalc_v2.0/src/
	tar cvzf Archive_SmartCalc_v2.0.tgz Archive_SmartCalc_v2.0/
	rm -rf Archive_SmartCalc_v2.0/

dvi:
	open readme_calc.md
