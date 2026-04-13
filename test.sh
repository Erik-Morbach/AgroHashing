#!/bin/bash

set -e

mkdir -p build

echo "Building..."
g++ -std=c++17 -O2 -Isrc src/sensor.cpp src/main.cpp src/sensorapp.cpp -o build/Main
g++ -std=c++17 -O2 -Isrc src/sensor.cpp src/benchmark.cpp -o build/Benchmark
echo "Build OK"

echo ""
echo "============================================================"
echo "  BENCHMARK — 1000 sensors"
echo "============================================================"
./build/Benchmark --count=1000 2>&1 | grep -v "was transformed into"

echo ""
echo "============================================================"
echo "  BENCHMARK — 5000 sensors"
echo "============================================================"
./build/Benchmark --count=5000 2>&1 | grep -v "was transformed into"

echo ""
echo "============================================================"
echo "  INTERACTIVE APP — Chaining (--chaining)"
echo "  register 3 sensors, display, exit"
echo "============================================================"
printf "1\n1\ntemperature\nfield-A\n1\n2\numidity\nfield-B\n1\n3\nph\nfield-C\n5\n0\n" \
    | ./build/Main --chaining 2>&1 | grep -v "was transformed into"

echo ""
echo "============================================================"
echo "  INTERACTIVE APP — Open Addressing (--open)"
echo "  register 3 sensors, display, exit"
echo "============================================================"
printf "1\n1\ntemperature\nfield-A\n1\n2\numidity\nfield-B\n1\n3\nph\nfield-C\n5\n0\n" \
    | ./build/Main --open 2>&1 | grep -v "was transformed into"
