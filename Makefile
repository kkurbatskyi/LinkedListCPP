#DO_NOT_DEBUG = -DNDEBUG
CXX = g++
VERSION = -std=c++14
CFLAGS = -pedantic -Wall -Wextra $(VERSION) $(DO_NOT_DEBUG)
LFLAGS = -Wall $(VERSION) 

INCS = LList.h 

SRCSTEST = LList.cpp\
	testLList.cpp
SRCS = LList.cpp\
	longestLList.cpp
   
OBJSTEST = $(SRCSTEST:.cpp=.o)
OBJS = $(SRCS:.cpp=.o)

EXECTEST = testLList
EXEC = longestLList

all: $(SRCSTEST) $(EXECTEST) $(SRCS) $(EXEC)

# To make an object from source
#.cpp.o: 
%.o:%.cpp $(INCS)
	$(CXX) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJS) 
	$(CXX) $(LFLAGS) $(OBJS) -o $@

$(EXECTEST): $(OBJSTEST) 
	$(CXX) $(LFLAGS) $(OBJSTEST) -o $@ 

# for Windows
clean:
	del *.o  $(EXECTEST).exe $(EXEC).exe
	@echo clean done

# for UNIX / Linux 
remove:
	\rm -f *.o  $(EXECTEST) $(EXEC)
	@echo clean done
