#include <boost/text/string.hpp>

#include "string_objects.hpp"

#include <benchmark/benchmark.h>

#include <iostream>


void BM_string_view_copy(benchmark::State & state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
            boost::text::string_view(string_views[state.range(0)]));
    }
}

void BM_string_copy(benchmark::State & state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(boost::text::string(strings[state.range(0)]));
    }
}

void BM_unencoded_rope_copy(benchmark::State & state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
            boost::text::unencoded_rope(unencoded_ropes[state.range(0)]));
    }
}

void BM_unencoded_rope_view_copy(benchmark::State & state)
{
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
            boost::text::unencoded_rope_view(unencoded_rope_views[state.range(0)]));
    }
}

BENCHMARK(BM_string_view_copy) BENCHMARK_ARGS();
BENCHMARK(BM_string_copy) BENCHMARK_ARGS();
BENCHMARK(BM_unencoded_rope_copy) BENCHMARK_ARGS();
BENCHMARK(BM_unencoded_rope_view_copy) BENCHMARK_ARGS();

BENCHMARK_MAIN()
