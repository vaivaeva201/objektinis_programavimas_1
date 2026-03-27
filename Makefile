main:
	g++ -std=c++17 strategija_3.cpp funkcijos.cpp -o programa

run: main
	./programa

clean:
	rm -f programa