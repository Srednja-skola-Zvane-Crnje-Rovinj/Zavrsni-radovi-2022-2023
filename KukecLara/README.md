# Lampa upravljana aplikacijom

## Tema: Led lampa s aplikacijom
### Mentor: Lovro Šverko, prof.
### Učenik: Lara Kukec, 4.D
### Smjer: tehničar za računalstvo

## Sadržaj:
Predgovor
1 Uvod
1.1 Izbor završnog rada
1.2 Cilj i zadaci
2 Proces rada
2.1 Korišteni materijali i alat
2.1.1 Alat
2.1.2 Komponente
2.2 Shema
2.2.1 Elektronička shema	
2.2.2 3D model
2.3 Proces izrade
2.3.1 Lemljenje
2.3.2 Testiranje led trake	
2.3.3 3D modeliranje lampe	
2.3.4 3D printanje	
2.4 Dizajn korisničkog sučelja
2.5 Programski kôd	
3. Zaključak	
4. Literatura	

## Predgovor

Izjavljujem pod punom odgovornošću da sam završni rad izradio samostalno, isključivo znanjem stečenim tijekom srednjoškolskog obrazovanja, služeći se navedenim izvorima podataka i uz stručno vodstvo mentora Lovra Šverka, prof., kojemu se još jednom srdačno zahvaljujem. Također se zahvaljujem svojim kolegicama i kolegama te ostalim profesoricama i profesorima na pomoći.

## 1 Uvod

Led lampe su postale popularan izbor za rasvjetu zbog svoje energetske učinkovitosti, trajnosti i fleksibilnosti u dizajnu. U ovom završnom radu bit će opisan proces izrade jedne takve led lampe korištenjem 3D modeliranja i printanja, upravljanje led lampom preko Arduina MKR1000 i upravljanje preko interneta pomoću Arduino IoT Cloud-a. Bit će opisan postupak odabira materijala za izradu sklopovlja i kućišta, te izrada samog sklopovlja i kućišta. Također, bit će opisane sve karakteristike led trake WS2812B, kao i postupak programiranja za upravljanje bojom, svjetlinom i paljenjem/gašenjem lampe preko interneta.

### 1.1 Izbor završnog rada

Ovaj završni rad sam izabrala iz više razloga, jedan od njih je taj što kroz ovaj rad mogu pokazati većinu svojih vještina steknutih kroz svoje školovanje. No i zato što me iskreno jako zanimalo kako bi to izgledalo da ja napravim sama svoju led lampu, odnosno što se sve mora napraviti da bi ona bila funkcionalna, ali naravno i estetična te primamljiva izgledom.

### 1.2 Cilj i zadaci

Cilj ovog rada je napraviti funkcionalnu led lampu koju će biti moguće upravljati preko WiFi mreže te naravno upoznati se s modernom tehnologijom koja je dio našeg svijeta. Prvobitno što se treba ustanoviti koje komponente ćemo koristiti za upravljanje led trake, zatim ide 3D modeliranje te printanje. Nakon toga nam slijedi programiranje naše upravljačke pločice te zatim izrada našeg korisničkog sučelja kojim ćemo upravljati Led lampom.

## 2 Proces rada
### 2.1 Korišteni materijali i alat
#### 2.1.1 Alat

#### Arduino IoT Cloud
Arduino IoT Cloud je oblak platforma za internet stvari (IoT) od tvrtke Arduino, koja omogućava povezivanje uređaja izgrađenih na Arduino platformi s internetom te omogućuje njihovo praćenje i upravljanje s bilo kojeg uređaja povezanog na internet.

Arduino IoT Cloud pruža korisničko sučelje za stvaranje i upravljanje IoT projekata, koje se lako mogu povezati s različitim vrstama senzora i akcijskih elemenata. Korisnici mogu stvarati vlastite prilagođene nadzorne ploče za praćenje podataka iz svojih uređaja, stvarati automatizirane scenarije i daljinski upravljati svojim uređajima.

#### Arduino IDE
Arduino IDE (Integrated Development Environment) je besplatno razvojno okruženje za programiranje Arduino pločica. IDE je razvijen kako bi programiranje bilo što jednostavnije i dostupnije široj publici.

Arduino IDE koristi C++ jezik s dodatnim funkcijama i bibliotekama specifičnim za Arduino platformu. IDE omogućuje programerima da izrade i učitaju kôd u Arduino pločicu. Također se može koristiti za praćenje serijskih podataka i debagiranje koda.

#### TinkerCAD 
Tinkercad je online besplatna platforma za 3D modeliranje i dizajniranje u kojoj korisnici mogu stvoriti 3D modele, elektroničke krugove i kodirati svoje projekte. Tinkercad je stvoren od strane tvrtke Autodesk i omogućuje korisnicima da dizajniraju različite vrste projekata, uključujući igračke, nakit, prototipe, i još mnogo toga.

