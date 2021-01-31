# Ladislav Rajcsányi - ID: 97914 - Skupina 14
import random


# definuje 4 rôzne riadky, budeme na to používať zoznany(listy), z týchto riadkov budeme potom zostavovať sachovnicu.
def prvy_riadok(n):  # ***
    prvy_riadok = []  # V tomto riadku budeme mať 3 "*", tento riadok budeme používať, ako vršok a spodok našej šachovnice
    for i in range((n - 3) // 2):
        prvy_riadok.append(" ")
    for i in range(3):
        prvy_riadok.append("*")
    for i in range((n - 3) // 2):
        prvy_riadok.append(" ")
    return prvy_riadok


def druhy_riadok(n):
    druhy_riadok = []  # *D*
    for i in range((n - 3) // 2):
        # v tomto riadku budeme mať zvislé Domčeky
        druhy_riadok.append(" ")
    druhy_riadok.append("*")
    druhy_riadok.append("D")
    druhy_riadok.append("*")
    for i in range((n - 3) // 2):
        druhy_riadok.append(" ")
    return druhy_riadok


def treti_riadok(n):
    treti_riadok = []  # ******D******
    for i in range((n - 3) // 2):
        # tento ridok umiestnime nad a pod  kolmými Domčekmi
        treti_riadok.append("*")
    treti_riadok.append("*")
    treti_riadok.append("D")
    treti_riadok.append("*")
    for i in range((n - 3) // 2):
        treti_riadok.append("*")
    return treti_riadok


def stvrty_riadok(n):
    stvrty_riadok = []  # *DDDDDXDDDDD*
    stvrty_riadok.append("*")  # riadok kolmých Domčekov , X znamená stred šachovnice
    for i in range((n - 2) // 2):
        stvrty_riadok.append("D")
    stvrty_riadok.append("X")
    for i in range((n - 2) // 2):
        stvrty_riadok.append("D")
    stvrty_riadok.append("*")
    return stvrty_riadok


def gensachovnica(n):
    sachovnica = []  # z definovaných riadkov zostavíme šachovnicu
    sachovnica.append(prvy_riadok(n))
    for i in range((n - 5) // 2):
        sachovnica.append(druhy_riadok(n))
    sachovnica.append(treti_riadok(n))
    sachovnica.append(stvrty_riadok(n))
    sachovnica.append(treti_riadok(n))
    for i in range((n - 5) // 2):
        sachovnica.append(druhy_riadok(n))
    sachovnica.append(prvy_riadok(n))
    return sachovnica


def tlacsachovnicu(n, sachovnica):  # túto fukciu budeme používať na vykreslenie šachovnice
    for i in range(n):
        for j in range(n):
            print(sachovnica[i][j], end="")
            # Budeme postupovať po riadkoch (i), a postupne budeme vypisovať zasebou nasledujúce prvky (j)
        print()


def trat_A(n, sachovnica):
    trat_A = []
    # Táto funkcia bude fungovať, ako "mapa" pre hráča A, do zoznamu trat_A budeme postupne pridávať ("appendovať") tie pozície, na ktorých sa nachádzajú hviezdičky
    # , pretože na tie pole môže stúpiť hráč A, táto funkcia potom nám umožňí ľahší pohyb (nebudeme po jednom kráčat, ale rovno sa dostaneme ("skočíme") na pole)
    # Šachovnicu rozdelíme na 5 častí: na 4 štvrtiny a na Domčeky
    for i in range(0, n // 2 + 1):  # 1.štvrtina
        for j in range(n // 2 + 1, n):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_A.append(poz)
    for i in range(n // 2 + 1, n):  # 2.štvrtina
        for j in range(n - 1, n // 2 - 1, -1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_A.append(poz)
    for i in range(n - 1, n // 2, -1):  # 3.štvrtina
        for j in range(n // 2 - 1, -1, -1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_A.append(poz)
    for i in range(n // 2, -1, -1):  # 4.štvrtina
        for j in range(0, n // 2 + 1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_A.append(poz)

    for i in range(0, n // 2):  # Domčeky
        j == n // 2

        if sachovnica[i][j] == "D":
            poz = [i, j]
            trat_A.append(poz)
    return trat_A


def trat_B(n, sachovnica):
    trat_B = []
    # Táto funkcia je taká istá ako predchádzajúca funkcia, ale vytvorí trasu("mapu") pre hráča B
    for i in range(n - 1, n // 2 - 1, -1):  # 1.
        for j in range(n // 2 - 1, -1, -1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_B.append(poz)
    for i in range(n // 2 - 1, -1, -1):  # 2.
        for j in range(0, n // 2 + 1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_B.append(poz)
    for i in range(0, n // 2 + 1):  # 3.
        for j in range(n // 2 + 1, n):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_B.append(poz)
    for i in range(n // 2 + 1, n):  # 4.
        for j in range(n - 1, n // 2 - 1, -1):
            if sachovnica[i][j] == "*":
                poz = [i, j]
                trat_B.append(poz)

    for i in range(n - 1, n // 2, -1):  # Domčeky
        j == n // 2

        if sachovnica[i][j] == "D":
            poz = [i, j]
            trat_B.append(poz)
    return trat_B


def setter_A(sach, Trat_A):
    # túto funkciu budeme používať nato, aby hráč A dal panáčika na štartovacie pole
    sach[Trat_A[0][0]][Trat_A[0][1]] = "A"


def setter_B(sach, Trat_B):
    # túto funkciu budeme používať nato, aby hráč B dal panáčika na štartovacie pole
    sach[Trat_B[0][0]][Trat_B[0][1]] = "B"


def find_A(sach, Trat_A):
    # táto funkcia zistí, či hráč A má panáčika na šachovnici, prekontroluje trat_A, Domčeky vynechá
    for i in range(len(Trat_A) - ((n - 3) // 2)):
        if sach[Trat_A[i][0]][Trat_A[i][1]] == "A":
            return 1
    else:
        return 0


def find_B(sach, Trat_B):
    # táto funkcia zistí, či hráč B má panáčika na šachovnici, prekontroluje trat_B, Domčeky vynechá
    for i in range(len(Trat_B) - ((n - 3) // 2)):
        if sach[Trat_B[i][0]][Trat_B[i][1]] == "B":
            return 1
    else:
        return 0


def volnydom_B(sach, Trat_B):
    # zistíme, či hráč B má voľné Domčeky
    for i in range(len(Trat_B) - 1, len(Trat_B) - ((n - 3) // 2) - 1, -1):
        if sach[Trat_B[i][0]][Trat_B[i][1]] == "D":
            return 1
    else:
        return 0


def volnydom_A(sach, Trat_A):
    # zistíme, či hráč A má voľné Domčeky
    for i in range(len(Trat_A) - 1, len(Trat_A) - ((n - 3) // 2) - 1, -1):
        if sach[Trat_A[i][0]][Trat_A[i][1]] == "D":
            return 1
    else:
        return 0


def hra(sac):
    tlacsachovnicu(n, sach)

    print("\nPre START stlačte ENTER")
    print("_ _ _ _ _ _ _ _ _ _ _ _ _")
    z = input()

    hrac = 0
    while volnydom_A(sach, Trat_A) == 1 and volnydom_B(sach, Trat_B) == 1:
        # Hru dovtedy hrajú, kým sú voľné Domčeky

        if hrac % 2 == 0:
            # v párnych kolách bude hádzať a kráčat hráč A
            if find_A(sach, Trat_A) == 0:
                # keď hráč A nemá panáčika na šachovnici, bude hádzať 3 x
                hA = 0
                for i in range(3):
                    c = random.randint(1, 6)

                    if c == 6:
                        setter_A(sach, Trat_A)
                        # keď hodil 6 , dá panáčika na štartovacie pole, a pridá k počte kôl, toto budeme používať na to, že keď niektorý hráč hodí 6 môže hodit ešte raz
                        print("A hodil kockou:", c)
                        hrac += 1
                        break
                    print("A hodil kockou:", c)

            else:
                p = random.randint(1, 6)  # vygeneruje náhodné číslo od 1 až po 6
                if p == 6:
                    hrac += 1  # keď hodil 6 môže hodiť ešte raz
                print("A hodil kockou:", p, "\n")
                sach[Trat_A[hA][0]][Trat_A[hA][1]] = "*"  # predchádzajúce pole prepíše na "*"
                hA += p  # spočítame hody, toto budeme používať pri pohybe

                if hA >= len(Trat_A):
                    hA -= p  # keď sa hodilo príliš veľké číslo, tak táto podmienka mu nedovoľuje aby vstúpil do Domčeka, a zostane tam, kde bol predtým
                    print("A nemôže ísť do Domčeka, lebo hodil príliš veľké číslo")
                elif sach[Trat_A[hA][0]][
                    Trat_A[hA][1]] == "A":  # skontroluje, či vlastný panáčik mu neprekáža, ak áno, tak zostane stáť
                    print("A nemôže íst na tú hraciu polu, lebo tam stojí jeho panáčik")
                    hA -= p
                elif sach[Trat_A[hA][0]][Trat_A[hA][1]] == "B":
                    print(
                        "A vyhodil panáčika B")  # zistí, či súper nemá panáčika na poli, kam bude kráčat, ak áno vyhodí ho
                elif sach[Trat_A[hA][0]][Trat_A[hA][1]] == "D":
                    print("A vošiel s panáčikom do Domčeka")

                sach[Trat_A[hA][0]][Trat_A[hA][1]] = "A"  # položí panáčika na nové pole

        else:
            if find_B(sach, Trat_B) == 0:
                hB = 0
                for i in range(3):
                    c = random.randint(1, 6)

                    if c == 6:
                        setter_B(sach, Trat_B)
                        print("B hodil kockou:", c)
                        hrac += 1
                        break
                    print("B hodil kockou:", c)


            else:
                q = random.randint(1, 6)
                print("B hodil kockou:", q)

                if q == 6:
                    hrac += 1
                sach[Trat_B[hB][0]][Trat_B[hB][1]] = "*"
                hB += q
                if hB >= len(Trat_B):
                    hB -= q
                    print("B nemôže ísť do Domčeka, lebo hodil príliš veľké číslo")
                elif sach[Trat_B[hB][0]][Trat_B[hB][1]] == "B":
                    print("B nemôže íst na tú hraciu polu, lebo tam stojí jeho panáčik")
                    hB -= q
                elif sach[Trat_B[hB][0]][Trat_B[hB][1]] == "A":
                    print("B vyhodil panáčika A")
                elif sach[Trat_B[hB][0]][Trat_B[hB][1]] == "D":
                    print("B vošiel s panáčikom do Domčeka")

                sach[Trat_B[hB][0]][Trat_B[hB][1]] = "B"

        tlacsachovnicu(n, sach)  # v každom kole vykreslí aktuálnu šachovnicu
        if volnydom_A(sach, Trat_A) == 0:
            print("Vyhral hráč A!")  # keď už nie sú voľné Domčeky, vypíše výhercu
        if volnydom_B(sach, Trat_B) == 0:
            print("Vyhral hráč B!")

        print("___________________________________")  # rozdelenie kôl
        input()  # pre pokračovanie očakáva stlačenie tlačítka
        hrac += 1


print("Zadajte veľkosť šachovnice.")  # zadanie vľkosti šachovnice
print("Hint: Zadajte nepárne číslo! ")

while True:  # prekontroluje, či sme zadali nepárne číslo, ak nie,tak bude vyžadovať nepárne číslo dovtedy, kým nezadáme

    n = int(input("\nVeľkosť: "))
    if n % 2 == 1:

        break

    else:
        print("Zadali ste nevhodné číslo,skúsťe ešte raz!")

sach = gensachovnica(n)
Trat_B = trat_B(n, sach)
Trat_A = trat_A(n, sach)
hra(sach)
