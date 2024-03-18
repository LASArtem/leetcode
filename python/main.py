from solutions.ISolution import ISolution
from solutions.SolutionFactory import SolutionFactory

import sys

arguments = sys.argv
mySolutionFactory = SolutionFactory()
mySolution = mySolutionFactory.createSolution(int(arguments[1]))
if mySolution.isReady() :
    mySolution.describeIssue()
    mySolution.run()
else:
    print("ERROR: solution can not be created")
    print(f'arguments[1]={arguments[1]}')