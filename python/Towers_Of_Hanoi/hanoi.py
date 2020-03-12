class MyStack:
    def __init__(self,name):
        self.items = []
        self.name = name
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

def hanoi(height,source,dest,other):
    if height >= 1:
        hanoi(height-1,source,other,dest)
        moveDisk(source,dest)
        hanoi(height-1,other,dest,source)

def moveDisk(fp,tp):
    print("# moving disk from",fp.name,"to",tp.name)
    disk = fp.top()
    tp.push(disk)
    fp.pop()
    print (x.name,"=", x.items)
    print (y.name,"=", y.items)
    print (z.name,"=", z.items)

x = MyStack("x")
y = MyStack("y")
z = MyStack("z")

x.push("AAAA")
x.push("BBB")
x.push("CC")
x.push("D")

hanoi(x.count(),x,z,y)
