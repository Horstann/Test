class complexNo:
    def __init__(self, real=0, img=0):
        self.real = real
        self.img = img
    def displayComplex(self):
        print(f"Your complex number = {self.real} + {self.img}i")

x = y = 0
while (True):
    try: x = int(input("Enter an integer: "))
    except: print("Invalid. Try again")
    else: break
print("")
while (True):
    try: y = int(input("Enter another integer: "))
    except: print("Invalid. Try again")
    else: break

n = complexNo(x, y)
n.displayComplex()