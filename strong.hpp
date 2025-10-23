#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

namespace strong {
    namespace {
        static int _count = 0;
    }
    class array {
        std::vector<double> data;
        int num{};

    public:
        array() {
            num = _count;
            std::cout << "array(" << num << ")_created!\n";
            _count++;
        }
        ~array() {
            std::cout << "array(" << num << ")_destroyed!\n";
        }

        inline static array iota(int n) {
            array a;
            a.data.resize(n);
            std::iota(a.data.begin(), a.data.end(), 1);
            return a;
        }

        inline array& show() {
            std::cout << "[ ";
            for (auto x : data) std::cout << x << " ";
            std::cout << "]\n";
            return *this;
        }

        inline array& plus(double x) {
            for (auto& e : data) e += x;
            return *this;
        }
        inline array& minus(double x) {
            for (auto& e : data) e -= x;
            return *this;
        }
        
        inline array& times(double x) {
            for (auto& e : data) e *= x;
            return *this;
        }
        inline array& times(const std::vector<double>& x) {
            for (size_t i = 0; i < data.size(); ++i)
                data[i] *= x[i];
            return *this;
        }

        inline array& divide(double x) {
            for (auto& e : data) e /= x;
            return *this;
        }

        inline array& equal(double x) {
            for (auto& e : data) e = e == x;
            return *this;
        }
        inline array& not_equal(double x) {
            for (auto& e : data) e = e != x;
            return *this;
        }
        inline array& less_than_or_equal(double x) {
            for (auto& e : data) e = e <= x;
            return *this;
        }
        inline array& less_than(double x) {
            for (auto& e : data) e = e < x;
            return *this;
        }
        inline array& greater_than_or_equal(double x) {
            for (auto& e : data) e = e >= x;
            return *this;
        }
        inline array& greater_than(double x) {
            for (auto& e : data) e = e > x;
            return *this;
        }
        inline array& binary_not() {
            for (auto& e : data) e = !e;
            return *this;
        }
        inline array& reverse() {
            std::reverse(data.begin(), data.end());
            return *this;
        }

        inline double max() { return *std::max_element(data.begin(), data.end()); }
        inline double min() { return *std::min_element(data.begin(), data.end()); }

        inline double last() { return data.back(); }
        inline double first() { return data.front(); }
        inline double pick(int n) {
            n--;
            if (n > data.size() || n < 0) return 0;
            return data[n]; 
        }

        inline double sum() { return std::reduce(data.begin(), data.end()); }

    }; 
}
