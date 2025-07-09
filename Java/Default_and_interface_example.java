interface Camera{
    void take_snap();
    void record_video();
    default void recording4K_video(){
        System.out.println("recording in 4k..");
    }
}

interface wifi  {
    String[] get_networks();
    void connect_to_networks(String network);
}

class myphone{
    void callnumber(int number){
        System.out.println("calling: "+number);
    }
    void pickcall(){
        System.out.println("connecting");
    }
}
class SmartPhone extends myphone implements wifi,Camera{
   public void take_snap(){
        System.out.println("Taking snap");
    }
    public void record_video(){
        System.out.println("recording video");
    }
    public void recording4K_video(){
        System.out.println("video in 4k");
    }
    public String[] get_networks() {
        System.out.println("Getting list of networks: ");
        String[] networkList = {"Aum","Viraj","Krisha"};
        return networkList;
    }
    public void connect_to_networks(String network){
        System.out.println("Connecting to " + network);
    }
}



public class Default_and_interface_example{
    public static void main(String[] args) {
        SmartPhone Aum = new SmartPhone(); 
        Aum.recording4K_video();
        String[] list = Aum.get_networks();
        for (String item: list) {
            System.out.println(item);
        }
    }
}