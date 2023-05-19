# Prepoznavanje lica pomoću računalnog vida

## 1. UVOD
Prepoznavanje lica predstavlja značajnu tehnologiju u području računalnog vida koja omogućava računalnim programima da otkriju prisutnost ljudskih lica i identificiraju njihovu lokaciju na slici ili video streamu. Računalni vid je grana računalne znanosti koja se fokusira na korištenje računalnih algoritama za analizu i razumijevanje slika i filmova. Cilj ovog područja je razviti računalne sustave koji mogu izvršavati različite zadatke, kao što su prepoznavanje objekata, prepoznavanje lica, prepoznavanje gesti, segmentacija objekata, detekcija pokreta i praćenje.
Kvalitetan detektor lica predstavlja ključan faktor u mnogim zadacima vezanim uz lice. Bez prepoznavanja lica, mobilne kamere ne bi mogle automatski prepoznati lice korisnika prilikom snimanja selfija ili identificirati druge osobe u kadru. Upravo stoga, daljnji razvoj i poboljšanje algoritama za prepoznavanje lica predstavlja prioritet u području računalnog vida.
Kako bi se osigurala uspješnost algoritama za prepoznavanje lica, potrebno je razviti napredne metode strojnog učenja i dubokog učenja koje mogu analizirati veliku količinu podataka i stvoriti precizne modele prepoznavanja lica. Osim toga, važno je uzeti u obzir različite uvjete osvjetljenja, pozicije lica i drugih varijabli koje mogu utjecati na prepoznavanje lica. Stoga, istraživači u ovom području nastoje razviti algoritme koji su otporni na varijacije okoline i koji mogu prepoznati lica u različitim uvjetima.
Uz napredak tehnologije, svake godine se pojavljuju novi detektori lica koji su brži i robusniji u prepoznavanju lica. Razvoj novih tehnologija za prepoznavanje lica donosi mnoge prednosti i mogućnosti u različitim područjima, kao što su sigurnost, zabava i komunikacija. Međutim, s obzirom na osjetljivost podataka o licima, nužno je osigurati etičnost i transparentnost u korištenju ovih tehnologija kako bi se izbjegla mogućnost zlouporabe ili kršenja privatnosti pojedinaca.
U konačnici, prepoznavanje lica predstavlja jedan od ključnih elemenata u području računalnog vida koji ima velik potencijal u različitim aplikacijama.

### 1.1 Izbor završnog rada
Prepoznavanje lica je uvijek bilo nešto što me fasciniralo i već dugo vremena htio sam se ozbiljnije pozabaviti time. Kod prepoznavanja lica sviđa mi se autonomnost samog softwarea i povezivanje komponenti u cjelinu odnosno kamere i samog programa. Posebno me zanimaju programi koji čine face mesh, prepoznavanje točki lica te segmentaciju slike. Vrlo sam motiviran za izradu ovoga rada u nadi da ću dobiti željene rezultate.

### 1.2 Cilj rada 
Izraditi funkcionalnu aplikaciju sa svrhom demonstracije raznih zadaća računalnog vida koristeći Jetson Nano mikroračunalo i Python programski jezik u Spyder3 razvojnom okruženju. Rad će sadržavati više primjera rada računalnog vida te sposobnosti praćenja i prepoznavanja lica. Koristiti ću biblioteku MediaPipe i OpenCV kako bih uspješno prepoznao lice te izvršio navedene zadaće.

## 2. PROCES RADA

### 2.1 Korišteni materijali i alati
Za izradu ovoga rada korišteni su sljedeći materijali i alati:
Jetson Nano
Spyder 3 programski jezik
MediaPipe biblioteka 
OpenCV
Web kamera 

#### 2.1.1 Alat

#### Jetson Nano
NVIDIA je 2019. stvorila računalnu ploču Jetson Nano. Ovaj je alat posebno napravljen za stvaranje i testiranje algoritama strojnog učenja i umjetne inteligencije, kao i za stvaranje raznih aplikacija u područjima robotike, autonomne vožnje, video analize i drugih.

Jedan od najmanjih računalnih uređaja, Jetson Nano ima CPU srednje klase koji može brzo izvršiti izazovne zadatke strojnog učenja i NVIDIA grafičku procesorsku jedinicu (GPU). Osim toga, Jetson Nano ima 4 gigabajta RAM-a i 4K video izlaz. Koristi se u različitim primjenama, uključujući računalni vid, identifikaciju objekata, detekciju lica i dijagnostiku medicinskih slika.

