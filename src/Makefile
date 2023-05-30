
all: interface start

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
	mkdir -p ../build ; cmake -B"../build" .
	$(MAKE) -C ../build

dist:
	tar czf ../dist.tar *

start:
	./../build/simpleNavigator

clean_graph:
	rm -rf Graph/build

clean_algs:
	rm -rf GraphAlgorithms/build

test:
	@$(MAKE) -C Tests

clean: clean_graph clean_algs
	rm -rf ../build
	@$(MAKE) clean -C Tests
	
dvi:
	mkdir -p documentation
	@doxygen Doxyfile && mv html documentation
	@open documentation/html/index.html

clang:
	cp ../matetials/linters/.clang-format .
	find . -name "*.cс" -o -name "*.h" | xargs clang-format -i

