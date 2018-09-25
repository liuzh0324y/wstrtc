
CXX = g++
AR = ar
CXXFLAGS = -I `pwd`/sdk/include -std=c++11 -fPIC
LDFLAGS = -L `pwd`/sdk/libs -lrecorder -pthread
INCLUDE = $(srcdir)/agora
TARGET = libagora.so

objects = recorder.o agora.o

$(TARGET): $(objects)
	$(CXX) $(LDFLAGS) $(objects) -shared -o $(TARGET) 

recorder.o: recorder.cc
	$(CXX) -c $(CXXFLAGS) recorder.cc

agora.o: agora.cc
	$(CXX) -c $(CXXFLAGS) agora.cc

clean:
	rm *.so *.o 