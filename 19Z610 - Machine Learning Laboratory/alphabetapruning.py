class Node:
    def __init__(self):
        self.val = 0
        self.lc:Node = Node()
        self.rc:Node = Node()

class Solution:
    def minimax(self, position:Node, depth:int, alpha:float, beta:float, maximizingPlayer:bool) -> int:
        if depth == 0:
            return position.val

        if maximizingPlayer:
            maxEval = -float('inf')
            for c in [position.lc, position.rc]:
                ceval = self.minimax(c, depth-1, alpha, beta, not(maximizingPlayer))
                maxEval = max(maxEval, ceval)
                
                alpha = max(maxEval, alpha)
                if beta <= alpha:
                    break
            return maxEval
        
        else:
            mineval = float('inf')
            for c in [position.lc, position.rc]:
                if alpha >= beta:
                    return
                ceval = self.minimax(c, depth-1, alpha, beta, not(maximizingPlayer))
                minEval = min(minEval, ceval)
                
                beta = min(beta, minEval)
                if beta <= alpha:
                    break
            return mineval