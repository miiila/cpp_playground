#include "array.h"

void print_array(int* nums) {
    for (int i = 0; i <5; i++) {
        std::cout << nums[i] << std::endl;
    }
}

void fun() {
    int nums[5] = {0,1};
    nums[0] = 2;
    nums[1] = 5;
    print_array(nums);
}
