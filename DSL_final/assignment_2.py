class Strings():
    def __init__(self, x):# x is a string
        self.strin = x
        self.n = len(self.strin)

    def long_word(self):
        lis = self.strin.split()
        max = lis [0]
        for i in range(len(lis)):
            if len(lis[i]) > len(max):
                max = lis[i]
        print("Longest word is", max)

    def freq_char(self):
        k = input("Enter Character ")
        cnt = 0
        for i in range(self.n):
            if self.strin[i] == k:
                cnt += 1
        print("Frequency of",k,"is",cnt)

    def palindrome(self):
        rev = self.strin[::-1]
        if rev == self.strin:
            print(self.strin,"is a Palindrome.")
        else:
            print(self.strin,"is NOT a Palindrome")

    def occurance(self):
        k = input("Enter Substring :")
        lenk = len(k)
        for each in range(self.n - lenk + 1):
            print(self.strin[each:each + lenk])
            every = self.strin[each: each + lenk]
            if every == k:
                print("Substrin",k,"Occured at",each)
                return each

    def count_occurance(self):
        k = input("Enter Word :")
        lis = self.strin.split()
        cnt = 0
        for each in range(len(lis)):
            if lis[each] == k:
                cnt = cnt + 1
        print(k,"Occured",cnt,'times.')