import random

wordlist = ["apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "pear", "quince", "raspberry", "strawberry", "tangerine", "ugli", "watermelon"]

randomword = random.choice(wordlist)
wordlength = len(set(randomword))

print(randomword, wordlength)