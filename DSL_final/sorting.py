class Sort():
    def __init__(self, n):
        self.lis = []
        self.n = n
    
    def getData(self):
        for i in range(self.n):
            element = int(input("Enter Roll no: "))
            self.lis.append(element)
    
    def bubble_sort(self):
        for i in range(self.n):
            swap = False
            for j in range(self.n - i - 1):
                if self.lis[j + 1] > self.lis[j]:
                    swap = True
                    self.lis[j + 1], self.lis[j] = self.lis[j], self.lis[j + 1]
            if swap == False:
                break
        print(self.lis)

    
    def insertion_sort(self):
        for i in range(self.n):
            key = self.lis[i]
            j = i - 1
            while j >= 0 and key < self.lis[j]:
                self.lis[j + 1] = self.lis[j]
                j -= 1
            self.lis[j + 1] = key
        print(self.lis)

    def selection_sort(self):
        for i in range(self.n):
            idx = i
            for j in range(i + 1, self.n):
                if self.lis[j] < self.lis[idx]:
                    idx = j
            self.lis[idx], self.lis[i] = self.lis[i], self.lis[idx]
        print(self.lis)
    
    def shell_sort(self):
        gap = self.n // 2
        while gap > 0:
            j = gap
            while j < self.n:
                i = j - gap
                while i >= 0:
                    if self.lis[i + gap] > self.lis[i]:
                        break
                    else:
                        self.lis[i + gap], self.lis[i] = self.lis[i], self.lis[i + gap]
                    i -= gap
                j += 1
            gap //= 2
        print(self.lis)
                     

   