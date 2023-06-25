
/**
 * Main class driver to test hw0 classes
 * Other classes include: PlayList and Video that students should implement
 * 
 * CS 305, Fall 2021
 * @author Martin Cenek 
 * @version August 2021
 */
public class Main {
    public static void main(String[] args) {
        // create PlayList objects
        PlayList johnList = new PlayList(-6);  //should create a PlayList with default of size 20
        PlayList maryList = new PlayList(2);
        
        // create Videos
        Video maryPop = new Video(2145, "Mary Poppins", 775);
        Video princess = new Video(3121, "Princess Diaries", 102);
        Video frozen = new Video(1233, "Frozen", 247);
        Video rambo = new Video(6212, "Rambo", -22);
        Video fict = new Video(1234, "Pulp Fiction", 124);
        Video wind = new Video(4545, "Gone with the Wind", -1234);
        Video secr = new Video(3222, "Madam Secretary ", 13);
        Video desp = new Video(2122, "Desperatos", -505);
        Video einst = new Video(1121, "Little Einstains", 224);
        Video pony = new Video(2121, "My Little Pony", -15);
        Video flint = new Video(3424, "Flinstones", 633);
        Video simps = new Video(8000, "Simpsons", 1214);
        
        // put some Videos into PlayList
        int err = 0;
        err = johnList.addVideo(maryPop);
        err = johnList.addVideo(princess);
        err = johnList.addVideo(frozen);
        err = johnList.addVideo(rambo);
        
        // for write-up: draw picture of what johnList's Videos looks like, including any empty array cells
        
        // print PlayList
        johnList.print();
        
        // put more Videos into PlayList
        err = johnList.addVideo(fict);
        err = johnList.addVideo(fict);
        err = johnList.addVideo(wind);
        err = johnList.addVideo(secr);
        err = johnList.addVideo(desp);
        
        // print PlayList
        johnList.print();
        
        // add Videos
        err = johnList.addVideo(einst);
        err = johnList.addVideo(pony);
        
        // print PlayList
        johnList.print();
        
        // add Videos to maryList
        err = maryList.addVideo(princess);
        err = maryList.addVideo(wind);
        maryList.print();
        
        // add another Video
        err = maryList.addVideo(secr);
        
        // for write-up
        //System.out.println(maryList);
        //System.out.println(johnList);
        
        return;
    }
}
