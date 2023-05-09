all: ant graph

ant:
	@mkdir -p build
	@cmake -B"build" AntColonyTests/.
	@$(MAKE) -C build
	./build/AntColonyTests

graph:
	@mkdir -p build
	@cmake -B"build" GraphTests/.
	@$(MAKE) -C build
	./build/GraphTests

clean:
	rm -rf build