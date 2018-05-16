/*
  Po�tuju�i sve faze procesa programiranja napraviti program koji pronalazi i ispisuje 
  sve slo�ene brojeve brojeve iz intervala m-n (10 < m < 100, 500 < n < 2000, m < n; 
  ukoliko unesene vrijednosti nisu ispravne, u�itavanje treba ponavljati), te pronalazi 
  i ispisuje njihovu aritmeti�ku sredinu. Napraviti sljede�e funkcije:
  - bool slozeni � koja �e ispitivati da li je broj slo�eni i
  - ispis � koja koja �e ispisivati sve slo�ene brojeve i vratiti main funkciji njihovu 
    aritmeti�ku sredinu.
    
  U glavnom programu je potrebno ispisati aritmeti�ku sredinu. 
  
  Slo�eni broj je svaki broj koji nije prosti, odnosno koji ima bar jednog djelioca osim 
  broja 1 i samog sebe.
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

double ispis(int m, int n)
{
    int brojac = 0;
    int suma = 0;
    for(int i = m; i <= n; i++)
    {
        if(prost(i))
        {
            cout << i << endl;
            suma += i;
            brojac++;
        }
    }
    
    return double(suma) / brojac;
}

int main()
{
    int m, n;
    do
    {
        cout << "Unesite m i n: ";
        cin >> m >> n;
    }while(m < 10 || m > 100 || n < 500 || n > 2000);
    
    cout << "Aritmeticka sredina prostih brojeva od " << m << " do " << n
        << " je " << ispis(m, n) << endl;
        
    return 0;
}