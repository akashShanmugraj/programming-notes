# this file generate nearly sorted test cases for predefiled ranges
import random

PRE_HALF_LIST_1 = list(range(0, 100))
SHF_RANGE_1 = list(range(100,151))
random.shuffle(SHF_RANGE_1)
POST_HALF_LIST_1 = list(range(151, 1001))

PRE_HALF_LIST_2 = list(range(0, 860))
SHF_RANGE_2 = list(range(860, 901))
random.shuffle(SHF_RANGE_2)
POST_HALF_LIST_2 = list(range(901, 1001))

PRE_HALF_LIST_3 = list(range(0, 430))
SHF_RANGE_3 = list(range(430, 513))
random.shuffle(SHF_RANGE_3)
POST_HALF_LIST_3 = list(range(513, 1001))


FIRST_STRING = '1000 ' + ' '.join(str(x) for x in PRE_HALF_LIST_1) + ' ' + ' '.join(str(x) for x in SHF_RANGE_1) + ' ' + ' '.join(str(x) for x in POST_HALF_LIST_1)
SECOND_STRING = '1000 ' + ' '.join(str(x) for x in PRE_HALF_LIST_2) + ' ' + ' '.join(str(x) for x in SHF_RANGE_2) + ' ' + ' '.join(str(x) for x in POST_HALF_LIST_2)
THIRD_STRING = '1000 ' + ' '.join(str(x) for x in PRE_HALF_LIST_3) + ' ' + ' '.join(str(x) for x in SHF_RANGE_3) + ' ' + ' '.join(str(x) for x in POST_HALF_LIST_3)

file1 = open("1000nearlysorted1.txt", "w")
file2 = open("1000nearlysorted2.txt", "w")
file3 = open("1000nearlysorted3.txt", "w")

file1.write(FIRST_STRING + "\n")
file2.write(SECOND_STRING + "\n")
file3.write(THIRD_STRING + "\n")

file1.close()
file2.close()
file3.close()