/*
 과제1:
   1. helloworld 출력
   2. argc, argv 를 이용하여 입력값을 받을 수 있어야 함.
   3. 동일한 결과를 보이는 두 개의 함수 를 작성
   4. 두 개의 함수는 iterative version, recursive version
   5. 동일한 결과를 출력.
   6. get_sum_iterative 구현시 -> 10 점
   7. 그 외 다른 동작을 하는 함수 구현시 -> 12 점
   8. 코드내 주석으로 어떻게 구동되는지 자세히 설명.
   */

  #include <stdio.h>
 /*입력한 숫자의 증감을 통해 정해진 숫자(target) 를 찾아가는 함수를 만들어 보았습니다.*/
 int Rfindnum(n, target) {
   //recursive version의 함수입니다.
    if (n == target) {
        return n; // 입력된  값 n이target과 같을 때 n을 반환합니다.
    }

    else if (n > target) {
        return Rfindnum(n - 1, target); // 입력된 값 n이 target 보다 클 때 n-1을 해서 다시 함수가  실행합니다.
    }

    else {
        return Rfindnum(n + 1, target);// 입력된 값 n이 target 보다 작을 때 n+1을 해서 다시 함수가 실행합니다.
    }
}

int Ifindnum(n, target) {
       //iterative version의 함수입니다.
    if (n < target) {
        for (n; n < target; n++); // 입력한 값 n이 target 보다 작을때에는 n이 target이 될 때까지 1씩 더하는것을 반복하는 기능입니다. 
    }
    
    if (n > target) {
        for (n; n > target; n--); // 입력한 값 n이 target보다 클 때에는 n이 target이 될 때까지 1씩 빼는 것을 반복하는 기능입니다.       
    }
         return n;
}

int main(int argc, char* argv[]) {
    printf("Helloworld\n");

    printf("argc = %d\n", argc); // argc:함수에 전달된 인자의 개수를 나타내도록 해주었습니다.

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]); //argv를 통해 전달된 인자를 나타내도록 해주었습니다. for문을 통해 전달된 인자가 모두 표시됩니다.
    }

    int target = 2021; // 찾아갈 수치입니다.
    int n;
    n = atoi(argv); // 문자열을 정수로 바꾸는 함수인 atoi()를 이용하여 입력된 인자를 n에 저장하도록 하였습니다.
    printf("입력하신 값이 %d 를 찾으러 갑니다.\n", target);

    int Iresult = Ifindnum(n, target); //n에는 입력한 인자가, target에는 2021이 들어가게 됩니다.
    int Rresult = Rfindnum(n, target);
    printf("%d\n", Iresult); // 함수의 리턴값이 출력됩니다.
    printf("%d\n", Rresult);
    return 0;
}

/*
<부연설명>
함수에 전달된 인자가 target이라는 숫자와 같게 만들기 위해 증가 또는 감소를 재귀 또는 반복으로  구현하였습니다.
<느낀점>
우선 명령인수 argc,argv와 atoi 함수에 대해 좀 더 자세히 알게 되었습니다. 
c언어를 배운 시간이 남들보다 짧아 명령인수 argc,argv 에 대해서 수업을 듣고도 잘 사용하지 않았으나, 
이번 기회를 통해 실제 스스로 만든 프로그램에 적용해본 것이 유용했고 인상깊었습니다. 
조금만 더 관심과 노력을 가지면 이해할 수 있는 것도, 과제를 통해 수동적으로 공부한 것이 부끄럽다는 생각이 들었고, 
앞으로 좀 더 능동적인 공부로 프로그래밍 실력을 향상시켜야겠다는 생각이 들었습니다.
재귀함수의 로직을 따라 실제 숫자가 어떻게 변하는지 생각해 보는것도 재미있고 신기했습니다.
처음에 rand()함수를 통해 target 값을 무작위로 선정하도록 하였으나, 
오류를 잡지 못하여 시간관계상 2021이라는 고정값으로 제출한 것이 아쉽습니다. 제출 이후에도 다양한 시도를 통해 작동되도록 해보고 싶다는 생각이 들었습니다.
*/