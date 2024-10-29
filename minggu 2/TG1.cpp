//Jika nums = [2, 5, 7, 9, 12] dan target = 8, fungsi searchInsert akan mengembalikan 3.
//Ini karena 8 seharusnya disisipkan pada indeks 3 agar array tetap terurut.

#include <iostream>

using namespace std;

int searchInsert(int nums[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int n, target;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int nums[n];
    cout << "Masukkan elemen array (terurut):" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Masukkan target: ";
    cin >> target;
    int index = searchInsert(nums, n, target);

    cout << "Output: " << index << endl;

    return 0;
}