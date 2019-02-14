def main ():
    import sys
    with open(sys.argv[1]) as file:
        #for loop for list of 
        T = int(file.readline())
        wrestlers = []
        wrestler_info = {}
        
        for n_index in range(T):
            wrestlers.append(file.readline().strip())
        for wrestler in wrestlers:
            wrestler_info[wrestler] = "Unassigned"
            
        #assign first name to baby face group
        wrestler_info[wrestlers[0]] = "Babyface"
        
        rivalries = []
        Y = int(file.readline())
        for r_index in range(Y):
            rivalries.append(file.readline().strip().split(" "))

        while True:
            changed = False

            for rivalry in rivalries:
                #check rivalries for a wrestler already assigned to one group, if so assign other wrsetler to other group
                if wrestler_info[rivalry[0]] == "Babyface":
                    if wrestler_info[rivalry[1]] == "Babyface":
                        print("No, impossible")
                        return
                    if wrestler_info[rivalry[1]] != "Heel":
                        wrestler_info[rivalry[1]] = "Heel"
                        changed = True

                if wrestler_info[rivalry[0]] == "Heel":
                    if wrestler_info[rivalry[1]] == "Heel":
                        print("No, impossible")
                        return
                    if wrestler_info[rivalry[1]] != "Babyface":
                        wrestler_info[rivalry[1]] = "Babyface"
                        changed = True

                if wrestler_info[rivalry[1]] == "Babyface" and wrestler_info[rivalry[0]] != "Heel":
                    wrestler_info[rivalry[0]] = "Heel"
                    changed = True

                if wrestler_info[rivalry[1]] == "Heel" and wrestler_info[rivalry[0]] != "Babyface":
                    wrestler_info[rivalry[0]] = "Babyface"
                    changed = True
                #if no wrestler in pair is assigned yet save spot and come back once the other pairs have been checked
            if changed == False:
                for wrestler in wrestlers:
                    if wrestler_info[wrestler] == "Unassigned":
                        wrestler_info[wrestler] = "Babyface"
                        changed = True
                        break
            
            if changed == False:
                break
                    
                #if can't assign everyone return "No, impossible"
        
        print("Yes, possible")
        print("Babyfaces : "+" ".join(wrestler for wrestler in wrestlers if wrestler_info[wrestler] == "Babyface"))
        print("Heels : "+" ".join(wrestler for wrestler in wrestlers if wrestler_info[wrestler] == "Heel"))
        #otherwise print "Yes"
        #print "Babyfaces: " followed by names of babyface wrestlers
        #print "Heels: " followed by name of heel face wrestlers
main()