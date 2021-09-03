window.BENCHMARK_DATA = {
  "lastUpdate": 1630637925607,
  "repoUrl": "https://github.com/wangpengx12/continuous_benchmarking",
  "entries": {
    "string memcpy Benchmark": [
      {
        "commit": {
          "author": {
            "email": "wangpeng12@kuaishou.com",
            "name": "wangpeng12"
          },
          "committer": {
            "email": "wangpeng12@kuaishou.com",
            "name": "wangpeng12"
          },
          "distinct": true,
          "id": "f9ae237d6336dca562d116a8cbf3082e05086370",
          "message": "MOD: mod bench-other.cpp to make test happy",
          "timestamp": "2021-09-03T10:58:09+08:00",
          "tree_id": "2ba316b13fb14171eeea689fe9deb129e30bd544",
          "url": "https://github.com/wangpengx12/continuous_benchmarking/commit/f9ae237d6336dca562d116a8cbf3082e05086370"
        },
        "date": 1630637925275,
        "tool": "googlecpp",
        "benches": [
          {
            "name": "BM_memcpy/8",
            "value": 9.010000212583691e-7,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 8.000000000000194e-7 ns\nthreads: 1"
          },
          {
            "name": "BM_memcpy/64",
            "value": 7.999999525054591e-7,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 8.000000000000194e-7 ns\nthreads: 1"
          },
          {
            "name": "BM_memcpy/512",
            "value": 7.999999525054591e-7,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 8.000000000000194e-7 ns\nthreads: 1"
          },
          {
            "name": "BM_memcpy/4096",
            "value": 8.000000661922968e-7,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 7.999999999995858e-7 ns\nthreads: 1"
          },
          {
            "name": "BM_memcpy/8192",
            "value": 8.99999918146932e-7,
            "unit": "ns/iter",
            "extra": "iterations: 1000000000\ncpu: 8.000000000000194e-7 ns\nthreads: 1"
          }
        ]
      }
    ]
  }
}