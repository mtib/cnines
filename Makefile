CC = clang
CFLAGS = --std=c11 -Wall
LFLAGS = -lm

.PHONY: run clean


run: cnines
	./cnines 123 10
	./cnines 123 16

debug: cnines.d
	./cnines.d 123 10
	./cnines.d 123 16

clean:
	rm -f cnines
	rm -f cnines.d
	rm *.o

analyze: analyzer
	echo ./analyzer "\$$(stty size|cut -d' ' -f2)" \$$1 > analyzer.sh
	chmod +x analyzer.sh
	./analyzer.sh 3

analyzer: analyzer.c analyzer.h nines.o
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ analyzer.c nines.o

cnines.d: cnines.c nines.d.o
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ -DDEBUG cnines.c nines.d.o

cnines: cnines.c nines.o
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ cnines.c nines.o

%.d.o: %.c %.h
	$(CC) $(CLFAGS) -c -o $@ -DDEBUG $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

%: %.c %.h
	$(CC) $(CLFAGS) -c -o $@ $<
