**Imię i nazwisko:** Jakub Pranica **Grupa:** Informatyka - 13i **Data:**
20-03-2017 **Przedmiot:** Metody Programowania

**Wykładowca:** dr inż. Zbigniew Kokosiński **Semestr:** 2

**Temat:** Napisać algorytm generujący graf o wymiarach n\^2 i podanej przez
użytkownika gęstości.

**Graf** – podstawowy obiekt rozważań teorii grafów, struktura matematyczna
służąca do przedstawiania i badania relacji między obiektami. W uproszczeniu
graf to zbiór wierzchołków, które mogą być połączone krawędziami w taki sposób,
że każda krawędź kończy się i zaczyna w którymś z wierzchołków.

**Graf skierowany** (**digraf**, od ang. directed graph) – rodzaj grafu
rozważanego w teorii grafów. Graf skierowany definiuje się jako uporządkowaną
parę zbiorów. Pierwszy z nich zawiera wierzchołki grafu, a drugi składa się z
krawędzi grafu, czyli uporządkowanych par wierzchołków. Ruch po grafie możliwy
jest tylko w kierunkach wskazywanych przez krawędzie. Graf skierowany można
sobie wyobrazić jako sieć ulic, z których każda jest jednokierunkowa. Ruch pod
prąd jest zakazany.

**Opis programu:** Program prosi użytkownika o podanie prawdopodobieństw a, b,
c, d (a+b+c+d=100%). Gdzie liczby te określają prawdopodobieństwo wybrania
danego przedziału ("trafienia" jedynki/krawędzi grafu w dany obszar). Użytkownik
decyduje również, czy graf ma być skierowany oraz, czy ma być ważony. Na koniec
program prosi jeszcze o podanie gęstości grafu, na podstawie której określa
ilość potrzebnych do wygenerowania jedynek (krawędzi). Zgodnie z podanymi
prawdopodobieństwami zostaje wylosowany jeden z przedziałów a, b, c lub d.
Jeżeli wybrany przedział jest wielkości 1, to w jego miejsce wstawiana jest
jedynka (lub w przypadku grafu ważonego wartość tego punktu jest zwiększana o
1). Jeżeli graf jest nieskierowany, to program robi to samo z punktem
symetrycznym do wylosowanego. Natomiast jeżeli wybrany przedział jest większy
niż 1, to zostaje on podzielony na ćwiartki oznaczone odpowiednio a, b, c oraz d
i losowanie zostaje powtórzone, tym razem dla mniejszego obszaru. Program
kontynuuje swoje działanie, dopóki nie wygeneruje wymaganej ilości jedynek
(krawędzi grafu). Na koniec podaje dodatkowo ich ilość. **(Pseudokod na odwrocie
kartki)**

**Napotkane problemy: 1.**Reprezentacja macierzowa grafu zapisana, za pomocą
tablic w języku programowania c++ **2.**Określenie i wygenerowanie podanej
ilości jedynek (krawędzi) na podstawie podanej przez użytkownika gęstości i
wielkości grafu. **3.**Rozpoznanie różnic w generacji grafu skierowanego oraz
ważonego **4.**Wypisanie na ekran i do pliku grafu w postaci macierzowej
zapisanego w tablicy dwuwymiarowej.

**Przykładowy wynik programu:**

![](media/fc4617fe875986f7f9a30bee52acb6c0.png)

Program generuje graf o wymiarach n\^2 i podanej przez użytkownika gęstości.
Gdzie wypisać wyniki? 1 - na ekran 2 - do pliku **1**

Podaj w % prawdopodobieństwo a: **10**

Podaj w % prawdopodobieństwo b: **10**

Podaj w % prawdopodobieństwo c: **10**

Przyjmuje, ze prawdopodobieństwo d wynosi: **70%**

Czy graf ma być skierowany? \<1-tak 0-nie\> **0**

Czy graf ma być ważony? \<1-tak 0-nie\> **0**

Rozmiar grafu wynosi 2 do n-tej (n\^2). Podaj n: \<1,9\> **4**

Podaj gęstość grafu w %: **30**

Rozpoczęto generacje grafu - proszę czekać

Wygenerowano graf nieskierowany

o wymiarach 2\^4=16 z prawdopodobieństwami:

a=10% b=10% c=10% d=70%

Gęstość grafu: 0.3 (76/256)

Podaj w % prawdopodobieństwo a: **25**

Podaj w % prawdopodobieństwo b: **25**

![](media/4ed5f143b5908bb59627a359348c62dc.png)

Podaj w % prawdopodobieństwo c: **25**

Przyjmuje, ze prawdopodobieństwo d wynosi: **25%**

Czy graf ma być skierowany? \<1-tak 0-nie\> **1**

Czy graf ma być ważony? \<1-tak 0-nie\> **1**

Rozmiar grafu wynosi 2 do n-tej (n\^2). Podaj n: \<1,9\> **3**

Podaj gęstość grafu w %: **40**

Rozpoczęto generacje grafu - proszę czekać

Wygenerowano graf skierowany ważony

o wymiarach 2\^3=8 z prawdopodobieństwami:

a=25% b=25% c=25% d=25%

Gęstość grafu: 0.4 (25/64)

**Pseudokod:**

