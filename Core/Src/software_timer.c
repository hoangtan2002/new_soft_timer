/*
 * software_timer.c
 *
 *  Created on: Nov 18, 2022
 *      Author: tan
 */


#include "software_timer.h"

softwareTimer Timer_array[MAX_TIMER];
static int current_timer = 0;

int isTimerSlotOccupied[MAX_TIMER] = {0,0,0,0,0,0,0,0,0,0,0};

void setTimer(int idx, int duration){
	 // keep track of array elements
	Timer_array[idx-1].counter = duration;
	Timer_array[idx-1].flag = 0;
	if(isTimerSlotOccupied[idx-1]==0){
		current_timer++;
		isTimerSlotOccupied[idx-1]=1;
	}
}


void timerRun(){
	for (int i=0; i<current_timer; i++){
		if (Timer_array[i].counter > 0){
			Timer_array[i].counter--;
			if (Timer_array[i].counter <= 0) Timer_array[i].flag = 1;
		}
	}
}

int isFlagRaised (int idx){
	if (Timer_array[idx-1].flag == 1) return 1;
	else return 0;
}
