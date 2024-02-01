# Thanmay
# MSDscript

# Macros
CXX = c++
CFLAGS = --std=c++11
CCSOURCE = main.cpp cmdline.cpp expr.cpp ExprTest.cpp
OBJS = main.o cmdline.o expr.o ExprTest.o
INCS = cmdline.hpp expr.hpp catch.h

# All
All: compiler linker

# Compiler
compiler: $(CCSOURCE) $(INCS)
	$(CXX) $(CFLAGS) -c $(CCSOURCE)

# Linker
linker: $(OBJS)
	$(CXX) $(OBJS) -o msdscript
	

msdscript: All

# PrintM
printM:
	@echo "CXX = c++"
	@echo "CFLAGS = --std=c++14"
	@echo "CCSOURCE = main.cpp cmdline.cpp expr.cpp ExprTest.cpp"
	@echo "OBJS = main.o cmdline.o expr.o ExprTest.o"
	@echo "INCS = cmdline.hpp expr.hpp"

# Phony
.PHONY: clean

# Clean
clean:
	rm -f *.o *.out msdscript
	@echo "CLEAN"

# Run
run: msdscript
	./msdscript --test



