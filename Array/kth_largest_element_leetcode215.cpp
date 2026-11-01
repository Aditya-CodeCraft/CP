// 215. Kth Largest Element in an Array >leetcode (given integer array nums and integer k, return the kth largest element) - min heap of size k approach, O(nlogk). Mirror of Array/kth_smallest_element.cpp with the heap and comparison flipped
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int,vector<int>,greater<int>>pq; //min-heap used
        for(int i=0;i<k;i++)
            pq.push(nums[i]);

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    return pq.top();
    }
};
