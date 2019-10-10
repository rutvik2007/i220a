CFLAGS = -Wall -Og -std=c11

%.dump:		%.o
		objdump -d $< >$@

%.s:		%.c
		$(CC) $(CFLAGS) -S $<



