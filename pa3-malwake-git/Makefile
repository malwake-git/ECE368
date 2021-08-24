
# ***
# *** DO NOT modify this file 
# ***

WARNING = -Wall -Wshadow --pedantic
ERROR = -Wvla -Werror
GCC = gcc -std=c99 -g $(WARNING) $(ERROR) 

VALGRIND = valgrind --tool=memcheck --verbose --log-file=memcheck.txt --leak-check=full
VAL = valgrind --leak-check=full --tool=memcheck --verbose --log-file

VALG = valgrind --tool=memcheck --log-file=vallog --leak-check=full --verbose

VALGR = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt

SRCS = genome.c
OBJS = $(SRCS:%.c=%.o)

pa3: $(OBJS)
	$(GCC) $(OBJS) -o pa3

.c.o:
	$(GCC) -c $*.c


test0: pa3
	./pa3 1 ./pa3 1 PA3_Examples/Aeromonas_hydrophila.txt output1 outputp1

test00: pa3
	./pa3 -h

test1: pa3
	./pa3 5 PA3_Examples/Aeromonas_hydrophila.txt output1.txt nodeoutput1.txt

test2: pa3
	./pa3 3 PA3_Examples/Aeromonas_hydrophila.txt output2.txt nodeoutput2.txt

test3: pa3
	./pa3 3 PA3_Examples/test.txt output3.txt nodeoutput3.txt

test4: pa3
	./pa3 7 PA3_Examples/Bacillus_cereus.txt output4.txt nodeoutput4.txt
test5: pa3
	./pa3 1 PA3_Examples/Bacteroides_fragilis.txt output5.txt nodeoutput5.txt
test6: pa3
	./pa3 4 PA3_Examples/Hg_chr14.txt output6.txt nodeoutput6.txt
test7: pa3
	./pa3 6 PA3_Examples/Mycobacterium_abscessus.txt output7.txt nodeoutput7.txt
test8: pa3
	./pa3 8 PA3_Examples/Rhodobacter_sphaeroides.txt output8.txt nodeoutput8.txt
test9: pa3
	./pa3 10 PA3_Examples/Staphylococcus_aureus.txt output9.txt nodeoutput9.txt
test10: pa3
	./pa3 7 PA3_Examples/Vibrio_cholera_updated.txt output10.txt nodeoutput10.txt
test11: pa3
	./pa3 7 PA3_Examples/Xanthomonas_axonopodis.txt output11.txt nodeoutput11.txt

test12: pa3
	time ./pa3 11 PA3_Examples/Xanthomonas_axonopodis.txt output12.txt nodeoutput12.txt


memory0: pa3
	$(VAL)=./valgrind.log ./pa3 1 PA3_Examples/Aeromonas_hydrophila.txt output1 outputp1

memory1: pa3
	$(VALGRIND)=./valgrind.log ./pa3 1 PA3_Examples/Aeromonas_hydrophila.txt output1 outputp1

memory001: pa3
	 $(VALGR) ./pa3 3 PA3_Examples/Aeromonas_hydrophila.txt output1 outputp1

memory002: pa3
	 $(VALGR) ./pa3 3 PA3_Examples/test.txt output1 outputp1

memory003: pa3
	 $(VALGRIND) ./pa3 3 PA3_Examples/Bacillus_cereus.txt output4 outputp4

memory004: pa3
	 $(VALGRIND) ./pa3 9 PA3_Examples/Rhodobacter_sphaeroides.txt output4 outputp
memory005: pa3
	 $(VALGRIND) ./pa3 7 PA3_Examples/Bacillus_cereus.txt output5 outputp5


clean: # remove all machine generated files
	rm -f pa3 *.o output?

all:
	gcc -std=c99 -pedantic -Wvla -Wall -Wshadow -O3 *.c -o pa3
