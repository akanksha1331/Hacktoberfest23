'''Leetcode Problem 901'''
class StockSpanner:

    def __init__(self):
        self.st = []

    def next(self, price: int) -> int:
        if len(self.st)==0:
            self.st.append([price,0])
            return 1
        else:
            i = 0
            while len(self.st)>0 and self.st[-1][0]<=price:
                if self.st[-1][1]==0:
                    i+=1
                    self.st.pop()
                elif self.st[-1][1]>0:
                    i+=self.st[-1][1]
                    i+=1
                    self.st.pop()
            self.st.append([price,i])
            return i+1


# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)
