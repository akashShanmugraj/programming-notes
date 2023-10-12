
stack = [2,3,3,'*',5,2,'+','/','-']
stack.reverse()
revstact = ['-', '/', '+', 2, 5, '*', 3, 3, 2]
memory = []


while (revstact):
    out = revstact.pop()
    if type(out) == int:
        memory.append(out)
    else:
        second = memory.pop()
        first = memory.pop()
        memory.append(eval(str(first)+out+str(second)))
    
    print(memory)
