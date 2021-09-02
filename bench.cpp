#include "./fib.hpp"
#include "benchmark/benchmark.h"

#include <iostream>

static void fib_10(benchmark::State &state) {
  for (auto _ : state) {
    // Suppress optimization otherwise this line is removed by DCE
    int i = 10;
    int a = 20;
    std::cout << "a:" << a << std::endl;
    benchmark::DoNotOptimize(i);
    benchmark::DoNotOptimize(fib(i));
  }
}

static void fib_20(benchmark::State &state) {
  for (auto _ : state) {
    int i = 20;
    int b = 50;
    std::cout << "b:" << b << std::endl;
    benchmark::DoNotOptimize(i);
    benchmark::DoNotOptimize(fib(i));
  }
}

// Register the function as a benchmark
BENCHMARK(fib_10);
BENCHMARK(fib_20);

// Run the benchmark
BENCHMARK_MAIN();

