def create_first_row(n):
    first_row = []

    for _ in range((n - 3) // 2):
        first_row.append(" ")

    for _ in range(3):
        first_row.append("*")

    for _ in range((n - 3) // 2):
        first_row.append(" ")

    return first_row


def create_second_row(n):
    second_row = []

    for _ in range((n - 3) // 2):
        second_row.append(" ")

    second_row.append("*")
    second_row.append("D")
    second_row.append("*")

    for _ in range((n - 3) // 2):
        second_row.append(" ")

    return second_row


def create_third_row(n):
    third_row = []  # ******D******

    for _ in range((n - 3) // 2):
        third_row.append("*")

    third_row.append("*")
    third_row.append("D")
    third_row.append("*")

    for _ in range((n - 3) // 2):
        third_row.append("*")

    return third_row


def create_fourth_row(n):
    fourth_row = []  # *DDDDDXDDDDD*

    fourth_row.append("*")  # riadok kolmých Domčekov , X znamená stred šachovnice

    for _ in range((n - 2) // 2):
        fourth_row.append("D")

    fourth_row.append("X")

    for _ in range((n - 2) // 2):
        fourth_row.append("D")

    fourth_row.append("*")

    return fourth_row


def generate_board(n):
    board = []  # z definovaných riadkov zostavíme šachovnicu

    board.append(create_first_row(n))

    for _ in range((n - 5) // 2):
        board.append(create_second_row(n))

    board.append(create_third_row(n))
    board.append(create_fourth_row(n))
    board.append(create_third_row(n))

    for _ in range((n - 5) // 2):
        board.append(create_second_row(n))

    board.append(create_first_row(n))

    return board


def print_board(n, board):  # túto fukciu budeme používať na vykreslenie šachovnice
    for i in range(n):
        for j in range(n):
            print(board[i][j], end="")
            # Budeme postupovať po riadkoch (i), a postupne budeme vypisovať zasebou nasledujúce prvky (j)
        print()


def select_size():
    print("=====================LUDO SIMULATOR =====================\n"
          "Select board-size\nHint: Select an odd number which is lower than 17! ")
    while True:
        n = int(input("\nSize: "))
        if (n % 2 == 1) & (n < 17):
            break
        else:
            print("You have selected an invalid value, try again!")
    return n
