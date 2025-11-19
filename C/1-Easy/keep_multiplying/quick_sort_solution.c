#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int Particiona(int *nums, int left, int right);
void quick_sort(int *nums, int left, int right);


int findFinalValue(int* nums, int numsSize, int original) {
    int i = 0;
    while(i < numsSize && nums[i] != original){
        i++;
    }

    if(i == numsSize){
        return original;
    }

    swap(&nums[0], &nums[i]);

    quick_sort(nums, 1, numsSize-1);

    i = 0;
    while(i < numsSize){
        if(nums[i] == original){
            original = 2 * original;
        }
        i++;
    }

    return original;
}



int Particiona(int *nums, int left, int right){
    int pivo = nums[right];
    int i = left - 1;

    for(int k = left; k < right; k++){
        if(nums[k] <= pivo){
            i++;
            swap(&nums[k], &nums[i]);
        }
    }
    swap(&nums[i+1], &nums[right]);
    return i+1;
}

void quick_sort(int *nums, int left, int right){
    if(left < right){
        int pivo = Particiona(nums, left, right);
        quick_sort(nums, left, pivo-1);
        quick_sort(nums, pivo+1, right);
    }
}