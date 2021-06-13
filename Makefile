CXX=g++
ENABLE_DEBUG=
#ENABLE_DEBUG+=-DDEBUG
all:test_gate test_adder test_sequential

test_gate: test_gate.o gate.o input_cmp.o
	$(CXX)   $^  -o $@
test_adder: test_adder.o adder.o gate.o input_cmp.o
	$(CXX) $^  -o $@
test_sequential: test_sequential.o sequential.o gate.o input_cmp.o
	$(CXX) $^ -DDEBUG  -o $@
%.o: %.cpp
	$(CXX) $(ENABLE_DEBUG) -c $<
clean:
	rm -rf *.o test_adder test_gate test_sequential
-include makefile.dep