Tinkercad je online besplatna platforma za 3D modeliranje i dizajniranje u kojoj korisnici mogu stvoriti 3D modele, elektroničke krugove i kodirati svoje projekte. Tinkercad je stvoren od strane tvrtke Autodesk i omogućuje korisnicima da dizajniraju različite vrste projekata, uključujući igračke, nakit, prototipe, i još mnogo toga.

Platforma je namijenjena kako početnicima, tako i iskusnim korisnicima, s intuitivnim sučeljem i velikim brojem resursa i materijala. Tinkercad sadrži sve potrebne alate za kreiranje 3D modela, uključujući biblioteke dijelova, alate za oblikovanje i manipulaciju objekata, te mogućnost uvoza i izvoza modela u različitim formatima.

Tinkercad je također integriran s elektroničkim alatima poput Arduinoa, što omogućuje korisnicima da izrade prototipe i projekte koji uključuju i hardverske i softverske elemente. Također omogućuje korisnicima da programiraju kôd za upravljanje projektima, a zatim ga uvezu u dizajn kako bi stvorili funkcionalne modele.

#### Lemilica 
Lemilica je električni alat koji se koristi za spajanje dijelova ili žica primjenom topline za otapanje lemilice. Toplina se stvara grijačem koji se nalazi u vrhu lemilice i zagrijava lemljeni spoj. Kada se toplina primijeni na spoj, lemljenica se stapa i povezuje dijelove.

#### 3D printer
3D printer je računalni uređaj koji koristi tehnologiju aditivne proizvodnje kako bi stvorio trodimenzionalni objekt iz digitalnog modela. Uređaj koristi slojevitu metodu izrade, gdje nanosi materijal u slojevima kako bi stvorio objekt po uputama koje se nalaze u digitalnom modelu.

#### 2.1.2 Komponente 

#### Arduino MKR1000
Arduino MKR1000 je razvojna pločica s mikrokontrolerom koja koristi Wi-Fi vezu i namijenjena je za razvoj IoT (Internet of Things) projekata. Opremljena je s 32-bitnim ARM mikrokontrolerom Atmel SAMD21, s 256 KB Flash memorije i 32 KB SRAM-a, te Wi-Fi modulom ESP8266 koji omogućuje bežičnu komunikaciju putem Wi-Fi mreže.

Arduino MKR1000 također ima ugrađen Li-Po punjivi baterijski priključak, niskoenergetski Bluetooth modul i nekoliko ulaza/izlaza (I/O) koji omogućuju povezivanje s različitim senzorima i aktuatorima. Osim toga, Arduino MKR1000 je kompatibilan s Arduino programskim okruženjem (IDE) i može se programirati korištenjem programskog jezika C++.

#### Led traka WS2812B 
WS2812B je LED traka koja se sastoji od više LED dioda spojenih zajedno na istom vodiču, a svaka pojedinačna LED dioda ima svoju adresu. Svaka LED dioda ima tri osnovne boje (crvenu, zelenu i plavu) i mogu se upravljati pojedinačno pomoću mikrokontrolera koji podržava PWM (Pulse Width Modulation) signal.

Osim toga, WS2812B trake su vrlo fleksibilne i mogu se lako saviti i prilagoditi obliku površine na kojoj se koriste. WS2812B trake se mogu programirati korištenjem različitih programskih jezika i platformi, kao što su Arduino, Raspberry Pi i drugi mikrokontroleri i platforme.

#### FastLED biblioteka
FastLED je popularna open-source biblioteka za Arduino platformu koja se koristi za upravljanje digitalnim LED trakama, uključujući WS2812B, WS2811, APA102 i druge.

Ova biblioteka omogućuje programerima da jednostavno upravljaju LED trakama korištenjem različitih efekata, animacija, uzoraka i boja. FastLED biblioteka koristi optimiziranu upotrebu memorije i performanse, što omogućuje upravljanje velikim brojem LED dioda s minimalnim opterećenjem mikrokontrolera.

#### ThingProperties biblioteka
ThingProperties je Arduino biblioteka koja omogućuje jednostavno stvaranje IoT (Internet of Things) projekata, uključujući upravljanje senzorima i aktuatorima putem interneta.

Ova biblioteka pojednostavljuje postavljanje i konfiguriranje WiFi mreže, omogućujući korisnicima da lako povežu svoj Arduino uređaj s mrežom i postave internet vezu. ThingProperties biblioteka također olakšava stvaranje korisničkog sučelja za upravljanje uređajem putem interneta, što može uključivati ​​prikaz podataka senzora, upravljanje aktuatorima i slanje obavijesti korisnicima.

### 2.2 Shema
#### 2.2.1 Elektronička shema
Na slici je prikazana elektronička shema napravljena u TinkerCADu. S obzirom da u tinkerCADu ne postoji Arduino MKR1000, korišten je Arduino Uno.  Na arduino uno je spojena led traka tako da je DIN (Data IN) izlaz na traci spojen žutom žicom na analogni 5 ulaz, +5V je spojeno na +5V na Arduinu crvenom žicom te GND (Ground) je spojen na GND crnom žicom. 

