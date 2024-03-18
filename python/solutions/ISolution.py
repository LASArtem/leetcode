"""
Interface clase for solutions
"""

class ISolution:
    def isReady(self):
        return False
    
    def describeIssue(self):
        pass

    def run(self):
        pass