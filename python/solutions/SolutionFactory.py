from solutions.ISolution import ISolution
from solutions.Solution0002 import Solution0002
from solutions.Solution0003 import Solution0003
from solutions.Solution0005 import Solution0005

class SolutionFactory:
    def createSolution(self, solutionNumber: int) -> ISolution:
        returnSolution = ISolution()

        if solutionNumber==2 :
            returnSolution = Solution0002()
        elif solutionNumber == 3 :
            returnSolution = Solution0003()
        elif solutionNumber == 5 :
            returnSolution = Solution0005()

        return returnSolution