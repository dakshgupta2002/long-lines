# Daksh Gupta
# 20103026 
# CSE

def Union(s1, s2):
    s3 = []
    for i in s1:
        s3.append(i)
    for j in s2:
        s3.append(j)

    return set(s3)


def Intersection(s1, s2):
    dictionary = {}
    s3=[]

    for i in s1:
        if i in dictionary.keys():
            dictionary[i] += 1
        else:
            dictionary[i] = 1

    for j in s2:
        if j in dictionary.keys():
            dictionary[j] += 1
        else:
            dictionary[j] = 1

    for key, values in dictionary.items():
        if values==2:
            s3.append(key)

    return s3


def Subtract(s1, s2):
    dictionary = {}
    s3 = []

    for i in s2:
        dictionary[i] = 1

    for j in s1:
        if j not in dictionary.keys():
            s3.append(j)
            
    return s3


s1 = set(map(int, input().split()))
s2 = set(map(int, input().split()))

print("Union of given sets is: {", *Union(s1, s2), "}")
print("Intersection of given sets is: {", *Intersection(s1, s2), "}")
print("Difference of given sets is: {",  *Subtract(s1,s2), "}")
