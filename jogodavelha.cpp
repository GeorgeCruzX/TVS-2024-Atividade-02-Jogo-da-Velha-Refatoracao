#include <iostream>
#include <cstdlib>

using namespace std;

void displayBoard(char board[3][3]) {
    system("cls");
    cout << "\t " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "\t-----------\n";
    cout << "\t " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "\t-----------\n";
    cout << "\t " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

int checkGameOver(char board[3][3]) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return (board[i][0] == 'X') ? 1 : 2;
    }

    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return (board[0][i] == 'X') ? 1 : 2;
    }

    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return (board[1][1] == 'X') ? 1 : 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return -1;
        }
    }
    return 0;
}

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char response;
    int choice, turn = 0, row, col;

    while (true) {
        cout << "#########-JOGO DA VELHA-#########\n\n";
        cout << "|MENU|\n";
        cout << "\n1 - Jogar   2 - Como Jogar   3 - Creditos   4 - Sair\n";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    turn = 0;
                    
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            board[i][j] = ' ';
                        }
                    }
                    do {
                        displayBoard(board);
                        turn = (turn % 2 == 0) ? 1 : 2;
                        cout << "Jogador " << turn << endl;
                        cout << "Digite a linha: ";
                        cin >> row;
                        cout << "Digite a coluna: ";
                        cin >> col;

                        if (row < 1 || col < 1 || row > 3 || col > 3 || board[row - 1][col - 1] != ' ') {
                            cout << "JOGADA INVALIDA!\n";
                            system("pause");
                        } else {
                            board[row - 1][col - 1] = (turn == 1) ? 'X' : 'O';
                            turn++;
                        }

                    } while (checkGameOver(board) == -1);

                    displayBoard(board);
                    int result = checkGameOver(board);
                    if (result == 0) {
                        cout << "VELHA!!!\nJogo Empatado\n";
                    } else {
                        cout << "JOGADOR " << result << " VENCEU!!!!\n";
                    }

                    cout << "Deseja jogar novamente? [S-N]\n";
                    cin >> response;
                } while (response == 's' || response == 'S');
                break;

            case 2:
                system("cls");
                cout << "#########--COMO JOGAR--#########\n";
                cout << "\nO jogador deve escolher uma linha(1 a 3) e uma coluna(1 a 3) para marcar a opcao em uma lacuna que esteja vazia.\nO jogo acaba quando um jogador conseguir completar tres lacunas sequencialmente\n\n";
                break;

            case 3:
                system("cls");
                cout << "\nSeminario de Linguagens de Programacao\n";
                cout << "\nC++ - Jogo da Velha\n";
                break;

            case 4:
                cout << "Obrigado por jogar! :)\n\n";
                exit(0);
                break;

            default:
                cout << "Opcao invalida!\n";
                cout << "Escolha somente as opcoes (1-4)\n";
                break;
        }
    }
    return 0;
}