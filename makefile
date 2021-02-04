Stock: main.o Stock.o Product.o Map.o
	g++ -Wall -fopenmp -o Stock main.cpp Stock.cpp Product.cpp Map.cpp
Stock.o: Stock.cpp Stock.hpp
	g++ -Wall -fopenmp -c Stock.cpp
Map.o: Map.cpp Map.hpp
	g++ -Wall -fopenmp -c Map.cpp
Product.o: Product.cpp Product.hpp
	g++ -Wall -c Product.cpp
main.o: main.cpp
	g++ -Wall -c main.cpp
clean:
	rm Stock main.o Stock.o Map.o Product.o
