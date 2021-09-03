bench: a.out
	./a.out

json: a.out
	./a.out --benchmark_format=json | tee benchmark_result.json

bench-other: other.out
	./other.out

json-other: other.out
	./other.out --benchmark_format=json | tee benchmark_result_other.json

bench-str: str.out
	./str.out
json-str: str.out
	./str.out --benchmark_format=json | tee benchmark_result_str.json

a.out: benchmark/build/src/libbenchmark.a bench.cpp fib.hpp
	clang++ -std=c++14 -O3 -I ./benchmark/include -L ./benchmark/build/src/ -pthread bench.cpp -l benchmark

other.out: benchmark/build/src/libbenchmark.a bench-other.cpp fib.hpp
	clang++ -std=c++14 -O3 -I ./benchmark/include -L ./benchmark/build/src/ -pthread bench-other.cpp -l benchmark -o other.out

str.out: benchmark/build/src/libbenchmark.a bench-str.cpp
	clang++ -std=c++14 -O3 -I ./benchmark/include -L ./benchmark/build/src/ -pthread bench-str.cpp -l benchmark -o str.out

benchmark/build/src/libbenchmark.a: benchmark/build benchmark/googletest
	cd ./benchmark/build && \
	cmake -DCMAKE_BUILD_TYPE=Release -DBENCHMARK_ENABLE_TESTING=true ../ && \
	make -j

benchmark/build: benchmark
	mkdir -p benchmark/build

benchmark:
	[ -d benchmark ] || git clone --depth=1 --single-branch --branch v1.5.0 https://github.com/google/benchmark.git benchmark

benchmark/googletest: benchmark
	[ -d benchmark/googletest ] || git clone --depth=1 --single-branch --branch release-1.10.0 https://github.com/google/googletest.git benchmark/googletest

clean:
	rm -rf a.out other.out benchmark

.PHONY: bench bench-other bench-str json json-other json-str clean
