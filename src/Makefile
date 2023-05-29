
all: interface

submodules:
	cd ..
	git submodule update --init --recursive
	git submodule update --recursive --remote
	cd src


s21_graph.a:
	@mkdir -p Graph/build
	@cmake -B"Graph/build" Graph/.
	@$(MAKE) -C Graph/build s21_graph.a

s21_graph_algorithms.a:
	@mkdir -p GraphAlgorithms/build
	@cmake -B"GraphAlgorithms/build" GraphAlgorithms/.
	@$(MAKE) -C GraphAlgorithms/build s21_graph_algorithms.a

interface:
	mkdir -p build
	@cmake -B"build" .
	@$(MAKE) -C build
	./build/simpleNavigator


# ant_test:
# 	@mkdir -p Tests/build
# 	@cmake -B"Tests/build" Tests/AntColonyTests/.
# 	@$(MAKE) -C Tests/build
# 	./Tests/build/AntColonyTests

clean_graph:
	rm -rf Graph/build

clean_algs:
	rm -rf GraphAlgorithms/build

clean: clean_graph clean_algs
	rm -rf build
	rm -rf Tests/build