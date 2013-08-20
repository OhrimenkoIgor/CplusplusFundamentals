CXXFLAGS = -std=c++11 -O0 -g -gdwarf-2 -Wall -fmessage-length=0

OBJS =		task1.o

LIBS =

TARGET =	task1.elf

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
