from Game import gameFunctions
from Game import playerFunctions
from Board import boardFunctions

n = boardFunctions.select_size()
board = boardFunctions.generate_board(n)
route_a = playerFunctions.map_route_a(n, board)
route_b = playerFunctions.map_route_b(n, board)
gameFunctions.game(board, route_a, route_b, n)
