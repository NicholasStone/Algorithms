# 给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现
# 次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：nums1 = [1,2,2,1], nums2 = [2,2]
# 输出：[2,2]
#  
# 
#  示例 2: 
# 
#  
# 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
# 输出：[4,9] 
# 
#  
# 
#  提示： 
# 
#  
#  1 <= nums1.length, nums2.length <= 1000 
#  0 <= nums1[i], nums2[i] <= 1000 
#  
# 
#  
# 
#  进阶： 
# 
#  
#  如果给定的数组已经排好序呢？你将如何优化你的算法？ 
#  如果 nums1 的大小比 nums2 小，哪种方法更优？ 
#  如果 nums2 的元素存储在磁盘上，内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？ 
#  
#  Related Topics 数组 哈希表 双指针 二分查找 排序 👍 602 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
"""
论证为什么需要找最小的那个建立 map
两个数组的交集无外乎下面这么几个情况：
1. 完全无交集
2. 有一些元素是相同的，有一些元素是不同的
3. 某一个是另一个的子集
4. 两个是完全相同的集合

对于这个题目来说，对于交集部分的花销，是必要的，但对于非交集部分的花销则是越少越好。
因此针对上面的4种情况，选用较少项的则是更加满足需求

整体思路就是
1. 给数量较少的数组建立一个 值 => 数量 对照的Map
2. 用第二组数据碰 Map，如果找到元素存在就放到交集数组中，并且数量 -1，如果数量为0则将此项删除
"""


class Solution(object):
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        shorter_list = nums1 if len(nums1) < len(nums2) else nums2
        longer_list = nums1 if len(nums1) >= len(nums2) else nums2

        map = {}

        for num in shorter_list:
            if num in map:
                map[num] += 1
            else:
                map[num] = 1

        result = []

        for item in longer_list:
            print(item)
            if item in map:
                result.append(item)
                map[item] -= 1
                print(map)
                if map[item] == 0:
                    map.pop(item)

        return result

# leetcode submit region end(Prohibit modification and deletion)
