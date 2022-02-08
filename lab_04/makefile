CFLAGS = -Wall -Werror -std=c99 -pedantic -g
HDRS_DIR = headers/
OBJ = $(patsubst %.c, %.o, $(wildcard functions/*.c *.c))
.PHONY: all clean run
all: app.exe
app.exe: $(OBJ)
	gcc -o $@ -I $(HDRS_DIR) $(CFLAGS) $^
%.o: %.c
	gcc -c -o $@ -I $(HDRS_DIR) $(CFLAGS) $< -MD
functions/%.o: functions/%.c
	gcc -c -o $@ -I $(HDRS_DIR) $(CFLAGS) $< -MD
clean:
	rm -f *.exe functions/*.o *.o functions/*.d *.d
include $(wildcard functions/*.d *.d)