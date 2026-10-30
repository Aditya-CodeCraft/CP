// 46. Permutations >leetcode (given array nums of distinct integers, return all possible permutations in any order) - swap approach
// NOTE: this code and Permutations_of_string/print_all_permutations_of_string_recursion.cpp are the same logic, just string replaced by vector<int> and result collected in vector<vector<int>> instead of printing

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void help(int i,vector<int>& nums,vector<vector<int>>&ans){
        if(i==nums.size()-1){ //saved 1 iteration as last element khud se hi swap hota h isse acha dont do redundant opern
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            help(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) { ///leetcode just gave this
        vector<vector<int>>ans;
        help(0,nums,ans);
        return ans;
    }
};
