PWD = /home/deathgod/SourceCode/CPP/src
C = clang
CXX = clang++
SOURCE_CPP = main.cpp
TARGET = main.o
PARAMS = -std=c++2a

touch:
	touch main.cpp

compile:	
	$(CXX) $(SOURCE_CPP) -o $(TARGET) $(PARAMS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)

move:
	mv *.cpp $(PWD)
