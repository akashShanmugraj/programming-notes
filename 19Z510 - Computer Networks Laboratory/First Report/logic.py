import sys

if len(sys.argv) < 5:
    print("ISFC ", sys.argv)
    # print("Please provide two command line arguments: targetword and guesscharacter")
    sys.exit(1)

targetword = sys.argv[1]
guesscharacter = sys.argv[2]
guesscount = int(sys.argv[3])
guessstate = sys.argv[4]

with open('/Users/akashshanmugaraj/Documents/programming-notes/19Z510 - Computer Networks Laboratory/First Report/params.txt', 'w') as file:
    file.write(f"targetword: {targetword}\n")
    file.write(f"guesscharacter: {guesscharacter}\n")
    file.write(f"guesscount: {guesscount}\n")
    file.write(f"guessstate: {guessstate}\n")

if guesscharacter in guessstate:
    print(f"ALR {guessstate} {guesscount}")
    sys.exit(0)

if guesscharacter in targetword:
    guessstate = "".join([c if c == guesscharacter or c in guessstate else "_" for c in targetword])
    if guessstate == targetword:
        print(f"DONE {guessstate} {guesscount}")
    print(f"CRCT {guessstate} {guesscount-1}")
    sys.exit(0)

print(f"WRNG {guessstate} {guesscount-1}")
sys.exit(0)
