CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: sub_main1 sub_main2 sub_main3

sub_main1: sub_main1.o Hashing.o
	$(CXX) $(CXXFLAGS) $^ -o $@

sub_main2: sub_main2.o Subtask2.o
	$(CXX) $(CXXFLAGS) $^ -o $@

sub_main3: sub_main3.o Subtask3.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o sub_main1 sub_main2 sub_main3