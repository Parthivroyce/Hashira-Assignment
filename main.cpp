/***************************************************************
 * Author: Parthiv Roychowdhury
 * Assignment: Secret Reconstruction using Lagrange Interpolation
 * Language: C++ (No external libraries used except standard headers)
 * 
 * Description: Converts values from various bases to decimal and
 *              reconstructs the secret (f(0)) using integer-based
 *              Lagrange interpolation on selected k points.
 ***************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

struct Point {
    int x;
    ull y;
};

// I am Converting just a string in a given base to decimal (ULL)
ull baseToDecimal(const string& value, int base) {
    ull result = 0;
    for (char c : value) {
        int digit = isdigit(c) ? c - '0' : tolower(c) - 'a' + 10;
        result = result * base + digit;
    }
    return result;
}

// I am using Lagrange interpolation at x = 0 to get constant term (f(0))
ull lagrangeInterpolationAtZero(const vector<Point>& points, int k) {
    ull result = 0;
    for (int i = 0; i < k; ++i) {
        long long xi = points[i].x;
        ull yi = points[i].y;
        long long num = 1, denom = 1;

        for (int j = 0; j < k; ++j) {
            if (i != j) {
                long long xj = points[j].x;
                num *= -xj;
                denom *= (xi - xj);
            }
        }
        if (denom == 0) continue;
        result += yi * (num / denom); // Integer interpolation
    }
    return result;
}

int main() {
    // Testcase 1 sample
    vector<Point> tc1 = {
        {1, baseToDecimal("4", 10)},
        {2, baseToDecimal("111", 2)},
        {3, baseToDecimal("12", 10)},
        {6, baseToDecimal("213", 4)}
    };
    int k1 = 3;

    // Testcase 2
    vector<Point> tc2 = {
        {1, baseToDecimal("13444211440455345511", 6)},
        {2, baseToDecimal("aed7015a346d63", 15)},
        {3, baseToDecimal("6aeeb69631c227c", 15)},
        {4, baseToDecimal("e1b5e05623d881f", 16)},
        {5, baseToDecimal("316034514573652620673", 8)},
        {6, baseToDecimal("2122212201122002221120200210011020220200", 3)},
        {7, baseToDecimal("20120221122211000100210021102001201112121", 3)},
        {8, baseToDecimal("20220554335330240002224253", 6)},
        {9, baseToDecimal("45153788322a1255483", 12)},
        {10, baseToDecimal("1101613130313526312514143", 7)}
    };
    int k2 = 7;

    // Sort by x-coordinate
    sort(tc1.begin(), tc1.end(), [](Point a, Point b) { return a.x < b.x; });
    sort(tc2.begin(), tc2.end(), [](Point a, Point b) { return a.x < b.x; });

    // Select k points for interpolation
    vector<Point> p1(tc1.begin(), tc1.begin() + k1);
    vector<Point> p2(tc2.begin(), tc2.begin() + k2);

    // Compute and output secrets
    ull secret1 = lagrangeInterpolationAtZero(p1, k1);
    ull secret2 = lagrangeInterpolationAtZero(p2, k2);

    cout << "\nSecret for Testcase 1 (f(0)) = " << secret1 << endl;
    cout << "Secret for Testcase 2 (f(0)) = " << secret2 << endl;

    return 0;
}
