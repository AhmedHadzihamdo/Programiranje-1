/*
  napi�ite program, u kojem �ete omogu�iti unos dva prirodna broja 
  manja od 500 koji predstavljaju granice intervala, te prona�i i 
  ispisati kojom znamenkom zavr�ava najve�i prosti broj u zadanom 
  intervalu ne uklju�uju�i grani�ne vrijednosti.
*/

#include <iostream>

using namespace std;

bool prost(int broj)
{
    for(int i = 2; i < broj; i++)
        if(broj % i == 0)
            return false;
            
    return true;
}

int main()
{
    int a, b;
        
    do
    {
        cout << "Unesite dva prirodna broja: ";
        cin >> a >> b;
        
    }while(a <= 0 || b <= 0 || a > 500 || b > 500);
    
    
    if(a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    
    
    for(int i = a - 1; i > b; i--)
    {
        if(prost(i))
        {
            cout << "Najveci prosti broj zavrsava cifrom " << i % 10 << endl;
            break;
        }
    }
            
    
    return 0;
}