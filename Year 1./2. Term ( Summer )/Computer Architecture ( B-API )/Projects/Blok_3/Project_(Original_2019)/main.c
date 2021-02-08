#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>

#pragma comment(lib, "Ws2_32.lib")

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#define DEFAULT_BUFLEN 4096

//uvodne nastavovacky
void main() {
    FILE *output;
    output = fopen("chat_log.txt", "w");

    WSADATA wsaData;  //struktura WSADATA pre pracu s Winsock
    HANDLE hConsole;// DECXCPR
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    PCONSOLE_SCREEN_BUFFER_INFO pcsbi = &csbi;
    int recvbuflen = DEFAULT_BUFLEN;
    char recvbuf[DEFAULT_BUFLEN];
    int prvocisla[DEFAULT_BUFLEN];
    int prvocislo = 0;


    GetConsoleScreenBufferInfo(hConsole, pcsbi);
    int y = csbi.dwCursorPosition.Y;

    //"vypocita" konzolové rozmery
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    printf("columns: %d\n", columns);
    y++;
    printf("rows: %d\n", rows);
    y++;

    //prvocsila
    for (int i = 2; i < DEFAULT_BUFLEN; i++) {
        int a = 0;
        for (int j = 2; j < DEFAULT_BUFLEN; j++) {
            if (i % j == 0)
                a++;
        }
        if (a == 1) {
            prvocisla[prvocislo] = i;
            //printf("%d\n", i);
            prvocislo++;
        }
    }
    //zelená farba
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    int iResult;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);     //zakladna inicializacia
    if (iResult != 0)     //kontrola, ci nestala chyba
    {
        printf("WSAStartup failed : %d\n", iResult);
        y++;
        return 1;
    }

    struct addrinfo *result = NULL, *ptr = NULL;     //struktura pre pracu s adresami
    struct addrinfo hints;

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;     //pracujeme s protokolom TCP/IP

    // Resolve the server address and port
    iResult = getaddrinfo("147.175.115.34", "777", &hints, &result);
    if (iResult != 0)     //kontrola, ci nenastala chyba
    {
        printf("getaddrinfo failed : %d\n", iResult);
        y++;
        WSACleanup();
        return 1;
    } else {
        printf("getaddrinfo didn t fail\n");
        y++;
        fprintf(output, "getaddrinfo didn t fail\n");
    }
    //vytvorenie socketu a pripojenie sa

    SOCKET ConnectSocket = INVALID_SOCKET;

    // Attempt to connect to the first address returned by
    // the call to getaddrinfo
    ptr = result;

    // Create a SOCKET for connecting to server => pokus o vytvorenie socketu
    ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (ConnectSocket == INVALID_SOCKET)     //kontrola, ci nenastala chyba
    {
        printf("Error at socket() : %ld\n", WSAGetLastError());
        y++;
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    } else
        printf("Error at socket DIDN T occur\n");
    y++;
    fprintf(output, "Error at socket DIDN T occur\n");
    // Connect to server. => pokus o pripojenie sa na server

    iResult = connect(ConnectSocket, ptr->ai_addr, (int) ptr->ai_addrlen);
    if (iResult == SOCKET_ERROR) {//kontrola, ci nenastala chyba
        printf("Not connected to server \n");
        y++;
        fprintf(output, "Not connected to server \n");
    } else {
        printf("Connected to server!\n");
        y++;
        fprintf(output, "Connected to server!\n");
    }

    if (iResult == SOCKET_ERROR)    //osetrenie chyboveho stavu
    {
        closesocket(ConnectSocket);
        ConnectSocket = INVALID_SOCKET;
        WSACleanup();
        return 1;
    }
    while (1) {
        //posielanie
        char sendbuf[DEFAULT_BUFLEN]; //buffer (v zasade retazec), kam sa budu ukladat data, ktore chcete posielat
        COORD pos = {0, y};
        SetConsoleCursorPosition(hConsole, pos);
        printf("\n");
        y++;
        if (strstr(sendbuf, "0")) {
            fclose(output);
            break;
        }
        if (!strstr(sendbuf, "prvocislo")) {
            printf("User: ");
            fprintf(output, "\n\nUser: ");
            fgets(sendbuf, DEFAULT_BUFLEN, stdin);
            fprintf(output, sendbuf);
            fprintf(output, "\n");

        } else {
            for (int i = 0; i < strlen(sendbuf); i++) {
                sendbuf[i] = recvbuf[prvocisla[i] - 1];

            }
            printf("User: ");
            fprintf(output, "\n\nUser: ");
            printf("%s\n", sendbuf);
            y++;
            fprintf(output, sendbuf);
            fprintf(output, "\n\n");
        }

        iResult = send(ConnectSocket, sendbuf, (int) strlen(sendbuf), 0);
        if (iResult == SOCKET_ERROR) {
            printf("send failed : %d\n", WSAGetLastError());
            y++;
            closesocket(ConnectSocket);
            WSACleanup();
            return 1;
        }

        printf("Bytes Sent : %ld\n", iResult);
        y++;     //vypisanie poctu odoslanych dat

        //prijimanie
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);     //funkcia na príjimanie

        if (iResult > 0) {
            printf("Bytes received : %d\n", iResult);
            y++;
        }    //prisli validne data, vypis poctu
        else if (iResult == 0) {
            {
                printf("Connection closed\n");
                y++;
            }
        }    //v tomto pripade server ukoncil komunikaciu
        else {
            printf("recv failed with error : %d\n", WSAGetLastError());
            y++;
        }   //ina chyba

        char *p;

        SetConsoleOutputCP(CP_UTF8);
        COORD pos2 = {columns / 2, y};
        SetConsoleCursorPosition(hConsole, pos2);
        printf("Morpheus: ");
        fprintf(output, "Morpheus: ");
        if (strstr(sendbuf, "123")) {
            for (int i = 0; i < 129; i++) {
                recvbuf[i] = (recvbuf[i] ^ 55);
            }
        }
        p = strchr(recvbuf, '\n');
        *p = '\0';
        int x = (columns / 2) + 10;
        char *pch;
        pch = strtok(recvbuf, " ");
        while (pch != NULL) {
            x += (strlen(pch) + 1);
            if (x > columns) {
                printf("\n");
                x = columns / 2;
                y++;
                fprintf(output, "\n");
                COORD pos2 = {columns / 2, y};
                SetConsoleCursorPosition(hConsole, pos2);
                continue;
            } else {
                printf("%s ", pch);
                fprintf(output, pch);
                fprintf(output, " ");
                pch = strtok(NULL, " ");
            }
        }
        printf("\n");
        y += 2;
    }
    closesocket(ConnectSocket);
    WSACleanup();
}