class MyQueue:
    def __init__(self):
        self.items = []
    def empty(self):
        return self.items == []
    def enqueue(self, item):
        self.items.insert(0,item)
    def dequeue(self):
        del self.items[-1]
    def size(self):
        return len(self.items)
    def lastr(self):
        return self.items[-1]

x = MyQueue() # Create the queue object.

# Put the values to the queue.
x.enqueue("Introduction to Artificial Intelligence")
x.enqueue("Database Management Systems")
x.enqueue("Data Mining")
x.enqueue("Operating Systems")

print x.size()

## FIRST IN FIRST OUT ##
print x.items
x.dequeue()
print x.items 
x.dequeue()
print x.items
x.dequeue()
print x.items
