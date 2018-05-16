/*
  Napisati funkciju koja kao parametar prima re�enicu (niz od najvi�e 200 karaktera) 
  i iz nje uklanja svaku rije� koja po�inje malim ili velikim slovom �s� (S i s). 
  Pored toga, funkcija treba da prebroji ukupan broj rije�i u re�enici prije izmjene. 
  Koristiti sljede�i prototip funkcije: int ukloniRijeci(char []).
  Npr. ako je data re�enica:
	"Stari most u Mostaru spaja obale rijeke Neretve."
  funkcija je treba pretvoriti u:
	"most u spaja obale rijeke"
  Funkcija vra�a broj rije�i u polaznoj re�enici (prije odsijecanja ostalih rije�i). 
  
  Radi jednostavnosti rje�enja, pretpostavite da je rije� bilo koji niz znakova razdvojen znakom razmak. 
*/

#include <iostream>

using namespace std;

int duzinaRecenice(char recenica[])
{
    int brojac = 0;
    while(recenica[brojac] != '\0')
        brojac++;
        
    return brojac;
}

int ukloniRijeci(char recenica[])
{
    int duzina = duzinaRecenice(recenica);
    
    int brRijeci = 0;
    for(int i = 0; i < duzina; i++)
    {
        while(recenica[i] != ' ')
            i++;
        
        brRijeci++;
        
        while(recenica[i] == ' ')
            i++;
    }
    
    for(int i = 0; i < duzina; i++)
    {
        if((recenica[i] == 'S' || recenica[i] == 's') && (recenica[i - 1] == ' ' || i == 0))
        {
            int j, k;
            j = k = i;
            while(recenica[j] != ' ' && j < duzina)
                j++;
            while(recenica[j] == ' ')
                j++;
                
            
                
            while(recenica[k] != '\0')
                recenica[k++] = recenica[j++];
            
            duzina = duzina - j + k;
        }
    }
    
    return brRijeci;
    
}


int main()
{
    char recenica[200] = {"Stari most u Mostaru spaja obale rijeke Neretve."};
    
    cout << "Recenica ima " << ukloniRijeci(recenica) << " rijeci" << endl;
    
    int i = 0;
    while(recenica[i] != '\0')
        cout << recenica[i++];
    return 0;
}