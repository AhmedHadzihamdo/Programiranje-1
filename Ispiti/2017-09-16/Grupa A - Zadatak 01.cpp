/*
   Napisati program koji rje�ava sljede�i problem.
   Date su firma A, B i C sa godi�njim prihodima:
   A - prihod 10M eura
   B - prihod 7M eura
   C - prihod 5M eura
   sa sljede�im stabilnim fiksnim godi�njim rastom prihoda za koji pretpostavljamo da se ne�e mijenjati
   A - 2.05%
   B - 2.80%
   C - 4.30%
   Potrebno je prona�i koja firma �e prva presti�i firmu A u godi�njem prihodu i za koliko godina �e se
   to desit. Tako�er potrebno je ispisati koliko �e sve tri firme imati godi�nji prihod u toj godini.
*/

#include <iostream>
 
using namespace std;
 
int main()
{
    const double godRastPrihodaA = 2.05,
                 godRastPrihodaB = 2.80,
                 godRastPrihodaC = 4.30;
   
    double prihodA = 10,
           prihodB = 7,
           prihodC = 5;
       
    int i = 0;
       
   
    while(prihodB < prihodA || prihodC < prihodA)
    {
        prihodA = prihodA + prihodA * godRastPrihodaA / 100;
        prihodB = prihodB + prihodB * godRastPrihodaB / 100;
        prihodC = prihodC + prihodC * godRastPrihodaC / 100;
        i++;  
    }
   
    if(prihodB > prihodC)
        cout << "Firma B ce prva prestici firmu A za " << i << " godina" << endl;
    else
        cout << "Firma C ce prva prestici firmu A za " << i << " godina" << endl;
       
    cout << "Firma A nakon " << i << " godina: " << prihodA << " miliona" << endl;
    cout << "Firma B nakon " << i << " godina: " << prihodB << " miliona" << endl;
    cout << "Firma C nakon " << i << " godina: " << prihodC << " miliona" << endl;
 
    system("pause>0");
    return 0;
}