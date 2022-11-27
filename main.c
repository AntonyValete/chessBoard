#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct square {
    char piece[3];
    char coordinate[3];
} square;

typedef struct board {
    square **squares;
} board;

board *createNewBoard();
void initializeBoard(board *boardAux);
void printfTitle();
void printfBoard(board *boardAux);
void freeBoard(board *boardAux);

int main() {
    board *newBoard;

    newBoard = createNewBoard();
    initializeBoard(newBoard);
    printfTitle();
    printfBoard(newBoard);

    freeBoard(newBoard);
    return 0;
}

board *createNewBoard() {
    board *aux = (board *) malloc(1*sizeof(board));

    aux->squares = (square **) malloc(8 * sizeof(square *));
    for (int j = 0; j < 8; j++) {
        aux->squares[j] = (square *) malloc(8 * sizeof(square));
    }

    return aux;
}

void initializeBoard(board *boardAux) {
    const char aux[8][8][3] = {
        {{"bR"}, {"bN"}, {"bB"}, {"bQ"}, {"bK"}, {"bB"}, {"bN"}, {"bR"}},
        {{"bP"}, {"bP"}, {"bP"}, {"bP"}, {"bP"}, {"bP"}, {"bP"}, {"bP"}},
        {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
        {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
        {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
        {{'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}, {'\0'}},
        {{"wR"}, {"wN"}, {"wB"}, {"wQ"}, {"wK"}, {"wB"}, {"wN"}, {"wR"}},
        {{"wP"}, {"wP"}, {"wP"}, {"wP"}, {"wP"}, {"wP"}, {"wP"}, {"wP"}}
    };

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            strcpy(boardAux->squares[i][j].piece, aux[i][j]);
}

void printfTitle() {
    FILE *title = fopen(".\\title.txt", "r");
    char aux;
    while (fscanf(title, "%c", &aux) != EOF) {
        putchar(aux);
    }
    fclose(title);
}

void printfBoard(board *boardAux) {
    puts("\t\t   a  b  c  d  e  f  g  h");
    for (int i = 0; i < 8; i++) {
        square *row = boardAux->squares[i];
        printf("\t\t%d ", i + 1);
        for (int j = 0; j < 8; j++) {
            if (row[j].piece[0] == '\0')
                printf("  |");
            else
                printf("%s|", row[j].piece);
        }
        putchar('\n');
        puts("\t\t  ------------------------");
    }
}

void freeBoard(board *boardAux) {
    for (int i = 0; i < 8; i++) {
        free(boardAux->squares[i]);
    }
    free(boardAux->squares);
    free(boardAux);
}