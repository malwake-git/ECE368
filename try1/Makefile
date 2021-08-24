# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_BUILDSTACK

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full

VAL = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

SRCS = main.c stack.c
OBJS = $(SRCS:%.c=%.o)

pa1: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o pa1

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

test: pa1
	./pa1

test1: pa1
	./pa1 pa1_examples/3.txt output1 output2
	diff output1 pa1_examples/3.pre
	diff output2 pa1_examples/3.delay

test2: pa1
	./pa1 pa1_examples/5.txt output3 output4
	diff output3 pa1_examples/5.pre
	diff output4 pa1_examples/5.delay



memory1: pa1
	 $(VALGRIND) ./pa1 pa1_examples/3.txt memcheck1 memcheck2
memory2: pa1
	 $(VALGRIND) ./pa1 pa1_examples/5.txt memcheck3 memcheck4

clean: # remove all machine generated files
	rm -f pa1 *.o output?


