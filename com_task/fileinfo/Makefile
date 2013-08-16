
TARGET =	libfileinfo.a

IDIR =.
CC=g++
CFLAGS=-I$(IDIR) -std=c++11 -O0 -g -gdwarf-2 -Wall -fPIC -fmessage-length=0 -pthread

ODIR=./obj
SDIR=.
LDIR =.

LIBS=

_DEPS = FileInfo.h FileList.h FileListCreator.h FileUtils.h LinuxFileList.h LinuxFileUtils.h WinFileList.h WinFileUtils.h LinuxThreadPool.h FileInfoLib.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = FileInfo.o FileList.o FileListCreator.o FileUtils.o LinuxFileList.o LinuxFileUtils.o WinFileList.o WinFileUtils.o LinuxThreadPool.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


all:	$(ODIR) $(TARGET)

$(TARGET): $(OBJ) 
	ar cvrs $@ $^ 
	
#g++ -shared -o $@ $^ $(CFLAGS) $(LIBS)
	
$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR):
	@mkdir -p $@ 

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
