#include <iostream>
using namespace std;
// char choice ; 
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'x';
bool draw = false ;
int row , column ;
void Display_board(){
    system("cls");
    cout<<"\n\n\t**TICK** **CROSS** **GAME**"<<endl;
    cout<<"\t\t\tPlayer1 [x]\n\t\t\tPlayer2 [0]\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  \n";
    cout<<"\t\t     |     |     \n";
}
void Player_turn(){
     char choice ;
    if(turn=='x')
    cout<<"\n\t\tPlayer1 [x] turn: ";
    
    if(turn=='0')
    cout<<"\n\t\tPlayer2 [0] turn: ";
    
    cin>>choice;
    
    switch(choice){
        case '1': row =0; column = 0 ; break;
        case '2': row =0; column = 1 ; break;
        case '3': row =0; column = 2 ; break;
        case '4': row =1; column = 0 ; break;
        case '5': row =1; column = 1 ; break;
        case '6': row =1; column = 2 ; break;
        case '7': row =2; column = 0 ; break;
        case '8': row =2; column = 1 ; break;
        case '9': row =2; column = 2 ; break;
        default :cout<<"invalid choice\n"<<endl;break ;}
    if (turn=='x'&& board[row][column]!='x'&& board[row][column]!='0') {board[row][column]= 'x'; turn = '0';}
    else if (turn=='0'&& board[row][column]!='x'&& board[row][column]!='0') {board[row][column]= '0'; turn = 'x';}
    else{ cout<<"\tbox already filled\n\tplease try again";Player_turn();}
    Display_board(); }
    bool game_over(){
        for(int i=0 ; i<3 ; i++)
        if (board[i][0]==board[i][1] && board[i][0] == board[i][2] || board[0][i]==board[1][i] && board[0][i] == board[2][i] )
        return false;
         if (board[0][0]==board[1][1] && board[0][0] == board[2][2] || board[2][0]==board[1][1] && board[1][1] == board[0][2] )
        return false;
        for(int i=0 ; i<3 ; i++)
        for(int j=0 ; j<3 ; j++)
        if( board[i][j] != 'x' && board[i][j] != '0')
        return true;
        draw = true ;
        return false ;
    }
int main() {
    while(game_over()){
         Display_board();
        Player_turn();
        game_over();
       }
   if (turn == '0' && draw == false)
   cout<<"\tPlayer1 [x] win!!\n\t**Congratulation**\n";
   else if (turn == 'x' && draw == false)
   cout<<"\tPlayer2 [0] win!!\n\t*Congratulation*\n";
   else cout<<"game draw\n";
    
    
    
    

    return 0;
}