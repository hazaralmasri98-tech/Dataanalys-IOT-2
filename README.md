# Dataanalys IOT 2

Det här är mitt projekt i C++, där jag har byggt ett program som samlar in, sparar och analyserar temperaturmätningar.
Projektet gjorde jag som en del av uppgiften “Datainsamlare och analysverktyg för mätvärden”, och målet var att lära mig mer om hur man arbetar med datastrukturer, statistik och programflöde i C++.

# Funktioner

I mitt program kan jag:

 Lägga till egna temperaturvärden manuellt

 Visa statistik (antal, summa, medelvärde, min, max, standardavvikelse)

 Visa alla sparade värden

 Sortera temperaturer (stigande eller fallande)

 Läsa in och spara data till CSV-fil

 Lägga till automatiska tidsstämplar för varje mätning

# Teknik och struktur

Jag har byggt programmet i C++, och använder "std::vector" för att lagra alla mätningar.
Jag har delat upp koden i flera filer för att få en tydlig struktur och bättre läsbarhet:

 measurement.h – innehåller strukturen för en mätning (varde, tid)

 data_manager.h / .cpp – innehåller logiken för att lägga till, läsa, spara, sortera och räkna statistik

 main.cpp – mitt huvudprogram med menyer och användarinteraktion

Jag har också lagt in felhantering för ogiltig inmatning och UTF-8-stöd för svenska tecken i Windows-konsolen.

# Projektstruktur
.
├── measurement.h        # Struct Measurement (varde + tid)
├── data_manager.h       # Deklaration av DataManager & Statistik
├── data_manager.cpp     # Implementation (beräkningar, sortering, filhantering)
├── main.cpp             # Huvudprogram med meny
├── temperaturer.csv     # Skapas automatiskt (lagrar mätningar)
└── README.md            # Den här filen

#  Så kör jag programmet
 Alternativ 1: Visual Studio (Windows)

Jag öppnar projektet i Visual Studio.

Jag trycker Ctrl + Shift + B för att bygga.

Sedan kör jag programmet med F5.

Programmet använder SetConsoleOutputCP(65001); för att visa svenska tecken korrekt i konsolen.

 Alternativ 2: g++ (Windows, Linux eller macOS)

g++ -std=c++17 -O2 -Wall -o Dataanalys_IOT main.cpp data_manager.cpp
./Dataanalys_IOT

# Så använder jag programmet

När programmet startar läser det automatiskt in filen temperaturer.csv om den finns.
Sedan visas menyn:

--- MENY ---
1) Lägg till temperatur
2) Visa statistik
3) Visa alla
4) Spara
5) Sortera
6) Avsluta
Val:


Jag väljer ett alternativ genom att skriva siffran och trycka Enter.

💡 Exempel på körning
Val: 1
Hur många temperaturer vill du lägga till? 3
Temperatur 1: 18.5
Temperatur 2: 20.7
Temperatur 3: 19.9
3 temperaturer tillagda!

Val: 2
Antal: 3
Medel: 19.7
Min: 18.5
Max: 20.7
Stdav: 0.9

# Filformat (CSV)

Alla mätningar sparas i en fil som heter temperaturer.csv.
Varje rad består av tid och temperatur separerade med ett kommatecken:

YYYY-MM-DD HH:MM,temperatur


Exempel:

2025-10-22 10:15,19.3
2025-10-22 12:00,21.5
2025-10-22 16:30,20.2

# Statistik som beräknas
Statistik	Förklaring
Antal	Hur många mätningar jag har gjort
Summa	Summan av alla temperaturer
Medel	Genomsnitt av alla värden
Min/Max	Lägsta och högsta temperatur
Stdav	Standardavvikelse (spridning)

# Mina tankar och lärdomar

Det här projektet har lärt mig mycket om:

hur jag kan använda vektorer för att lagra data,

hur jag räknar ut statistik på ett effektivt sätt,

hur jag gör filinläsning och sparning i CSV-format,

och hur jag bygger ett tydligt menyflöde i ett konsolprogram.

Jag märkte också hur viktigt det är att hantera felinmatningar och att ha en tydlig struktur mellan logik och presentation.

# Mitt GitHub-repo

 https://github.com/hazaralmasri98-tech/Dataanalys_IOT.git

# Avslutning

Jag är väldigt nöjd med hur projektet blev!
Det var både roligt och lärorikt att bygga ett program som kan samla in och analysera data på ett praktiskt sätt.
Jag fick använda både logiskt tänkande och kreativitet för att få allt att fungera smidigt.

Testa gärna mitt program och säg vad du tycker — jag tar gärna emot feedback! 
