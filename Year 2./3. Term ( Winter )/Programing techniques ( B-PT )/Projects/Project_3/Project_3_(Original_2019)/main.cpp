/*
Meno a priezvisko: Ladislav Rajcsányi

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du03.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
	 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
	 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
	 Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>
#include <cstring>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Uzol zretazeneho zoznamu
struct Node {
    int data; // hodnota uzla
    Node* next; // smernik na dalsi uzol zoznamu
};

// Zretazeny zoznam
struct List {
    Node* first; // smernik na prvy uzol zoznamu
};

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada pole 'data' od najvacsieho po najmensi prvok.
	Pouzite algoritmus insertion sort.
	Usporiadanie je od najvacsieho po najmensi prvok (opacne ako na tutorialy)!

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[in] length - pocet prvkov pola

	VSTUPNE PODMIENKY:
		'length' moze mat lubovolnu hodnotu
		'data' ukazuje na platne pole

	PRIKLADY:
		{1,3,2} -> {3, 2, 1}
		{} -> {}
*/

void insertionSort(int *data, const size_t length) {
    for (int i = 1; i < length; ++i) {
        for (int j = i; j > 0; j--) {
            if (data[j] > data[j - 1]) {
                swap(data[j], data[j - 1]);
            }
            else {
                break;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada textove retazce v poli 'data' od najvacsieho po najmensi prvok (lexikograficky).
	Pouzite algoritmus insertion sort.
	Usporiadanie je od najvacsieho po najmensi prvok!

	 PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada.
				Pole obsahuje smerniky na textove retazce.
				Kazdy textovy retazec je ukonceny '\0'.
				Posledny smernik ma hodnotu 'nullptr'. Podla toho urcite pocet prvkov pola (pocet textovych retazcov).

	VSTUPNE PODMIENKY:
		'data' obsahuje minimalne jeden smernik.
		Posledny smernik ma hodnotu 'nullptr'.

	PRIKLADY:
		{"Juraj", "Peter", "Andrej", nullptr} -> {"Peter", "Juraj", "Andrej", nullptr}
		{nullptr} -> {nullptr}

	POZNAMKY:
		Pri testovani mozete jednoducho pole vytvorit nasledovnym sposobom:
		const char *mena[] = {"Juraj", "Peter", "Andrej", nullptr};

		Na porovnanie obsahu textovych retazcov vyuzite prislusnu funkciu zo standardnej kniznice.
*/

void insertionSort(const char *data[]) {
    size_t length = 0, index = 0;
    const char* tmp = data[index];
    while (tmp){
        ++length;
        ++index;
        tmp = data[index];
    }
    for (size_t i = 1; i < length; ++i){
        for (size_t j = i; j > 0; j--){
            if (strcmp(data[j], data[j - 1])>0){
                swap(data[j], data[j - 1]);
            }
            else{
                break;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada zretazeny zoznam 'list' od najvacsieho po najmensi prvok.
	Pouzite algoritmus insertion sort.
	Usporiadanie je od najvacsieho po najmensi prvok!

	PARAMETRE:
		[in, out] list - zretazeny zoznam, ktory funkcia usporiada

	VSTUPNE PODMIENKY:
		'list' obsahuje lubovolny pocet uzlov (moze byt prazdny)
		'list' nie je 'nullptr'

	PRIKLADY:
		vstup: 2->1->3, vystup: 3->2->1
		vstup: prazdny zoznam, vystup: prazdny zoznam
*/
Node* findPreviousNode(List* list, Node* node);
void swapNodes(List* list, Node *a, Node *b);

void insertionSort(List * list) {
    if (!list->first) {
        return;
    }
    Node * current = list->first->next;
    Node * next = NULL;
    while (current) {
        Node * pred = findPreviousNode(list, current);
        if (current->data > pred->data) {

            next = current->next;
            while (current->data > pred->data) {
                swapNodes(list, current, pred);
                pred = findPreviousNode(list, current);
                if (!pred || !current)
                    break;
            }
            current = next;
            continue;
        }
        current = current->next;
    }
}
//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Vykona algoritmus merge (cast algoritmu merge sort).
	Kombinute dve susedne usporiadane casti v poli 'input' do jednej usporiadanej casti v poli 'output'
	Usporiadanie je od najvacsieho po najmensi prvok!

	PARAMETRE:
		[out] 'output' - vystupne pole, ktoreho cast output[low]...output[high-1] bude po vykonani funkcie usporiadana
		[in] 'input'   - vstupne pole, ktoreho casti input[low]...input[middle-1] a input[middle]...input[high-1]
						 musia byt pri volani funkcie usporiadane od najvacsieho po najmensi prvok
		[in] 'low'     - index 1. prvku lavej usporiadanej casti pola 'input'
		[in] 'middle'  - index 1. prvku pravej usporiadanej casti pola 'input'
		[in] 'high'    - index za poslednym prvkom pravej usporiadanej casti pola 'input'

	VYSTUPNE PODMIENKY:
		output[low] ... output[high-1] obsahuje usporiadane prvky z input[low] ... input[high-1]
		obsah 'input' sa nemeni
		prvky s indexami mensimi ako 'low' sa nemenia (v obidvoch poliach)
		prvky s indexami vacsimi alebo rovnymi ako 'high' sa nemenia (v obidvoch poliach)

	PRIKLAD:
		low: 4
		middle: 8
		hight: 12
		input:  {10, 20, 30, 40, 7, 5, 2, 0, 8, 4, 2, 1, 10, 20, 30, 40}
		output: {10, 20, 30, 40, 8, 7, 5, 4, 2, 2, 1, 0, 10, 20, 30, 40}
*/
void merge(int* output, const int* input, const size_t low, const size_t middle, const size_t high) {
    size_t first = low;
    size_t second = middle;
    size_t out = low;

    while (first < middle && second < high) {
        if (input[first] > input[second]) {
            output[out] = input[first];
            ++first;
        }
        else {
            output[out] = input[second];
            ++second;
        }
        ++out;
    }
    while (first < middle) {
        output[out] = input[first];
        ++first;
        ++out;
    }
    while (second < high) {
        output[out] = input[second];
        ++second;
        ++out;
    }
}
//-------------------------------------------------------------------------------------------------
// ULOHA (0.2 boda)
//-------------------------------------------------------------------------------------------------
/*
	Usporiada prvky v poli 'data' od najvacsieho po najmensi.
	Pouzite algoritmus merge sort.
	Usporiadanie je od najvacsieho po najmensi prvok!

	PARAMETRE:
		[in, out] data - pole, ktore funkcia usporiada
		[int]   length - pocet prvkov pola

	VSTUPNE PODMIENKY:
		'data' ukazuje na platne pole

	PRIKLADY:
		{1,3,2} -> {3, 2, 1}
		{} -> {}

	POZNAMKA:
		Pri implementacii top-down bude vhodne vytvorit a zavolat rekurzivnu funkciu.
*/

void Merge_Sort_Recurive(int* arr_A, int* arr_B, int left, int right);

void mergeSort(int *data, const size_t length) {
    int* tmpArray = new int[length];
    std::memcpy(tmpArray, data, length * sizeof(int));
    Merge_Sort_Recurive(data, tmpArray,0, length);
    delete [] tmpArray;
}

//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------
// tu mozete doplnit pomocne funkcie a struktury

void Merge_Sort_Recurive(int* arr_A, int* arr_B, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    const size_t middle = (left + right) / 2;
    Merge_Sort_Recurive(arr_B, arr_A, left, middle);
    Merge_Sort_Recurive(arr_B, arr_A, middle, right);
    merge(arr_A, arr_B, left, middle, right);
}

Node* findPreviousNode(List* list, Node* node) {
    Node* tmp = list->first;
    while (tmp) {
        if (tmp->next == node) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

void swapNodes(List* list, Node *a, Node *b) {
    if (!a || !b) {
        return;
    }
    Node* pred_a = findPreviousNode(list, a);
    Node* pred_b = findPreviousNode(list, b);
    if (pred_a) {
        pred_a->next = b;
    }
    if (pred_b) {
        pred_b->next = a;
    }
    Node* tmp = a->next;
    a->next = b->next;
    b->next = tmp;
    if (a == list->first) {
        list->first = b;
        return;
    }
    if (b == list->first) {
        list->first = a;
    }
}

int main() {
    return 0;
}