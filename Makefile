all:main

main:main.cc svgcpp.cc
	g++ -o $@ $^ -O2 -std=c++14

format:main.cc svgcpp.cc svgcpp.h
	clang-format -style=google -i $^

clean:
	rm -rf main a.svg
