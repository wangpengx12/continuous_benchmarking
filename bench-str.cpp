#include "benchmark/benchmark.h"
#include <string.h>
#include <iostream>

static void BM_memcpy(benchmark::State& state) {
  char* src = new char[state.range(0)];
  char* dst = new char[state.range(0)];

  memset(src, 'x', state.range(0));
  for (auto _ : state) {
    memcpy(dst, src, state.range(0));
  }
  state.counters["ops"] = benchmark::Counter(state.iterations(), benchmark::Counter::kIsRate);
  state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(state.range(0)));
  delete[] src;
  delete[] dst;
}



// Register the function as a benchmark
BENCHMARK(BM_memcpy)->Range(8, 8<<10);;
// BENCHMARK(fib_40)->DenseThreadRange(1, 6, 2)->UseRealTime()->Repetitions(5)->ReportAggregatesOnly(true);

extern bool FLAGS_benchmark_counters_tabular;
// Run the benchmark
// BENCHMARK_MAIN();
//
int main(int argc, char** argv) {
  benchmark::Initialize(&argc, argv);
  FLAGS_benchmark_counters_tabular = true;
  benchmark::RunSpecifiedBenchmarks();
}

