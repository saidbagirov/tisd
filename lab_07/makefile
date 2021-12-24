INC = ./inc/
OBJ = ./out/
SRC = ./src/
CFLAGS = -std=c99 -I$(INC) -Wall -Werror -pedantic -c

app.exe: $(OBJ)main.o $(OBJ)conn.o $(OBJ)graph.o $(OBJ)io.o $(OBJ)matrix.o
	gcc -o $@ $^

$(OBJ)main.o: $(SRC)main.c
	gcc $(CFLAGS) -o $@ $^

$(OBJ)conn.o: $(SRC)conn.c
	gcc $(CFLAGS) -o $@ $^

$(OBJ)graph.o: $(SRC)graph.c
	gcc $(CFLAGS) -o $@ $^

$(OBJ)io.o: $(SRC)io.c
	gcc $(CFLAGS) -o $@ $^

$(OBJ)matrix.o: $(SRC)matrix.c
	gcc $(CFLAGS) -o $@ $^

run: app.exe
	./$^

clean:
	rm ./out/*.o *.exe *.png *.txt