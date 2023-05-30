
all: algorithms graph salesman

algorithms:
	@mkdir -p AlgorithmsTests/build
	@cmake -B"AlgorithmsTests/build" AlgorithmsTests/.
	@$(MAKE) -C AlgorithmsTests/build
	./AlgorithmsTests/build/AlgorithmsTests

graph:
	@mkdir -p GraphTests/build
	@cmake -B"GraphTests/build" GraphTests/.
	@$(MAKE) -C GraphTests/build
	./GraphTests/build/GraphTests

salesman:
	@mkdir -p SalesmanTests/build
	@cmake -B"SalesmanTests/build" SalesmanTests/.
	@$(MAKE) -C SalesmanTests/build
	./SalesmanTests/build/SalesmanTests

clean:
	rm -rf SalesmanTests/build
	rm -rf GraphTests/build
	rm -rf AlgorithmsTests/build