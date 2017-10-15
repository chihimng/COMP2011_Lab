//
//  main.cpp
//  COMP2011 Lab 6
//
//  Created by Chihim Ng on 13/10/2017.
//  Copyright © 2017 Chihim Ng. All rights reserved.
//

#include <iostream>
using namespace std;

const int BOARD_SIZE = 9;

bool isGroupValid(int group[9]) {
    bool isValid = true;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (group[j] == i) {
                break;
            } else if (j == 8) {
                isValid = false;
            }
        }
        if (!isValid) {
            break;
        }
    }
    return isValid;
}

bool check_solution(int board[][BOARD_SIZE]){
    bool isGameValid = true;
    // check rows
    for (int i = 0; i < BOARD_SIZE; i++) { // each row
        int group[9] = {};
        for (int j = 0; j < BOARD_SIZE; j++) { // each col
            group[j] = board[i][j];
        }
        if (!isGroupValid(group)) {
            isGameValid = false;
            break;
        }
    }
    if (!isGameValid) {
        return isGameValid;
    }

    // check cols
    for (int i = 0; i < BOARD_SIZE; i++) { // each col
        int group[9] = {};
        for (int j = 0; j < BOARD_SIZE; j++) { // each row
            group[j] = board[j][i];
        }
        if (!isGroupValid(group)) {
            isGameValid = false;
            break;
        }
    }
    if (!isGameValid) {
        return isGameValid;
    }

    // check boxes
    for (int i = 0; i < 3; i++) { // row offset
        for (int j = 0; j < 3; j++) { // col offset
            int group[9] = {};
            int rowOffset = i * 3;
            int colOffset = j * 3;
            for (int i = 0; i < 3; i++) { // each row of box
                for (int j = 0; j < 3; j++) { // each col of box
                    group[j + 3 * i] = board[i + rowOffset][j + colOffset];
                }
            }
            if (!isGroupValid(group)) {
                isGameValid = false;
                break;
            }
        }
        if (!isGameValid) {
            break;
        }
    }
    return isGameValid;
}

bool isGuessLegal(int board[][BOARD_SIZE], int row, int col, int guess) {
    int rowGroup[BOARD_SIZE] = {};
    int colGroup[BOARD_SIZE] = {};
    int boxGroup[BOARD_SIZE] = {};
    int rowOffset = row / 3 * 3;
    int colOffset = col / 3 * 3;
    for (int i = 0; i < BOARD_SIZE; i++) {
        rowGroup[i] = board[row][i];
        colGroup[i] = board[i][col];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boxGroup[j + 3 * i] = board[i + rowOffset][j + colOffset];
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (rowGroup[i] == guess) {
            return false;
        }
        if (colGroup[i] == guess) {
            return false;
        }
        if (boxGroup[i] == guess) {
            return false;
        }
    }
    return true;
}

