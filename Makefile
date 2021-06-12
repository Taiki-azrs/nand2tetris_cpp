CXX=g++
all:test_gate test_adder test_sequential

test_gate: test_gate.o gate.o input_cmp.o
	$(CXX)  $^ -o $@ -g
test_adder: test_adder.o adder.o gate.o
	$(CXX) $^  -o $@
test_sequential: test_sequential.o sequential.o gate.o input_cmp.o
	$(CXX) $^  -o $@
%.o: %.cpp
	$(CXX) -c $<
clean:
	rm -r *.o test_adder test_gate test_sequential
-include makefile.dep
