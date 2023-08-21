import random

N = 100000

# open file in write mode
file1 = open("MULascending.txt", "w")
file2 = open("MULdescending.txt", "w")
file3 = open("MULrandom.txt", "w")


# write 100 lines
for i in range(N):
    print(i)
    numberlist1 = list(range(0, i+1))
    numberstring1 = ' '.join(str(x) for x in numberlist1)
    file1.write(str(i) + " " + numberstring1 + "\n")

    numberlist2 = numberlist1[::-1]
    numberstring2 = ' '.join(str(x) for x in numberlist2)
    file2.write(str(i) + " " + numberstring2 + "\n")

    random.shuffle(numberlist1)
    numberstring3 = ' '.join(str(x) for x in numberlist1)
    file3.write(str(i) + " " + numberstring3 + "\n")

file1.close()
file2.close()
file3.close()
