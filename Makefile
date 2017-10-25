
all: receive send
.PHONY: all

OBJECTS1 = receive.o
OBJECTS2 = send.o
BIN1 = receive
BIN2 = send

CC := gcc

$(BIN1):$(OBJECTS1)
	$(CC) -o $(BIN1) $(OBJECTS1)

$(BIN2):$(OBJECTS2)
		$(CC) -o $(BIN2) $(OBJECTS2)

.PHONY: clean
clean:
	rm $(OBJECTS1) $(OBJECTS2) $(BIN1) $(BIN2)

