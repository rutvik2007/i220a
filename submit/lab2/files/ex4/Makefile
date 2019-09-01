PROJECT = key-value
SRC_FILES= \
	key-value.c\
	key-value.h\
	main.c\
	process-file.c\
	process-file.h

CFLAGS = -g -Wall -std=c11
LDFLAGS = -lm
key-value:	process-file.o key-value.o main.o
	$(CC) key-value.o process-file.o main.o -o  $@ $(LDFLAGS)
dist: $(PROJECT).tar.gz
$(PROJECT).tar.gz:		$(SRC_FILES)
	tar -cf $(PROJECT).tar $(SRC_FILES)
	gzip -f $(PROJECT).tar
main.o: main.c key-value.h process-file.h
process-file.o: process-file.c process-file.h
key-value.o: key-value.c key-value.h

clean:
		rm -f *.o $(PROJECT) $(PROJECT).tar.gz
depend:
		$(CC) -MM $(CPPFLAGS) *.c

