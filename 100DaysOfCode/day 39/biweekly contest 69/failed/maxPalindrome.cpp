#include <bits/stdc++.h>
using namespace std;

// idk the error
class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        unordered_map<string, int> occur;
        for (int i = 0; i < words.size(); i++)
            occur[words[i]]++;

        unordered_map<string, int>::iterator it;
        int ans = 0;

        //try to use this at last
        //since only one of this

        int middle = 0;

        for (it = occur.begin(); it != occur.end(); it++)
        {
            string foo = it->first;
            string boo = "";
            boo += foo[1];
            boo += foo[0];

            //if foo == boo
            // see if value even then act as normal
            //if odd then you can add in centre and set middle to 1
            if (foo == boo)
            {
                if (occur[foo] % 2 == 1)
                {
                    if (!middle)
                    {
                        ans += 2;
                        middle = 1;
                    }
                    
                    occur[foo]--;
                }

                ans += 2*occur[foo];
                occur[foo]=0;

            }else ans += 4 * min(occur[foo], occur[boo]);

            occur[foo] = 0;
            occur[boo] = 0;
        }

        return ans;
    }
};