#### Spyder 3
Python znanstveno programiranje podržano je u open-source Integrated Development Environment (IDE) pod nazivom Spyder. Spyder je akronim za "Scientific PYthon Development EnviRonment". To je učinkovit instrument za numeričko računanje, znanstveno istraživanje i analizu podataka.
Znanstvenici i analitičari podataka mogu s lakoćom pisati, testirati i uklanjati pogreške u svom kodu koristeći Spyderovo korisničko sučelje i niz alata. Uz uređivač koda, ima preglednik datoteka, preglednik varijabli i konzolu za interaktivne Python sesije. Preferencije korisnika mogu se prilagoditi kroz potpuno prilagodljivo sučelje. Spyderova sposobnost da besprijekorno funkcionira s raznim dobro poznatim Python bibliotekama, uključujući NumPy, SciPy, Matplotlib i Pandas, jedna je od njegovih najznačajnijih karakteristika. Zbog Spyderove integracije s ovim bibliotekama, koje su ključne za znanstveno računalstvo i analizu podataka, to je fantastična opcija za znanstveno programiranje. 
Funkcionalnost za interaktivno računalstvo koju Spyder nudi razlikuje ga od ostalih Python IDE-ova. To omogućuje programerima da pokrenu kod i vide rezultate u stvarnom vremenu. Zajedno s dodatnim interaktivnim računalnim značajkama kao što su dovršavanje naredbenog retka i inline grafički prikaz, Spyder također podržava IPython konzolu.

#### 2.1.2 Komponente

#### MediaPipe
MediaPipe je open-source okvir razvijen od strane Googlea koji omogućuje razvoj realno-vremenskih aplikacija za obradu slike i strojno učenje. Ovaj okvir nudi širok raspon funkcionalnosti, uključujući pre-izgrađene modele za detekciju objekata, praćenje ruku i detekciju lica, koje se lako mogu integrirati u aplikacije.
Izrađen je pomoću C++ i Python programskih jezika, a pruža API-je za oba jezika. Okvir podržava TensorFlow i TFLite, omogućujući integraciju modela strojnog učenja u aplikacije. Arhitektura MediaPipe-a je fleksibilna i proširiva, što programerima omogućuje prilagodbu funkcionalnosti ovog okvira.
MediaPipe pruža podršku za različite ulaze medija, uključujući web kamere, mikrofone i video datoteke, što čini ovaj okvir idealnim za aplikacije koje zahtijevaju obradu audio i video ulaza u stvarnom vremenu. Ova svestranost čini ga popularnim za različite primjene, uključujući virtualnu i proširenu stvarnost, robotiku i automatizaciju. MediaPipe je popularan u aplikacijama gdje se pre-izgrađene komponente za praćenje ruku, detekciju lica i detekciju objekata često koriste. Također je popularan u robotici i automatizaciji, gdje se koristi za razvoj robota koji mogu navigirati i biti u interakciji sa svojim okruženjem.

#### OpenCV
Biblioteka za računalni vid i strojno učenje otvorenog koda koju je stvorio Intel naziva se OpenCV (Open Source Computer Vision Library). Robotika, nadzor te obrada slike i videa samo su neke od komercijalnih i akademskih namjena.
Svestranost OpenCV-a u rukovanju raznim slikovnim i video formatima, uključujući JPEG, PNG i MPEG, jedna je od njegovih najboljih kvaliteta. Osim toga, nudi veliki izbor unaprijed izrađenih metoda računalnog vida i strojnog učenja, poput onih za procjene optičkog protoka, prepoznavanje objekata, otkrivanje značajki i filtriranje slike.	
Python, Java i MATLAB uključeni su u OpenCV, koji je razvijen korištenjem C++. Za programere koji žele stvarati računalni vid i aplikacije za strojno učenje u željenom programskom jeziku OpenCV daje tu mogućnost.

Sposobnost OpenCV-a da omogući paralelnu obradu jedna je od njegovih glavnih prednosti. Ima podršku za SIMD (Single Instruction Multiple Data), GPU ubrzanje i multi-threading, omogućujući programerima da maksimalno iskoriste vrhunski hardver za povećanje brzine svojih programa.
S velikom i angažiranom zajednicom programera koja dodaje nove algoritme, poboljšava trenutne metode i nudi podršku i dokumentaciju, OpenCV je također vrlo proširiv.
Praćenje i otkrivanje objekata jedna je od najčešće korištenih upotreba OpenCV-a. To je izvrsna opcija za izradu aplikacija koje mogu prepoznati i pratiti stvari u stvarnom vremenu jer dolazi s unaprijed ugrađenim algoritmima za prepoznavanje značajki i odgovarajućim algoritmima kao što su SIFT i SURF.

