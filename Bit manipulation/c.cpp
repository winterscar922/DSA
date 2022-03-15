// Problem link:https://leetcode.com/problems/single-number-ii/

// Problem: Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// tc:(31*n)



int singleNumber(vector<int>& nums) {
    int ele = 0;
    for (int i = 0; i <= 31; i++) {
        int cnt = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (((nums[j] >> i) & (1LL))) {
                cnt++;
            }
        }
        if (cnt % 3 != 0) {
            ele += (1LL << i);
        }
    }
    return ele;
}