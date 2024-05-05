from typing import List

class Backtracking:
    def subsetsum(self, mainarray: List[int], recursearray: List[int], targetsum: int, elementpointer: int) -> int:
        if elementpointer >= len(mainarray):  # Check for reaching the end of the array
            return
        if sum(recursearray) == targetsum:
            print(recursearray)
        self.subsetsum(mainarray, recursearray+[mainarray[elementpointer]], targetsum, elementpointer + 1)
        self.subsetsum(mainarray, recursearray, targetsum, elementpointer + 1)

            
bt = Backtracking()
tc = [2,2,3,6,7]
targetsum = 7
bt.subsetsum(tc, [], targetsum, 0)