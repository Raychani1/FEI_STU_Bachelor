# 2.
# Uvazujme zoznam t. Zoznam t bude mat n prvkov. Prvky zoznamu t budu zoznamy obsahujuce k
# cisel (kazdy z n zoznamov obsahuje k cisel). Mozeme to potom brat tak, ze zoznam t reprezentuje
# maticu rozmeru n*k, kde kazdy z prvkov zoznamu t reprezentuje jeden riadok matice. Definujte
# funkciu, ktorej argumentami budu dve matice A a B. Funkcia vrati sucet A+B. V pripade, ze matice
# nie je mozne scitat, funkcia vypise “Zadane matice nie je mozne scitat”.


def sucet_matic(A, B):
    if len(A) != len(B) or len(A[0]) != len(B[0]):
        print("Zadane matice nie je mozne scitat.")
    else:
        riadok_nula = []
        for i in range(len(A[0])):
            riadok_nula.append(0)
        sucet = []
        for i in range(len(A)):
            sucet.append(riadok_nula[:])
        for i in range(len(A)):
            for j in range(len(A[0])):
                sucet[i][j] = A[i][j] + B[i][j]
        return sucet


A = [[1, 2, 3], [4, 5, 6]]
B = [[3, 1, 0], [4, 5, 5]]
print(sucet_matic(A, B))


#################################################################


def sucet_matic(A, B):
    if len(A) != len(B) or len(A[0]) != len(B[0]):
        print("Zadane matice nie je mozne scitat.")
    else:
        sucet = []
        for i in range(len(A)):
            sucet.append([])
            for j in range(len(A[0])):
                sucet[i].append(A[i][j] + B[i][j])
        return sucet


A = [[1, 2, 3], [4, 5, 6]]
B = [[3, 1, 0], [4, 5, 5]]
print(sucet_matic(A, B))
