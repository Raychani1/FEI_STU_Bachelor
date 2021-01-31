import random

import Board.boardFunctions as bF
import Game.playerFunctions as pF


def player_turn(board, route, n, game_turn, player_position, player_figure, enemy_figure):
    if pF.player_position(board, route, n, player_figure) == -1:
        # keď hráč A nemá panáčika na šachovnici, bude hádzať 3 x
        player_position = 0
        for _ in range(3):
            c = random.randint(1, 6)

            if c == 6:
                pF.set_player(board, route, player_figure)
                # keď hodil 6 , dá panáčika na štartovacie pole, a pridá k počte kôl, toto budeme používať na to, že keď niektorý hráč hodí 6 môže hodit ešte raz
                print(f'{player_figure} rolled: {c}')
                game_turn += 1
                break

            print(f'{player_figure} rolled: {c}')

    else:
        p = random.randint(1, 6)  # vygeneruje náhodné číslo od 1 až po 6

        if p == 6:
            game_turn += 1  # keď hodil 6 môže hodiť ešte raz

        print(f'{player_figure} rolled: {p}')
        board[route[player_position][0]][route[player_position][1]] = "*"  # predchádzajúce pole prepíše na "*"
        player_position += p  # spočítame hody, toto budeme používať pri pohybe

        if player_position >= len(route):
            player_position -= p  # keď sa hodilo príliš veľké číslo, tak táto podmienka mu nedovoľuje aby vstúpil do Domčeka, a zostane tam, kde bol predtým
            print(f'{player_figure} can not enter Home because rolled quite big number.')

        elif board[route[player_position][0]][route[player_position][1]] == player_figure:
            # skontroluje, či vlastný panáčik mu neprekáža, ak áno, tak zostane stáť
            print(f'{player_figure} can not step on that field because his own pawn is standing there.')
            player_position -= p

        elif board[route[player_position][0]][route[player_position][1]] == enemy_figure:
            print(
                f'{player_figure} kicked out {enemy_figure}\'s pawn.')  # zistí, či súper nemá panáčika na poli, kam bude kráčat, ak áno vyhodí ho

        elif board[route[player_position][0]][route[player_position][1]] == "D":
            print(f'{player_figure} entered Home.')

        board[route[player_position][0]][route[player_position][1]] = player_figure  # položí panáčika na nové pole

    return game_turn


def game(board, route_a, route_b, n):
    player1_figure = pF.player_figure_selection(1, '')
    player2_figure = pF.player_figure_selection(2, player1_figure)
    bF.print_board(n, board)

    print("\nPress ENTER to start")
    print("_ _ _ _ _ _ _ _ _ _ _ _ _")
    z = input()

    player = 0

    while pF.empty_house(board, route_a, n) == 1 and pF.empty_house(board, route_b, n) == 1:
        if player % 2 == 0:
            player = player_turn(board, route_a, n, player, pF.player_position(board, route_a, n, player1_figure),
                                 player1_figure, player2_figure)

        else:
            player = player_turn(board, route_b, n, player, pF.player_position(board, route_b, n, player2_figure),
                                 player2_figure, player1_figure)

        bF.print_board(n, board)  # v každom kole vykreslí aktuálnu šachovnicu

        if pF.empty_house(board, route_a, n) == 0:
            print(f'{player1_figure} wins!')  # keď už nie sú voľné Domčeky, vypíše výhercu

        if pF.empty_house(board, route_b, n) == 0:
            print(f'{player2_figure} wins!')

        print("___________________________________")  # rozdelenie kôl
        player += 1
