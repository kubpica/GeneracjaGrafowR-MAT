#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

using namespace std;
bool czydopliku = false;
ofstream wynik;

int main()
{
    wynik.open("wynik.txt");
    srand( time( NULL ) );
    int a = 0; int b = 0; int c = 0; int d = 0; int n = 0; double gestosc = 0; bool czySkierowany = false; int rozmiar = 0;  int ilosc = 0; bool czyWazony = false;

    cout << "Program generuje graf o wymiarach n^2 i podanej przez uzytkownika gestosci." << endl;

    cout << "Gdzie wypisac wyniki? 1 - na ekran 2 - do pliku" << endl;
    cin >> n;
    if(n==2) czydopliku = true;
    n = 0;

    while(1){
        cout << "Podaj w % prawdopodobienstwo a: ";
        cin >> a;
        if(a>100 || a<0){
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }
        cout << "Podaj w % prawdopodobienstwo b: ";
        cin >> b;
        if((a+b)>100 || (a+b)<0){
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }
        cout << "Podaj w % prawdopodobienstwo c: ";
        cin >> c;
        if((a+b+c)>100 || (a+b+c)<0){
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }
        d = 100 - a - b - c;
        cout << "Przyjmuje, ze prawdopodobienstwo d wynosi: " << d << "%" << endl;

        cout << "Czy graf ma byc skierowany? (1-tak 0-nie) ";
        cin >> n;
        if(n==1) czySkierowany = true;
        else if (n==0) czySkierowany = false;
        else{
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }

        cout << "Czy graf ma byc wazony? (1-tak 0-nie) ";
        cin >> n;
        if(n==1) czyWazony = true;
        else if (n==0) czyWazony = false;
        else{
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }

        cout << "Rozmiar grafu wynosi 2 do n-tej (n^2). Podaj n: <1,9> ";
        cin >> n;
        if(n<1 || n>9){
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }
        rozmiar = pow( 2, n );

        cout << "Podaj gestosc grafu w %: ";
        cin >> gestosc;
        if(gestosc>100 || gestosc<0){
            cout << "Podano bledne dane. Sprobuj jeszcze raz." << endl;
            continue;
        }
        gestosc = gestosc/100;
        ilosc = gestosc*rozmiar*rozmiar;

        break;
    }

    cout << "Rozpoczeto generacje grafu - prosze czekac" << endl;

    int ktory = 0;
    int rozmiarAktualnejCw = rozmiar;
    int x = rozmiar;
    int y = rozmiar;
    int graf[y][x];

    for(int i = 0; i<y; i++){
        for(int j = 0; j<x; j++){
            graf[i][j] = 0;
        }
    }

    do{
        x=1;
        y=1;
        do{
            int i =( std::rand() % 100 ) + 1;
            //int i = 50; //losuje liczbe od 1 do 100. I sprawdzam w ktorej cwiartce wypadla
            //cout << "Punkt i zostal wylosowany z wartoscia " << i << " wiec ";
            //jezeli rozmiar wylosowanej cwiartki jest rowny 1 to wpisuje to miejsce liczbe 1 w przeciwnym wypadku:
            //wybieram ten przedzial w ktorym wypadla i dziele go na kolejne cwiartki i powtarzam powyzszy krok (losowanie)
            rozmiarAktualnejCw /= 2;
            if(i>0 && i<=a){
                //Wylosowano æwiartkê a. Wiêc nic nie rób.
            }
            else if(i>a && i<=a+b){
                //Wylosowano æwiartkê b. Wykonaj wiêc dzia³anie:
                x += rozmiarAktualnejCw;
            }
            else if(i>a+b && i<=a+b+c){
                //Wylosowano æwiartkê c. Wykonaj wiêc dzia³anie:
                y += rozmiarAktualnejCw;
            }
            else if(i>a+b+c && i<=100){
                //Wylosowano æwiartkê d. Wykonaj wiêc dzia³ania:
                x += rozmiarAktualnejCw;
                y += rozmiarAktualnejCw;
            }
           // cout << "x: " << x << " y: " << y << endl;
        }while(rozmiarAktualnejCw != 1);
        if(graf[y-1][x-1]==0){
            //cout << "Wstawiam 1 w wylosowany punkt grafu: graf[" << x-1 << "][" << y-1 << "]=1" << endl;
            graf[y-1][x-1]=1;
            ktory++;
            if(!czySkierowany && x!=y){
                graf[x-1][y-1]=1;
                ktory++;
            }
        }else if(czyWazony){
            graf[y-1][x-1]++;
            if(!czySkierowany) graf[x-1][y-1]++;
        }

        rozmiarAktualnejCw = rozmiar;
    }while(ktory<ilosc);

    x = rozmiar;
    y = rozmiar;
    cout << endl;
    if(czydopliku) wynik << "   "; else cout << "   ";
    char litera = 'A';
    for(int j = 0; j<x; j++){
        if(j == x/2) if(czydopliku) wynik << "  "; else cout << "  ";
        if(czydopliku) wynik << litera << " "; else cout << litera << " ";
        litera++;
        if(litera=='Z'+1) litera = 'a';
        else if(litera=='z'+1 || litera=='?'+1) litera = '?';
    }
    litera = 'A';
    if(czydopliku) wynik << endl; else cout << endl;
    if(czydopliku) wynik << endl; else cout << endl;
    for(int i = 0; i<y; i++){
        if(i == y/2){
            if(czydopliku) wynik << "   "; else cout << "   ";
            for(int j = 0; j<=x; j++) if(czydopliku) wynik << "| "; else cout << "| ";
            if(czydopliku) wynik << endl; else cout << endl;
        }
        if(czydopliku) wynik << litera << "  "; else cout << litera << "  ";
        litera++;
        if(litera=='Z'+1) litera = 'a';
        else if(litera=='z'+1 || litera=='?'+1) litera = '?';
        for(int j = 0; j<x; j++){
            if(j == x/2) if(czydopliku) wynik << "| "; else cout << "| ";
            if(czydopliku) wynik << graf[i][j] << " "; else cout << graf[i][j] << " ";
        }
        if(czydopliku) wynik << endl; else cout << endl;
    }

    if(czydopliku) wynik << endl; else cout << endl;
    if(czydopliku) wynik << "Wygenerowano graf "; else cout << "Wygenerowano graf ";
    if(czySkierowany) {if(czydopliku)wynik << "skierowany"; else cout << "skierowany";}
    else {if(czydopliku)wynik << "nieskierowany"; else cout << "nieskierowany";}
    if(czyWazony) {if(czydopliku)wynik << " wazony"; else cout << " wazony";}
    if(czydopliku) wynik << " o wymiarach 2^" << n << "=" << rozmiar << " z prawdopodobienstwami:" << endl; else cout << " o wymiarach 2^" << n << "=" << rozmiar << " z prawdopodobienstwami:" << endl;
    if(czydopliku) wynik << "a=" << a << "% b=" << b << "% c=" << c << "% d=" << d << "%" << endl; else cout << "a=" << a << "% b=" << b << "% c=" << c << "% d=" << d << "%" << endl;
    if(czydopliku) wynik << "Gestosc grafu: " << (double) gestosc << " (" << ilosc << "/" << rozmiar*rozmiar << ")" << endl; else cout << "Gestosc grafu: " << (double) gestosc << " (" << ilosc << "/" << rozmiar*rozmiar << ")" << endl;
    if(czydopliku) cout << "Gotowe. Wyniki znajdziesz w pliku wynik.txt" << endl;
    cin >> n;
}
