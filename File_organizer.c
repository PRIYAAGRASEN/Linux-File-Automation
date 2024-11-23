#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

//Function to create directories if they do not exist 
void create_directory(const char *dir_name){
  struct stat st = {0};
  if(stat(dir_name , &st)== -1){
    mkdir(dir_name , 0700);
  }
}

//function to move files based on type
void move_file(const char *file, const char *destination){
  char command[256];
  snprintf(command, sizeof(command), "mv\" %s "\" "%s\"", file, destination);
  system(command);
}

//File extensions and their corresponding folders
const char *image_ext[] = {".jpg",".png",".gif",NULL};
const char *video_ext[] = {".mp4",".mkv",".avi",NULL};
const char *doc_ext[] = {".txt",".pdf",".docx",NULL};

create_directory("Images");
create_directory("Documents");
create_directory("Videos");

while((entry = readdir(dir)
