class Payment {
    void makePayment() {
        System.out.println("Processing payment...");
    }
}

class CreditCardPayment extends Payment {
    void makePayment() {
        System.out.println("Processing Credit Card Payment...");
    }
}
class PayPalPayment extends Payment {
    void makePayment() {
        System.out.println("Processing PayPal Payment...");
    }
}

class UPIPayment extends Payment {
    void makePayment() {
        System.out.println("Processing UPI Payment...");
    }
}

public class dynamic_method_dispatch_example {
    public static void main(String[] args) {
        Payment payment; 
        

        payment = new CreditCardPayment();
        payment.makePayment();
        
        payment = new PayPalPayment();
        payment.makePayment(); 
        
        payment = new UPIPayment();
        payment.makePayment();
    }
}