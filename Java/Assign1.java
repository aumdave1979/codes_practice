import java.util.Scanner;
public class Assign1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
		System.out.println("Aum Dave");	
	    System.out.println("92400133058");
        System.out.print("Enter number: ");
        int n = s.nextInt();// Read the integer entered by the user and store it in 'n'.
        
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) System.out.print(i + " ");// If it's prime, print it followed by a space.
        }
    }   
    static boolean isPrime(int num) {// Method to check if a number is prime.
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; i++)// Loop from 2 up to the square root of 'num'.
            if (num % i == 0) return false;
        return true;
}
}
