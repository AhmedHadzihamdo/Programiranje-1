/*
  Neka je data matrica dimenzija 11x12 u kojoj svaki red predstavlja fudbalera 
  nekog tima, a svaka kolona utakmicu (fudbalski me�) u toku sezone. Elementi 
  matrice predstavljaju broj postignutih golova po utakmici. Kreirati, a potom 
  u glavnom programu testirati, sljede�e funkcije:
  � Funkciju za unos svih golova za odabranu utakmicu. Omogu�iti poziv funkcije 
    iz main funkcije vi�e puta kako bi se unijeli podaci za sve utakmice. 
  � Funkciju koja za odabranog fudbalera vr�i ispis postignutih golova po utakmicama.
    Ukoliko fudbaler nije postigao niti jedan gol, podatak za tu utakmicu se ne 
    ispisuje. Pored toga, funkcija kao rezultat vra�a prosje�an broj postignutih 
    golova za cijelu sezonu.
  � Funkciju koja pronalazi fudbalera sa najboljim prosjekom postignutih golova
    te ispisuje njegov prosjek u sezoni i vra�a index tog fudbalera.
  � Funkciju koja vra�a najuspje�niju utakmicu u sezoni i ispisuje procenat 
    postignutih golova na toj utakmici (ra�unaju�i svih 11 igra�a i sve postignute golove), 
    ukupan broj golova i index igra�a koji je postigao najvi�e golova na toj utakmici. 
    Primjer ispisa funkcije:
    
    -----------------Utakmica 3-----------------
    Brog golova: 4
    Procenat za tim � broj golova u odnosu na broj igra�a u timu: 36.36% (4/11*100)
    Najuspje�niji igra�: 6.
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void unos(int goloviPoUtakmici[][12])
{
    srand(time(0));
    for(int i = 0; i < 11; i++)
        for(int j = 0; j < 12; j++)
            cin >> goloviPoUtakmici[i][j];
}
                    
double statistikaIgraca(int igrac[], bool ispis = false)
{
    int suma = 0;
    for(int i = 0; i < 12; i++)
    {
        suma += igrac[i];
        if(igrac[i] != 0 && ispis)
            cout  << "Utakmica " << i + 1 << " " << igrac[i] << endl;
    }
    
    return (double)suma / 12;
}


int najboljiUcinak(int goloviPoUtakmici[][12])
{
    int max = 0;
    for(int i = 1; i < 11; i++)
        if(statistikaIgraca(goloviPoUtakmici[max]) < statistikaIgraca(goloviPoUtakmici[i]))
            max = i;
     
    cout << "Najbolji igrac je igrac broj " << max + 1 << " sa " << statistikaIgraca(goloviPoUtakmici[max])
         << " golova po utakmici." << endl;
    return max;
    
}
int najuspjesnijaUtakmica(int goloviPoUtakmici[][12])
{
    int ucinak[12] = {0};
    
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            ucinak[i] += goloviPoUtakmici[j][i];
        }
        
    }
    
    int max = 0;
    for(int i = 1; i < 12; i++)
        if(ucinak[max] / 11 < ucinak[i] / 11)
            max = i;
            
    int maxGolova = 0;
    for(int i = 1; i < 11; i++)
        if(goloviPoUtakmici[maxGolova][max] < goloviPoUtakmici[i][max])
            maxGolova = i;
    
    //Ispis
    cout << endl;
    int k = 0;
    while(k < 17)
    {
        cout << "-";
        k++;
    }
    cout << "Utakmica " << max + 1;
    while(k < 40)
    {
        cout << "-";
        k++;
    }
    cout << endl;
    cout << "Broj golova: " << ucinak[max] << endl;
    cout << "Procenat za tim - broj golova u odnosu na broj igra�a u timu: " << 100 * (ucinak[max] / 11) << "%" << endl;
    cout << "Najuspjesniji igrac: " << goloviPoUtakmici[maxGolova][max] << endl;
    
    
    return max;
    
}

int main()
{
    int goloviPoUtakmici[11][12];
    
    unos(goloviPoUtakmici);
    
    for(int i = 0; i < 11; i++)
    {
        statistikaIgraca(goloviPoUtakmici[i], true);
        cout << endl;
    }
        
    najboljiUcinak(goloviPoUtakmici);
    najuspjesnijaUtakmica(goloviPoUtakmici);
    

    return 0;
}