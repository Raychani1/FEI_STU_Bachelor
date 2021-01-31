# 5.
# Definujte funkciu, ktorej argumentami budu dve matice A a B (matice budu reprezentovane
# rovnako ako v ulohe 2). Funkcia vrati sucin A*B. V pripade, ze matice nie je mozne vynasobit,
# funkcia vypise “Zadane matice nie je mozne vynasobit”.

def sucin_matic(A, B):
    if len(A[0]) != len(B):
        print("Zadane matice nie je mozne vynasobit.")
    else:
        riadok_nula = []
        for i in range(len(B[0])):
            riadok_nula.append(0)
        sucet = []
        for i in range(len(A)):
            sucet.append(riadok_nula[:])

        for i in range(len(A)):
            for j in range(len(B[0])):
                for k in range(len(A[0])):
                    sucet[i][j] += A[i][k] * B[k][j]
        return sucet


def vypis_maticu(A):
    for i in range(len(A)):
        for j in range(len(A[0])):
            print(A[i][j], end=" ")
        print()


A = [[1, 2, 3], [4, 5, 6]]
B = [[0, 1, 1], [0, 2, 1], [1, 1, 0]]
print(sucin_matic(A, B))
