
// Problem link: https://leetcode.com/problems/single-number-iii/

// Problem: Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// tc:(n*32)

// idea: remove all "2 occuring elements" by taking xor of all elements,then find lsb and divide the array into two parts by checking its set/unset.Finally take xor again to remove duplicates.


vector<int> singleNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans1, ans2, ans(2);
    if (n == 2) {
        return nums;
    }
    int o = nums[0];
    for (int i = 1; i < n; i++) {
        o ^= nums[i];
    }

    int rsb = 0;

    for (int i = 0; i < 32; i++) {
        if (o & (1LL << i)) {
            rsb = i;
            break;
        }
    }
    for (auto x : nums) {
        if ((x & (1LL << rsb)) == (o & (1LL << rsb))) {
            ans1.push_back(x);
        }
        else {
            ans2.push_back(x);
        }
    }

    for (auto x : ans1)
        ans[0] ^= x;

    for (auto x : ans2)
        ans[1] ^= x;


    return ans;
}

