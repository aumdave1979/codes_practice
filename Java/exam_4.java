  class Animal{
    int No_of_legs; // just to give a comman attribute
    String Type; //defines that it is a carnivore ,omnivore , herbivour for example
  }
  class Dog extends Animal{
    String Home; //just to find a comman attribute between dog and breed. It specifies whether pet or street dog
    String health; // just to find a comman attribute between dog and breed. It specifies whether handicap or not
  }
  class Breed extends Dog{
    String Breed; // which breed it is of
  }
// here Multilevel inheritance is done. we are taking the attribute of a comman animal to breed with the help of dog class
//it shows the multilvel inheritance supports in java

public class exam_4 {
    public static void main(String[] args) {
        Breed B = new Breed();
        B.No_of_legs = 4;
        B.Type = "Omnivore";
        B.Home = "Pet";
        B.health = "Handicap";
        B.Breed = "Golded Retreiver";
        System.out.println(B.Breed);
        System.out.println(B.health);
        System.out.println((B.Home));
    }
}
