# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

TESTFALGS = -DTEST_BUILDPA2 -DTEST_BUILDBALANCE -DTEST_BUILDTREE

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full
VAL = valgrind --leak-check=full --tool=memcheck --verbose --log-file

VALG = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

VALGR = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt

SRCS = balance.c pa2.c tree.c stack.c
OBJS = $(SRCS:%.c=%.o)

pa2: $(OBJS)
	$(GCC) $(TESTFALGS) $(OBJS) -o pa2

.c.o:
	$(GCC) $(TESTFALGS) -c $*.c

test: pa2
	./pa2 -b examples/ops0.b output1.b
	diff output1.b examples/tree0.b

test0: pa2
	./pa2 -e output4.b

test00: pa2
	./pa2 -h

test1: pa2
	./pa2 -b examples/ops0.b output1.b
	diff output1.b examples/tree0.b

test2: pa2
	./pa2 -b examples/ops1.b output2.b
	diff output2.b examples/tree1.b

test3: pa2
	./pa2 -b examples/ops2.b output3.b
	diff output3.b examples/tree2.b

test4: pa2
	./pa2 -b examples/ops3.b output4.b
	diff output4.b examples/tree3.b

test5: pa2
	./pa2 -e output1.b
test6: pa2
	./pa2 -b examples/ops3.b output7.b
	diff output7.b examples/tree1.b

test7: pa2
	./pa2 -b examples/ins_rand_1M.b output8.b
	diff output8.b examples/ins_rand_1M_key.b

test8: pa2
	./pa2 -b examples/ins_rand_1M_key.b output9.b


teste0: pa2
	./pa2 -e examples/invalidtree0.b
teste1: pa2
	./pa2 -e examples/invalidtree1.b
teste2: pa2
	./pa2 -e examples/invalidtree2.b

teste3: pa2
	./pa2 -e examples/ins_rand_1M.b
teste4: pa2
	./pa2 -e examples/ins_rand_1M_key.b


memory0: pa2
	$(VAL)=./valgrind.log ./pa2 -e examples/invalidtree0.b
memory01: pa2
	$(VAL)=./valgrind.log ./pa2 -e examples/invalidtree1.b
memory02: pa2
	$(VAL)=./valgrind.log ./pa2 -e examples/invalidtree2.b

memory1: pa2
	 $(VALGRIND) ./pa2 -b examples/ops0.b memcheck0.b
memory2: pa2
	 $(VALGRIND) ./pa2 -b examples/ops1.b memcheck1.b
memory3: pa2
	 $(VALGRIND) ./pa2 -b examples/ops2.b memcheck2.b
memory4: pa2
	 $(VALGRIND) ./pa2 -b examples/ops3.b memcheck3.b

memory001: pa2
	 $(VALGR) ./pa2 -b examples/ops0.b memcheck0.b
memory002: pa2
	 $(VALGR) ./pa2 -b examples/ops1.b memcheck1.b
memory003: pa2
	 $(VALGR) ./pa2 -b examples/ops2.b memcheck2.b
memory004: pa2
	 $(VALGR) ./pa2 -b examples/ops3.b memcheck3.b
memory005: pa2
	 $(VALGR) ./pa2 -e examples/invalidtree0.b
memory006: pa2
	 $(VALGR) ./pa2 -e examples/invalidtree1.b
memory007: pa2
	 $(VALGR) ./pa2 -e examples/invalidtree2.b
memory008: pa2
	 $(VALGR) ./pa2 -e examples/test111.b
memory009: pa2
	 $(VALGR) ./pa2 -e examples/ins_rand_1M.b
memory010: pa2
	 $(VALGRIND) ./pa2 -e examples/ins_rand_1M_key.b
memory011: pa2
	 $(VALGR) ./pa2 -b examples/ins_rand_1M.b memcheck4.b
memory012: pa2
	 $(VALGR) ./pa2 -b examples/ins_rand_1M_key.b memcheck5.b




clean: # remove all machine generated files
	rm -f pa2 *.o output?


all:
	gcc -std=c99 -pedantic -Wvla -Wall -Wshadow -O3 *.c -o pa2
