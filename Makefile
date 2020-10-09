all: libsplit testsplit

libsplit: libsplit.a

libsplit.a: split.o
	ar r $@ $^

split.o: split.h

testsplit: testsplit.o libsplit.a
	gcc -o $@ $^

testsplit.o: split.h

.c.o: 
	gcc -c $<
