def main ():
    import sys
    with open(sys.argv[1]) as file:
        #for loop for list of 
        T = int(file.readline())
        #assign first name to baby face group
        for n_index in range(T):
            #take in rest of names
        Y = int(file.readline())
        for r_index in range(Y):
            #check each line for a wrestler already to one group, if so assign other wrsetler to other group
            #if no wrestler in pair is assigned yet save spot and come back once the other pairs have been checked
            #if can't assign everyone return "No, impossible"
        
        #otherwise print "Yes"
        #print "Babyfaces: " followed by names of babyface wrestlers
        #print "Heels: " followed by name of heel face wrestlers
main()