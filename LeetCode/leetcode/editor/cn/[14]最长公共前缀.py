# 编写一个函数来查找字符串数组中的最长公共前缀。 
# 
#  如果不存在公共前缀，返回空字符串 ""。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：strs = ["flower","flow","flight"]
# 输出："fl"
#  
# 
#  示例 2： 
# 
#  
# 输入：strs = ["dog","racecar","car"]
# 输出：""
# 解释：输入不存在公共前缀。 
# 
#  
# 
#  提示： 
# 
#  
#  1 <= strs.length <= 200 
#  0 <= strs[i].length <= 200 
#  strs[i] 仅由小写英文字母组成 
#  
#  Related Topics 字符串 👍 1903 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        pos = self.getCommonPrefixLength(strs)
        return strs[0][:pos]

    def getCommonPrefixLength(self, strs: List[str]) -> int:
        min_length = min(map(len, strs))

        if min_length <= 0:
            return 0


        for i in range(min_length):
            char = strs[0][i]

            for str in strs:
                if str[i] != char:
                    return i

        return min_length

# leetcode submit region end(Prohibit modification and deletion)