**Wypisz na ekran:** "Program generuje graf o wymiarach n\^2 i podanej przez
użytkownika gęstości. \\n"

**Wypisz na ekran:** "Podaj w % prawdopodobienstwo a: \\n" //oraz b i c. Program
sam ustali prawdopodobieństwo d.

**Użytkownik podaje liczbę**, a program przypisuje ją do zmiennej **a; //**tak
samo z b i c.

**Zdefiniuj** bool czySkierowany = false; **oraz** bool czyWazony = false;

**Wypisz na ekran:** "Czy graf ma być skierowany? (1-tak 0-nie) "

**Jeżeli użytkownik wybrał 1 (tak), to ustaw** czySkierowany **na true.
//**program analogicznie pyta, czy graf ma być ważony

**Wypisz na ekran:** "Rozmiar grafu wynosi 2 do n-tej (n\^2). Podaj n: \<1,9\> "

**Użytkownik podaje liczbę**, a program przypisuje ją do zmiennej **n;**

**Na podstawie podanej liczby program określa rozmiar grafu:** rozmiar = pow( 2,
n );

**Wypisz na ekran:** "Podaj gęstość grafu w %: "

**Użytkownik podaje liczbę**, a program przypisuje ją do zmiennej **gestosc;**

**Na podstawie podanej gęstości program określa ilość jedynek (krawędzi) do
wylosowania:**

ilosc = (gestosc/100)\*rozmiar\*rozmiar; **Wypisz na ekran:** "Rozpoczęto
generację grafu - proszę czekać \\n "

**Zdefiniuj** int ktory = 0**;** int rozmiarAktualnejCw = rozmiar**;** int x =
rozmiar**;** int y = rozmiar**;** int graf[y][x]**;**

**Wyzeruj wszystkie elementy tablicy 2-wymiarowej graf.**

**Powtarzaj:**

**Ustaw wartość** x=1; **oraz** y=1;

**Powtarzaj:**

**Zmniejsz rozmiarAktualnejCw o połowę:** rozmiarAktualnejCw /= 2;

**Wylosuj liczbę i z przedziału \<1,100\>**

**Sprawdź, do którego przedziału należy wylosowana liczba i wykonaj odpowiednie
dla danego przedziału działania:**

if(i\>0 && i\<=a){ //Wylosowano ćwiartkę a. Więc nic nie rób. }else if(i\>a &&
i\<=a+b){

//Wylosowano ćwiartkę b. Wykonaj więc działanie:

x += rozmiarAktualnejCw;

}else if(i\>a+b && i\<=a+b+c){

//Wylosowano ćwiartkę c. Wykonaj więc działanie:

y += rozmiarAktualnejCw;

}else if(i\>a+b+c && i\<=100){

//Wylosowano ćwiartkę d. Wykonaj więc działania:

x += rozmiarAktualnejCw;

y += rozmiarAktualnejCw; }

**dopóki rozmiarAktualnejCw nie jest równy 1; (**rozmiarAktualnejCw != 1**)**

**//w tym momencie powyższa pętla została zakończona więc zmienne x i y
zawierają współrzędne wylosowanego punktu grafu.**

**Jeżeli wylosowany punkt grafu jest równy zeru to: (**graf[y-1][x-1]==0**)**

**nadaj mu wartość równą 1 (**graf[y-1][x-1]=1;**)**

**oraz zwiększ** ktory **o 1 (**ktory++;**)**

**Dodatkowo jeżeli** czySkierowany == false **to:**

**nadaj wartość punktu przeciwległego (symetrycznego) równą 1
(**graf[x-1][y-1]=1;**)**

**oraz ponownie zwiększ** ktory **o 1 (**ktory++;**)**

**w przeciwnym wypadku, jeżeli** czyWazony == true **to: (**else
if(czyWazony)**)**

**zwiększ wartość wylosowanego punktu o 1 (**graf[y-1][x-1]++;**)**

**Dodatkowo jeżeli** czySkierowany == false **to:**

**zwiększ wartość punktu przeciwległego (symetrycznego) o 1
(**graf[x-1][y-1]++;**)**

**Ustaw wartość** rozmiarAktualnejCw = rozmiar;

**dopóki wartość ktory jest mniejsza od wartości ilosc; (**ktory\<ilosc**)**

**Wypisz graf na ekranie lub do pliku. Na koniec podaj jeszcze jego rozmiar oraz
gęstość.**

**Pełny kod programu w C++ dostępny pod adresem:** http://pastebin.com/JwPU13Lq

**Wnioski:** Program działa i prawidłowo losuje/generuje wszystkie możliwe
krawędzie grafu dla podanych przez użytkownika danych, takich jak:
prawdopodobieństwo poszczególnych ćwiartek, rozmiar grafu (n) oraz jego rodzaj
(skierowany/nieskierowany, ważony/nieważony). Czas generacji grafu wydłuża się
wraz ze wzrostem wartości n lub/i jego gęstości.

**Literatura:**

-   pl.wikipedia.org/wiki/Graf_(matematyka) oraz
    pl.wikipedia.org/wiki/Graf_skierowany

-   http://riad.pk.edu.pl/\~zk/MP_HP.html - dr inż. Zbigniew Kokosiński

-   "Kombinatoryka dla programistów" - Lipski Witold
