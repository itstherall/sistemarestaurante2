executable: objects
	g++ -pedantic -std=c++11 -o comanda
	@echo "Successful compilation!"
   
objects: *.cpp
	g++ -pedantic -std=c++11 *.cpp