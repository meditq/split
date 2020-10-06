all: libsplit testsplit

libsplit: libsplit.a

libsplit.a: split.o
	ar r $@ $^

split.o: split.h

testsplit: libsplit testsplit.o
	gcc -o $@ testsplit.o libsplit.a

testsplit.o: split.h

.c.o: 
	gcc -c $<
