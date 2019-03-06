def firstFit(capacity, weights):
    binlist = []
    for weight in weights:
        foundBin = False
        for bin in  range(len(binlist)):
            if binlist[bin] >= weight:
                binlist[bin] -= weight
                foundBin = True
                break
        if foundBin == False:
            binlist.append(capacity-weight)
    return len(binlist)

def firstFitD(capacity, weights):
    return firstFit(capacity, sorted(weights, reverse=True))

def bestFit(capacity, weights):
    binlist = []
    for weight in weights:
        bestBin = None
        for bin in range(len(binlist)):
            this = binlist[bin] - weight
            if this < 0:
                continue
            if bestBin is None or this < binlist[bestBin] - weight:
                bestBin = bin
        if bestBin is None:
            binlist.append(capacity-weight)
        else:
            binlist[bestBin] -= weight
    return len(binlist)

def main():
    with open("bin.txt") as file:
        TC = int(file.readline())
        for TC_index in range(TC):
            capacity = int(file.readline())
            N = int(file.readline())
            weights = [int(a) for a in file.readline().strip().split(" ")]
            ff = firstFit(capacity, weights)
            ffd = firstFitD(capacity, weights)
            bf = bestFit(capacity, weights)
            print("Test Case {} First Fit: {}, First Fit Decreasing: {}, Best Fit: {}".format(TC_index+1, ff, ffd, bf))

main()