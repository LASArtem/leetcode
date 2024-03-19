from solutions.ISolution import ISolution
from solutions.SolutionDefault import SolutionDefault
from solutions.Solution0002 import Solution0002
from solutions.Solution0003 import Solution0003

class SolutionFactory:
    def createSolution(self, solutionNumber: int) -> ISolution:
        returnSolution = SolutionDefault()

        if solutionNumber==2 :
            returnSolution = Solution0002()
        elif solutionNumber == 3 :
            returnSolution = Solution0003()

        return returnSolution