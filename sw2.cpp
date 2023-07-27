#include <iostream>
#include <queue>
using namespace std;

vector<int> firstnegative(int *arr, int n, int k, vector<int> &ans)
{
    queue<int> q;
    int i = 0, j = 0;
    while (j < n)
    {
        // Check if the current element is negative and add it to the queue
        if (arr[j] < 0)
        {
            q.push(arr[j]);
        }

        // If the window size is not yet k, just move the right pointer (j)
        if (j - i + 1 < k)
        {
            j++;
        }
        // When the window size reaches k, store the first negative element and move both pointers
        else if (j - i + 1 == k)
        {
            // If the queue is empty, there is no negative element in the current subarray
            if (q.empty())
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(q.front()); // The front of the queue contains the first negative element
                if (arr[i] == q.front())
                {
                    q.pop(); // If the element going out of the window is the first negative, remove it from the queue
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n = 8;
    int k = 3;
    vector<int> ans;
    int arr[] = {-2, -3, 5, 2, -9, 7, 1, 3};
    vector<int> a = firstnegative(arr, n, k, ans);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
