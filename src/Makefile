MAKEFILE      = Makefile

####### Compiler, tools and options

CXX           = g++
DEFINES       = 
CXXFLAGS      = -pipe -g -std=gnu++11 -Wall -W -fPIC $(DEFINES)
INCPATH       = -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -L/usr/lib -lncurses
DEL_FILE      = rm -f

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = ./AbstractCreator.cpp \
		./AbstractPresenter.cpp \
		./AbstractSolver.cpp \
		./BruteSolver.cpp \
		./CandidateSolver.cpp \
		./Evaluator.cpp \
		./NaiveCreator.cpp \
		./Ncursespresenter.cpp \
		./SeedCreator.cpp \
		./Sudoku.cpp \
		./Tester.cpp \
		./main.cpp 
OBJECTS       = AbstractCreator.o \
		AbstractPresenter.o \
		AbstractSolver.o \
		BruteSolver.o \
		CandidateSolver.o \
		Evaluator.o \
		NaiveCreator.o \
		Ncursespresenter.o \
		SeedCreator.o \
		Sudoku.o \
		Tester.o \
		main.o
TARGET        = qlik_sudoku


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)


all: $(TARGET)

clean: 	
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Compile

AbstractCreator.o: ./AbstractCreator.cpp ./AbstractCreator.h \
		./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractCreator.o ./AbstractCreator.cpp

AbstractPresenter.o: ./AbstractPresenter.cpp ./AbstractPresenter.h \
		./globals.h \
		./Sudoku.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractPresenter.o ./AbstractPresenter.cpp

AbstractSolver.o: ./AbstractSolver.cpp ./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AbstractSolver.o ./AbstractSolver.cpp

BruteSolver.o: ./BruteSolver.cpp ./BruteSolver.h \
		./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o BruteSolver.o ./BruteSolver.cpp

CandidateSolver.o: ./CandidateSolver.cpp ./CandidateSolver.h \
		./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CandidateSolver.o ./CandidateSolver.cpp

Evaluator.o: ./Evaluator.cpp ./Evaluator.h \
		./Sudoku.h \
		./globals.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Evaluator.o ./Evaluator.cpp

NaiveCreator.o: ./NaiveCreator.cpp ./NaiveCreator.h \
		./AbstractCreator.h \
		./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o NaiveCreator.o ./NaiveCreator.cpp

Ncursespresenter.o: ./Ncursespresenter.cpp ./Ncursespresenter.h \
		./AbstractPresenter.h \
		./globals.h \
		./Sudoku.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Ncursespresenter.o ./Ncursespresenter.cpp

SeedCreator.o: ./SeedCreator.cpp ./SeedCreator.h \
		./AbstractCreator.h \
		./AbstractSolver.h \
		./Sudoku.h \
		./globals.h \
		./Evaluator.h \
		./AbstractPresenter.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o SeedCreator.o ./SeedCreator.cpp

Sudoku.o: ./Sudoku.cpp ./Sudoku.h \
		./globals.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Sudoku.o ./Sudoku.cpp

Tester.o: ./Tester.cpp ./Tester.h \
		./Sudoku.h \
		./globals.h \
		./AbstractPresenter.h \
		./Evaluator.h \
		./BruteSolver.h \
		./AbstractSolver.h \
		./CandidateSolver.h \
		./Ncursespresenter.h \
		./SeedCreator.h \
		./AbstractCreator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Tester.o ./Tester.cpp

main.o: ./main.cpp ./globals.h \
		./Tester.h \
		./Sudoku.h \
		./AbstractPresenter.h \
		./Evaluator.h \
		./BruteSolver.h \
		./AbstractSolver.h \
		./CandidateSolver.h \
		./Ncursespresenter.h \
		./SeedCreator.h \
		./AbstractCreator.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o ./main.cpp

