package javastudy;
import java.util.Scanner;

public class week1_10430 {
	public static void main(String[] args) {
		java.util.Scanner scanner= new java.util.Scanner(System.in); 		//스캐너 객체 선언 
		
		//입력 
		System.out.print("A를 입력하세요: ");		
		int A=scanner.nextInt();
		
		System.out.print("B를 입력하세요: ");
		int B=scanner.nextInt();
		
		System.out.print("C를 입력하세요: ");
		int C=scanner.nextInt();
		
		//출력 
		System.out.println((A+B)%C);
		System.out.println(((A%C) + (B%C))%C);
		System.out.println((A*B)%C);
		System.out.println(((A%C)*(B%C))%C);
		
		scanner.close();
	}
}
