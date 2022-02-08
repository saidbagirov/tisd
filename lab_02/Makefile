CFILES = $(wildcard *.c)
OBJECTS = $(CFILES:%.c=%.o)
CFLAGS = -Werror -Wall -pedantic -std=c99 -g
app.out: $(OBJECTS) *.h
	gcc $(CFLAGS) $(OBJECTS) -o $@
%.o: %.c *.h
	gcc $(CFLAGS) -c $<
run: app.out
	./$^
clean:
	rm *.o *.out