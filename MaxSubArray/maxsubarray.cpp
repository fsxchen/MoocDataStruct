#include <iostream>
using namespace std;

void showArray(int* arr, int len) {
    for (int i = 0; i < len; ++i)
        cout << arr[i] << ;
}

int main () {
    int k;
    cout << "请输入一个正整数k:";
    cin >> k;
    int *arr = new int[k];
    for(int i = 0; i < k; i++) {
        cin >> arr[i];
    }
    showArray(arr, k);
    return 0;
}
