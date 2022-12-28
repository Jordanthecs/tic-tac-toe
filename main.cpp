#include<iostream>
using namespace std;

void resetBoard(char[3][3]);
void printBoard(char[3][3]);
int checkFreeSpaces(char[3][3]);
void playerMove(char[3][3],char);
void compMove(char[3][3],char);
char checkWinner(char[3][3],char,char);

int main(){
    char you;
    char comp;
    string ans;

    cout<<"Do you want to play tic tac toe?(yes or no)\n";
    cin>>ans;
    while(ans == "yes"){
        cout<<"Do you want to be X or 0: ";
        cin>>you;
        if(you == 'X'){
            comp = '0';
        }else{
            comp = 'X';
        }
        char position[3][3];
        resetBoard(position);
        while(checkFreeSpaces(position) != 0 && checkWinner(position,you,comp) == 'y'){
            playerMove(position,you);
            checkFreeSpaces(position);
            if(checkFreeSpaces(position) != 0 || checkWinner(position,you,comp) == 'y'){
                compMove(position,comp);
                }
            checkWinner(position,you,comp);
        }

        if(checkWinner(position,you,comp) == you){
            cout<<"YOU WON!!!\n\n";
        }else if(checkWinner(position,you,comp) == comp){
            cout<<"YOU LOST!!!\n\n";
        }else{
            cout<<"It is a tie...\n\n";
        }

        cout<<"Do you want to play again?(yes or no)\n";
        cin>>ans;
    }  
    return 0;
}

void resetBoard(char position[3][3]){
    for(int i = 0; i< 3;i++){
        for(int j = 0; j< 3;j++){
            position[i][j] = ' ';
        }
    }
    printBoard(position);
    
}

void printBoard(char position[3][3]){
    cout<<" "<< position[0][0] <<" | "<<position[0][1]<<" | "<<position[0][2]<<endl;
    cout<<"---"<<"|"<<"---"<<"|"<<"---"<<endl;
    cout<<" "<< position[1][0] <<" | "<<position[1][1]<<" | "<<position[1][2]<<endl;
    cout<<"---"<<"|"<<"---"<<"|"<<"---"<<endl;
    cout<<" "<<position[2][0]<<" | "<<position[2][1]<<" | "<<position[2][2]<<endl;
}

int checkFreeSpaces(char position[3][3]){
    int count = 9;
    for(int i = 0; i< 3;i++){
        for(int j = 0; j< 3;j++){
            if(position[i][j] != ' '){
                count--;
            }
        }
    }
    return count;
}

void playerMove(char position[3][3],char you){
    int row, col;
    cout<<"Row: ";
    cin >>row;
    cout<<"Column: ";
    cin>>col;
    while(row > 2 || col > 2 || position[row][col] != ' '){
        cout<<"Space is either non-existent or already taken chose another: \n";
        cout<<"Row: ";
        cin >>row;
        cout<<"Column: ";
        cin>>col;
    }
    position[row][col] = you; 
    printBoard(position);
    cout<<endl<<endl;
}

void compMove(char position[3][3],char comp){
    int row, col;
    row = rand()%3;
    col = rand()%3;
    while(row > 2 || col > 2 || position[row][col] != ' '){
        row = rand()%3;
        col = rand()%3;
    }
    position[row][col] = comp; 
    printBoard(position);
}

char checkWinner(char position[3][3],char you,char comp){
    if(position[0][0] == you && position[0][1] == you && position[0][2] == you){
        return you;
    }else if(position[1][0] == you && position[1][1] == you && position[1][2] == you){
        return you;
    }else if(position[2][0] == you && position[2][1] == you && position[2][2] == you){
        return you;
    }else if(position[0][0] == you && position[1][0] == you && position[2][0] == you){
        return you;
    }else if(position[0][1] == you && position[1][1] == you && position[2][1] == you){
        return you;
    }else if(position[0][2] == you && position[1][2] == you && position[2][2] == you){
        return you;
    }else if(position[0][0] == you && position[1][1] == you && position[2][2] == you){
        return you;
    }else if(position[0][2] == you && position[1][1] == you && position[2][0] == you){
        return you;
    }else if(position[0][0] == comp && position[0][1] == comp && position[0][2] == comp){
        return comp;
    }else if(position[1][0] == comp && position[1][1] == comp && position[1][2] == comp){
        return comp;
    }else if(position[2][0] == comp && position[2][1] == comp && position[2][2] == comp){
        return comp;
    }else if(position[0][0] == comp && position[1][0] == comp && position[2][0] == comp){
        return comp;
    }else if(position[0][1] == comp && position[1][1] == comp && position[2][1] == comp){
        return comp;
    }else if(position[0][2] == comp && position[1][2] == comp && position[2][2] == comp){
        return comp;
    }else if(position[0][0] == comp && position[1][1] == comp && position[2][2] == comp){
        return comp;
    }else if(position[0][2] == comp && position[1][1] == comp && position[2][0] == comp){
        return comp;
    }else{
        return 'y';
    }
}