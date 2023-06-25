
/**
 * Playlist class that makes use of the video class to create an array of video objects
 * 
 * CS 305, Fall 2021
 * @author Comingupwithnames
 * @version September 2021
 */
public class PlayList 
{
    private Video[] Videos;
    private int numVideos;
    private int maxVideos;
    /**
     *A method that creates a new array of video objects called Videos
     *
     *@param maxVideos
     *@return None
     */
    public PlayList(int maxVideos) 
    {
        if(maxVideos <= 0) //Checks to see if maxVideos is less than zero and if it is, sets it to 15
        {
            this.maxVideos = 15;
        }
        else
        {
            this.maxVideos = maxVideos;
        }
        Videos = new Video[this.maxVideos];
        numVideos = 0;
    }

    /**
     *A method that adds a video object to the array of videos
     *
     *@param Video
     *@return int
     */
    public int addVideo(Video Video)
    {
        if(numVideos >= maxVideos) //Checks to see if the number of videos being added to the playlist exceed the max number allowed
        {
            System.out.println("Cannot add another video to playlist. Max size has been reached.");
            return -1;
        }
        else
        {
            Videos[numVideos]= Video;
            numVideos++;
            return 0;
        }
    }

    /**
     *A method that prints out a string form of the Videos array by printing out every video object
     *
     *@param None
     *@return void
     */
    public void print()
    {
        System.out.println("VideoList:");
        for(int i = 0; i<numVideos; i++)
        {
            Videos[i].print();
        }
        int totalDuration = 0;
        for(int i = 0; i<numVideos; i++) //Adds up all the durations and then divides them by 60 afterwards
        {
            totalDuration += Videos[i].getDuration();
        }
        double totalTime = (double) totalDuration/60;
        System.out.print("Total play time: ");
        System.out.printf("%.2f", totalTime); //Rounds totaltime to two decimal places
        System.out.println("");
        System.out.println("");
    }
}