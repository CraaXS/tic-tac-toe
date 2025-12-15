one = "1"
two = "2"
three = "3"
four = "4"
five = "5"
six = "6"
seven = "7"
eight = "8"
nine = "9"

playing = True

while playing:
    print("Tic Tac Toe")
    print("===========")
    print(f"{one}|{two}|{three}")
    print(f"{four}|{five}|{six}")
    print(f"{seven}|{eight}|{nine}")
    x = input("X: ")
    if x == 1:
        one = "X"
