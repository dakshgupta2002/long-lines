#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool reached(vector<int> &arr, int start, vector<int> &visited)
    {
        if (arr[start] == 0)
        {
            return true;
        }

        visited[start] = 1;

        if (start + arr[start] < arr.size() && !visited[start + arr[start]] &&
            start - arr[start] >= 0 && !visited[start - arr[start]])
        {
            //both conditions possible
            return reached(arr, start - arr[start], visited) || reached(arr, start + arr[start], visited);
        }
        else if (start + arr[start] < arr.size() && !visited[start + arr[start]])
        {
            //can only go forward
            return reached(arr, start + arr[start], visited);
        }
        else if (start - arr[start] >= 0 && !visited[start - arr[start]])
        {
            //can only go back
            return reached(arr, start - arr[start], visited);
        }

        return false;
    }
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> visited(arr.size(), 0);
        return reached(arr, start, visited);
    }
};

int main()
{

}