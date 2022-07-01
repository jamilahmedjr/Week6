#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

//all variable
const int column = 5,
rows = 10;
const string FileName = "BowlingScores.txt";
string name[rows];
int number[rows][column];
double average[rows];

//function
void getBowlingData(string name[], int number[][column]) {
    //txt file
    ifstream fs;
    fs.open(FileName);
    if (!fs) {
        cout << "No file found" << endl;
    }
    else
    {
        int i = 0;
        //while
        while (i < rows)
        {
            fs >> name[i];
            for (int n = 0; n < column; n++) {
                fs >> number[i][n];
            }
            i++;
        }
    }
}
//function
void GetAverageScore(int number[][column], double average[]) {
    // score average
    int i = 0;
    while (i < rows) {
        double sum = 0;
        for (int n = 0; n < column; n++) {
            sum += number[i][n];
        }
        average[i] = sum / column;
        i++;
    }
}

//function
void PrettyPrintResults(string name[], int number[][column], double average[]) {

    int i = 0;
    while (i < rows)
    {
        cout << name[i] << setw(5) << "\t";
        for (int n = 0; n < column; n++) {
            cout << number[i][n] << "\t";
        }
        cout << average[i] << endl;
        i++;
    }
}
//function
void welcome() {
    //title
    cout << "*********************************************************" << endl;
    cout << "***Welcome to bowling league's average bowling scores****" << endl;
    cout << "*********************************************************" << endl;
}
//main
int main() {
    // function out

    welcome();
    getBowlingData(name, number);
    GetAverageScore(number, average);
    PrettyPrintResults(name, number, average);

    system("pause");
    return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
