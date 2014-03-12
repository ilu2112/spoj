# Approach: reversed binary

num = int(raw_input())
while num != -1:
    print(int(bin(num)[2:][::-1].lstrip("0"), 2))
    num = int(raw_input())