import sys
for line in sys.stdin: 
    print (1 if int(line) == 1 else 2 * int(line) - 2)
