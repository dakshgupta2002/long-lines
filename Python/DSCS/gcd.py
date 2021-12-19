# Daksh Gupta
# 20103026 
# CSE

#one way of doing it in O(max(a,b)) is:
#iterate over all numbers from max(a, b) to 1 until that number divides both a and b
def gcd(a, b): 
    for i in range (max(a,b), 0, -1):
        if (a%i == 0 and b%i==0):
            return i 


#to optimise the solution
#we are applying Euclidean's Division Algorithm 
#this decreases complexity to O(log(max(a,b)))
def gcd(a, b):
    #swap a and b if a<b
    if(a<b):
        a,b=b,a
    
    #we find our gcd
    if (a%b==0):
        return b
    #this is the euclidean algo 
    #the remainder is the new b 
    #and b is the new a
    return gcd(b, a%b)


for i in range(int(input())):
    a, b = map(int, input().split())
    print(gcd(a, b))