//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

//The overall run time complexity should be O(log (m+n)).

//Input Format

//The First Line contains two integers N an M denoting the size of two arrays respectively.
//The Second Line contains N integers denoting the numbers of elements in the array 1.
//The Third Line contains M integers denoting the numbers of elements in the array 2.
//Constraints

//nums1.length == n
//nums2.length == m
//0 <= n <= 100000
//0 <= m <= 100000
//1 <= m + n <= 200000
//-10^6 <= nums1[i], nums2[i] <= 10^6
//Output Format

//Print the answer to the question.

//Sample Input 0

//9 7
//-962 -811 -799 -436 -151 287 344 453 770
//257 775 1592 3072 5093 6278 6502
//Sample Output 0

//398.5
//Sample Input 1

//6 9
//-931 -802 -648 -85 763 869
//1684 1736 2634 3576 5301 7607 8221 9244 9479
//Sample Output 1

//1736
// solution:-
#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    if (n > m) return findMedianSortedArrays(nums2, nums1);

    int l = 0, r = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int mid2 = (n + m + 1) / 2 - mid;

        int left1 = (mid == 0 ? INT_MIN : nums1[mid - 1]);
        int right1 = (mid == n ? INT_MAX : nums1[mid]);
        int left2 = (mid2 == 0 ? INT_MIN : nums2[mid2 - 1]);
        int right2 = (mid2 == m ? INT_MAX : nums2[mid2]);

        if (left1 <= right2 && left2 <= right1) {
            if ((n + m) % 2 == 0) {
                return (double)(max(left1, left2) + min(right1, right2)) / 2;
            } else {
                return (double)max(left1, left2);
            }
        } else if (left1 > right2) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> nums1(n), nums2(m);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
