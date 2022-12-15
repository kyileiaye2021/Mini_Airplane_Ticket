#include <iostream>
const int MAXROW = 7;
const int MAXCOL = 4;

char arrayOfTicket[MAXROW][MAXCOL];

//declaring functions
void introduction(char a[][MAXCOL], int maxRow);
void takeInput(char a[][MAXCOL], int maxRow);
void column(int seatCol, int& num);
void compute(char a[][MAXCOL], int maxRow, int seatRow, int seatCol);
void output(char a[][MAXCOL], int maxRow);

int main(){
    using namespace std;
    
    introduction(arrayOfTicket, MAXROW);
   
    return 0;
}
/**
 * @brief Display available seats before letting the user choose
 * Make an char type array of size 4 (array[]) to put character values into dimensional array of char type(a[][MAXCOL]) with nested for loop
 * Occupied seats are defaultly placed and displayed after the loop
 * @param a - arrayOfTicket
 * @param maxRow - size of 1st dimensional array
 * @param answer - a variable asking the user to repeat the program
 */
void introduction(char a[][MAXCOL], int maxRow){
    using namespace std;
    char array[] = {'A', 'B', 'C','D'};
    int i, j;
    
    for(i = 0; i < MAXROW; i++){
        cout << i + 1 << " ";
        for(j = 0; j < MAXCOL; j++){
            if((i == 0) && (array[j] == 'A') || ((i == 1) && (array[j] == 'B')) || ((i == 3) && (array[j] == 'C'))){ 
                a[i][j] = 'X';
            }
            else{
                a[i][j] = array[j];
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    takeInput(a, MAXROW);

}
/**
 * @brief taking input(seat row and column) from user
 * if the seat is occupied, make user to choose another seat
 * @param a - arrayOfTicket
 * @param maxRow - maximum rows of the seat(size of the first dimensional array)
 */
void takeInput(char a[][MAXCOL], int maxRow){
    using namespace std;
    int rows, number;
    char columns, ans;
   
    cout << "Enter seat number you want to register for: ";
    cin >> rows >> columns;
    column(columns, number);

    //Taking user input value if the user take the occupied seats
    while(a[rows - 1][number] == 'X'){
        cout << "Sorry.This place is already occupied.\nPlease select another seat: ";
        cin >> rows >> columns;
        column(columns, number);
    }

    compute(a, maxRow, rows, number);
    output(a, MAXROW);
    //Using recursion to repeat the function and take the input again
    cout << "Do you want to reserve seat for another passenger? Enter (Y)es or (N)o: ";
    cin >> ans;
    if(ans == 'Y' || ans == 'y'){
        takeInput(a, maxRow);
    }
    else{
        cout << "Thank you for using our service!";
    }

}
/**
 * @brief Put the array indexs corresponding to the character value of user input
 * Reference the variable num to update the number corresponding to the user input value every time while loop in takeInput() function is iterated 
 * @param seatCol - the initial input value for seat column from the user
 * @param num - seat column number (index of the second dimensional array)
 */
void column(int seatCol, int& num){

    switch(seatCol){
        case 'A':
        case 'a':
            num = 0;
            break;
        case 'B':
        case 'b':
            num = 1;
            break;
        case 'C':
        case 'c':
            num = 2;
            break;
        case 'D':
        case 'd':
            num = 3;
            break;
    }
}
/**
 * @brief mark 'X' in the seat row and column after the user put the right value
 * @param a - arrayOfTicket
 * @param maxRow - size of first dimensional array (max size of seat rows which is 7)
 * @param seatRow - the row number the user choose
 * @param seatCol - the column number the user choose
 */
void compute(char a[][MAXCOL], int maxRow, int seatRow, int seatCol){
    using namespace std;

    int i, j;
    for(i = 0; i < maxRow; i++){
        for(j = 0; j < MAXCOL; j++){
            if((i+1) == seatRow && j == seatCol){
                a[i][j] = 'X';
            }
        }
    }
}
/**
 * @brief output the occupied places including the user's seat
 * @param a - arrayOfTicket
 * @param maxRow - size of 1st dimensional array which is 7
 */
void output(char a[][MAXCOL], int maxRow){
    using namespace std;
    int i, j;
    for(i = 0; i < maxRow; i++){
        cout << i + 1 << " ";
        for(j = 0; j < MAXCOL; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

