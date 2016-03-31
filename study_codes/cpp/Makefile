CROSS_COMPILE=

CC=$(CROSS_COMPILE)g++
CFLAGS= -c -g -Wall -I./
LDFLAGS= -lpthread -lrt

STRIP=$(CROSS_COMPILE)strip

SOURCES= 

OBJECTS=$(SOURCES:.cpp=.o)

TARGET=daemon_app

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 
# 	$(STRIP) $(TARGET)
.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(TARGET)
