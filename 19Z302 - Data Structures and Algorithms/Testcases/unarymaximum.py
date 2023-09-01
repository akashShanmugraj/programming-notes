import random

N = 10000

FILE_NAME_1 = '10K.ascending.txt'
FILE_NAME_2 = '10K.descending.txt'
FILE_NAME_3 = '10K.random.txt'

# open file in write mode
file1 = open(FILE_NAME_1, "w")

LIST_NUM = list(range(0, N+1))
NUMBER_STRING = str(N+1) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file1.write(NUMBER_STRING + "\n")

file1.close()


# open file in write mode
file2 = open(FILE_NAME_2, "w")

LIST_NUM = list(range(0, N+1))
LIST_NUM = LIST_NUM[::-1]
NUMBER_STRING = str(N+1) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file2.write(NUMBER_STRING + "\n")

file2.close()


# open file in write mode
file3 = open(FILE_NAME_3, "w")

LIST_NUM = list(range(0, N+1))
random.shuffle(LIST_NUM)
NUMBER_STRING = str(N+1) + ' ' + ' '.join(str(x) for x in LIST_NUM)

file3.write(NUMBER_STRING + "\n")

file3.close()