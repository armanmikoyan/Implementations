CXX := g++
CXXFLAGS := -std=c++20

SRCS := main.cpp

OUT := view

$(OUT): $(SRCS) impl.hpp
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUT)
	./$(OUT)

.PHONY: clean

clean:
	rm -f $(OUT)
