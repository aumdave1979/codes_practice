abstract class Shape {
    abstract void area();
}
class Rectangle extends Shape {
    int length, breadth;
    Rectangle(int a, int b) {
        length = a;
        breadth = b;
    }
    @Override
    void area() {
        int area = length * breadth;
        System.out.printf("Area of Rectangle %d",area);
    }
}
class Square extends Shape {
    int side;
    Square(int x) {
        side = x;
    }
    @Override
    void area() {
        int area = side * side;
        System.out.printf("Area of Square %d",area);
    }
}
public class exam_5 {
    public static void main(String[] args) {
        Rectangle One = new Rectangle(5, 3);
        One.area();
        Square Two = new Square(4);
        Two.area();
    }
}
