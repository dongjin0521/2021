/*
1. 입력으로 들어온 문자열 출력

2. Heap 영역에 위에서 선언한 구조체형의 배열을 할당 (크기: n)
3. oddNum 에 임의의 홀수를 넣고, evenNum 에 임의의 짝수를 넣는다.
    숫자 범위: 0-50, 단, 한 번 사용한 숫자는 다시 나올 수 없음.
*/

#include <stdio.h>
#include <stdlib.h> //rand() 사용 
#include <time.h> //time 사용 
#include <string.h> //strcpy 사용
typedef struct {
char name[20];
int oddNum;//홀수
int evenNum;//짝수
}mnum;//mnum이라는 별명의 구조체 정의
void DoMallocQuiz(char* c[], int ea); int randtempO(ea);
int randtempE(ea);
int main(int argc, char* argv[]) { DoMallocQuiz("Quiz1", 5); return 0;
}

void DoMallocQuiz(char *c[], int ea) { //char형 포인터 배열에 이름 저장
mnum *s=NULL; // mnum형 포인터 변수 s 선언 및 초기 화
s = (mnum*)malloc(sizeof(mnum)); //동적 메모리 할당 
strcpy(s->name,c); //문자열 복사, 동적 메모리 사용 
printf("%s\n", s->name); //입력으로 들어온 문자열 출력 (조건1)
printf("ODD: "); 
randtempO(ea);
printf("EVEN: "); 
randtempE(ea);
free(s);//동적 메모리 반납 
}

int randtempO(int ea) {
//입력한 개수만큼의 값을 내보내기 위해 ea 사용 
srand((time(NULL)));
//실행마다 다른 숫자를 위한 시드 설정
int i, r, j;
mnum *random[5]; //mnum형 포인터 배열 random 
mnum *odd = NULL; //mnum형 포인터 변수 odd 
odd = (mnum*)malloc(sizeof(mnum));
//동적 메모리 할당

for (i = 0; i < ea; i++) {
again:; //레이블 int r = NULL;
r = rand() % 51; //0~50 범위에서 랜덤 생성, rand()%(b- a+1)+a: a~b사이의 난수
if (r % 2 == 0) {
goto again; //짝수라면 다시
}
for (j = 0; j <= i - 1; j++)
if (r == random[j]) //rand()로 생성한 숫자가 현재 배열 위치 앞까지 중에 있는지 반복을 통해 찾아봄
goto again; //이미 존재한다면 다시
random[i] = r; //배열에 생성 난수 저장
}
for (i = 0; i < ea; i++) { //3번조건 oddNum과 evenNum에 임의의 숫자를 넣으라는 조건을 충족시키기 위한 반복문 
odd->oddNum = random[i]; //동적 메모리 사용 
printf("%d ", odd->oddNum);
}
printf("\n"); 
free(odd); //동적 메모리 반납
}

int randtempE(int ea){
srand((time(NULL)));
int i, r, j;
mnum *random[5];
mnum *even = NULL;
even = (mnum*)malloc(sizeof(mnum));

for(i=0;i<ea;i++){
again:;
int r = NULL;
r = rand() % 51;
if (r % 2 == 1) {
goto again; //홀수라면 다시 }
for (j = 0; j <= i - 1; j++) if (r == random[j])
goto again;
random[i] = r;
}
for (i = 0; i < ea; i++) printf("%d ", random[i]); printf("\n");
return 0;
free(even);//동적 메모리 반납
}

/*
우선 이번 과제를 하는데 정말 많은 시간이 들었지만, 완성했고 들인 시간 만큼이나 얻은 것도 많은 것 같아 즐거웠습니다.
C언어에 대한 지식이 부족해 솔직히 수업 영상을 들을 때도 잠시 멍 하기도 했지만, 코드를 직접 짜고, 수많은 오류를 겪으며 검색하고, 수정해보니 구조와 작동원리를 이해할 수 있었습니다.
입력받은 문자를 출력하는 과정도 처음에 mnum형 포인터 배열 형식으로 그대로 입력받으려 하니 오 류가 나서 char형 포인터 배열로 입력받은 후, 문자열을 strcpy를 통해 동적할당 한 배열에 넣는 것도 배웠고 원하는 범위 내의 숫자를 난수 생성하는 방법도 익혔으며, 난수가 중복되지 않게 하려면 어떻 게 해야 하는지 또한 알게 되었습니다.
과제를 모두 끝마치고 제출 후 강의를 다시 들을 생각인데, 훨씬 더 수월하게 내용을 이해할 수 있을 것 같아 기대됩니다.
과제 중에서 배열을 생성할 때 포인터를 쓰지 않아도 될 것 같은 경우가 있어 해 보았는데 정상작동 하였습니다. 관련 내용을 찾아보고 좀 더 이해도를 높여야겠다는 생각이 들었습니다.
*/