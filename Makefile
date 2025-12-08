all: main
 
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iheaders
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
 
SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.hpp' -print)
 
main: $(SRCS) $(HEADERS)
    $(CXX) $(CXXFLAGS) $(SRCS) -o "$@" $(LIBS)
 
main-debug: $(SRCS) $(HEADERS)
    $(CXX) $(CXXFLAGS) -U_FORTIFY_SOURCE -O0 $(SRCS) -o "$@" $(LIBS)
 
clean:
    rm -f main main-debug
 
.PHONY: all clean
