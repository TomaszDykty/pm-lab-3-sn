# Parametry projektu

Nazwa: pm-lab-3  
Autor: Paweł Dąbal (pawel.dabal@wat.edu.pl)  
Opis: Projekt bazowy repozytorium na trzecie spotkanie laboratoryjne z przedmiotu _Technika mikroprocesorowa_.  
Wersja: v1.0  
Data: 23.05.2020 r.

# Informacje o studencie

Imię i nazwisko studenta: Tomasz Dykty 
Numer albumu: 72524  
Grupa studencka: WEL18DE1S1

# Odpowiedzi do pytań z instrukcji
...
W jaki sposób można rozbudować funkcjonalność programu
w przypadku gdy liczba naciśnięć przycisku przekroczy określoną ilość?
wpisać ((unsignet))! przed liczbą int w deklaracji licznik będzie zliczał do dwa razy większej wartości a przy przepełnieniu spowrotem będzie liczył od zera

Przy ostatniej wartości zliczanej dla przycisk dać warunek od maksymalnej liczby i utwożyć nową zmienną do której będzie zapisywana liczba prepełnień.
nsigned int a = 0;

27 linijki dopisać
if (liczba_nacisniec>=10000)
{a++;
liczba_nacisniec=0;
}
a mi ędzy 28 a 29 dopisać
if (liczba_nacisniec>=10000 || a>0){Serial.print(a);}
if (liczba_nacisniec<10 && a>0){// 3 ify z elzami poto by wpisać zera przy wyświetlaniu danych
          Serial.print("000");
        }
        else
        {
          if (liczba_nacisniec<100 && a>0){
            Serial.print("00");
          }
          else
          {
            if (liczba_nacisniec<1000 && a>0){
             Serial.print("0");
           }
            
          }
        }

W jaki sposób można zwiększyć liczbę obsługiwanych poleceń oraz liczbę obsługiwanych parametrów? 
- zwiększyć szybkość transmisji z 9600 na wyższą , zwiększyć format ramki


