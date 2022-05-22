from cs50 import get_string

s = get_string("Number: ")

total = 0

for i in range(len(s) - 2, -1, -2):
    mul = (2 * int(s[i]))
    while (mul):
        total += mul % 10
        mul = int(mul / 10)


for i in range(len(s) - 1, -1, -2):
    total += int(s[i])

if total % 10 != 0:
    print("INVALID")
else:
    if len(s) == 15 and s[:2] in ['34', '37']:
        print("AMEX")
    elif len(s) == 16 and s[:2] in ['51', '52', '53', '54', '55']:
        print("MASTERCARD")
    elif (len(s) == 13 or len (s) == 16) and s[0] == '4':
        print("VISA")
    else:
        print("INVALID")