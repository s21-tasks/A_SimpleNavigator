all: ant

ant:
	@mkdir -p build
	@cmake -B"build" AntColonyTests/.
	@$(MAKE) -C build
	./build/AntColonyTests

clean:
	rm -rf build