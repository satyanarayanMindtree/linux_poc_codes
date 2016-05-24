CROSS_COMPILE=

CC=$(CROSS_COMPILE)gcc
CFLAGS = -g -wall
LDFLAGS = -lpthread -lrt

sources= pipes.c
objects=$(sources:.c =.o)

target= pipe_bin

all: $(objects) $(target)

$(target): $(objects)
	$(CC) $(objects) -o $@ $(LDFLAGS)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
	
clean:
	$(RM) *.o $(target)
