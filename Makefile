CFLAGS = -Wall -Werror
OBJ = g++ $(CFAGS) -c $< -o $@

.PHONY: clean

all: target1 target2 bin/geometry.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

bin/geometry.exe: build/main.o build/areCollinear.o build/circle_intersects.o build/getCos.o build/getMax.o build/getMin.o build/getSlope.o build.getYIntercept.o build/peresech.o build/printCircle.o build/printpoligon.o build/printTriangle.o build/projectionsIntersect.o build/proverka.o
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.c src/geometry.h
	$(OBJ)

build/circle_intersects.o: src/circle_intersects.c src/geometry.h
	$(OBJ)

build/printCircle.o: src/printCircle.c src/geometry.h
	$(OBJ)

build/printPoligon.o: src/printPoligon.c src/geometry.h
	$(OBJ)

build/printTriangle.o: src/printTriangle.c src/geometry.h
	$(OBJ)

build/proverka.o: src/proverka.c src/geometry.h
	$(OBJ)

build/peresech.o: src/peresech.c src/geometry.h
	$(OBJ)

build/areCollinear.o: src/areCollinear.c src/geometry.h
	$(OBJ)

build/getCos.o: src/getCos.c src/geometry.h
	$(OBJ)

build/getMax.o: src/getMax.c src/geometry.h
	$(OBJ)

build/getMin.o: src/getMin.c src/geometry.h
	$(OBJ)

build/getSlope.o: src/getSlope.c src/geometry.h
	$(OBJ)

build/getYIntercept.o: src/getYInterceot.c src/geometry.h
	$(OBJ)

build/projectionsIntersect.o: src/progectionsIntersect.c src/geometry.h
	$(OBJ)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin





 

