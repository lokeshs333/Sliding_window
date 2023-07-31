#include <iostream>
using namespace std;
#include <map>
int sliding(string &s, int k)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int ans = 0;
    unordered_map<char, int> mpp;
    while (j < s.size())
    {
        mpp[s[j]]++;
        if (mpp.size() <= k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        if (mpp.size() > k)
        {
            while (mpp.size() > k)
            {
                if (mpp[s[i]] == 1)
                    mpp.erase(s[i]);
                else if (mpp[s[i]] > 1)
                    mpp[s[i]]--;
                i++;
            }
            j++;
        }
    }
    return ans;
}
int main()
{
    string s = "abaccab";
    string aa = "aabbppqs";
    cout << aa.size() << endl;
    int a = sliding(s, 2);
    cout << "your answer is " << a;
    return 0;
}
