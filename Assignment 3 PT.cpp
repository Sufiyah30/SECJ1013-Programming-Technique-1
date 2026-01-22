/*
NOR FATIHAH BINTI OTHMAN (A25CS0296)
NOR AIN FAHIRA BINTI MUHAMAD FARIQ (A25CS0295)
NORSUFIYAH ALIYAH BINTI MD JOHAIMI (A24SC0215)
8 JANUARY 2026
*/



#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Function to display the lines
void displayLine()
{
    for (int i = 0; i < 52; i++)
        cout << "-";
    cout << endl;
}


//Function to find individual winner
int findIndWinner(int totalInd[], int size)
{
    int highest = totalInd[0];
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (totalInd[i] > highest)
        {
            highest = totalInd[i];
            index = i;
        }
    }
    return index;
}

//Function to find team winner
int findTeamWinner(int totalTeam[], int size)
{
    int highest = totalTeam[0];
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (totalTeam[i] > highest)
        {
            highest = totalTeam[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    const int ROWS = 12;
    const int COLS = 7;
    const int TEAMS = 3;

    int marks[ROWS][COLS];
    int totalInd[ROWS] = {0};
    int totalTeam[TEAMS] = {0};


    //to open the input and output file
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

     //to check if the file can be opened
    if (!infile)
    {
        cout << "Sorry, input file does not exist!" << endl;
        return 0;
    }

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            infile >> marks[i][j];

    infile.close();

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 2; j < COLS; j++)
            totalInd[i] += marks[i][j];

        int teamIndex = marks[i][0] - 1;
        totalTeam[teamIndex] += totalInd[i];
    }

    int indWinner = findIndWinner(totalInd, ROWS);
    int teamWinner = findTeamWinner(totalTeam, TEAMS);

    int index = 0;

    displayLine();
    outfile << "----------------------------------------------------" << endl;

    cout << "Id     E1  E2  E3  E4  E5  Total" << endl;
    outfile << "Id     E1  E2  E3  E4  E5  Total" << endl;

    for (int t = 1; t <= TEAMS; t++)
    {

        displayLine();
        outfile << "----------------------------------------------------" << endl;

        cout << "TEAM " << t << endl;
        outfile << "TEAM " << t << endl;

        for (int p = 0; p < 4; p++)
        {
            cout << setw(5) << marks[index][1];
            outfile << setw(5) << marks[index][1];

            for (int j = 2; j < COLS; j++)
            {
                cout << setw(4) << marks[index][j];
                outfile << setw(4) << marks[index][j];
            }

            cout << setw(6) << totalInd[index] << endl;
            outfile << setw(6) << totalInd[index] << endl;

            index++;
        }

        cout << left << setw(29) << "TOTAL" << right << totalTeam[t - 1] << endl;
        outfile << left << setw(29) << "TOTAL" << right << totalTeam[t - 1] << endl;
    
    }

    displayLine();
    outfile << "----------------------------------------------------" << endl;

    cout << "Winner for Individual Category: "
         << marks[indWinner][1]
         << " (Team " << marks[indWinner][0] << ")" << endl;

    outfile << "Winner for Individual Category: "
            << marks[indWinner][1]
            << " (Team " << marks[indWinner][0] << ")" << endl;

    cout << "Winner for Group Category: Team "
         << teamWinner + 1
         << " (Score = " << totalTeam[teamWinner] << ")" << endl;

    outfile << "Winner for Group Category: Team "
            << teamWinner + 1
            << " (Score = " << totalTeam[teamWinner] << ")" << endl;

    outfile.close();

    cout << "Press any key to continue . . ." << endl;

    return 0;
}