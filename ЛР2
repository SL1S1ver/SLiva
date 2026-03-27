MAX = 8

print("Vvod 1 stroki: ", end='')
a = input()

for char in a:
    if char != '0' and char != '1':
        print("Oshibka!")
        exit(1)

len_a = len(a)
if len_a > MAX:
    print("Nevernaya dlina")
    exit(1)

a = a.zfill(MAX)
print("1 stroka:", a)

print("Vvod 2 stroki: ", end='')
b = input()

for char in b:
    if char != '0' and char != '1':
        print("Oshibka")
        exit(1)

len_b = len(b)
if len_b > MAX:
    print("Nevernaya dlina")
    exit(1)

b = b.zfill(MAX)
print("2 stroka:", b)

print("Conjuction: ", end='')
for i in range(MAX):
    if a[i] == '1' and b[i] == '1':
        print('1', end='')
    else:
        print('0', end='')
print()
