// 二分查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//题目描述：在一个有序无重复元素的数组nums中，寻找一个元素target,找到就返回下标，否则返回-1

#include <iostream>
#include <vector>

//二分查找前提条件：有序无重复数组
//要点：考虑边界条件，以及区间的定义。
//区间的定义一般有两种，1.左闭右闭，2.左闭右开

class Solution
{
public:
    /// @brief 二分查找，区间左闭右闭
    /// @param nums 有序无重复数组
    /// @param target 待查找值
    /// @return 成功返回索引，失败返回-1
    int search_fun1(const std::vector<int>& nums,int target)
    {
		std::cout << "call search_fun1\n";

        // 定义左闭右闭区间
        int left = 0;
        int right = nums.size() - 1;

        //当left==right时，[left,right]仍然有效，使用<=
        while (left<=right)
        {
			int middle = left + (right - left) >>1;//等同于(right + left) / 2，说是可以防止溢出

            // target 在middle左边
			if (target < nums[middle])
				right = middle - 1;

            // target 在middle右边
			else if (target > nums[middle])
				left = middle + 1;

            else
            {
                //num[middle]==target
                //在数组中找到目标值，返回下标
                std::cout << "value index: " << middle << std::endl;
                return middle;
            }
        }

        //未找到目标值
        std::cout << "not found.\n";
        return -1;
    }

    /// @brief 二分查找，区间左闭右开
    /// @param nums 有序无重复数组
    /// @param target 待查找值
    /// @return 成功返回索引，失败返回-1
    int search_fun2(const std::vector<int>& nums, int target)
    {
        std::cout << "call search_fun2\n";
		// 定义左闭右开区间
		int left = 0;
		int right = nums.size();
        while (left<right)
        {
            //a>>b表示二进制右移b位（去掉末b位），相当于a除以2的b次方（取整）
            //经常用>>1来代替 /2（div 2)
            int middle = left + ((right - left) >> 1);

			// target 在middle左边，右侧为开区间
			if (target < nums[middle])
				right = middle;

			// target 在middle右边，左侧为闭区间
			else if (target > nums[middle])
				left = middle + 1;

			else
			{
                //num[middle]==target
				//在数组中找到目标值，返回下标
                std::cout << "value index: " << middle << std::endl;
				return middle;
			}
        }

		//未找到目标值
		std::cout << "not found.\n";
		return -1;
    }
};


int main()
{
    std::vector<int> v = {1, 3, 5, 7, 9, 10,20,30};
    Solution s;
    s.search_fun1(v, 10);
    s.search_fun2(v, 10);

	s.search_fun1(v, 90);
	s.search_fun2(v, 2);
    std::cin.get();
    return 0;
}

