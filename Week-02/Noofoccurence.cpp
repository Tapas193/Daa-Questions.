#include <iostream>
#include <vector>
using namespace std;

int firstocc(vector<int>& nums, int key, int n) {
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < key) low = mid + 1;
        else if (nums[mid] > key) high = mid - 1;
        else {
            first = mid;
            high = mid - 1;
        }
    }
    return first;
}

int lastocc(vector<int>& nums, int key, int n) {
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < key) low = mid + 1;
        else if (nums[mid] > key) high = mid - 1;
        else {
            last = mid;
            low = mid + 1;
        }
    }
    return last;
}
int main() {
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the Elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int key;
    cout << "Enter the Key: ";
    cin >> key;
    int first = firstocc(nums, key, n);
    int last = lastocc(nums, key, n);
    if (first == -1)
        cout << "Key not found\n";
    else
        cout << "The Occurrence are: " << (last - first + 1) << endl;
    return 0;
}
