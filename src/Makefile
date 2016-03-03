# Austin Chen, 2/18/2016

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2
DEBUG=-Wall -g
OFILES=csvRequester.o swapper.o list.o user.o

requester: $(OFILES)
	$(CXX) $(DEBUG) $(OFILES) -o requester
	@echo "The program is ready!"

.SUFFIXES: .o .cpp

clean:
	-rm -f *.o *~ requester

list.o: list.cpp list.h user.h
user.o: user.cpp user.h
swapper.o: swapper.cpp swapper.h list.h user.h
csvRequester.o: csvRequester.cpp user.h list.h
