CXXFLAGS = -std=c++11 -O0 -g -gdwarf-2 -Wall -fmessage-length=0

OBJS =		task2.o cpmv.o

LIBS =

TARGET =	task2.elf

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
