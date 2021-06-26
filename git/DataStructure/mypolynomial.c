/*
동영상에서 주어진 두 식을 화면에 print_poly_assign 함수를 이용하여 출력하고,
add_poly_assign 함수를 이용하여 두 식의 합을 구한 후, 다시 print_poly_assign 함수를 이용하여 합을 출력.
교재에 나온 방법이 아닌, 본인만의 자료구조 또는 계산 방법을 디자인 해서 진행.
*/

#include <stdio.h>
#define MAX_DEGREE 10 // 다항식 레이블 최댓값 
typedef struct {// polynomial 구조체 선언
float coef[MAX_DEGREE];//다항식 계수
} polynomial;

polynomial add_poly_assign(polynomial a, polynomial b)
// 두 다항식 더하는 함수
{
int degree; //정수형 인덱스 변수
polynomial c;
for (degree = MAX_DEGREE; degree >= 0; degree--) {//MAX_DEGREE 에서 0까지 반복, degree는 레이블 을 의미
c.coef[degree] = a.coef[degree] + b.coef[degree]; //차례대로 하나씩 모두 
}
return c;
}

void print_poly_assign(polynomial p,int pos) //차수를 출력함수에 직접 입력
//출력 관련 함수
{
polynomial c;
int degree; //정수형 인덱스 변수
for (degree = 0; degree <= pos-1; degree++) {// 0에서부터 차수-1 까지 1씩 증가 반복
printf("%3.1f x^%d+ ", p.coef[degree], pos - degree); //pos-degree 를 해야 최고차항부터, 즉 실제 인덱스와 정반대 순서
}
printf("%3.1f x^%d\n ", p.coef[pos], 0); //상수항 뒤에는 ‘+’를 제외하기 위해 사용 
}

int main(void)
{
polynomial a = {8,0,7,1}; polynomial b = {10,3,0,1}; polynomial c;
print_poly_assign(a,3); //차수를 출력함수에 직접 입력 
print_poly_assign(b,3); //차수를 출력함수에 직접 입력
c = add_poly_assign(a, b); printf("------------------------------------------------------------\n"); 
print_poly_assign(c,3); //차수를 출력함수에 직접 입력
return 0; 
}

/* 
기존 코드보다 좀 더 간단하고 쉬운 코드를 만들어 보았습니다.
출력할 때 degree 가 실제 단어가 의미하는 바와 정반대 순서로 되어 있어 한눈에 작동과정을 떠올리기 힘들다는 단점이 있었으며, 코딩을 할 때 변수의 이름 지정과 이름에 맞는 숫자가 프로그램 제작 및 유지보수에서 상당히 중요한 역할을 할 수 있겠다는 생각이 들었습니다.
기존에는 차수를 구조체를 통해 한번에 다 입력하였지만, 다른 방식으로도 만들어 보고 싶어 출력함수에 차수를 직접 입력하게 하였으며, 효율성을 떠나 다양한 방법으로 같은 출력 결과를 만들어 내고 생각하는 과정이 재미있었습니다.
실제 숫자가 있던 없던, 두 다항식을 더하는 함수에서 사전에 설정된 MAX_DEGREE 값 내의 모든 차수에서 반복하기 때문에 수업시간에 배웠던 코드보다 비효율적이라는 생각이 들었습니다.
*/






