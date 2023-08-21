import random

N = 100000

FILE_NAME_1 = 'ascending.txt'

# open file in write mode
file1 = open(FILE_NAME_1, "w")

LIST_NUM = list(range(0, N+1))
NUMBER_STRING = str(N) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file1.write(NUMBER_STRING + "\n")

file1.close()

FILE_NAME_2 = 'descending.txt'

# open file in write mode
file2 = open(FILE_NAME_2, "w")

LIST_NUM = list(range(0, N+1))
LIST_NUM = LIST_NUM[::-1]
NUMBER_STRING = str(N) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file2.write(NUMBER_STRING + "\n")

file2.close()

FILE_NAME_3 = 'random.txt'

# open file in write mode
file3 = open(FILE_NAME_3, "w")

LIST_NUM = list(range(0, N+1))
random.shuffle(LIST_NUM)
NUMBER_STRING = str(N) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file3.write(NUMBER_STRING + "\n")

file3.close()