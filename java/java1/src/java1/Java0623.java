package java1;
import java.util.Scanner;
public class Java0623 {
	public static void main(String[] args) {
		System.out.println("Hello World");
		System.out.println("3과5의 합은:"+(3+5));
		System.out.printf("3과5의 합은 %d 입니다.\n",3+5);
		String a="문자열";
		System.out.println(a);
		int num1=10;
		double num2=5.0;
		int num3=num1/(int)num2;
		System.out.println(num3);
		
		boolean b=true;
		System.out.println(b);
		
		int score;
		String name;
		Scanner sc=new Scanner(System.in);
		System.out.print("점수를 입력하시오:");
		score=sc.nextInt();
		System.out.print("이름 입력하시오:");
		name=sc.next();
		
		System.out.printf("점수는 %d이고 ",score);
		System.out.printf("이름은 %s입니다.",name);

		if(score>=90) {
			
			System.out.println("90점 이상입니다.");
			
		}
	
	}
}
