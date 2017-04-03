#include "TwoDimensionKnapsack.hpp"
#include <cassert>
// #include <iostream>
using namespace std;

#define TEST_MAX 1024

struct ZOKTest {
    int value[MAX];
    int weight1[MAX];
    int weight2[MAX];
    int count;
    int w1;
    int w2;
    int result;
} test_cases[] = {
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 1, 3, 9, 7, 2, 2, 3, 4, 6, 8 }, 
        { 0, 3, 2, 4, 7, 9, 2, 3, 1, 4, 5 }, 
        10, 10, 10, 22,
    },      // 0
    { 
        { 0, 1, 7, 3, 7, 5,  4, 7, 8, 4, 10 },
        { 0, 2, 4, 6, 8, 10, 1, 3, 15, 7, 9 }, 
        { 0, 1, 7, 3, 8, 10, 11, 3, 5, 3, 9 }, 
        10, 20, 20, 25
    },      // 1
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 
        { 0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 
        10, 25, 25, 45
    },      // 2
    { 
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
        { 0, 1, 2, 4, 7, 9, 13, 4, 3, 2, 11 }, 
        { 0, 1, 3, 8, 4, 14, 13, 4, 2, 1, 1 }, 
        10, 20, 20, 34
    },      // 3
    {
        { 0, 1, 1, 5,  4, 9, 7,  31, 13, 34, 21, 17 },
        { 0, 1, 6, 31, 5, 9, 10, 34, 1,  3,  17, 3 },
        { 0, 5, 2, 11, 4, 6, 2,  4,  7,  13, 7,  1 },
        11, 50, 50, 106
    },      // 4
    {
        { 0, 12, 142, 5,  14, 15,  45, 42, 61, 41, 0,  42, 42, 25, 14, 215, 45, 42, 1,  31 },
        { 0, 42, 2,   15, 4,  15,  15, 42, 3,  1,  10, 12, 1,  52, 14, 1,   4,  4,  1,  4  },
        { 0, 2,  3,   5,  43, 21,  45, 2,  13, 1,  1,  37, 42, 5,  14, 5,   5,  2,  6,  41 },
        19, 80, 80, 635
    },      // 5
};


int main()
{
    int count = sizeof(test_cases) / sizeof(ZOKTest);
    for (int i = 0; i < count; i++) {
        ZOKTest & t = test_cases[i];
        int r = TwoDimensionKnapsack(t.value, t.weight1, t.weight2, t.count, t.w1, t.w2);
        // cout << i << ": " << r << endl;
        assert(r == t.result);
    }

    return 0;
}
