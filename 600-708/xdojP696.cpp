#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    int n, arr[30];
    int maxn, minn, maxIndex, minIndex;
    int temp;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    minn = *min_element(arr, arr + n);
    minIndex = min_element(arr, arr + n) - arr;
    /*swap(arr[0], arr[minIndex]);*/
    
    maxn = *max_element(arr, arr + n);
    maxIndex = max_element(arr, arr + n) - arr;
    //swap(arr[n-1], arr[maxIndex]);

    arr[0] ^= arr[minIndex];
    arr[minIndex] ^= arr[0];
    arr[0] ^= arr[minIndex];

    arr[n-1] ^= arr[maxIndex];
    arr[maxIndex] ^= arr[n-1];
    arr[n-1] ^= arr[maxIndex];

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';

    return 0;    
}