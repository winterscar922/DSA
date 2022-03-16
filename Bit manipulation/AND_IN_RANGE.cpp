class Solution {
public:
// problem link:https://leetcode.com/problems/bitwise-and-of-numbers-range/
    
// idea: 
//       FOR a position i,there will occur a ZERO after (1<<i) sessions.So check for the sessions in each bit of given number.
//       IF there are more than (1<<i) numbers in the given range for a bit , there will occur atleast one zero in that bit.
    
long long rangeBitwiseAnd(long long left, long long right) {
        long long diff=(right-left+1);
        long long sum=0;
        for(long long i=0;i<32;i++){
            if(diff<=(1LL<<i) && (left>>i)&1 && (right>>i)&1){
                sum+=(1LL<<i);
            }
        }
        return sum;
    }
};
