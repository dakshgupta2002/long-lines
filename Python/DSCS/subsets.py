# Daksh Gupta
# 20103026 
# CSE

# In the array A at every step we have two
# choices for each element either we can
# ignore the element or we can include the
# element in our subset
def subsets(A, subset, index):
    print(*subset)
    for i in range(index, len(A)):
         
        # include the A[i] in subset.
        subset.append(A[i])
         
        # move onto the next element.
        subsets(A, subset, i + 1)
         
        # exclude the A[i] from subset and
        # triggers backtracking.
        subset.pop(-1)
    return
 

set = list(map(int, input().split()))

subsets(set, [], 0)