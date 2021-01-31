def map_route_a(n, board):
    route_a = []
    # Táto funkcia bude fungovať, ako "mapa" pre hráča A, do zoznamu trat_A budeme postupne pridávať ("appendovať") tie pozície, na ktorých sa nachádzajú hviezdičky
    # , pretože na tie pole môže stúpiť hráč A, táto funkcia potom nám umožňí ľahší pohyb (nebudeme po jednom kráčat, ale rovno sa dostaneme ("skočíme") na pole)
    # Šachovnicu rozdelíme na 5 častí: na 4 štvrtiny a na Domčeky
    for i in range(0, n // 2 + 1):  # 1.štvrtina
        for j in range(n // 2 + 1, n):
            if board[i][j] == "*":
                poz = [i, j]
                route_a.append(poz)

    for i in range(n // 2 + 1, n):  # 2.štvrtina
        for j in range(n - 1, n // 2 - 1, -1):
            if board[i][j] == "*":
                poz = [i, j]
                route_a.append(poz)

    for i in range(n - 1, n // 2, -1):  # 3.štvrtina
        for j in range(n // 2 - 1, -1, -1):
            if board[i][j] == "*":
                poz = [i, j]
                route_a.append(poz)

    for i in range(n // 2, -1, -1):  # 4.štvrtina
        for j in range(0, n // 2 + 1):
            if board[i][j] == "*":
                poz = [i, j]
                route_a.append(poz)

    for i in range(0, n // 2):  # Domčeky
        j = n // 2

        if board[i][j] == "D":
            poz = [i, j]
            route_a.append(poz)

    return route_a


def map_route_b(n, board):
    route_b = []
    # Táto funkcia je taká istá ako predchádzajúca funkcia, ale vytvorí trasu("mapu") pre hráča B
    for i in range(n - 1, n // 2 - 1, -1):  # 1.
        for j in range(n // 2 - 1, -1, -1):
            if board[i][j] == "*":
                poz = [i, j]
                route_b.append(poz)

    for i in range(n // 2 - 1, -1, -1):  # 2.
        for j in range(0, n // 2 + 1):
            if board[i][j] == "*":
                poz = [i, j]
                route_b.append(poz)

    for i in range(0, n // 2 + 1):  # 3.
        for j in range(n // 2 + 1, n):
            if board[i][j] == "*":
                poz = [i, j]
                route_b.append(poz)

    for i in range(n // 2 + 1, n):  # 4.
        for j in range(n - 1, n // 2 - 1, -1):
            if board[i][j] == "*":
                poz = [i, j]
                route_b.append(poz)

    for i in range(n - 1, n // 2, -1):  # Domčeky
        j = n // 2
        if board[i][j] == "D":
            poz = [i, j]
            route_b.append(poz)

    return route_b


def set_player(board, route, player):
    board[route[0][0]][route[0][1]] = player


def empty_house(board, route, n):
    for i in range(len(route) - 1, len(route) - ((n - 3) // 2) - 1, -1):
        if board[route[i][0]][route[i][1]] == "D":
            return 1

    return 0


def player_position(board, route, n, player):
    for i in range(len(route) - ((n - 3) // 2)):
        if board[route[i][0]][route[i][1]] == player:
            return i

    return -1


def player_figure_selection(player_number, enemy_figure):
    while True:
        if player_number == 1:
            print(f'\nPlayer{player_number} select your figure\nIt can not be asterisk (*), D')
        else:
            print(
                f'\nPlayer{player_number} select your figure\nIt can not be asterisk (*), '
                f'D, or the figure of your opponent ({enemy_figure})')

        player_figure = input()

        if (player_figure != '*') & (player_figure != 'D') & (player_figure != enemy_figure):
            break

    return player_figure
