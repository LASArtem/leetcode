"""
SolutionDefault
"""

from solutions.ISolution import ISolution

class SolutionDefault(ISolution):
    def isReady(self):
        return False
    
    def describeIssue(self):
        print("SolutionDefault")

    def run(self):
        pass