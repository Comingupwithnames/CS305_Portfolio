/*
Title: video.c
author: Comingupwithnames
v1: 09/14/2021
creates a video object for use in a playlist array of video objects
*/

#include <stdio.h>
#include <string.h>
#include "playlist.h"
#include "video.h"

video create_video(int duration, char* name, int likes)
{
video myVideo;

    //Checks to see if the duration is greater than zero and sets it as such and sets it to 0 if it is equal to or less than 0
    if(duration>0)
    {
     myVideo.duration = duration;   
    }
    else
    {
     myVideo.duration = 0;   
    }

    //Checks to see if the number of likes is greater than zero and sets it as such and sets it to 0 if it is equal to or less than 0
    if(likes>0)
    {
     myVideo.likes = likes;
    }
    else
    {
     myVideo.likes = 0;
    }

    //Declares the name length to be MAX_NAME_LENGTH and sets each array index to the proper character
    myVideo.name[MAX_NAME_LENGTH];
    for (int i = 0; i< MAX_NAME_LENGTH; i++)
    {
     myVideo.name[i] = name[i];
    }

    //If the string length is shorter than MAX_NAME_LENGTH then it will set all the rest of the elements to spaces
    if(strlen(myVideo.name) < MAX_NAME_LENGTH)
    {
        for(int j = strlen(myVideo.name); j<MAX_NAME_LENGTH; j++)
        {
         myVideo.name[j] = ' ';
        }
    }

myVideo.name[MAX_NAME_LENGTH] = '\0'; //Sets the end of the array equal to a null character
return myVideo;
}

void print(video myVideo)
{
    double converttedDuration = (double)myVideo.duration/60.0; //Converts the duration to minutes and seconds
    printf("%.2f\t%s\t%d\n", converttedDuration, myVideo.name, myVideo.likes);
}