### 2.2 Proces izrade
Rad sam započeo spojivši Jetson Nano te instaliranjem Ubuntu operacijskog sustava. Nakon instalacije operacijskog sustava slijedila je instalacija potrebnih programa i biblioteka odnosno Spyder3, MediaPipe i OpenCV. Kada su svi programi bili instalirani ostalo je osmisliti modele te napisati programski kod uz pomoć kojeg bi ti modeli bili ostvareni. 

#### 2.2.1 Landmark detekcija
Ovaj model jedan je od jednostavnijih primjera računalnog vida te nam daje osnovne točke lica odnosno nos, oči, usta i uši te stvara kvadrat oko našeg lica te time daje do znanja da je naše lice pronađeno. Ovakav program ima mnoge primjene a jedna od glavnih je u fotoaparatima na pametnim telefonima.

#### 2.2.2 Segmentacija selfiea
Model segmentacije selfiea nam omogućuje prikaz lica i samo lica dok se cijela pozadina ili zamagli ili potpuno ukloni. Konkretno u mom modelu pozadina se pretvara u sivu boju te je lice izolirano u prednjem planu. Ova vrsta računalnog vida dosta je popularnija posljednjih nekoliko godina zbog sve većeg broja online sastanka gdje korisnici ne moraju biti na nekom određenom mjestu već mogu biti gdje žele te samo trebaju uključiti segmentaciju selfiea.

#### 2.2.3 Crte dlana
Računalni vid ima mnoge primjene te sam kako bih pokazao raznovrsnost računalnog vida napravio model koji prepoznaje i prikazuje crte dlana. Ovaj model pratit će vaše ruke te ocrtavati položaj vaših prstiju i dlana. 

#### 2.2.4 Face Mesh
Face mesh tehnologija je suvremena tehnika računalnog vida koja omogućuje praćenje i analizu lica u realnom vremenu. Ova tehnologija koristi sofisticirane algoritme za prepoznavanje i praćenje različitih dijelova lica, poput očiju, nosa, usta i obrva, te stvara digitalni 3D model lica. Ovaj model može biti korišten u raznim aplikacijama, uključujući virtualno isprobavanje šminke, izradu avatara za igre, praćenje pokreta lica u filmskoj industriji i druge.

### 2.3 Programski kod
Programski kod ovoga rada pisan je Python programskim jezikom u Spyder 3 razvojnom sučelju. Svaki od modela ima par osnovnih funkcija kao pozivanje biblioteka te otvaranje kamere. Najzahtjevniji, a ujedno i najzanimljiviji dio koda je samo označavanje točki lica te je taj kod u malo drugačijim oblicima prisutan u tri modela, Landmark detekcija, Crte dlana, te u modelu Face Mesh.

## 3. ZAKLJUČAK
U ovom radu provedeno je istraživanje područja prepoznavanja lica s ciljem demonstriranja različitih mogućnosti računalnog vida pomoću Jetson Nano mikroračunala i programskog jezika Python unutar razvojnog okruženja Spyder 3. Prepoznavanje lica predstavlja ključni korak u mnogim aplikacijama koje se temelje na računalnom vidu, uključujući autonomna vozila, sigurnosne sustave, praćenje objekata i slično. Kroz primjenu MediaPipe biblioteke i OpenCV-a, razvijena je funkcionalna aplikacija koja je sposobna prepoznati lica te izvršavati različite zadatke vezane uz računalni vid, poput segmentacije slike, prepoznavanja točaka lica i praćenja objekata.  Korištenje Jetson Nano mikroračunala omogućilo je brzu i efikasnu obradu podataka te izvođenje zahtjevnih zadataka strojnog učenja. Rezultati istraživanja pokazuju da je Jetson Nano mikroračunalo zajedno s MediaPipe bibliotekom i razvojnim okruženjem Spyder 3 izuzetno koristan alat za razvoj aplikacija računalnog vida. Napredne mogućnosti prepoznavanja lica i obrade slika mogu se postići uz relativno malo napora i prihvatljive vremenske zahtjeve. Ova istraživanja pružaju temelj za daljnji razvoj i primjenu u različitim područjima koja zahtijevaju računalni vid i prepoznavanje lica.

## 4. LITERATURA
https://learnopencv.com/face-recognition-an-introduction-for-beginners/ (06.01.2023).

https://elinux.org/Jetson_Nano (21.02.2023.)

https://www.spyder-ide.org/ (22.03.2023.)

https://www.youtube.com/watch?v=E2Dap5SfXkI&t (22.03.2023.)

https://mediapipe.dev/  (23.03.2023.)

https://developers.google.com/mediapipe (16.04.2023.)

https://summerofcode.withgoogle.com/programs/2023/organizations/opencv (16.04.2023.)

https://pypi.org/project/opencv-python/ (21.04.2023.)


