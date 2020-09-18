#include <stdio.h>
#include <iostream>


using namespace std;
int main()
{

    int *oArr;
    int *nArr;

    int n;
    cout << "what size arr do you want to make ";
    cin >> n;

    oArr = new int[n];

    for (int i = 0; i < n; i++)
    {
        oArr[i] = i + 1;
    }

    //display arrays contents

    for (int i = 0; i < n; i++)
    {
        cout << oArr[i] << endl;
    }

    int p;
    cout << "what size now?: ";
    cin >> p;

    nArr = new int[p];

    for(int i = 0; i < n; i++)
    {
        nArr[i] = oArr[i];
        //cout << "adding" << i + 1 << endl;
    }

    delete []oArr;

    oArr = nArr;

    oArr[6] = 100;

    nArr = NULL;

    for (int i = 0; i < p; i++)
    {
        cout << oArr[i] << endl;
    }



    return 0;
}