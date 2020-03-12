class MyStack:
    def __init__(self):
        self.items = []    
    def push(self, key):
        self.items.append(key)
    def pop(self):
        del self.items[-1]
    def top(self):
        return self.items[-1] 
    def empty(self):
        return bool(self.items) #Return false if its empty
    def count(self):
        return len(self.items)
     
        
x = MyStack()


## LAST IN LAST OUT ######
x.push("Introduction to Artificial Intelligence")
x.push("Database Management Systems")
x.push("Data Mining")
x.push("Operating Systems")

print x.items
print x.top()
x.pop() 
print x.items
print x.count()
x.pop()
x.pop()
print x.items
