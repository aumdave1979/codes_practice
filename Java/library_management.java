import java.util.Scanner;
import java.util.ArrayList;
class Liabrary {
    ArrayList<String> books = new ArrayList<>();
    ArrayList<String> issued = new ArrayList<>();
    Scanner sc = new Scanner(System.in);

    Liabrary() {
        System.out.println("Welcome to Aum's Liabrary");
    }

    public void addBook() {

        System.out.println("Please enter the book name u want to add");
        char add = 'y';
        do {
            books.add(sc.nextLine());
            System.out.println("Wanna add another book? press y for yes and n for no.");
            add = sc.next().charAt(0);
            if (add == 'y') {
                System.out.println("please add the book");
                sc.nextLine();
            }
        } while (add != 'n');
    }
    
    public void issuBooks() {
        showAvailable();
        System.out.println("Please select the book u want to issu.");
        String issubook = sc.next();
        if (books.contains(issubook)) {
            books.remove(issubook);
            issued.add(issubook);
            System.out.println(issubook + " is now issued to u");
        } else {
            System.out.println("This book is currently not available");
        }
    }

    public void showAvailable() {
        if (books.size() == 0) {
            System.out.println("NO books are added in the liabray");
            System.out.println("you can add books to liabray");
        } else {
            System.out.println("This are the available books sir/mam");
            System.out.println(books);
        }
    }

    public void returnBook() {
        if (issued.size() != 0) {
            issuedByYou();
            System.out.println("Which book u want to return?");
            String returnbok = sc.next();
            if (issued.contains(returnbok)) {
                issued.remove(returnbok);
                books.add(returnbok);
                System.out.println("Thanks for returning the book sir. Hope u liked the book");
            } else {
                System.out.println("This book is not from our liabray. You can't return it here.");
            }
        } else {
            System.out.println("U never issued any book sir");
        }
    }

    private void issuedByYou() {
        System.out.println("This are the books issued by u?");
        System.out.println(issued);
    }
}

public class library_management {
    public static void main(String[] args) {
       
        Scanner scn = new Scanner(System.in);
        Liabrary kushals = new Liabrary();
        kushals.addBook();
        System.out.println("Press i to issue the book\nPress s to see the avilable book\nPress r to return the book\nPress e to exit the liabrary");
        char todo = scn.next().charAt(0);
        do {
            if (todo == 'i' || todo == 'I') {
                kushals.issuBooks();
            } else if (todo == 's' || todo == 'S') {
                kushals.showAvailable();
            } else if (todo == 'r' || todo == 'R') {
                kushals.returnBook();
            }
            System.out.println("How can we help u sir");
            System.out.println(
                    "Press i to issue the book\nPress s to see the avilable book\nPress r to return the book\nPress e to exit the liabrary");
            todo = scn.next().charAt(0);
        } while (todo != 'e' && todo != 'E');
        System.out.println("Thanks for visiting our liabrary, Visit Again");
    }
}