# 8.
# Pomocou forcyklov a funkcie print definujte funkciu grid s parametrom n, ktora vykresli mriezku s n riadkami a n stlpcami.

def grid(n):
    for _ in range(n):
        print('+ - - - - ' * n, end='+\n')
        for _ in range(4):
            print('|         ' * n, end='|\n')
    print('+ - - - - ' * n, end='+\n')


grid(6)
