CROSS_COMPILE=

CC=$(CROSS_COMPILE)g++
CFLAGS= -c -g -Wall -I./
LDFLAGS= -lpthread -lrt

STRIP=$(CROSS_COMPILE)strip

SOURCES= copy_constructor.cpp

OBJECTS=$(SOURCES:.cpp=.o)

TARGET=execute_app

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 
# 	$(STRIP) $(TARGET)
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(TARGET)
