#include <bits/stdc++.h>
using namespace std;

bool is_possible(string possible, unordered_map<char, int> &mpp)
{
    unordered_map<char, int> mppp;
    for (int i = 0; i < possible.size(); i++)
    {
        mppp[possible[i]]++;
    }
    return mpp == mppp;
}

int sliding_window(string &text, unordered_map<char, int> &mpp, int k)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    string s = "";

    while (j < text.size())
    {
        s += text[j]; // Include the current character in the window
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if (is_possible(s, mpp))
                cnt++;
            s.erase(s.begin()); // Remove the first character from the window
            i++;
            j++;
        }
    }

    return cnt;
}

int main()
{
    string text = "forxxorfxdofr";
    string word = "for";
    int k = word.size();
    unordered_map<char, int> mpp;
    for (int i = 0; i < word.size(); i++)
    {
        mpp[word[i]]++;
    }

    int a = sliding_window(text, mpp, k);
    cout << "lokesh pandey" << endl;
    cout << a;

    return 0;
}
