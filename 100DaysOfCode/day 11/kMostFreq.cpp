#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m1;
        map<int, vector<int>, greater<int>> frequency;

        for (int i = 0; i < nums.size(); i++)
        {
            m1[nums[i]]++;
        }

        for (auto it : m1)
        {
            frequency[it.second].push_back(it.first);
        }

        vector<int> solution;

        for (auto j : frequency)
        {
            for (auto l : j.second)
            {
                if (solution.size() == k)
                    return solution;
                solution.push_back(l);
            }
        }
        return solution;
    }
};
//using min heap
//find all frequencies of all elements and store in mao
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> m1;
    for (int i = 0; i < nums.size(); i++) m1[nums[i]]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<int>> pq; 

    for(auto it: m1){
        pq.push({it.second, it.first});

        if (pq.size()>k){
            pq.pop();
        }
    }

    //print the queue
}

//just trying implementing nested vector and map
int main()
{
    vector<int> nums{10, 10, 10, 131, 131, 11, 11, 11, 11, 11, 11, 11, 123, 123, 123, 123};

    unordered_map<int, int> m1;
    unordered_map<int, vector<int>> frequency;

    for (int i = 0; i < nums.size(); i++)
    {
        m1[nums[i]]++;
    }

    for (auto it : m1)
    {
        frequency[it.second].push_back(it.first);
    }
}