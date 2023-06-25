/*
Title: playlist.c
author: Comingupwithnames
v1: 09/14/2021
creates a playlist object that contains an array of video objects to be added onto or removed with the methods below
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"
#include "video.h"

//Creates a playlist with a length of the integer passed into it and corrects the integer if it is negative or 0
playlist* create_playlist(int max_vids)
{
    playlist* myVideos; 
    myVideos = (playlist*)malloc(sizeof(playlist));
    myVideos->num_videos = 0;
//Checks to see if max_vids is greater than one and sets it to the passed parameter and if not, sets it to 15 if less than or equal to 0.
    if(max_vids > 0)
    {
        myVideos->max_videos = max_vids;
    }
    if(max_vids <= 0)
    {
        myVideos->max_videos = 15;
    }

    int videoDataSize = sizeof(video); //Gets the size of the video object for memory allocation
    int num_of_videos = myVideos->max_videos;
    int forMallocPurposes = videoDataSize * num_of_videos;//Multiplies the size of the video object in bytes by the number of videos max
    myVideos->videos = (video*)malloc(forMallocPurposes);

    return myVideos;
}   

//Adds a video to the playlist if there is no duplicate already in the playlist
int add_video (playlist* myVideos, video vid)
{
    int result;//Used for strcmp

    if(myVideos->num_videos >= myVideos->max_videos)
    {
        printf("Cannot add another video to the playlist. Max playlist size exceeded\n");
        return -1;
    }
    for(int i=0; i<myVideos->num_videos;i++)
    {
        result = strcmp(myVideos->videos[i].name,vid.name);
        if(result==0)
        {
            printf("Cannot add video to playlist. Duplicate video name.\n");
            return -1;
        }
    }
    myVideos->videos[myVideos->num_videos] = vid;//Adds the video to the playlist
    myVideos->num_videos+=1;//Increments the number of videos in the list
    return 0;
}

//Shuffles the playlist using the rand() function and assigns elements at random
void shuffle(playlist* myVideos)
{
    if(myVideos->num_videos <= 0)
    {
        printf("Cannot shuffle empty playlist.\n");
    }
    for(int i = 0; i<myVideos->num_videos;i++)
    {
        video temp = myVideos->videos[i];//temporary storage for array at index i
        int randomNumber = rand()%myVideos->num_videos + 1;//Sets the modulus to the number of videos plus one to account for the shift the modulus function applies
        myVideos->videos[i] = myVideos->videos[randomNumber];
        myVideos->videos[randomNumber] = temp;
    }
}

//Removes a video if it exists in the list and prints an error message if it is not in the list or if the list size is less than or equal to zero
int delete_video(playlist* myVideos, char* videoName)
{
    int result;
    int vidNameLength = strlen (videoName);
    if(myVideos->num_videos <= 0)
    {
        printf("Video named %s not found. Playlist is empty.\n", videoName);
        return -1;
    }

    else
    {
     for(int i=0; i<myVideos->num_videos;i++)
            {
            result = strncmp(myVideos->videos[i].name,videoName,vidNameLength);//Compares to see if the two strings are the same
                if(result == 0)
                    {
                        for(int j = i; j < myVideos->num_videos-1;j++)
                        {
                            myVideos->videos[j] = myVideos->videos[j+1];//Shifts all the elements right of the index to the left
                        }
                        myVideos->num_videos--;
                        return 0;
                    }   
            }
        printf("Video named %s not found in the playlist.\n", videoName);
        return -1;
    }
    
}

//Calculates the maximum duration out of every video object in the playlist
double calc_max_duration(playlist* myVideos)
{
    double maxDuration = myVideos->videos[0].duration;

    for(int i=0; i<myVideos->num_videos;i++)
    {
        if(maxDuration<myVideos->videos[i].duration)
        {
            maxDuration = myVideos->videos[i].duration;
        }
    }
    return maxDuration/60.0;
}

//Calculates the minimum duration out of every video object in the playlist
double calc_min_duration(playlist* myVideos)
{
    double minDuration = myVideos->videos[0].duration;

    for(int i=0; i<myVideos->num_videos;i++)
    {
        if(minDuration>myVideos->videos[i].duration)
        {
            minDuration = myVideos->videos[i].duration;
        }
    }
    return minDuration/60.0;
}

//Calculates the total duration for every video object in the playlist
double calc_total_duration(playlist* myVideos)
{
   double totalDuration = 0.0;

   for(int i=0; i<myVideos->num_videos;i++)
    {
        totalDuration += myVideos->videos[i].duration;
    }
    return totalDuration/60.0;
}

//Prints the playlist object as a list of strings using the video's print function
void print_playlist(playlist* myVideos)
{
    printf("Playlist:\n");
    printf("\t duration \t name \t\t likes\n");
    for(int i=0; i<myVideos->num_videos;i++)
    {
        printf("Video ");
        print(myVideos->videos[i]);
    }
    printf("\t The total time of the playlist is: %.2f\n", calc_total_duration(myVideos));
    printf("\t The shortest video of the playlist is: %.2f\n", calc_min_duration(myVideos));
    printf("\t The longest video of the playlist is: %.2f\n\n", calc_max_duration(myVideos));
}

//Frees the arrays created by the create_playlist function
void free_playlist(playlist*myVideos)
{
    free(myVideos->videos);
    free(myVideos);
}

