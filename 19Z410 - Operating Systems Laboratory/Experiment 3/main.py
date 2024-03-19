processlist = [["process0",10], ["process1",20], ["process2",15], ["process3",25]]

timequantum = 5

def isempty(processlist):
    count = 0
    for process in processlist:
        count += process[1]
    return count

while (isempty(processlist)):
    for process in processlist:
        if process[1] == 0:
            # processlist.remove(process)
            pass
        else:
            result = process[1] - timequantum
            process[1] = 0 if result < 0 else result
        print(process[0], process[1])
    print("\n\n")
