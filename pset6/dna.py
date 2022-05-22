from sys import argv, exit
import csv

flist = []
def dataf(rdata):
    ls = []
    for i in rdata:
            if "name" in i:
                ls = i[1:]
            else:
                flist.append(i)
    return ls

def cdata(nucleotide, rtxt):
    init = len(nucleotide)
    k = init
    seq = []
    count = 0

    while k <= len(rtxt):
        count = 0
        if rtxt[k - init : k] == nucleotide:
            count = 1
            t = k
            while True and t <= len(rtxt):
                t += init
                if rtxt[t - init : t] == nucleotide:
                    count += 1

                else:
                    seq.append(count)
                    break

        else:
            seq.append(count)

        k += 1

    return max(seq)

if len(argv) != 3:
    exit(1)

if __name__ == '__main__':

    with open (argv[1], "r") as database:
        with open(argv[2], "r") as sequences:
            rdata = csv.reader(database)
            rtxt2 = sequences.readlines()
            rtxt = rtxt2[0]
            arr = dataf(rdata)
            out = []
            for i in arr:
                out.append(str(cdata(i, rtxt)))


            for i in flist:
                if out == i[1:]:
                    print(i[0])
                    exit(0)

            print("No match")
            exit(0)