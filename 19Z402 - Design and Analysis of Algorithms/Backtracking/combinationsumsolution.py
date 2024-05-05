from typing import List


from typing import List

class Solution:
    def recursivefunc(self, carr, start, sum, sumarray, ansarr, target):
        # using the start variable to not consider previous elements in the recursion
        # https://github.com/akashShanmugraj/programming-notes/assets/65720968/2a500045-2fa8-4768-b03f-e07a34b1a433
        if sum == target:
            ansarr.append(sumarray)
            return True
        elif sum > target:
            return False
        else:
            for i in range(start, len(carr)):
                self.recursivefunc(
                    carr, i, sum + carr[i], sumarray + [carr[i]], ansarr, target
                )

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        answerarray = []
        candidates.sort()  # sort the candidates array

        self.recursivefunc(candidates, 0, 0, [], answerarray, target)
        return answerarray


tc = [2, 3, 6, 7]
target = 7

sol = Solution()
print(sol.combinationSum(tc, target))
