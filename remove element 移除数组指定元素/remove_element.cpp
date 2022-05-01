// remove_element.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//题目描述：原地移除数组中所有等于val的元素，要求不能使用额外的辅助空间，空间复杂度为O(1)。返回移除元素后新数组的size

#include <iostream>
#include <vector>

class Solution
{
public:

    /// @brief 移除元素 暴力解法，first loop to travel array, second loop to update array
    /// @param nums 数组
    /// @param val 想移除的元素
    /// @return 移除后数组size
    int removeElementFun1(std::vector<int>& nums,int val)
    {
        int size = nums.size();
		std::cout << "\n\norigin size: " << size << std::endl;;

        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] == val)    //发现需要移除的元素，则将数组全体向前移动一位
            {
                std::cout << "call voilent two loop function!\nfind value: " << nums[i] << std::endl;
                for (int j=i+1;j<nums.size();j++)
                {
                    nums[j-1] = nums[j];//这里用nums[j-1]，而不是nums[i],因为可能有多个重复
                }
                i--;    //此时nums[i]已经改变，所以需要向前移动一位
                size--;
            }
        }
        std::cout << "removed element, final size: " << size << std::endl;
        return size;
    }

	/// @brief 移除元素 双指针法，快慢指针
	/// @param nums 数组
	/// @param val 想移除的元素
	/// @return 移除后数组size
    int removeElementFun2(std::vector<int>& nums, int val)
    {
        std::cout << "\n\norigin size: " << nums.size() << std::endl;;

		int slowIndex = 0;
		for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            //如果不是目标元素,则slowindex equal with fastIndex 
            //若找到val,则slowIndex停下，fast继续找，停下多少次则在找到多少个val
			if (val != nums[fastIndex])
            {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
                continue;
				//nums[slowIndex++] = nums[fastIndex];
			}
			std::cout << "call fast slow pointer function!\n find value: " << nums[fastIndex] << std::endl;

		}
        std::cout << "removed element, final size: " << slowIndex << std::endl;;
		return slowIndex;
    }


};

int main()
{
    Solution s;
    std::vector<int> nums1 = { 0,1,2,3,3,0,4 };
    s.removeElementFun1(nums1, 3);

	std::vector<int> nums2 = { 0,1,2,3,3,0,4,7,8,9,9,9};
	s.removeElementFun2(nums2, 9);

    std::cin.get();
}
