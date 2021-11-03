#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{

    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v1(n);
        for (int &i : v1)
        {
            cin >> i;
        }
        sort(v1.begin(), v1.end());

        int curr_subtracting = 0;
        int max_extracted = -10000000000;

        for (int i = 0; i < n; i++)
        {
            v1[i] -= curr_subtracting;
            if (v1[i] > max_extracted)
            {
                max_extracted = v1[i];
            }
            curr_subtracting+=v1[i];
        }

        cout << max_extracted << endl;
    }

    return 0;
}
