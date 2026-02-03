#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high,long long &comparisons, long long &inversions) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        comparisons++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void merge_sort(vector<int>& arr, int left, int right,long long &comparisons, long long &inversions) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid, comparisons, inversions);
        merge_sort(arr, mid + 1, right, comparisons, inversions);
        merge(arr, left, mid, right, comparisons, inversions);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        long long comparisons = 0;
        long long inversions = 0;

        merge_sort(arr, 0, n - 1, comparisons, inversions);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
        cout << comparisons << "\n";
        cout << inversions << "\n";
    }

    return 0;
}
