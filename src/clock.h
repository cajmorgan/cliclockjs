#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h> 

void colorSelection(char *color);


int clockFunc() {
  long timeref;
  time_t newSeconds;
  time(&newSeconds);
  timeref = newSeconds;
  char *seconds;
  char *minutes;
  char *hours;
  char nulseconds[4] = "0";
  char nulminutes[4] = "0";
  char nulhours[4] = "0";
  int howMany = 0;
  char colorStr[] = "\033[1;36m";

  colorSelection(colorStr);
  
  //Alloc
  seconds = (char *)malloc(sizeof(char) * 10);
  minutes = (char *)malloc(sizeof(char) * 10);
  hours = (char *)malloc(sizeof(char) * 10);

  printf("%s", colorStr);
  system("clear");

  while(1) {
    time(&newSeconds);
    howMany += 1;
    if(howMany == 4000000) {
      printf("\r%s %s %s", nulhours, nulminutes, nulseconds);
      fflush(stdout);
    }
    if(timeref != newSeconds) {
      howMany = 0;
      timeref = newSeconds;

      //Seconds
      if(timeref % 60 >= 10) {
        sprintf(seconds, "%ld", timeref % 60);
        strcpy(nulseconds, seconds);
      } else {
        sprintf(seconds, "%ld", timeref % 60);
        nulseconds[0] = '0';
        nulseconds[1] = seconds[0];
      }

      //Minutes
      if((timeref / 60) % 60 >= 10) {
        sprintf(minutes, "%ld", (timeref / 60) % 60);
        strcpy(nulminutes, minutes);
      } else {
        sprintf(minutes, "%ld", (timeref / 60) % 60);
        nulminutes[0] = '0';
        nulminutes[1] = minutes[0];
      }

      //Hours
      if((timeref / 3600) % 24 >= 10) {
        sprintf(hours, "%d", localtime(&newSeconds)->tm_hour);
        strcpy(nulhours, hours);
      } else {
        sprintf(hours, "%d", localtime(&newSeconds)->tm_hour);
        nulhours[0] = '0';
        nulhours[1] = hours[0];
      }
      printf("\r%s:%s:%s", nulhours, nulminutes, nulseconds);

      fflush(stdout);
    }
  }
  
  return 0;
}

void colorSelection(char *color) {
  char value;
  bool loop = true;
  char *colors[5] = {
    "\033[1;31m", "\033[1;32m", "\033[1;36m", "\033[1;35m", "\033[1;37m"
  };

  puts("Select color:");
  printf("%s", colors[0]);
    printf("Red - Enter \"1\"\n");
  printf("%s", colors[1]);
    printf("Green - Enter \"2\"\n");
  printf("%s", colors[2]);
    printf("Cyan - Enter \"3\"\n");
  printf("%s", colors[3]);
    printf("Purple - Enter \"4\"\n");
  printf("%s", colors[4]);
    printf("White - Enter \"5\"\n");
  printf("\033[0m");

  int printed = 0;

  while(loop) {
    scanf("%c", &value);   

    switch(value) {
      case '1': 
        strcpy(color, colors[0]);
        loop = false;
        break;
      case '2':
        strcpy(color, colors[1]);
        loop = false;
        break;
      case '3':
        strcpy(color, colors[2]);
        loop = false;
        break;
      case '4':
        strcpy(color, colors[3]);
        loop = false;
        break;
      case '5':
        strcpy(color, colors[4]);
        loop = false;
        break;
      default: {
        if(printed == 0) {
         puts("Valid number please!");
         printed += 1;
        } else {
          printed = 0;
        }
        break;
      }
    } 
  }
}