#include <iostream>
#include <vector>
using namespace std;

int max_subarray_sum_k(vector<int> &nums, int sum)
{
    int cursum = 0;
    int i = 0;
    int j = 0;
    int maxi = 0;

    while (j < nums.size())
    {
        cursum += nums[j];

        if (cursum < sum)
        {
            j++;
        }
        else if (cursum == sum)
        {
            int cnt = j - i + 1;
            maxi = max(maxi, cnt);
            j++;
        }
        else if (cursum > sum)
        {
            while (cursum > sum)
            {
                cursum -= nums[i];
                i++;
            }
            j++;
        }
    }

    return maxi;
}

int main()
{
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(5);
    int sum = 5;
    int a = max_subarray_sum_k(nums, sum);
    cout << "Answer is " << a << endl;
    return 0;
}
