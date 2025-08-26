import cProfile

# O(2^n)
def recursiveFib(n):
    if n < 2:
        return n
    else:
        return recursiveFib(n-1) + recursiveFib(n-2)

# O(n)
def iterativeFib(n):
    if n < 2:
        return n
    else:
        a, b = 0, 1
        for i in range(n-1):
            a, b = b, a+b
        return b



cProfile.run('recursiveFib(30)')
cProfile.run('iterativeFib(30)')
