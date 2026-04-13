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
void runBenchmark(const string& name, Table&& table, int count) {
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

void bench(int count) {
    cout << "============================================================" << endl;
    cout << "  " << count << " sensors | Chaining buckets=101,501,1001 | Open slots=2003, 5003" << endl;
    cout << "============================================================" << endl;
    runBenchmark("Chaining (Linked List) 101", LinkedHashTable<Sensor, 101>(), count);
    runBenchmark("Chaining (Linked List) 501", LinkedHashTable<Sensor, 501>(), count);
    runBenchmark("Chaining (Linked List) 1001", LinkedHashTable<Sensor, 1001>(), count);
    runBenchmark("Chaining (Linked List) 10001", LinkedHashTable<Sensor, 10001>(), count);

    if(count <= 2003)
        runBenchmark("Open Addressing (Linear Probing) 2003", OpenHashTable<Sensor, 2003>(), count);
    if(count <= 5003)
        runBenchmark("Open Addressing (Linear Probing) 5003", OpenHashTable<Sensor, 5003>(), count);
    if(count <= 10003)
        runBenchmark("Open Addressing (Linear Probing) 10003", OpenHashTable<Sensor, 10003>(), count);
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

    if (count == 0) {bench(1000); bench(5000); }
    else bench(count);

    return 0;
}
