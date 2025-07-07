#include<iostream>
#include<string>
using namespace std;

// Variables for Tic-Tac-Toe
char space[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int row, column;
char token = 'x';
bool draw = false;
string n1, n2;

// =============== QUIZ GAME ===============
void playQuiz() {
int score = 0;
char answer;
cout << "Welcome to the Quiz!\n\n";

cout << "1. Which gas is most abundant in the Earth's atmosphere?\n";
cout << "A. Oxygen\nB. Carbon dioxide\nC. Nitrogen\nD. Hydrogen\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'C') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n2. What is the output of the following Python code?\nprint(2 * 3 * 2)\n";
cout << "A. 64\nB. 12\nC. 16\nD. 256\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'B') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n3. What part of the cell contains genetic material?\n";
cout << "A. Mitochondria\nB. Ribosome\nC. Nucleus\nD. Golgi apparatus\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'C') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n4. In HTML, which tag is used to insert a line break?\n";
cout << "A. <lb>\nB. <br>\nC. <linebreak>\nD. <break>\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'B') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n5. What is the chemical symbol for Potassium?\n";
cout << "A. Po\nB. P\nC. K\nD. Pt\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'C') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n6. Which data structure uses LIFO (Last In, First Out) principle?\n";
cout << "A. Queue\nB. Stack\nC. Linklist\nD. Array\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'B') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n7. Which planet has the most moons?\n";
cout << "A. Earth\nB. Mars\nC. Jupiter\nD. Saturn\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'D') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n8. What does HTTP stand for?\n";
cout << "A. HyperText Transfer Protocol\nB. Hyper Tool Transfer Protocol\nC. High Text Transfer Process\nD. High Tech Transfer Platform\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'A') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n9. What is Newton's Third Law of Motion?\n";
cout << "A. An object in motion stays in motion\nB. Force equals mass times acceleration\nC. Every action has an equal and opposite reaction\nD. Energy can neither be created nor destroyed\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'C') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\n10. In Python, what is the correct way to define a function?\n";
cout << "A. function myFunc():\nB. def myFunc:\nC. define myFunc():\nD. def myFunc():\n";
cout << "Enter your answer (A/B/C/D): ";
cin >> answer;
if (toupper(answer) == 'D') {
cout << "Right answer!\n"; score++;
} else { cout << "Wrong answer!\n"; }

cout << "\nYour final score is: " << score << "/10\n";
}

// =============== TIC TAC TOE GAME ===============

void drawBoard() {
cout << "\n";
cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << endl;
cout << "---|---|---" << endl;
cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << endl;
cout << "---|---|---" << endl;
cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << endl;
cout << "\n";
}

void playerTurn() {
int digit;
if (token == 'x') {
cout << n1 << ", please enter your move (1-9): ";
} else {
cout << n2 << ", please enter your move (1-9): ";
}
cin >> digit;

if (digit == 1) { row = 0; column = 0; }
else if (digit == 2) { row = 0; column = 1; }
else if (digit == 3) { row = 0; column = 2; }
else if (digit == 4) { row = 1; column = 0; }
else if (digit == 5) { row = 1; column = 1; }
else if (digit == 6) { row = 1; column = 2; }
else if (digit == 7) { row = 2; column = 0; }
else if (digit == 8) { row = 2; column = 1; }
else if (digit == 9) { row = 2; column = 2; }
else {
cout << "Invalid input! Try again.\n";
playerTurn();
return;
}

if (space[row][column] != 'x' && space[row][column] != '0') {
space[row][column] = token;
token = (token == 'x') ? '0' : 'x';
} else {
cout << "Cell already taken! Try again.\n";
playerTurn();
}
}

bool checkWin() {
for (int i = 0; i < 3; i++) {
if ((space[i][0] == space[i][1] && space[i][1] == space[i][2]) ||
(space[0][i] == space[1][i] && space[1][i] == space[2][i])) {
return true;
}
}
if ((space[0][0] == space[1][1] && space[1][1] == space[2][2]) ||
(space[0][2] == space[1][1] && space[1][1] == space[2][0])) {
return true;
}
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
if (space[i][j] != 'x' && space[i][j] != '0') {
return false;
}
}
}
draw = true;
return true;
}

void playTicTacToe() {
cout << "Enter the name of Player 1: ";
cin.ignore();
getline(cin, n1);

cout << "Enter the name of Player 2: ";
getline(cin, n2);

cout << n1 << " will play first (X)\n";
cout << n2 << " will play second (O)\n";

draw = false;
token = 'x';

while (!checkWin()) {
drawBoard();
playerTurn();
}
drawBoard();

if (draw) {
cout << "Game Draw!\n";
} else {
if (token == '0') {
cout << n1 << " wins!!\n";
} else {
cout << n2 << " wins!!\n";
}
}
}

// =============== MAIN MENU ===============
int main() {
int choice;
cout << "Choose a Game to Play:\n";
cout << "1. Quiz Game\n";
cout << "2. Tic-Tac-Toe Game\n";
cout << "Enter your choice (1/2): ";
cin >> choice;

switch(choice) {
case 1:
playQuiz();
break;
case 2:
playTicTacToe();
break;
default:
cout << "Invalid choice. Exiting...\n";
}

return 0;
}

