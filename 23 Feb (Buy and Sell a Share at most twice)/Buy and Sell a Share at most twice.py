from typing import List


class Solution:
    def maxProfit(self, n : int, price : List[int]) -> int:
        # code here
        fb,fs=-999999,0
        sb,ss=-999999,0
        for p in price:
            fb = max(fb,-p) 
            fs = max(fs,p+fb)
            sb = max(sb,fs-p)
            ss = max(ss,sb+p)
        return ss 