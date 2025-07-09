class Rectangle{
    Rectangle(){
        System.out.println("I am Constructor of rectangle class without parameter.");
    }
    Rectangle(int i){
        System.out.printf("I am a constructor with parameter %d.",i);
    }
    Rectangle(int a,int b){
        System.out.printf("I am Constructor with 2 parameters %d and %d.",a,b);
    }
    Rectangle(int x, int y , int z){
        System.out.printf("I am contructor with 3 paramters %d,%d and %d",x,y,z);
    }
}
public class exam_3 {
    public static void main(String[] args) {
        Rectangle A = new Rectangle(1,2,3);
    }
}
