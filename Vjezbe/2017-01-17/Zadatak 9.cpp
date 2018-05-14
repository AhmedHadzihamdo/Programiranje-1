/*
  Uz pomo� matrice realnih brojeva dimenzija 5x7 izraditi program za evidenciju i kalkulaciju uspje�nosti vremenskih prognoza (prosje�nih dnevnih temperatura) odre�enog grada. Redovi matrice predstavljaju meteorologe �ije se prognoze unose, dok se kolone odnose na vremenski period od 7 dana. Uz matricu je neophodno krerati globalni jednodimenzionalni niz od 7 elemenata koji �e �uvati stvarna mjerenja temperatura za isti vremenski period, a na osnovu kojeg �e se procijeniti uspje�nost prognoza pojedinih meteorologa. Vrijednosti elemenata ovog niza prilikom deklaracije postaviti na: 25.5, 26.8, 21, 32, 35.6, 36, 33.5.
Implementaciju programa uraditi pomo�u sljede�ih funkcija:
�	UnesiPrognoze � funkcija za unos prognoza odre�enog meteorologa za kompletan period od 7 dana. Vrijednosti prosje�nih temperatura moraju biti unutar intervala [-20, 50] �C. (Pojasnjenje: unose se podaci za samo jedan izabrani red. Tako ce se korisniku omoguciti da unese prognoze za jednog po jednog meteorologa.)
�	IzracunajUspjesnost � funkciju koja vra�a procentualnu vrijednost uspje�nosti prognoza za �eljenog meteorologa. Prognoza, odnosno prosje�na temperatura na odre�eni dan, smatra se uspje�nom ako od stvarnog mjerenja ne odstupa vi�e od 5 �C. (Pojasnjenje: poredi se podaci iz jednog reda odnosno za jednog meteorologa sa podacima iz posebnog niza koji sadr�i stvarne vrijednosti mjerenja, te ako je razlika manja od +/-5 taj podatak se smatra uspjesnom prognozom. Na kraju treba podjeliti broj uspjesnih prognoza sa 7 koliko ima dana u sedmici i vratiti procenat uspjesnosti.)
�	PronadjiNajuspjesnijegMeteorologa � funkciju koja pronalazi meteorologa sa najta�nijim vremenskim prognozama, odnosno najve�im procentom uspjeha. (Pojasnjenje: Red koji ima najveci procenat koji se dobije iz prethodno opisane funkcije IzracunajUspjesnost je u stvari red sa najuspjesnijim meteorologom.)  
�	PronadjiDanSaNajnizimPrognozama � funkciju koja pronalazi dan koji je imao u prosjeku najnize prognoze. (Pojasnjenje: Naci kolonu sa najnizom aritmetickom sredinom svih svojih vrijednosti. Nije potrebno porediti sa nizom sa stvarnim temperaturama.)
Napisati i kratak testni program za provjeru ispravnosti implementiranih funkcija.
*/

#include <iostream>
#include <cmath>

using namespace std;

const int meteorolog = 5;
const int dan = 7;

double temperature[dan] = {25.5, 26.8, 21, 32, 35.6, 36, 33.5};

void unesiPrognoze(double niz[][dan]);
double najnizePrognoze(double niz[][dan]);
double uspjesnostMjerenja(double niz[][dan], int m);
int najuspjesnijiMeteorolog(double niz[][dan]);

int main()
{
    double mjerenja[meteorolog][dan];
    int m;
    
    unesiPrognoze(mjerenja);
    cout << "Najniza prognoza je za " << najnizePrognoze(mjerenja) << ". dan" << endl;
    
    do
    {
        cout << "Izaberite meteorologa" << endl;
        cin >> m;
        
    }while(m < 1 || m > 5);
    
    cout << "Uspjesnost meteorologa broj" << m << " je " << uspjesnostMjerenja(mjerenja, m-1) * 100 << "%" << endl;
    cout << "Najuspjeniji meteorolog je meteorolog broj " << najuspjesnijiMeteorolog(mjerenja) + 1 << " sa % tacnosti od " 
        << uspjesnostMjerenja(mjerenja, najuspjesnijiMeteorolog(mjerenja)) * 100 << "%" << endl;
        
        
    
}

int najuspjesnijiMeteorolog(double niz[][dan])
{
    double uspjesnost[meteorolog];
    int max;
    
    for(int i = 0; i < meteorolog; i++)
    	uspjesnost[i] = uspjesnostMjerenja(niz, i);
    
    max = 0;
    for(int i = 1; i < meteorolog; i++)
    	if(uspjesnost[i] > uspjesnost[max])
            max = i;	
    
    return max;
}

double uspjesnostMjerenja(double niz[][dan], int m)
{
    double suma = 0;
    
    for(int i = 0; i < dan; i++)
    	if(abs(niz[m][i]-temperature[i]) < 5)
            suma++;
    
    return suma / 7;    
}

double najnizePrognoze(double niz[][dan])
{
    double prosjek[dan] = {};
    int min;
    
    for(int i = 0; i < dan; i++)
    {
        for(int j = 0; j < meteorolog; j++)
        {
            prosjek[i] += niz[j][i];
        }
        prosjek[i] = prosjek[i] / 7;
    }
    
    
        
    min = 0;
    for(int i = 1; i < dan; i++)
    	if(prosjek[i] < prosjek[min])
            min = i;
    
    return min;

}

void unesiPrognoze(double niz[][dan])
{
    for(int i = 0; i < meteorolog; i++)
    {
        cout << "Unesite mjerenja " << i + 1 << ". meteorologa" << endl;
        for(int j = 0; j < dan; j++)
        {
            do
            {
                cin >> niz[i][j];
                
            }while(niz[i][j] < -20 || niz[i][j] > 50);
        }
    }
}