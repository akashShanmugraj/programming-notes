from math import dist
from heapq import heappop as hout
from heapq import heappush as hin
from heapq import heapify as hp5


matrix = [
    [0,  0,  1,  0,  0],
    [0,  1,  0,  0,  0],
    [0,  0,  0,  1,  0],
    [1,  1,  0,  1,  0],
    [0,  0,  0,  0,  0],
]

class Solution:
    def __init__(self, mat):
        self.m = mat
        self.start = (0,0)
        self.end = (0,4)
    
    def n(self, xpos, ypos, vset):
        offset = [[0,1], [1,0], [0,-1], [-1,0]]
        r = []
        for xo, yo in offset:
            xv, yv = xpos + xo, ypos + yo
            # if (xpos, ypos) == (3,2):
            #     print(xv,yv)
            if xv < 0 or xv >= 5 or yv < 0 or yv >= 5:
                continue
            if (xv, yv) in vset:
                continue
            if not self.m[xv][yv]:
                r.append((xv, yv))
        
        return r
    
    def g(self, cx, cy):
        return dist((cx,cy), self.end)
    
    def hadd(self, h, cx, cy, vset):
        hin(
                h,
                (
                    self.g(cx,cy),
                    (cx,cy)
                )
            )
        
        vset.add((cx,cy))
        
        return None
    
    def hpop(self, h):
        hval, coord = hout(h)
        return coord
    
    def search(self):
        cx, cy = self.start
        h = []
        v = set()
        self.hadd(h, cx, cy, v)

        c = 0
        print(h)
        while h:

            cx, cy = self.hpop(h)
            print(cx, cy)
            
            if (cx, cy) == self.end:
                print('END FOUND')
                break
            
            sfc = self.n(cx,cy,v)
            for tcx, tcy in sfc:
                self.hadd(h, tcx, tcy,v)
            print(h)
    
        
        print("OUT OF LOOP")
        
    def recurse(self, cx, cy, h, v, p):
        print(cx,cy)
        if not h:
            return False
        print(102)
        hp5(h)
        
        cx, cy = self.hpop(h)
            
        if (cx, cy) == self.end:
            print('END FOUND')
            print(h, p)
            return p+[cx, cy]
        
        sfc = self.n(cx, cy, v)
        htemp = []
        for tcx, tcy in sfc:
            self.hadd(htemp, tcx, tcy, v)
        
        return True if self.recurse(cx, cy, h+htemp, v, p+[[cx, cy]]) else False

    def callrecurse(self):
        newh = []
        self.hadd(newh,0,0,set())
        self.recurse(0,0,newh,set(),[])
s = Solution(matrix)
s.callrecurse()
