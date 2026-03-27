main:
	g++ -std=c++17 konteinerius_tyrimas.cpp funkcijos.cpp -o programa

run: main
	./programa

clean:
	rm -f programa