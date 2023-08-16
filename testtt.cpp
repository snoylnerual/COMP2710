#include <iostream>
#include <cstdint>
using namespace std;


int main()
{
    //int CITY_AUBURN = 1;
    //int CITY_ATLANTA = 2;
    //int CITY_ATHENS = 3;

    enum Cities
    {
        CITY_AUBURN,
        CITY_ATLANTA,
        CITY_ATHENS
    };

    Cities city;

    //put print around it
    void printCity(Cities city) 
    {
        switch(city)
        {
            case CITY_AUBURN:
                cout << "Auburn";
                break;
            case CITY_ATLANTA:
                cout << "Atlanta";
                break;
            case CITY_ATHENS:
                cout << "Athens";
                break;
            default:
                cout << "Unknown";
                break;
        }
    }


    for (int n=100; n<1000; n+=100)
    {
        cout << "X";
    }
    cout <<"\n\n";
    int n = 100;
    do{
        cout << "X";
        n = n+100;
    
    } while(n < 1000);

    cout << "\n\n";

    int array[5];
    cout << array[5] << "\n\n";
    cout << array[4] << "\n\n";

    int array2[5] = {0};
    cout << array2[4];

    int array3[5] = {0,0};
    cout << array3[4];

    int array4[5] = {0,0,0};
    cout << array4[4];

    int array5[5] = {0,0,0,0,0};
    cout << array5[4];


return 0;
}