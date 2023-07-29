#include <iostream>
#include <unordered_map>
using namespace std;
int sliding_window(string &s, int k)
{
    int i = 0;
    int j = 0;
    int maxi = 0;
    unordered_map<char, int> mpp;
    while (j < s.size())
    {
        mpp[s[j]]++;
        if (mpp.size() < k)
            j++;
        else if (mpp.size() == k)
        {
            int cnt = j - i + 1;
            maxi = max(maxi, cnt);
            j++;
        }
        else if (mpp.size() > k)
        {

            while (mpp.size() > k)
            {

                if (mpp[s[i]] == 1)
                {
                    mpp.erase(s[i]);
                }
                else
                {
                    mpp[s[i]]--;
                }
                i++;
            }
            j++;
        }
    }
    return maxi;
}
int main()
{
    // cout<<"lokesh pandey"<<endl;
    string s = "aabacbebebe";
    // cout << s.size();
    int k = 3;
    int ans = sliding_window(s, k);
    cout << "lokesh your answer is " << ans << endl;
    return 0;
}