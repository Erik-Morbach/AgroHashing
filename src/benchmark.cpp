#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include "sensor.hpp"
#include "linkedHashTable.hpp"
#include "openHashTable.hpp"

using namespace std;
using namespace std::chrono;

size_t getMemoryKB() {
    ifstream file("/proc/self/status");
    string line;
    while (getline(file, line)) {
        if (line.rfind("VmRSS:", 0) == 0) {
            size_t val;
            istringstream ss(line.substr(6));
            ss >> val;
            return val;
        }
    }
    return 0;
}

template<typename Table>
void runBenchmark(const string& name, Table& table, int count) {
    cout << "=== " << name << " ===" << endl;
    cout << "Sensors: " << count << endl;

    size_t memBefore = getMemoryKB();
    auto insertStart = high_resolution_clock::now();

    for (int i = 0; i < count; i++) {
        table.add(Sensor(i, "type" + to_string(i % 10), "loc" + to_string(i % 50)));
    }

    auto insertEnd = high_resolution_clock::now();
    size_t memAfter = getMemoryKB();

    auto searchStart = high_resolution_clock::now();
    for (int i = 0; i < count; i++) {
        table.search(Sensor(i, "", ""));
    }
    auto searchEnd = high_resolution_clock::now();

    long long insertUs = duration_cast<microseconds>(insertEnd - insertStart).count();
    long long searchUs = duration_cast<microseconds>(searchEnd - searchStart).count();

    cout << "Insert time:    " << insertUs << " us (" << insertUs / 1000.0 << " ms)" << endl;
    cout << "Search time:    " << searchUs << " us (" << searchUs / 1000.0 << " ms)" << endl;
    cout << "Collisions:     " << table.getCollisions() << endl;
    cout << "Memory delta:   " << (long long)(memAfter - memBefore) << " KB" << endl;
    cout << "Memory after:   " << memAfter << " KB" << endl;
    cout << endl;
}

void bench1000() {
    cout << "============================================================" << endl;
    cout << "  1000 sensors | Chaining buckets=101 | Open slots=2003" << endl;
    cout << "============================================================" << endl;
    LinkedHashTable<Sensor, 101> chaining;
    runBenchmark("Chaining (Linked List)", chaining, 1000);

    OpenHashTable<Sensor, 2003> open;
    runBenchmark("Open Addressing (Linear Probing)", open, 1000);
}

void bench5000() {
    cout << "============================================================" << endl;
    cout << "  5000 sensors | Chaining buckets=101 | Open slots=10007" << endl;
    cout << "============================================================" << endl;
    LinkedHashTable<Sensor, 101> chaining;
    runBenchmark("Chaining (Linked List)", chaining, 5000);

    OpenHashTable<Sensor, 10007> open;
    runBenchmark("Open Addressing (Linear Probing)", open, 5000);
}

int main(int argc, char* argv[]) {
    int count = 0;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg.rfind("--count=", 0) == 0) {
            count = stoi(arg.substr(8));
        }
    }

    cout << "Running benchmarks..." << endl;
    cout << "Note: transform logs are from existing instrumentation" << endl << endl;

    if (count == 0 || count == 1000) bench1000();
    if (count == 0 || count == 5000) bench5000();

    return 0;
}
