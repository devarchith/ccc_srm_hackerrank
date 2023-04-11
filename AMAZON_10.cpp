//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

//Find two lines that together with the x-axis form a container, such that the container contains the most water.

//Return the maximum amount of water a container can store.

//Notice that you may not slant the container.

//Input Format

//First line contains an integer N denoting the size of array A.
//Second Line contain N integers representing the elements of the array.
//Constraints

//n == height.length
//2 <= n <= 10^5
//0 <= height[i] <= 10^4
//Output Format

//Contains an Integer

//Sample Input 0

//5
//286 403 570 819 917
//Sample Output 0

//1209
//Sample Input 1

//9
//1229 3254 269 1351 71 406 46 8 680
//Sample Output 1

//5440
//solution:-
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n - 1;
    int maxArea = 0;
    while(left < right) {
        int area = min(height[left], height[right]) * (right - left);
        maxArea = max(maxArea, area);
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxArea;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << maxArea(height);
    return 0;
}
