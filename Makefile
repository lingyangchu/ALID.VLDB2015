APP    = RUN
SRCS = $(wildcard *.cpp)
HDRS = $(wildcard *.h)
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -c -fopenmp -O3 
DBG    = #-g
LIBS   = -fopenmp -O3

#all : $(APP) clean

$(APP) : $(OBJS)
	g++ -o RUN $(LIBS) $(DBG) $(OBJS) 

%.o: %.cpp %.h
	g++ $(CXXFLAGS) $(DBG) $< -o $@

.PHONY: clean
clean :
	-rm $(OBJS) $(APP)

.PHONY: clear
clear :
	-rm $(APP)

