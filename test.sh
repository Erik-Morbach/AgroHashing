#!/bin/bash

set -e

echo "Building..."
./build.sh
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
