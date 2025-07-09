import java.util.Scanner;

public class exam_1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the Number to check Even or Odd: ");
        int a = sc.nextInt();
        if(a%2 == 0){
            System.out.println("The given number is Even");
        }
        else{
            System.out.println("The given number is Odd");
        }
    }
}
