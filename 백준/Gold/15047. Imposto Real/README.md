# [Gold I] Imposto Real - 15047 

[문제 링크](https://www.acmicpc.net/problem/15047) 

### 성능 요약

메모리: 3240 KB, 시간: 4 ms

### 분류

깊이 우선 탐색, 그래프 이론, 그래프 탐색, 트리

### 제출 일자

2025년 2월 17일 19:05:25

### 문제 설명

<p>O reino de Nlogônia é rico, o povo é educado e feliz, mas o Rei é um tirano quando o assunto se refere a impostos. A cada final de ano, cada cidade do país deve pagar uma determinada quantidade de quilos de ouro em impostos. Chegado o momento de coletar os impostos, o Rei envia sua carruagem real para recolher o ouro devido, usando as estradas do reino.</p>

<p>Cada estrada liga duas cidades diferentes e pode ser percorrida nas duas direções. A rede de estradas é tal que é possível ir de qualquer cidade para qualquer outra cidade, possivelmente passando por cidades intermediárias, mas há apenas um caminho entre duas cidades diferentes.</p>

<p>Em cada cidade há um cofre real, utilizado para armazenamento de ouro de impostos. Os cofres reais são imensos, de forma que cada cofre tem capacidade de armazenar todo o ouro devido por todo o reino. A carruagem sai da capital, percorrendo as estradas do reino, visitando as cidades para recolher o ouro devido, podendo usar qualquer cofre real para armazenar temporariamente uma parte do imposto recolhido, se necessário. Ao final da coleta, todo o ouro devido por todas as cidades deve estar armazenado no cofre real da capital.</p>

<p>Ávaro como é o Rei, ele contratou o seu time para, dados a quantidade de ouro a ser recolhido em cada cidade (em kg), a lista das estradas do reino, com os respectivos comprimentos (em km) e a capacidade de carga da carruagem real (em kg), determine qual é a mínima distância que a carruagem deve percorrer para recolher todo o ouro devido.</p>

### 입력 

 <p>A primeira linha contém dois inteiros N e C indicando respectivamente o número de cidades e a capacidade de carga da carruagem (2 ≤ N ≤ 10<sup>4</sup> e 1 ≤ C ≤ 100). A capital do reino é identificada pelo número 1, as outras cidades são identificadas por inteiros de 2 a N. A segunda linha contém N inteiros E<sub>i</sub> representando a quantidade de imposto devido por cada cidade i (0 ≤ E<sub>i</sub> ≤ 100 para 1 ≤ i ≤ N). Cada uma das linhas seguintes contém três inteiros A, B e C, indicando que uma estrada liga a cidade A e a cidade B (1 ≤ A, B ≤ N) e tem comprimento C (1 ≤ C ≤ 100).</p>

### 출력 

 <p>Seu programa deve produzir uma única linha com um inteiro representando a menor distância que a carruagem real deve percorrer para recolher todo o imposto devido, em km.</p>

