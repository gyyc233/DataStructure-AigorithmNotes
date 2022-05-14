// min_lenth_continue_sub_array.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

//给定一个含有 n 个正整数的数组和一个正整数 target 。
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。
// 如果不存在符合条件的子数组，返回 0 。
//示例 1：
//输入：target = 7, nums = [2, 3, 1, 2, 4, 3]
//输出：2
//解释：子数组 [4, 3] 是该条件下的长度最小的子数组

class Solution
{
public:
	Solution();
	~Solution();

	//暴力解法
	int minSubArrayLenBruteForce(int target, std::vector<int> nums)
	{
		int min_sub_array_lenth=0;
		int sum = 0;
		int result = INT32_MAX;
		for (int i=0;i<nums.size();i++)
		{
			sum = 0;//每次找之前，需要重新清零

			for (int j=i;j<nums.size();j++)
			{
				sum += nums[j];
				if (sum >= target)
				{
					min_sub_array_lenth = j - i + 1;
					result = result < min_sub_array_lenth ? result : min_sub_array_lenth;

					std::cout << "[ ";
					for (int k=i;k<=j;k++)
					{
						std::cout << nums[k] << " ";
					}
					std::cout << "]" << std::endl;
					break;
				}
			}
		}
		int re= result == INT32_MAX ? 0 : result;
		std::cout << "return : " << re << std::endl;

		return re;
	}

	/// @brief 使用滑动窗口（双指针法的一种）
	/// @details 不断调节数组的起始位置和终止位置
	/// @param target 
	/// @param nums 
	/// @return 
	int minSubArrayLenSlidingWindows(int target, std::vector<int> nums)
	{
		int result = INT32_MAX;
		int sum = 0;//滑动窗口数值之和
		int i = 0;//滑动窗口起始位置
		int lenth;//滑动窗口长度
		for (int j=0;j<nums.size();j++)
		{
			sum += nums[j];
			//while: 每次更新i,并不断比较子数组是否满足条件
			while (sum>=target)
			{
				lenth = j - i + 1;
				result = result < lenth ? result : lenth;
				//从子数组前面开始缩小窗口，直到不满足条件，再再次从尾部生长窗口
				sum -= nums[i++];//滑动窗口，不断变更i(子数组的起始位置)。
			}
		}
		return result == INT32_MAX ? 0:result;
	}
private:

};

Solution::Solution()
{
}

Solution::~Solution()
{
}

int main()
{
	Solution* solution = new Solution();
	std::vector<int> nums = {4, 6, 2, 1, 7,9,4};
	solution->minSubArrayLenBruteForce(11, nums);
	std::cout << "sliding windows result: " << solution->minSubArrayLenSlidingWindows(11, nums)<< std::endl;
	return 0;
}
