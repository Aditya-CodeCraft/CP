// 47. Permutations II >leetcode (given array nums that might contain duplicates, return all possible unique permutations in any order) - swap approach with unordered_set per level to skip duplicate picks

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    void generate(int index,int n,vector<int>&nums,vector<vector<int>>&ans){
        if(index==n-1) //kyuki last index apne se hi swap hota h thats redundant
        {
            ans.push_back(nums);
            return;
        }

        unordered_set<int>s;
        for(int i=index;i<n;i++) //i starts from curr index
        {
            if(s.find(nums[i])!=s.end()) continue;
            s.insert(nums[i]);
            swap(nums[i],nums[index]);
            generate(index+1,n,nums,ans);
            swap(nums[i],nums[index]); //undo
        }


    }


    vector<vector<int>> permuteUnique(vector<int>& nums) { //leetcode gives just this fn
        vector<vector<int>>data;
        int n=nums.size();
        generate(0,n,nums,data);
        return data;

        //either use set in above function or use this sh*t thing <cheap brainless trick>
        // set<vector<int>> unique(data.begin(), data.end());
        // vector<vector<int>>ans(unique.begin(), unique.end()); converting set{vector} to vector[vector]
        //then return ans;

    }
};
