import java.util.Scanner;

public class Assign2 {

    // Recursive method to find nth Fibonacci number
    static int fibonacciRecursive(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }

    // Non-recursive (iterative) method to print Fibonacci series
    static void fibonacciIterative(int count) {
        int a = 0, b = 1;
        System.out.print("Fibonacci Series (Iterative): ");
        for (int i = 0; i < count; i++) {
            System.out.print(a + " ");
            int next = a + b;
            a = b;
            b = next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter how many Fibonacci numbers you want: ");
        int count = sc.nextInt();

        // Iterative method
        fibonacciIterative(count);

        // Recursive method
        System.out.print("Fibonacci Series (Recursive): ");
        for (int i = 0; i < count; i++) {
            System.out.print(fibonacciRecursive(i) + " ");
        }
        System.out.println("Aum Dave");
        System.out.println("92400133058");
    }
}
