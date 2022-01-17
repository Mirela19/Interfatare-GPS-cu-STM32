# Descrierea proiectului
Sistemul de poziționare globală (GPS) este un sistem de navigație bazat pe satelit, care constă din 24 de sateliți în orbită, fiecare dintre aceștia efectuând două circuite în jurul Pământului la fiecare 24 de ore.
Acești sateliți transmit trei biți de informații - numărul satelitului, poziția acestuia în spațiu și ora în care este trimisă informația. Aceste semnale sunt preluate de receptorul GPS, care utilizează aceste informații pentru a calcula distanța dintre acesta și sateliții GPS. Cu semnale de la trei sau mai mulți sateliți, un receptor GPS își poate triangula locația pe sol (adică, longitudine și latitudine) față de poziția cunoscută a sateliților.

Proiectul presupune o interfațare a unui modul GPS cu microcontrolerul STM32F103C8 pentru a găsi coordonatele locației și a le afișa pe un afișaj LCD 16x2.

## Componente utilizate
- microcontroller STM32F103C8 
- modul GPS
- afișaj LCD 16x2
- breadboard
- fire 

### Modulul GPS

Este un modul GPS GY-NEO6MV2 XM37-1612. Acest modul GPS are patru pini +5V, GND, TXD și RXD. Acesta comunică folosind pinii seriali și poate fi ușor interfațat cu portul serial al STM32F103C8.


Modulul GPS trimite datele în format NMEA (FIG.1). Formatul NMEA este format din mai multe propoziții, dintre care avem nevoie de una singură. Această propoziție începe de la $GPGGA și conține coordonatele, ora și alte informații utile. Acest GPGGA se referă la datele de corecție ale sistemului de poziționare globală.

Mai jos este un exemplu $GPGGA String, împreună cu descrierea acestuia:

$GPGGA,104534.000,7791.0381,N,06727.4434,E,1,08,0.9,510.4,M,43.9,M,,*47

$GPGGA,HHMMSS.SSS,latitudine,N,longitudine,E,FQ,NOS,HDP,altitudine,M,înălțime,M,,date de control

În proiectul curent am folosit o bibliotecă GPS TinyGPSPlus care extrage toate informațiile necesare din propoziția NMEA și pentrn care trebuie doar să scriem o linie de cod pentru a obține latitudinea și longitudinea.


![gps](https://user-images.githubusercontent.com/56684731/149729951-bb262dc6-69b6-4a47-a12a-f46426e7d2ae.PNG)

## Schema electrică 

## Conexiuni de circuit între modulul GPS și STM32F103C8

## Conexiuni între LCD 16x2 și STM32F103C8


## Găsirea latitudinii și a longitudinei cu GPS și STM32

După construirea configurației și încărcarea codului,trebuie plasat modulul GPS într-o zonă deschisă pentru a primi semnalul rapid. Uneori este nevoie de câteva minute pentru a primi semnalul, așa că trebuie așteptat ceva timp. LED-ul va începe să clipească în modulul GPS când începe să primească semnal și coordonatele locației vor fi afișate pe afișajul LCD.

Putem verifica latitudinea și longitudinea locației utilizând Google maps.




