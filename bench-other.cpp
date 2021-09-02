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
  state.counters["ops"] = benchmark::Counter(state.iterations(), benchmark::Counter::kIsRate)
}

static void fib_40(benchmark::State &state) {
  for (auto _ : state) {
    int i = 40;
    int b = 50;
    benchmark::DoNotOptimize(b);
    benchmark::DoNotOptimize(i);
    benchmark::DoNotOptimize(fib(i));
  }
  state.counters["ops"] = benchmark::Counter(state.iterations(), benchmark::Counter::kIsRate)
}

// Register the function as a benchmark
BENCHMARK(fib_30)->DenseThreadRange(1, 6, 2)->UseRealTime()->Repetitions(5)->ReportAggregatesOnly(true);
BENCHMARK(fib_40)->DenseThreadRange(1, 6, 2)->UseRealTime()->Repetitions(5)->ReportAggregatesOnly(true);

extern bool FLAGS_benchmark_counters_tabular;
// Run the benchmark
// BENCHMARK_MAIN();
//
int main(int argc, char** argv) {
  benchmark::Initialize(&argc, argv);
  FLAGS_benchmark_counters_tabular = true;
  benchmark::RunSpecifiedBenchmarks();
}

