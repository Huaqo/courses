# TODO
print("Height: ")
while True:
    try:
        size = int(input())
        if 1 <= size <= 8:
            break
        else:
            print("Height between 1 and 8: ")
    except ValueError:
        print("Height with numeric value: ")

for i in range(1, size+1):
    print(((size - i) * ' ') + (i * '#'))