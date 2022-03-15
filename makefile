all:
	g++ -Isrc -Iinclude src/main.cpp -o pcpp
	gcc -Isrc -Iinclude src/main.c -o pcp

cpp:
	g++ -Isrc -Iinclude src/main.cpp -o pcpp

c:
	gcc -Isrc -Iinclude src/main.c -o pcp