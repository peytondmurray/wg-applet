CC = clang++
DEPS = gtk+-3.0
CFLAGS = $(shell pkg-config --cflags $(DEPS))
LDFLAGS = $(shell pkg-config --libs $(DEPS))
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

wg-applet: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<


.PHONY: clean
clean:
	rm -f $(OBJ) wg-applet
