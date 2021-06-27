PWD = E://CPP_LEETCODE
C = clang
CXX = clang++
SOURCE_CPP = main.cpp
TARGET = main.exe
PARAMS = -g  -Wall -static-libgcc -fcolor-diagnostics --target=x86_64-w64-mingw -std=c++17
    

touch:
	touch main.cpp

check:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./main.exe

compile:	
	$(CXX) $(SOURCE_CPP) -o $(TARGET) $(PARAMS)

run:
	./$(TARGET)

clean:
	rm $(TARGET)

move:
	mv *.cpp $(PWD)
