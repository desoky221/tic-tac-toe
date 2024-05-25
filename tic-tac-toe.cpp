#include <iostream>
#include <ctime>
using namespace std;

int r =0,c=0,count,player_turn;
int input;
char x_o_turn;
//this is the array when it is print it shows the squares number and board shape
char board[5][5] = {{'1', '|', '2', '|', '3'},
                    {'_', '_', '_', '_', '_'},
                    {'4', '|', '5', '|', '6'},
                    {'_', '_', '_', '_', '_'},
                    {'7', '|', '8', '|', '9'}
};
//this function print array board
void print_board (){
    for (int row = 0; row < 5; row++) {

        for (int column = 0; column < 5; column++) {
            cout << board[row][column] << " ";
        }
        cout << endl;
    }
}

void r_c(int input,int *c,int *r){
    if (input == 1 || input == 4 || input == 7) {
        *c = 0;
    } else if (input == 2 || input == 5 || input == 8) {
        *c = 2;
    } else if (input == 3 || input == 6 || input == 9) {
        *c = 4;
    }
    if (input == 1 || input == 2 || input == 3) {
        *r = 0;
    } else if (input == 4 || input == 5 || input == 6) {
        *r = 2;
    } else if (input == 7 || input == 8 || input == 9) {
        *r = 4;
    }
}


int checkwin ()
{     // those are the winning conditions
    if (board [0][0]==board[0][2]&&board[0][2]==board[0][4]){
        return 1;
    }
    else if (board [2][0]==board[2][2]&&board[2][2]==board[2][4]){
        return 1;
    }
    else if (board [4][0]==board[4][2]&&board[4][2]==board[4][4]){
        return 1;
    }
    else if (board [0][0]==board[2][0]&&board[2][0]==board[4][0]){
        return 1;
    }
    else if (board [0][2]==board[2][2]&&board[2][2]==board[4][2]){
        return 1;
    }
    else if (board [0][4]==board[2][4]&&board[2][4]==board[4][4]){
        return 1;
    }
    else if (board [0][0]==board[2][2]&&board[2][2]==board[4][4]){
        return 1;
    }
    else if (board [0][4]==board[2][2]&&board[2][2]==board[4][0]){
        return 1;
    }// this is the drawing condition
    else if (board[0][0]!='1'&&board[0][2]!='2'&&board[0][4]!='3'
             &&board[2][0]!='4'&&board[2][2]!='5'&&board[2][4]!='6'&&
             board [4][0]!='7'&&board[4][2]!='8'&&board[4][4]!='9'){
        return 0;
    }
    else
    {
        return -1;
    }
}
void compvshuman() {
    bool lop=true;

    board[r][c]='X';
    cout<<endl;
    print_board();
    //calling checkwin function to check for wins or draw
    if (checkwin() == 1) {
        cout << "==============\nyou won the game!!\n==============";
        count =10;
    } else if (checkwin() == 0) {
        cout << "==============\nits a draw\n==============";
        count =10;
    }else {

        while (lop) {
            srand(time(0));
            int randomnumber = 1 + rand() % 9;
            input = randomnumber;
            r_c(input, &c, &r);
            if (board[r][c] == 'X' || board[r][c] == 'O') {
                lop = true;
            } else {
                board[r][c] = 'O';
                cout<<"==========================="<<endl;
                print_board();
                lop = false;
            }
            if (checkwin() == 1) {
                cout << "==============\nyou lost!!\n==============";
                lop = false;
                count = 10;
            } else if (checkwin() == 0) {
                cout << "==============\nits a draw\n==============";
                lop = false;
                count = 10;
            }
        }
    }
}



void humanvshuman() {
    if (count %2==0){
        x_o_turn = 'X';
    }
    else{
        x_o_turn='O';
    }

    board[r][c]=x_o_turn;
    print_board();
    //calling checkwin function to check for wins or draw
    if (checkwin() == 1) {
        cout << "==============\nplayer "<<x_o_turn<<" has won!!\n==============";
        count =10;
    } else if (checkwin() == 0) {
        cout << "==============\nits a draw\n==============";
        count =10;
    }
}

int main () {
    cout<<"choose 1 to play against the computer\n2 to play with a friend:";
    int choice;
    cin>>choice;
    cout << "player 1 is 'x'\nplayer 2 is 'o'";
    cout << "\n---------------------------------\n";
    cout << "choose one of the numbered squares from 1-9:\n";

    print_board();
    //game main loop

    for (count = 0; count < 9; count++) {

        cout << "\nenter a number\n";
        cin >> input;
        //taking input x and output the square right index in the array
        r_c(input,&c,&r);

        if (board[r][c] == 'X' ||board[r][c] == 'O') {
            cout << "=>you cant enter a square number\nthat is already entered.\n";
            count -=1;
        }
        else {if (choice==1){
                compvshuman();}
            else if (choice==2){
                humanvshuman();
            }
            else {
                cout<<"invalid";
                count=10;
            }
        }
    }
    return 0;
}