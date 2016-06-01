build:
	gcc Object.h -o Object
rebuild:
	make clean
	make build
test:
	make build
	gcc private/example.c -o test
	./test
clean:
	rm Object
	rm test
