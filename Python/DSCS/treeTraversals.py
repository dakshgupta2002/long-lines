# Daksh Gupta
# 20103026 
# CSE

class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key


# A function to do inorder tree traversal
def printInorder(root):
 
    if root:
 
        # First recur on left child
        printInorder(root.left)
 
        # then print the data of node
        print(root.val, end= " ")
 
        # now recur on right child
        printInorder(root.right)
 
 
# A function to do postorder tree traversal
def printPostorder(root):
 
    if root:
 
        # First recur on left child
        printPostorder(root.left)
 
        # the recur on right child
        printPostorder(root.right)
 
        # now print the data of node
        print(root.val, end = " ")
 
 
# A function to do preorder tree traversal
def printPreorder(root):
 
    if root:
 
        # First print the data of node
        print(root.val, end = " ")
 
        # Then recur on left child
        printPreorder(root.left)
 
        # Finally recur on right child
        printPreorder(root.right)
 
 


root = Node(17)
root.left = Node(12)
root.right = Node(20)
root.left.left = Node(3)
root.left.right = Node(6)


print ("Preorder traversal of binary tree is: ")
printPreorder(root)
 
print ("\nInorder traversal of binary tree is: ")
printInorder(root)
 
print ("\nPostorder traversal of binary tree is: ")
printPostorder(root)