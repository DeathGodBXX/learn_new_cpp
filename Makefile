PWD = /home/deathgod/SourceCode/CPP/
C = clang
CXX = clang++
SOURCE_CPP = main.cpp
TARGET = main.o
PARAMS = -std=c++2a

touch:
	touch main.cpp

check:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./main.o

compile:	
	$(CXX) $(SOURCE_CPP) -o $(TARGET) $(PARAMS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)

move:
	mv *.cpp $(PWD)
