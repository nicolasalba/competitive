from decimal import *
getcontext().prec = 200 #The decimal precisition

n = int(input())
nums = [int(x) for x in input().split(" ")]
ans = Decimal(0)
for i in range(0,len(nums)):
  for j in range(i+1,len(nums)):
    for k in range(1,nums[j]+1):
      ans += max(0,nums[i]-k)/Decimal(nums[i]*nums[j])
      # Also for reduce getcontext().prec = 100
print("{:.6f}".format(ans)) #The rounding half six decs
# import ast as a
# tree = ast.parse("x + 5")
# print(ast.dump(tree, indent=2))
# eval(string expr)
