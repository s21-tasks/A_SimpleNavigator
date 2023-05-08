
submodules:
	cd ..; git submodule update --init --recursive

s21_graph.a: submodules
	@mkdir -p Graph/build
	@cmake -B"Graph/build" Graph/.
	@$(MAKE) -C Graph/build s21_graph.a

s21_graph_algorithms.a: submodules
	@mkdir -p GraphAlgorithms/build
	@cmake -B"GraphAlgorithms/build" GraphAlgorithms/.
	@$(MAKE) -C GraphAlgorithms/build s21_graph_algorithms.a

test: submodules
	mkdir -p build
	@cmake -B"build" .
	@$(MAKE) -C build



clean_graph:
	rm -rf Graph/build

clean_algs:
	rm -rf GraphAlgorithms/build

clean: clean_graph clean_algs