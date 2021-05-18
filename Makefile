CXX=g++
all:test_gate test_adder

test_gate: test_gate.o gate.o
	$(CXX) $^  -o $@
test_adder: test_adder.o adder.o gate.o
	$(CXX) $^  -o $@

%.o: %.cpp
	$(CXX) -c $<
clean:
	rm -r *.o test_adder test_gate
-include makefile.dep
