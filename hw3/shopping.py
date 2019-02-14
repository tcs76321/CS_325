def ideal_items (weights, prices, starting_index, carry_weight):
    if starting_index >= len(weights):
        return (0, [])
        
    (price_without, items_without) = ideal_items(weights, prices, starting_index + 1, carry_weight)
    if carry_weight < weights[starting_index]:
        return (price_without, items_without)
    (price_with, items_with) = ideal_items(weights, prices, starting_index + 1, carry_weight-weights[starting_index])
    price_with += prices[starting_index]
    items_with += [starting_index]
    
    if price_without > price_with:
        return (price_without, items_without)
    else:
        return (price_with, items_with)



def main ():
   with open("shopping.txt") as file, open("results.txt", "w") as output:
        T = int(file.readline())
        for test_index in range(T):
            N = int(file.readline())
            weights = []
            prices = []
            for item_index in range(N):
                numbers = file.readline().split(" ")
                weights.append(int(numbers[1]))
                prices.append(int(numbers[0]))
            family_size = int(file.readline())

            total_price = 0
            all_items = []
            for family_index in range(family_size):
                carry_weight = int(file.readline())
                (price, items) = ideal_items(weights, prices, 0, carry_weight)
                total_price  += price
                all_items.append(items)

            output.write("Test Case {}\n".format(test_index+1))
            output.write("Total Price {}\n".format(total_price))
            output.write("Member Items\n")
            
            for family_index in range(family_size):
                output.write("{}: {}\n".format(family_index+1, " ".join(str(x+1) for x in all_items[family_index])))
                




main()