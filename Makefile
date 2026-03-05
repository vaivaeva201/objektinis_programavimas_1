main:
	g++ vektorius.cpp funkcijos.cpp -o programa

run: main
	./programa

clean:
	rm -f programa