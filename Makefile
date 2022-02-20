CC:=g++
PROGS:= \
	main \

.PHONY : all
all : $(PROGS)
main: main.o StudentList.o
	$(CC) $^ -o $@
main.o: main.cpp
	$(CC) -c main.cpp
StudentList.o: StudentList.cpp
	$(CC) -c StudentList.cpp
.PHONY : clean
clean:
	rm *.o main

