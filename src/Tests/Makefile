
algorithms:
	@mkdir -p build
	@cmake -B"build" AlgorithmsTests/.
	@$(MAKE) -C build
	./build/AlgorithmsTests

graph:
	@mkdir -p build
	@cmake -B"build" GraphTests/.
	@$(MAKE) -C build
	./build/GraphTests

salesman:
	@mkdir -p build
	@cmake -B"build" SalesmanTests/.
	@$(MAKE) -C build
	./build/SalesmanTests

clean:
	rm -rf build