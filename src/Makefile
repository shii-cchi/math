CC = gcc
CFLAGS = -std=c11 -Wall -Werror -Wextra
GCOV_FLAG = -fprofile-arcs -ftest-coverage -fPIC -O0
GCOV_FLAG_TEST = --coverage
TEST_FLAG = -lcheck
LINUX_FLAG = -lm -lsubunit -lrt -lpthread
ifeq ($(shell uname), Linux)
	TEST_FLAG += $(LINUX_FLAG)
endif
SOURCES_1 = another.c exponentiation_and_reverse.c trigonometry.c arctrigonometry.c
SOURCES_2 = another.o exponentiation_and_reverse.o trigonometry.o arctrigonometry.o
SOURCES_3 = test/test.c 
SOURCES_4 = test.o

all: clean math.a

math.a:
	$(CC) $(CFLAGS) -c $(SOURCES_1)
	ar rc _math.a $(SOURCES_2)
	ranlib _math.a
	-rm -rf *.o

test_math.a: clean
	$(CC) $(CFLAGS) $(GCOV_FLAG) -c $(SOURCES_1)
	ar rc _math.a $(SOURCES_2)
	ranlib _math.a

test: clean test_math.a
	$(CC) $(CFLAGS) -c $(SOURCES_3)
	$(CC) $(CFLAGS) $(GCOV_FLAG_TEST) -o tests $(SOURCES_4) _math.a $(TEST_FLAG)
	-rm -rf *.o
	./tests

gcov_report: clean test
	gcovr -r . --html-details -o report_math.html

clean:
	-rm -rf *.o *.a *.out *.gcda *.gcno *.html *.css
	-rm -f tests
