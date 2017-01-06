CXX ?= g++

CXXFLAGS += -c -Wall $(shell pkg-config --cflags opencv)
LDFLAGS += $(shell pkg-config --libs --static opencv)

all: contours

contours: ./bin/contours2.o; $(CXX) $< -o $@ $(LDFLAGS)

./bin/%.o: ./src/%.cpp; $(CXX) $< -o $@ $(CXXFLAGS)

clean: ; rm -rf ./bin/*.o contours