#### 2.2.2 3D model 
3D model napravljen je na platformi TinkerCAD. Sastoji se od 5 dijelova, donji dio koji je spremište za Arduino (sastoji se od gornjeg i donjeg dijela), zatim imamo unutarnji dio na koji je tu da ledice zalijepimo na njega, poslije njega imamo vanjski dio kroz koji prolazi svjetlost ledica te na kraju imamo poklopac.

### 2.3 Proces izrade
#### 2.3.1 Lemljenje 
Na led traku sam na izlaze morala zalemiti žice kako mi arduino mogao komunicirati s led trakom. Na +5V sam zalemila crvenu žicu, na DIN (Data IN) žutu te na GND (Ground) crnu.

#### 2.3.2 Testiranje led trake
Kako bi bila sigurna da sam dobro zalemila žice testirala sam led traku pokretanjem programa koji sam napravila. 

#### 2.3.3 3D modeliranje lampe
Lampu sam modelirala u TinkerCADu. sSastoji se od pet dijelova, kao što sam već navela. 
Donji dio se spaja vijcima koji takođerautomatski služe kao nogice, a dijelovi za postavljanje i prekrivanje ledica se stavljaju u utore napravljene na gornjem dijelu spremišta za Arduino.

#### 2.3.4 3D printanje 
Nakon napravljenog 3D modela spremamo ga kao STL file koji printa model sloj po sloj s PLA filamentom.

### 2.4 Dizajn korisničkog sučelja
Dizajn korisničkog sučelja sam radila u Arduino IoT Cloudu. Korisničko sučelje se može koristiti i na računalu i na mobitelu, sve što trebate je biti spojeni na internet. Pošto imamo lampu kojoj želimo mijenjati boje dodala sam Color Picker na kojem možemo izabrati bilo koju boju te on to onda šalje arduinu. Dodala sam i Switch kako bismo mogli uključiti i isključiti našu lampu. S obzirom da nam nekad treba jače a nekad slabije svjetlo dodala sam Slider pomoću kojeg mijenjamo svjetlinu kojom lampa svijetli. Te na kraju sam dodala jednu zabavnu opciju, Button koji kad pritisnete svaka ledica na led traci svijetli svojom nasumičnom bojom.

### 2.5 Programski kôd
Prvo što trebamo napraviti je uključiti biblioteke koje su nam potrebne. Ovdje su to FastLED i thingProperties. 
FastLED nam pomaže okko upravljanja led trakom i optimizira njezino korištenje. Isto tako ima puno različitih efekata i opcija za lakše programiranje led trake. 
Dok nam thingProperties pomaže oko postavljanja i konfiguriranja WiFi mreže za arduino koji ćemo koristiti kako bismo upravljali našom lampom.

Nakon toga trebamo definirati sve potrebne stvari kao na primjer na kojem se pinu izlaz za ledice nalazi što je u našem slučaju pin 5, broj ledica, tip naše led trake. Zatim moramo postaviti početne postavke.

Naravno trebamo i postaviti ažuriranje konekcije s Arduino IoT Cloudom.

Funkcija onBojaLedChange() kada se vrijednost color pickera promijenji šalje to arduinu i tada se mijenja boja led trake u odabranu boju. 

Funkcija onPoverOnOffChange() uključuje/isključuje lampu u ovisnosti ako je prekidač stavljen na ON ili OFF te ako se lampa uključuje postavlja trenutno odabranu boju u color pickeru. 

Funkcija onSvjetlinaLedChange() s obzirom na mijenjanje vrijednosti na slideru mijenja i svjetlinu led lampe.

Funkcija onFade1Change() mijenja boje ledica u nasumične boje ako je dugme pritisnuto.

## 3. Zaključak

U ovom maturalnom radu sam istražila izradu led lampe koja se može upravljati preko interneta. Koristili smo Arduino MKR1000 mikrokontroler, led traku i korisničko sučelje s platforme Arduino IoT Cloud za upravljanje. Također sam analizirala postupak izrade modela kućišta u TinkerCADu i isprintala ga na 3D printeru. LED lampa je testirana i funkcionalna je, omogućujući korisniku da odabere različite opcije i kontrolira ih putem Android aplikacije. Ovaj projekt je dobar primjer kako se tehnologija može koristiti u svrhu stvaranja novih i korisnih proizvoda za svakodnevnu upotrebu.

## 4. Literatura

https://randomnerdtutorials.com/guide-for-ws2812b-addressable-rgb-led-strip-with-arduino/#more-26734    (29.11.2022) 

https://wokwi.com/projects/312460386125218368  (29.11.2022)

https://randomnerdtutorials.com/guide-for-ws2812b-addressable-rgb-led-strip-with-arduino/ (20.2.2023)

https://www.instructables.com/An-Eye-Catching-3D-Printed-Hexagonal-Cells-LED-Lam/ (17.3.2023) 

https://www.reddit.com/r/FastLED/comments/ejgkv0/simple_rainbow_wave/?onetap_auto=true&onetap_auto=true (12.5.2023)

https://docs.arduino.cc/arduino-cloud/getting-started/dashboard-widgets (11.5.2023)




