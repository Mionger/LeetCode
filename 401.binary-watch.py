#
# @lc app=leetcode id=401 lang=python3
#
# [401] Binary Watch
#
class Solution:
    def readBinaryWatch(self, num: int) -> 'List[str]':
    # num相当于深度
        output = []
        for h in range(12):
          for m in range(60):
            if bin(h * 64 + m).count('1') == num:
              output.append('%d:%02d' % (h, m))
        return output

s = Solution()
print(s.readBinaryWatch(0))
