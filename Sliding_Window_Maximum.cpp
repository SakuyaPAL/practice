/*
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
	vector<int> result;
	deque<int> dq;

	if (nums.empty()) 
	{
		return result;
	}

	/* Finding maximum of the first sliding window - start */
	for (int i = 0; i < k; i++)
	{
		if(i == 0)
		{
			// First element of the array
			dq.push_back(i);
		}
		else
		{
			while (nums[i] > nums[dq.back()])
			{
				dq.pop_back();
				if (dq.empty())
				{
					break;
				}
			}
			dq.push_back(i);
		}
	}

	// maximum of the first sliding window
	result.push_back(nums[dq.front()]);
	/* Finding maximum of the first sliding window - end */

	/* Finding maximum of the rest sliding windows - start */
	for (int i = k; i < nums.size(); i++)
	{
		if (dq.front() <= i - k)
		{
			dq.pop_front();
		}
		if(dq.empty())
		{
			dq.push_back(i);
		}
		else
		{
			while (nums[i] > nums[dq.back()])
			{
				dq.pop_back();
				if (dq.empty())
				{
					break;
				}
			}
			dq.push_back(i);
		}
		result.push_back(nums[dq.front()]);
	}
	/* Finding maximum of the rest sliding windows - end */

	return result;
}

int main()
{
	vector<int> arr_in = { 9, 10, 9, -7, -4, -8, 2, -6 };
	vector<int> arr_out = maxSlidingWindow(arr_in, 5);
	for (int i = 0; i < arr_out.size(); i++)
	{
		cout << arr_out[i] << " ";
	}
	cout << endl;
	return 0;
}