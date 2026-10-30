// Kth Smallest >gfg (given an array arr and integer k, return the kth smallest element in the array) - max heap of size k approach, O(nlogk)
//gfg me mil jayega quo

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
    //     priority_queue<int,vector<int>,greater<int>>pq; min heap
    //     for(int i=0;i<arr.size();i++)
    //         pq.push(arr[i]);

    //     for(int i=0;i<k-1;i++)
    //         pq.pop();

    // return pq.top();
    // }
    // in case of incoming elements it becomes efficient as at that time this code push takes o(logn) + pop will take klogn so ideally then O(klogn) but incoming elements in sort approach take additional nlogn time

    priority_queue<int>pq; //max heap
    for(int i=0;i<k;i++)
        pq.push(arr[i]); //klogk

    for(int i=k;i<arr.size();i++) //n-k
    {
        if(arr[i]<pq.top()) //mrko min chaiye toh maximum vale ko eliminate kro by checking this condition
        {
            pq.pop(); //logk
            pq.push(arr[i]); //logk logk hoga kyuki mera heap 'k' size ka h agr n elements le kr banate toh logn hota isliye iska S.C hoga O(K) kyuki k size hi lga
        }
    } //  klogk+(n-k)2logk = O(nlogk)
    return pq.top();
}
};
