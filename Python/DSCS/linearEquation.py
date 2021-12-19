# Daksh Gupta
# 20103026 
# CSE


# ques-6:
# print solutions for x1 + x2 + x3 = 10
# for each x >= 0

solutions=0
# x1 visites every value from its minimum value =0, maximum value =10
for x1 in range(11):
    # x2 visites every value from its minimum value =0, maximum value =10
    for x2 in range(11):
        # x3 visites every value from its minimum value =0, maximum value =10
        for x3 in range(11):
            # we found a solution under given constraints
            if x1 + x2 + x3 == 10:
                solutions+=1
                print("x1 =", x1, " x2 =", x2," x3 =", x3)


print("Total possible solutions are: ", solutions) # which should be 66 
#we can also verify this by combinatronics 
# for x1 = n, x2+x3 = 10-n 
# n has 10 possible values 
# for each case, number of solutions for x2+x3 = 10-n are 10-n+1
# hence sum(11-n) ( for n=0 to 10 )
# 1 + 2 + 3 .... + 10 + 11 == 66