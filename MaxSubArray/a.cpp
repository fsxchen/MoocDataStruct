#include <iostream>
using namespace std;

const int MIN_INT = 0x80000000;

inline int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if(b >= a && b >= c) return b;
    else return c;
}

void findCrossSubArray(int *arr, int low, int mid, int high, int returnArr[]) {
    int leftSum = MIN_INT;
    int lsum = 0;
    int max_left, max_right;
    int i, j;
    for (i = mid; i >= 0; i--) {
        lsum = lsum + arr[i];
        if (lsum > leftSum){
            leftSum = lsum;
            max_left = i;
        }
    }

    int rightSum = MIN_INT;
    int rsum = 0;
    for (j = mid + 1; j <= high; ++j) {
        rsum = rsum + arr[j];
        if (rsum > rightSum){
            rightSum = rsum;
            max_right = j;
        }
    }
    returnArr[0] = max_left; returnArr[1] = max_right; returnArr[2] = leftSum + rightSum;
}

void findMaxSubArray(int *arr, int low, int high, int resultArr[]) {
    if(low == high) {
        resultArr[0] = low;
        resultArr[1] = high;
        resultArr[2] = arr[low];
        return;
    } else {
        int lResArr[3], rResArr[3], cResArr[3];
        int mid = (high + low) / 2;
        findCrossSubArray(arr, low, mid, high, cResArr);
        findMaxSubArray(arr, low, mid, lResArr);
        findMaxSubArray(arr, mid + 1, high, rResArr);
        if ((max(lResArr[2], rResArr[2], cResArr[2])) == lResArr[2]){
            resultArr[0] = lResArr[0];
            resultArr[1] = lResArr[1];
            resultArr[2] = lResArr[2];
        }
        else if ((max(lResArr[2], rResArr[2], cResArr[2])) == rResArr[2]){
            resultArr[0] = rResArr[0];
            resultArr[1] = rResArr[1];
            resultArr[2] = rResArr[2];
        }
        else {
            resultArr[0] = cResArr[0];
            resultArr[1] = cResArr[1];
            resultArr[2] = cResArr[2];
        }
    }

}

int main () {
    int K;
    cin >> K;
    int *arr = new int[K];
    for(int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    int res[3];
    int resultArr[3] = {};
    findMaxSubArray(arr,0, K - 1, resultArr);
    cout << resultArr[2] << ' '<< arr[resultArr[0]] << ' ' << arr[resultArr[1]] << endl;

    delete[] arr;
    return 0;
}
