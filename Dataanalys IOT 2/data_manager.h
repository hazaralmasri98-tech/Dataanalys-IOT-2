#pragma once
#include "measurement.h"
#include <vector>
#include <string>

using namespace std;

struct Statistics {
    int count{};
    double sum{}, average{}, min{}, max{}, stddev{};
};

class DataManager {
public:
    void add(double value, const string& time);
    Statistics calculate() const;
    void showAll() const;
    bool readFile(const string& filename);
    bool saveFile(const string& filename) const;
    void sort(bool ascending = true);
    static string currentTime();

private:
    vector<Measurement> data;
};