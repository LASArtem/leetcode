class Solution:
    counter: int = 0
    def __init__(self):
        print('__init__')

    def getWinner(self, arr, k: int) -> int:
        print('getWinner') 
        k = k if k < len(arr) else (len(arr)-1)
        winCounter=0
        while winCounter != k :
            if arr[0] > arr[1] :
                winCounter += 1
            else:
                winCounter = 1
                arr[0], arr[1] = arr[1], arr[0]
            self.moveSecondToEnd(arr)
        print('finish:', 'winCounter=', winCounter, 'len=', len(arr), 'k=', k)
        return arr[0]

    def moveSecondToEnd(self, arr) -> None:
        lastIndex = len(arr) - 1;
        if lastIndex >= 2:
            lastNumber = arr[1];
            for i in range(2, lastIndex+1):
                arr[i-1] = arr[i]
            arr[lastIndex]=lastNumber

arr = [1,11,22,33,44,55,66,77,88,99]
k = 100

solution = Solution()
#solution.getWinner(arr, 2)
print('The winner is: ', solution.getWinner(arr, k))