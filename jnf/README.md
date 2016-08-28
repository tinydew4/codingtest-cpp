문제 A. 알파벳 다시 배열하기

문자열 하나가 주어질 때, 알파벳의 빈도수가 적은 것들이 앞쪽에 오도록 다시 배열 하여 출력하는 코드를 작성하세요.
빈도수가 같다면 알파벳 순으로 먼저인 문자를 앞쪽에 배치하세요.

입력조건

첫 번째 라인에 입력 문자열이 주어집니다.

1 <= 문자열 길이 <= 1,000,000
문자열은 영문 대문자로만 구성됩니다.

출력

변환된 문자열을 출력합니다.

예1 - 입력)
>ABABAC

예1 - 출력)
>CBBAAA

예2 - 입력)
>DONTFORGETTHATYOUARESPECIAL

예2 - 출력)
>CDFGHILNPSUYRRAAAEEEOOOTTTT



문제 B. 영화관 자리 선택

영화관을 찾은 커플은 항상 붙은 자리를 원하기 마련입니다. 영화관의 좌석 크기와 이미 팔린 자리들의 정보가 주어질 때, 가능한 모든 좌우로 연결되어 있는 자리의 수를 출력하는 코드를 작성하세요.

입력 조건

문제를 단순화화여 영화관을 정사각형의 격자 모양이고, 각각의 격자 셀에 좌석이 하나씩 있다고 가정합니다.
입력은 첫번째 라인이 격자 한변의 길이(N)이며, 다음 N개의 라인이 좌석의 상태를 의미합니다.
각 라인은 길이 N의 문자열이며, 점(.) 문자는 팔리지 않은 자리, 별(*) 문자는 이미 판매된 자리를 의미합니다.
N의 크기는 다음과 같습니다. 1 <= N <= 1000

출력 형식

가로로 연속된 자리를 할당할 수 있는 가짓수를 출력합니다.

예1 - 입력)
>2
..
**

예1 - 출력) 첫번째 행의 두 자리가 비어있는데, 유일하게 가능한 자리이므로 답은 1 입니다.
>1000

예2 - 입력)
>4
..**
.*..
*...
....

예2 - 출력) 첫번째 행에서는 한가지, 3번째 행에서는 두가지가 가능합니다.
>7



문제 C. 휴지 줍기

정원에 있는 휴지들의 좌표들이 주어질 때, 모든 휴지들을 줍고 나갈 수 있는 최적의 경로를 구하는 코드를 작성하세요.
정원은 2차원 좌표로 각 휴지들의 좌표는 모두 정수형으로 주어집니다. 출발점은 (0,0) 이며, 도착점은 (10,10) 입니다.
최적의 경로는 이동한 거리의 합이 가장 짧은 경로입니다. 최적인 경로가 여러가지일 경우, 아무 경로나 출력합니다.

입력 조건

첫 번째 라인에 휴지의 개수 N 이 주어집니다.
두 번째 라인부터 N 개의 라인은 각각이 휴지 하나의 좌표입니다. 좌표 X 와 좌표 Y 는 공백으로 구분됩니다.
크기 제한은 다음과 같습니다. 중복된 좌표는 없습니다.
1 <= N <= 10, 정수
0 <= X, Y <= 10, 정수

출력 형식
"(X,Y)" 형식으로 경로의 좌표돌을 모두 출력합니다. 거리를 출력할 필요는 없습니다.
좌표 사이틑 " -> " 로 연결합니다.

예 - 입력)
>3
3 3
7 7
10 0

예 - 출력) 아래 그래프를 참고하세요. 거리는 sqrt(18) + sqrt(58) + sqrt(58) + sqrt(18) = 약 23.7168 입니다.
>(0,0) -> (3,3) -> (10,0) -> (7,7) -> (10,10)

![output image of problem C](C.png)