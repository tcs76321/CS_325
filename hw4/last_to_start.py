def main ():
    with open("act.txt") as file:
        p = 1
        while True:
            num_activities = file.readline().strip()
            if num_activities == "":
                break
            num_activities = int(num_activities)
            activities = []
            for index in range(num_activities):
                y = file.readline().split(" ")
                activities.append((int(y[0]), int(y[1]), int(y[2])))
            activities.sort(key=lambda x: x[1], reverse=True)
            n = len(activities)
            activities_result = [activities[0][0]]
            k = 0
            for m in range (2, n):
                if activities[m][2] <= activities[k][1]:
                    activities_result.append(activities[m][0])
                    k = m
            activities_result.reverse()
            print("Set {}".format(p))
            p += 1
            print("Number of activities selected = {}".format(len(activities_result)))
            print("Activities: {}".format(" ".join(str(x) for x in activities_result)))








main()