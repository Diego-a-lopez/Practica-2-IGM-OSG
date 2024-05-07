
# Set the default target
TARGET = spinningcube


# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11

# Libraries
LIBS = -losg -losgViewer -losgDB -losgUtil -losgGA -lOpenThreads

# Targets
all: make

make:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(TARGET).cpp $(LIBS)

run: 
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all make run clean

# Add a rule for compiling individual executables
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)
