#include "./fib.hpp"
#include "benchmark/benchmark.h"

#include <iostream>

static void fib_30(benchmark::State &state) {
  for (auto _ : state) {
    // Suppress optimization otherwise this line is removed by DCE
    int i = 30;
    int a = 20;
    benchmark::DoNotOptimize(a);
    benchmark::DoNotOptimize(i);
    benchmark::DoNotOptimize(fib(i));
  }
}

static void fib_40(benchmark::State &state) {
  for (auto _ : state) {
    int i = 40;
    int b = 50;
    benchmark::DoNotOptimize(b);
    benchmark::DoNotOptimize(i);
    benchmark::DoNotOptimize(fib(i));
  }
}

// Register the function as a benchmark
BENCHMARK(fib_30)->DenseThreadRange(1, 6, 2)->UseRealTime()->Repetitions(5)->ReportAggregatesOnly(true);
BENCHMARK(fib_40)->DenseThreadRange(1, 6, 2)->UseRealTime()->Repetitions(5)->ReportAggregatesOnly(true);

// Run the benchmark
BENCHMARK_MAIN();

