/**
 * Video class that lays out the parameters for a video object
 * 
 * CS 305, Fall 2021
 * @author Comingupwithnames
 * @version September 2021
 */
public class Video
{
    //Instance variables
    private int Duration;
    private String Name;
    private int Likes;

    /**
    Constructor for the video class
     */
    public Video(int Duration, String Name, int Likes)
    {
        if(Duration<=0) //Sets the duration to the parameter provided unless it is lower than zero, then it will set it to zero
        {
            this.Duration = 0;
        }
        else
        {
            this.Duration = Duration;
            
        }
        this.Name = Name;
        if(Likes<=0) //Sets the number of likes to the parameter provided unless it is lower than zero, then it will set it to zero
        {
            this.Likes = 0;
        }
        else
        {
            this.Likes = Likes;
        }
    }

    /**
     *A method that prints out a string form of the video object
     *
     *@param None
     *@return void
     */
    public void print()
    {
        double converttedDuration = (double)Duration/60; //Converts the Duration to minutes and seconds
        System.out.print("Video ");
        System.out.printf("%.2f", converttedDuration); //Rounds the new convertted double to two decimal places
        System.out.println("\t\t" + Name + "\t" + Likes);
    }

    /**
     *A method that returns the number of likes
     *
     *@param None
     *@return int
     */
    public int getLikes()
    {
        return Likes;
    }

    /**
     *A method that returns the duration of the video
     *
     *@param None
     *@return int
     */
    public int getDuration()
    {
        return Duration;
    }

}