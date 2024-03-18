from solutions.ISolution import ISolution
from solutions.SolutionDefault import SolutionDefault
from solutions.Solution0002 import Solution0002



class SolutionFactory:
    def createSolution(self, solutionNumber: int) -> ISolution:
        returnSolution = SolutionDefault()

        if solutionNumber==2 :
            returnSolution = Solution0002()

        return returnSolution