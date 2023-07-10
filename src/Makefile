CC = gcc
FLAGS = -std=c11 -Wall -Wextra -Werror
FLAG_COV = --coverage
LIBS = -lcheck
TEST_LIBS = -lcheck -lm -lpthread

all: gcov_report

clang:
	clang-format -n -style=google s21_*.c s21_*.h other_funcs.c unit_tests.c

s21_matrix.a:
	$(CC) $(FLAGS) -c s21_*.c other_funcs.c
	ar rc s21_matrix.a *.o
	ranlib s21_matrix.a

test: s21_matrix.a
	$(CC) $(FLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	./s21_matrix

install lcov:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

leak: s21_matrix.a
	$(CC) $(FLAGS) -c unit_tests.c -o unit_tests.o
	$(CC) unit_tests.o s21_matrix.a $(TEST_LIBS) -o s21_matrix
	CK_FORK=no leaks -quiet -atExit -- ./s21_matrix

gcov_report: test
	$(CC) $(FLAGS) --coverage unit_tests.c s21_*.c s21_*.h s21_matrix.a $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcovReport" -o gcov_test.info -c -d .
	genhtml -o report gcov_test.info
	open report/index.html

clean:
	rm -rf s21_matrix
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
	rm -rf ./report

rebuild: clean all