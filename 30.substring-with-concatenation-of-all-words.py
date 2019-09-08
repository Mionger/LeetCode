#
# @lc app=leetcode id=30 lang=python3
#
# [30] Substring with Concatenation of All Words
#
class Solution(object):
    def findSubstring(self, s, words):
        result = []
        if len(words) == 0:
            return result
        length = len(words[0])
        if length > len(s):
            return result
        #匹配所有的字符串需要的长度
        count_c = len(words) * length
        
        i = 0
        while i < len(s) - count_c + 1:
            word = s[i:i + length]
            if word in words:
                ss = s[i:i + count_c]
                if self.isValid(ss, words, length):
                    result.append(i)
                i += 1
            else:
                i += 1
        return result

    def isValid(self, ss, words, length):
        words_ss = []
        # 对这个长串分割
        for x in range(len(ss) // length):
            word = ss[x * length:(x + 1) * length]
            words_ss.append(word)
        #一一对应
        for word in words:
            if word in words_ss:
                words_ss.remove(word)
            else:
                return False
        return True
