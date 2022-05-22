from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

k = n - 1

for i in range(1, n + 1):
    print(k * " " + i * "#" + "  " + i * "#")
    k -= 1