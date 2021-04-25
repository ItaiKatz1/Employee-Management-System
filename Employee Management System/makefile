CC = g++
OBJS = Employee.o DataBase.o main.o
EXEC = run
DEBUG_FLAG = -g
COMP_FLAG = -c
CLEAN = clean
$(EXEC):$(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@
Employee.o:Employee.h Employee.cpp
	$(CC) $(COMP_FLAG) $*.cpp
DataBase.o:DataBase.h DataBase.cpp
	$(CC) $(COMP_FLAG) $*.cpp
main.o:main.cpp Employee.h DataBase.h
	$(CC) $(COMP_FLAG) $*.cpp
clean:
	rm -f $(OBJS) $(EXEC)
