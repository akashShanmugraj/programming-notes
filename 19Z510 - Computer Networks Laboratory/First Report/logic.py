import sys

if len(sys.argv) < 5:
    print("Please provide two command line arguments: targetword and guesscharacter")
    sys.exit(1)

targetword = sys.argv[1]
guesscharacter = sys.argv[2]
guesscount = int(sys.argv[3])
guessstate = sys.argv[4]

if guesscharacter in guessstate:
    print(f"ALR {guessstate} {guesscount}")
    sys.exit(1)

if guesscharacter in targetword:
    guessstate = "".join([c if c == guesscharacter or c in guessstate else "_" for c in targetword])
    print(f"CRCT {guessstate} {guesscount-1}")
    sys.exit(0)

print(f"WRNG {guessstate} {guesscount-1}")
sys.exit(1)
