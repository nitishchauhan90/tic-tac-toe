#include<bits/stdc++.h>
using namespace std;
void formationofBoard(vector<vector<char> >&board){
    cout << "   1   2   3"<<endl;
    for(int i=0;i<3;i++){
        cout<<i+1<<" ";
        for(int j=0;j<3;j++){
            cout<<" "<<board[i][j]<<" ";
            if(j<2){
                cout<<"|";
            }
        
        }
        cout<<endl;
        if(i<2){
            cout<<"  ---+---+---"<<endl;
        }
    }
}
bool checkwin(char currentplayer,vector<vector<char> >&board){
    if(board[0][0]==currentplayer&&board[1][1]==currentplayer&&board[2][2]==currentplayer){
        return true;
    }
    if(board[0][2]==currentplayer&&board[1][1]==currentplayer&&board[2][0]==currentplayer){
        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        if(board[i][0]==currentplayer&&board[i][1]==currentplayer&&board[1][2]==currentplayer){
            return true;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if(board[0][i]==currentplayer&&board[1][i]==currentplayer&&board[2][i]==currentplayer){
            return true;
        }
    }
}
bool checktie(vector<vector<char> >&board){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
int main(){
    vector<vector<char> >board(3,vector<char>(3,' '));
    char currentplayer='X';
    int row,column;
    while(true){
        formationofBoard(board);
        cout<<"Player "<< currentplayer<<" enter the move(row and column)";
        cin>>row>>column;
        if(row<1||row>3||column<1||column>3||board[row-1][column-1]!=' '){
            cout<< "Invalid move! Try again."<<endl;
            continue;
        }
        board[row-1][column-1]=currentplayer;
        if(checkwin(currentplayer,board)){
            formationofBoard(board);
            cout<<"Player "<<currentplayer<<" win this match"<<endl;
            break;
        }
        currentplayer = (currentplayer=='X') ? 'O' : 'X' ;
        if(checktie(board)){
            formationofBoard(board);
            cout<<"This match is Tie."<<endl;
            cout<<"PLAY AGAIN"<<endl;
            break;
        }
    }   
    return 0;
}