# 实现 strStr() 函数。 
# 
#  给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如
# 果不存在，则返回 -1 。 
# 
#  
# 
#  说明： 
# 
#  当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 
# 
#  对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：haystack = "hello", needle = "ll"
# 输出：2
#  
# 
#  示例 2： 
# 
#  
# 输入：haystack = "aaaaa", needle = "bba"
# 输出：-1
#  
# 
#  示例 3： 
# 
#  
# 输入：haystack = "", needle = ""
# 输出：0
#  
# 
#  
# 
#  提示： 
# 
#  
#  0 <= haystack.length, needle.length <= 5 * 10⁴ 
#  haystack 和 needle 仅由小写英文字符组成 
#  
#  Related Topics 双指针 字符串 字符串匹配 👍 1140 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
from typing import List


class Solution:
    def buildNext(self, pattern: str) -> List[str]:
        str_length = len(pattern)
        next = [-1] * str_length

        for j in range(str_length)[1:]:
            i = next[j - 1]
            while i >= 0 and pattern[i + 1] != pattern[j]:
                i = next[i]

            if pattern[i + 1] == pattern[j]:
                next[j] = i + 1
            else:
                next[j] = -1

        return next

    def findIndex(self, string: str, pattern: str) -> int:
        NOT_FOUND = -1
        string_length = len(string)
        pattern_length = len(pattern)

        if string_length < pattern_length:
            return NOT_FOUND

        string_pointer = 0
        pattern_pointer = 0

        next = self.buildNext(pattern)
        # 当两个指针 string_pointer 与 pattern_pointer 没有超过对应字符串长度时，比较继续
        while string_pointer < string_length and pattern_pointer < pattern_length:
            # 当两个指针所指的字母相同时，都向后移动一位
            if string[string_pointer] == pattern[pattern_pointer]:
                string_pointer += 1
                pattern_pointer += 1
            # 否则就将 `pattern_pointer` 移动到 next 函数所对应的位置上 (对于  `pattern_pointer` 指针已经在后面几位的情况)
            elif pattern_pointer > 0:
                pattern_pointer = next[pattern_pointer - 1] + 1
            # 对于 `pattern_pointer` 指针在 0 位的情况，说明此时 `pattern` 中没有对应的（从开头开始的）子字符串与 `string` 对应，则直接从下一位进行比较( `string_pointer` += 1)
            else:
                string_pointer += 1
        # 当循环结束时有两种情况
        # 没有匹配到 或者 匹配成功
        # 如果 `pattern_pointer` 与 `pattern_length` 相等，则匹配成功
        # 如果不相等，则说明 `pattern` 已经超过了 `string` 的剩余长度，则返回 -1
        return string_pointer - pattern_length if pattern_pointer == pattern_length else NOT_FOUND

    def strStr(self, haystack: str, needle: str) -> int:
        # return 0 if len(needle) == 0 else self.findIndex(haystack, needle)
        if len(needle) == 0:
            return 0
        else:
            return self.findIndex(haystack, needle)

# leetcode submit region end(Prohibit modification and deletion)
