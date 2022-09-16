CXX = g++
INCLUDES = -I /usr/local/include/eigen3 -I /usr/local/include/jsoncons -I /usr/local/include/jsoncons_ext -I /usr/local/include/jsoncons_ext/csv
objects = ekf.o fusion.o geo_ned.o run_fusion.o utils.o
CPPFLAGS = $(INCLUDES)

all: $(objects) main

$(filter %.o,$(obj_files)): %.o: %.cpp
	echo "target: $@ prereq: $<"
$(filter %.result,$(obj_files)): %.result: %.raw
	echo "target: $@ prereq: $<" 

%.o : %.cpp
		$(CXX) -c $(CPPFLAGS) $< -o $@

main: main.cpp
	$(CXX) $(CPPFLAGS) $(LDFLAGS) main.cpp *.o -o main

clean:
	rm -f $(objects) main