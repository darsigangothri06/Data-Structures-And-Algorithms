# Implement a binary tree -- Add a node
# Creating a node
class TreeNode:
    def __init__(self, data = 0, left = None, right = None):
        self.data = data
        self.left = None
        self.right = None
    
    def printTree(self):
        if self.left:
            self.left.printTree()
        print(self.data),
        if self.right:
            self.right.printTree()
            
    def insert(self, data):
        if self.data:
            if data < self.data:
                if self.left == None:
                    self.left = TreeNode(data)
                else:
                    self.left.insert(data)
            else:
                if self.right == None:
                    self.right = TreeNode(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data
            
            
            
root = TreeNode(5)
root.insert(4)
root.insert(3)
root.insert(6)
root.insert(5)
root.printTree()
