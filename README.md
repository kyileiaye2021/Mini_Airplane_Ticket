# Mini_Airplane_Ticket
##### Kyi Lei Aye
##### 11/25/2022

### Overview
This program displays the available seats of a mini flight and allow passengers to occupy for their seats.

### Problem Solving Phase
1. First, display the available seats so that the passengers can know which seats are still available to occupy
2. Let the user type the seat number
3. Take user input again if they accidentally type the number that was already occupied
4. Update and display the seat the users have occupied
5. Ask the users again if they want to save seats for another passengers

### Implementation Phase
1. Initialize an array of size 4 and insert elements to dimensional array by using for loop to display the available seats of the mini plane in introduction() function: Some of the places are occupied manually.
2. Take user input and compare it to the indexes and indexed variables of two dimensional array in takeInput() function
3. Take user input again by using While loop if indexed variable of the second dimensional array which is same as seat column of the user input is 'X'
4. Alter the user input of the seat column of character type to integer value that can be equated to the indexes of the second dimensional array to easily compare the indexed variable of the array of char type and the user variable input of char type
5. Change the value of indexed variables of the array that is equal to the row and column that the user occupy to 'X' by comparing in For loop in compute() function
6. Output the updated available seats
7. Use recursion to take input again and update the available seats including the previous user's seat number

### Notes
1. Re-running the whole program by using Do-While loop cannot memorize the previous user's input value and would not update that information in the next time the program is run.
2. Recursion - which means that a function is called in its function definition - can help solving the above problem.

### Reference
**https://www.stechies.com/tic-tac-toe-cpp/**
