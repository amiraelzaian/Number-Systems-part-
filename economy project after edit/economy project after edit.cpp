#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    cout << "\n\n====================================================\n";
    cout << "*~*~*~*~*~*~*~*~ ECONOMIC PROJECT ~*~*~*~*~*~*~*~*~*\n";
    cout << "====================================================\n";

    cout << "    Hello, Enter the number of projects, please ^_^" << endl;
    int rows;
    cin >> rows;
    vector<vector<int>> project(rows, vector<int>(3));

    cout << " ^_^ To make The app work well, Remember that:  ^_^" << endl;
    cout << " -1- The Boom values must be bigger than normal values and Recession values ^_^." << endl;
    cout << " -2- The Normal values must be bigger than recission values  ^_^. \n" << endl;
    cout << "==============================================================================\n";
    cout << " Enter the alternatives of each project in sequence : *Recession, *Normal, *Boom\n";
    cout << "==============================================================================\n";
    // enter elements
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> project[i][j];
        }
    }
    // variable equal the first element in the first,second and the third column 
    int maxBom = project[0][2];
    int maxNormal = project[0][1];
    int maxRecession = project[0][0];

    /* the maximax way.*/
    // we will compare the first element with its column
    // from this part we knew the maximum value from each row.
    for (int i = 1; i < rows; i++)
    {
        if (maxBom < project[i][2])
        {
            maxBom = project[i][2];
        }
        if (maxRecession < project[i][0])
        {
            maxRecession = project[i][0];
        }
        if (maxNormal < project[i][1])
        {
            maxNormal = project[i][1];
        }
    }
    /* the average*/
    // avrage array contain the max vlaue of each row
    vector <int > avge_arr;
    int sum_row = 0;
    for (int i = 0;i < rows;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            sum_row += project[i][j];
        }
        avge_arr.push_back(sum_row);
    }
    int MaxAvge = avge_arr[0];
    // we export the max value of the avge array 
    for (int i = 1;i < rows;i++)
    {
        if (MaxAvge < avge_arr[i])
        {
            MaxAvge = avge_arr[i];
        }
    }
    int intAvge = MaxAvge / rows;
    int modAvge = MaxAvge % rows;

    /* regret */
    // this is the regret table
     // we will subtract and put the end values int the regret table.
     // declare the regret table.
    vector<vector<int>> Regret_arr(rows, vector<int>(3));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                Regret_arr[i][j] = maxRecession - project[i][0];
            }
            if (j == 1)
            {
                Regret_arr[i][j] = maxNormal - project[i][1];
            }
            if (j == 2)
            {
                Regret_arr[i][j] = maxBom - project[i][2];
            }
        }
    }

    // we will access to each row of the regret array and take the maximum value of each project
    // and put it in array its column is equal to num of projects 
    // this array contain the max value of each column!!
    vector<int> max_regret_arr;
    for (int i = 0; i < rows; i++)
    {
        int maxelement = Regret_arr[i][0];
        for (int j = 1; j < 3; j++)
        {
            if (maxelement < Regret_arr[i][j])
            {
                maxelement = Regret_arr[i][j];
            }
        }
        max_regret_arr.push_back(maxelement);
    }
    // variable we compare with the end array to know the min value 
    int min_reg_value = max_regret_arr[0];
    // we use this variable to know num of regret project !
    int numOFproject = 0;
    for (int i = 1; i < rows; i++)
    {
        if (min_reg_value > max_regret_arr[i])
        {
            min_reg_value = max_regret_arr[i];
            numOFproject = i;
        }
    }

    // printing 

    cout << " \n ** Enter a number to choose the way to calculate the economy." << endl;
    cout << " ** The app will give you a recommendation to invest !!!\n" << endl;
    cout << "\n\n";
    cout << " ===> 1- MaxiMax way.\n ===> 2- MaxiMin way.\n ===> 3- Equally Likely Criterion (the average) way.\n ===> 4- The regret (MinMax)." << endl;
    int choice;
    cin >> choice;


    if (choice == 1) {
        cout << " - The decision with MaxiMax : " << maxBom << endl;
        cout << " - The best project to invest is project number : " << numOFproject << endl;
        cout << "---> as it has The max revenue ." << endl;

    }
    else if (choice == 2)
    {
        cout << " - The decision with MaxiMin : " << maxRecession << endl;
        cout << " - The best project to invest is project number : " << numOFproject << endl;
        cout << "---> as it has The max revenue ." << endl;
    }
    else if (choice == 3)
    {
        cout << " - The decision with Equally Likely Criterion is : " << intAvge << "." << modAvge << endl;
        cout << " - The best project to invest is project number : " << numOFproject << endl;
        cout << "---> as it has The max revenue ." << endl;
    }
    else if (choice == 4)
    {
        cout << " - The Min Regret is from project " << numOFproject << " and equal : " << min_reg_value << endl;
        cout << " - The best project to invest is project number : " << numOFproject << endl;
        cout << " --> as it has The lowest regret ." << endl;
    }
    else
    {
        cout << " - Invalid choice, Please run the app again, remember to enter from choices ^_^ " << endl;
    }

    return 0;
}