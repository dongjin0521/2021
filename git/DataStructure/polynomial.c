/* 1. 교재에 있는 다항식 프로그램을 본인의 Linux 계정에서 구현하고 구동 시키기 */
#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b)) // 매크로 인수지정, 삼항연산자
#define MAX_DEGREE 101
typedef struct { //구조체 선언
int degree; //다항식 차수
float coef[MAX_DEGREE]; //다항식 계수 
} polynomial;

polynomial poly_add1(polynomial A, polynomial B) // 두 다항식 더하는 함수 
{
polynomial C;
int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
int degree_a = A.degree;
int degree_b = B.degree;
C.degree = MAX(A.degree, B.degree); //C의 차수

while (Apos <= A.degree && Bpos <= B.degree) { //A차수,B차수 >= 0
if (degree_a > degree_b) { // if ( A차수 > B차수 )
    C.coef[Cpos++] = A.coef[Apos++]; //각 인덱스+1
    degree_a--; //a차수 -1
}

else if (degree_a == degree_b) {

    C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];//각 인덱스+1
    degree_a--; degree_b--;//a차수-1,b차수-1 
    }
else {
    C.coef[Cpos++] = B.coef[Bpos++];//각 인덱스+1 degree_b--;//b차수-1
}
}
return C;}

void print_poly(polynomial p) {
for (int i = p.degree; i > 0; i--)
printf("%3.1fx^%d + ", p.coef[p.degree - i], i); // %3.1f 3:전체 출력폭 1 : 소수점 이하의 숫자 개수 

printf("%3.1f\n", p.coef[p.degree]); //상수항 뒤에는 +가 오면 안되므로 따로 
}

int main(void)
{
polynomial a = { 5,{ 3, 6, 0, 0, 0, 10 } };
polynomial b = { 4,{ 7, 0, 5, 0, 1} }; polynomial c;
print_poly(a);
print_poly(b);
c = poly_add1(a, b); printf("------------------------------ ------------------------------\n"); print_poly(c);
return 0;
}

/*
구조체를 선언하고 이를 사용하는 방법에 대해 수업을 듣고 좀 더 정확하게 이해하고, 이를 직접 사용함으로써 여러 형태의 변수들을 편리하게 묶어 관리할 수 있다는 것을 직접 확인할 수 있어서 좋았습니다.
배열을 사용하여 비슷하지만 다수의 정보가 저장되어야 하는 것들을 쉽게 사용할 수 있어 재미있었습니다.
While 문의 구조를 소스코드만 보았을 때는 상당히 어려워 보이고 구조를 이해하기 힘들었는데, 저만의 언어로 간단히 재구성하고,직접 작동되는 과정을 배열을 통해 눈으로 보고 따라가며 이해하니 훨씬 수월하였습니다.
앞으로도 이해가 힘든 코드가 있을 때에는 모니터만 붙잡고 있지 말고, 다양한 방법을 통해 생각하는 코더가 되면 좋겠다는 생각을 하였습니다. 
*/