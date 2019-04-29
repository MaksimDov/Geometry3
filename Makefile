CFLAGS = -Wall -Werror
OBJ = g++ $(CFLAGS) -c $< -o $@
TEST = g++ $(GFLAGS) -I thirdparty/catch2 -c $< -o $@

.PHONY: clean

all: target1 target2 target3 target4 bin/geometry.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

target3:
	mkdir -p build/src

target4:
	mkdir -p build/test


bin/geometry.exe: build/src/main.o build/src/areCollinear.o build/src/circle_intersects.o build/src/getCos.o build/src/getMax.o build/src/getMin.o build/src/getSlope.o build/src/getYIntercept.o build/src/peresech.o build/src/printCircle.o build/src/printPoligon.o build/src/printTriangle.o build/src/projectionsIntersect.o build/src/proverka.o
	g++ $(CFLAGS) $^ -o $@

build/src/main.o: src/main.c src/geometry.h
	$(OBJ)

build/src/circle_intersects.o: src/circle_intersects.c src/geometry.h
	$(OBJ)

build/src/printCircle.o: src/printCircle.c src/geometry.h
	$(OBJ)

build/src/printPoligon.o: src/printPoligon.c src/geometry.h
	$(OBJ)

build/src/printTriangle.o: src/printTriangle.c src/geometry.h
	$(OBJ)

build/src/proverka.o: src/proverka.c src/geometry.h
	$(OBJ)

build/src/peresech.o: src/peresech.c src/geometry.h
	$(OBJ)

build/src/areCollinear.o: src/areCollinear.c src/geometry.h
	$(OBJ)

build/src/getCos.o: src/getCos.c src/geometry.h
	$(OBJ)

build/src/getMax.o: src/getMax.c src/geometry.h
	$(OBJ)

build/src/getMin.o: src/getMin.c src/geometry.h
	$(OBJ)

build/src/getSlope.o: src/getSlope.c src/geometry.h
	$(OBJ)

build/src/getYIntercept.o: src/getYIntercept.c src/geometry.h
	$(OBJ)

build/src/projectionsIntersect.o: src/projectionsIntersect.c src/geometry.h
	$(OBJ)



bin/geometry_test.exe: build/test/test.o build/test/test_circle_intersects.o build/test/test_printCircle.o build/test/test_printPoligon.o build/test/test_printTriangle.o build/test/test_proverka.o build/test/test_getCos.o build/test/test_getMax.o build/test/test_getMin.o build/test/test_getSlope.o build/test/test_getYIntercept.o build/test/test_projectionsIntersect.o
	g++ $(CFLAGS)  $^ -o $@

build/test/test.o: test/test.c test/geometry.h
	$(TEST)
build/test/test_circle_intersects.o: test/test_circle_intersects.c test/geometry.h
	$(TEST)

build/test/test_printCircle.o: test/test_printCircle.c test/geometry.h
	$(TEST)

build/test/test_printPoligon.o: test/test_printPoligon.c test/geometry.h
	$(TEST)

build/test/test_printTriangle.o: test/test_printTriangle.c test/geometry.h
	$(TEST)

build/test/test_proverka.o: test/test_proverka.c test/geometry.h
	$(TEST)

build/test/test_areCollinear.o: test/test_areCollinear.c test/geometry.h
	$(TEST)

build/test/test_getCos.o: test/test_getCos.c test/geometry.h
	$(TEST)

build/test/test_getMax.o: test/test_getMax.c test/geometry.h
	$(TEST)

build/test/test_getMin.o: test/test_getMin.c test/geometry.h
	$(TEST)

build/test/test_getSlope.o: test/test_getSlope.c test/geometry.h
	$(TEST)

build/test/test_getYIntercept.o: test/test_getYIntercept.c test/geometry.h
	$(TEST)

build/test/test_projectionsIntersect.o: test/test_projectionsIntersect.c test/geometry.h
	$(TEST)




clean:
	rm build/*.o
	rm bin/*.exe
	rm -R -f build
	rm -R -f bin





 

