import java.util.Scanner;

public class Assign3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Taking input from user
        System.out.print("Enter Employee ID: ");
        int empId = sc.nextInt();
        sc.nextLine();  // Consume the leftover newline

        System.out.print("Enter Employee Name: ");
        String name = sc.nextLine();

        System.out.print("Enter Employee Salary: ");
        double salary = sc.nextDouble();
        sc.nextLine();  // Consume newline

        System.out.print("Enter Department: ");
        String department = sc.nextLine();

        // Displaying employee details
        System.out.println("\n--- Employee Details ---");
        System.out.println("ID        : " + empId);
        System.out.println("Name      : " + name);
        System.out.println("Salary    : ₹" + salary);
        System.out.println("Department: " + department);
    }
}
