all: libsplit testsplit

libsplit: libsplit.a

libsplit.a: split.o
	ar r $@ $^

split.o: split.h

testsplit: testsplit.o libsplit.a
	gcc -o $@ $^ -lreadline

testsplit.o: split.h

.c.o: 
	gcc -c $<

clean: 
	rm -f libsplit.a testsplit *.o
