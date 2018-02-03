OBJS = bin/list.o bin/test.o
CC = clang++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

.PHONY: go nuke clean before

go: test

	./test

test: before $(OBJS)

	$(CC) $(LFLAGS) $(OBJS) -o test

bin/list.o: src/list.cc

	$(CC) $(CFLAGS) src/list.cc -o bin/list.o

bin/test.o: src/test.cc

	$(CC) $(CFLAGS) src/test.cc -o bin/test.o

clean: nuke

nuke:

	rm -f */*.o *~ list test

before:

	if [ ! -d bin ]; then mkdir bin; fi
