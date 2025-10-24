#define _CRT_SECURE_NO_WARNINGS  
#include "data_manager.h"
#include <algorithm>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;

void DataManager::add(double value, const string& time) {
    data.push_back({ value, time });
}

Statistics DataManager::calculate() const {
    Statistics s{};
    if (data.empty()) return s;

    s.count = static_cast<int>(data.size());
    s.min = s.max = data.front().value;

    for (const auto& m : data) {
        s.sum += m.value;
        if (m.value < s.min) s.min = m.value;
        if (m.value > s.max) s.max = m.value;
    }

    s.average = s.sum / s.count;

    double acc = 0.0;
    for (const auto& m : data) {
        double d = m.value - s.average;
        acc += d * d;
    }
    s.stddev = std::sqrt(acc / s.count);
    return s;
}

void DataManager::showAll() const {
    if (data.empty()) {
        cout << "No data yet.\n";
        return;
    }
    for (const auto& m : data)
        cout << m.time << "," << m.value << "\n";
}

bool DataManager::readFile(const string& filename) {
    ifstream in(filename);
    if (!in) return false;

    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;
        auto p = line.find(',');
        if (p == string::npos) continue;

        string time = line.substr(0, p);
        string val = line.substr(p + 1);

        for (auto& c : val)
            if (c == ',') c = '.';

        try {
            add(stod(val), time);
        }
        catch (...) {
        }
    }
    return true;
}

bool DataManager::saveFile(const string& filename) const {
    ofstream out(filename);
    if (!out) return false;
    for (const auto& m : data)
        out << m.time << "," << m.value << "\n";
    return true;
}

void DataManager::sort(bool ascending) {
    std::sort(data.begin(), data.end(),
        [ascending](const Measurement& a, const Measurement& b) {
            return ascending ? (a.value < b.value) : (a.value > b.value);
        });
}

std::string DataManager::currentTime() {
    std::time_t t = std::time(nullptr);
    std::tm* tmv = std::localtime(&t);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M", tmv);
    return std::string(buf);
}