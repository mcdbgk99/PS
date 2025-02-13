# [Diamond III] Ekstremna Ekspedicija - 20320 

[문제 링크](https://www.acmicpc.net/problem/20320) 

### 성능 요약

메모리: 85164 KB, 시간: 864 ms

### 분류

다이나믹 프로그래밍, 수학, 확률론

### 제출 일자

2025년 2월 13일 21:35:47

### 문제 설명

<p>Mladi informatičar Kile mora skidati kile te se stoga odlučio uputiti na Sljeme. Proučavajući planinarske karte, Kile je primijetio da staze na Sljemenu čine stablastu strukturu. Preciznije, poistovjetio ih je s bridovima u stablu, dok je mjesta na kojima se staze sijeku predstavio čvorovima.</p>

<p>Zaključio je da se stablo sastoji od n čvorova koje je označio prirodnim brojevima od 1 od n. Zatim je isplanirao q izleta, gdje i-ti izlet počinje u čvoru a<sub>i</sub>, a završava u čvoru b<sub>i</sub>. Također je pomalo nadobudno procijenio da će udaljenost između bilo koja dva susjedna čvora prevaliti za točno jednu minutu.</p>

<p>Međutim, Kile nije naročito poznat po svojim orijentacijskim vještinama. Stoga će, nakon što se nađe u nekom čvoru, nasumično i uniformno odabrati sljedeću stazu kojom će kročiti (među stazama kojima je taj čvor jedna od krajnjih točaka). Kako bi Kile mogao isplanirati svoje daljnje aktivnosti, za svaki od q izleta zanima ga očekivano vrijeme koje će provesti pentrajući se po Sljemenu. Odnosno, zanima ga koliko je očekivano vrijeme (u minutama) prolaska od čvora a<sub>i</sub> do čvora b<sub>i</sub> ako će se kretati na gore opisan način. Pomozite mu!</p>

<p><strong>Napomena</strong>: Moguće je dokazati da se traženo očekivano vrijeme može zapisati u obliku neskrativog razlomka P/R. Da bismo izbjegli probleme s preciznošću, potrebno je ispisati broj P · R<sup>−1</sup> (mod 10<sup>9</sup> + 7)</p>

### 입력 

 <p>U prvom su retku prirodni brojevi n (2 ≤ n ≤ 300 000) i q (1 ≤ q ≤ 300 000) iz teksta zadatka.</p>

<p>U sljedećih n − 1 redaka nalaze se brojevi u<sub>i</sub> i v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ n) koji označavaju da su čvorovi s oznakama u<sub>i</sub> i v<sub>i</sub> direktno povezani bridom. Bridovi će biti takvi da tvore stablo (jednostavan povezan graf bez ciklusa) od n čvorova.</p>

<p>U i-tom od sljedećih q redaka nalaze se međusobno različiti brojevi a<sub>i</sub> i b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ n) koji predstavljaju početnu i završnu točku i-tog izleta.</p>

### 출력 

 <p>U i-tom je retku potrebno ispisati očekivano trajanje i-tog izleta kako je opisano u tekstu zadatka.</p>

