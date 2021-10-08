LIB = /usr/lib64 # Change this to point to the appropriate location for Boost.
CROW = ./ # Change this if for some reason you are using the Makefile in a different location from the .cpp file.
CROW_FLAGS = -std=c++1y -L $(LIB) -lboost_system -lboost_thread -lpthread
O_FILES = crow_test.o

all: crw_server

crw_server: $(O_FILES)
	g++ $(CROW_FLAGS) $(O_FILES) -o crw_server

crw_server.o: $(CROW)crow_test.cpp
	g++ -c $(CROW_FLAGS) $(CROW)crow_test.cpp

clean:
	rm *.o crw_server