import sys

def input_data(m):
    temp_bs = ['0', '0', '0', '0', '0', '0', '0', '0']
    print("Input bs:", end=" ")
    line = input()
    kol = 0
    for tmp in line:
        if (tmp not in ['0', '1']) or (kol >= 8):
            print("Incorrect")
            sys.exit(0)
        temp_bs[kol] = tmp
        kol += 1
    for i in range(kol):
        m[8 - kol + i] = temp_bs[i]

def fileinput(arbuz, m):
    try:
        file = open(arbuz, 'r')
    except:
        print("File not found")
        sys.exit(0)
    
    temp_bs = ['0', '0', '0', '0', '0', '0', '0', '0']
    kol = 0
    
    content = file.read().strip()
    for tmp in content:
        if (tmp not in ['0', '1']) or (kol >= 8):
            print("Incorrect")
            sys.exit(0)
        temp_bs[kol] = tmp
        kol += 1
    
    for i in range(kol):
        m[8 - kol + i] = temp_bs[i]
    
    file.close()

def output(m):
    print("Stroka = ", end="")
    for i in range(8):
        print(m[i], end="")
    print()

def fileoutput(arbuz, m):
    file = open(arbuz, 'w')
    file.write("Stroka = ")
    for i in range(8):
        file.write(m[i])
    file.close()

def conjaction(s1, s2, s3):
    for i in range(8):
        if (s1[i] == '1') and (s2[i] == '1'):
            s3[i] = '1'
        else:
            s3[i] = '0'

def main():
    bs1 = ['0', '0', '0', '0', '0', '0', '0', '0']
    bs2 = ['0', '0', '0', '0', '0', '0', '0', '0']
    res = ['0', '0', '0', '0', '0', '0', '0', '0']
    
    fileinput("arbuz.txt", bs1)
    input_data(bs2)
    
    print("BS 1:", end="")
    output(bs1)
    print("BS 2:", end="")
    output(bs2)
    
    conjaction(bs1, bs2, res)
    output(res)
    
    input("Press Enter to continue...")

if __name__ == "__main__":
    main()