bool isBoardEmpty(int board[][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int board[][BOARD_SIZE], int i, int j){
    // solved found if board not empty
    if (isBoardEmpty(board)) {
        return true;
    }
    // move to next cell if cell not empty
    if (board[i][j] != 0) {
        return solve(board, i + (j + 1) / BOARD_SIZE, (j + 1) % BOARD_SIZE);
    }
    // iterate guesses
    for (int guess = 1; guess <= BOARD_SIZE; guess++) {
        if (isGuessLegal(board, i, j, guess)) {
            // assign if guess is legal
            board[i][j] = guess;
            // recursion
            if (solve(board, i, j)) {
                return true;
            } else {
                // children have no solution, try next guess
                board[i][j] = 0;
            }
        }
    }
    // all guesses iterated, no solution found
    return false;
}

bool solve_sudoku(int board[][BOARD_SIZE]){
    return solve(board, 0, 0);
}


//fill the int array given a digits string describing the puzzle board
void fill_board(int board[][BOARD_SIZE], const char s[])
{
    int len = BOARD_SIZE * BOARD_SIZE;
    for(int i = 0; i < len; ++i)
        board[i / BOARD_SIZE][i % BOARD_SIZE] = (int)(s[i] - '0');
}

void print_board(int board[][BOARD_SIZE])
{
    cout << "Sudoku board" << endl;

    for(int i = 0; i < BOARD_SIZE; ++i)
    {
        for(int j = 0; j < BOARD_SIZE; ++j)
            cout << (j ? " " : "") << board[i][j];

        cout << endl;
    }
}

void go_task1()
{
    const int n_cases = 10;
    const char sample_boards[n_cases][BOARD_SIZE * BOARD_SIZE + 1] = {
        "143628579572139468986754231391542786468917352725863914237481695619275843854396127",
        "123456789578139624496872153952381467641297835387564291719623548864915372235748916",
        "123456789965718423847329165632871954589634217714295638298567341351942876476183592",
        "123456789549873261867129435615798324432615978978342516296587143784931652351264897",
        "123456789549178263786239415698721534235964871417583926364892157972615348851347692",
        "534678912672196348197342567859761423426853791713924856961537284287419635345286179",
        "323456789965718423847329165632871954589634217714295638298567351351942876476183592",
        "123456789457918362689372545932164857768529431214783926895237614276848593341695278",
        "723456789867912345459738612534187926782694153691325874915273468276849531348561297",
        "123456789698317254457829136386741592579632418641598673964173825735284961812965347"};

    cout << "Please enter the ID of test cases, input -1 to run all of cases" << endl;
    int case_id;
    cin >> case_id;

    int board[BOARD_SIZE][BOARD_SIZE];//array holder for sudoku

    if(case_id == -1)
    { //run all test cases if entering -1
        for(case_id = 0; case_id < n_cases; ++case_id)
        {
            cout << "Running test case " << case_id << " ......" << endl;
            fill_board(board, sample_boards[case_id]);
            print_board(board);

            if(check_solution(board))
                cout << "Valid" << endl;
            else
                cout << "Invalid" << endl;
            cout << endl;
        }
    }
    else if(case_id >= 0 && case_id < n_cases)
    {
        cout << "Running test case " << case_id << " ......" << endl;
        fill_board(board, sample_boards[case_id]);
        print_board(board);

        if(check_solution(board))
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
        cout << endl;
    }
    else
        cout << "Invalid test case ID." << endl;

}

void go_task2()
{
    const int n_cases = 16;
    const char sample_boards[n_cases][BOARD_SIZE * BOARD_SIZE + 1] = {
        "530070000600195000098000060800060003400803001700020006060000280000419005000080079",
        "009748000700000000020109000007000240064010590098000300000803020000000006000275900",
        "001700509573024106800501002700295018009400305652800007465080071000159004908007053",
        "625038970009200005040095302987020030150067009000019587498601053000083640016002090",
        "056090800910805702030607590000002106460951287127008000089126473001009000670040910",
        "260501300700820561305006008401369800053470100800000643174600900900157284002004006",
        "239000405000950007607314209071006502063085074004091600002500840385140926100820000",
        "356970081000600034802501700508420106100060450604150800001897045485006072003040600",
        "062403817010006003038710002040960270087030500106074089800201700050007904274650130",
        "062403817010006003038710002040960270087030500106074089800201700050007904274650130",
        "530070000600196000098000060800060003400803001700020006060000280000419005000080079",
        "923001074100098002700430190304005621097806503060304000475203010610089430000007065",
        "160000079307918256005460000014080023600043005073602901700300814081020307406871000",
        "806503497504280600090400200081760005005090780067035140700901500059300802402650970",
        "030652090592870061070000520000090200814200009920134786000046005149085002056700948",
        "823579000059401720700620500076102008200008007130790452080000200007214835540037010"};

    cout << "Please enter the ID of test cases, input -1 to run all of cases" << endl;
    int case_id;
    cin >> case_id;

    int board[BOARD_SIZE][BOARD_SIZE];//array holder for sudoku

    if(case_id == -1)
    { //run all test cases if entering -1
        for(case_id = 0; case_id < n_cases; ++case_id)
        {
            cout << "Running test case " << case_id << " ......" << endl;
            fill_board(board, sample_boards[case_id]);
            print_board(board);

            if(solve_sudoku (board))
            {
                cout << "Solution found!" << endl;
                print_board(board);
            }
            else
                cout << "No solution exists!" << endl;
            cout << endl;
        }
    }
    else if(case_id >= 0 && case_id < n_cases)
    {
        cout << "Running test case " << case_id << " ......" << endl;
        fill_board(board, sample_boards[case_id]);
        print_board(board);

        if(solve_sudoku (board))
        {
            cout << "Solution found!" << endl;
            print_board(board);
        }
        else
        {
            cout << "No solution exists!" << endl;
        }
        cout << endl;
    }
    else
        cout << "Invalid test case ID." << endl;
}


int main()
{
    cout << "***************************************************" << endl;
    cout << "Sudoku Cracker" << endl;
    cout << "***************************************************" << endl << endl;

    while(true)
    {
        int task_id;

        cout << "Please select task" << endl;
        cout << "1: Sudoku Validator" << endl; //Enter 1 for task 1
        cout << "2: Sudoku Solver" << endl;    //Enter 2 for task 2
        cout << "Enter 0 to exit" << endl;     //Enter 0 to exit

        cin >> task_id;

        if(task_id == 1)
            go_task1();
        else if(task_id == 2)
            go_task2();
        else if(task_id == 0)
            break;
        else
            cout << "Invalid input! Please re-enter the task id." << endl;
    }

    return 0;
}
