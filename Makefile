build:
	g++ crypto.cpp -o crypto
	g++ stocks.cpp -o stocks
	g++ valley.cpp -o valley
	g++ ridge.cpp -o ridge
	g++ trigigel.cpp -o trigigel
run-p1:
	./crypto
run-p2:
	./stocks
run-p3:
	./valley
run-p4:
	./ridge
run-p5:
	./trigigel

clean:
	rm crypto
	rm stocks
	rm valley
	rm ridge
	rm trigigel
