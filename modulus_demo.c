#include <stdio.h>

int main() {
    int size = 4;
    int nums = 30;
    // can use size for an array eg: int ai[size];

    for (int i=0; i< nums; i+=1) {
        int idx = i % size; //modulus keeps idx in range 0 to size -1

        printf("i: %2d, idx: %2d, size: %2d, nums: %2d\n", i, idx, size, nums);
    }
}