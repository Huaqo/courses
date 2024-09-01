# TODO

quarters = 0.25
dimes = 0.10
nickels = 0.05
pennies = 0.01

coins = 0

print('Change owed: ')

while True:
    try:
        change = float(input())
        if change >= 0:
            break
        else:
            print("Change must be greater then 0: ")
    except ValueError:
        print("Change must be a numeric value: ")

while change > 0:
    if change >= quarters:
        change -= quarters
        coins += 1
    elif change >= dimes:
        change -= dimes
        coins += 1
    elif change >= nickels:
        change -= nickels
        coins += 1
    elif change >= pennies:
        change -= pennies
        coins += 1

    change = round(change, 2)

print(coins)
