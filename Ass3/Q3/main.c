#include <stdio.h>
#include "car.h"
#include "stackar.h"
#include "fatal.h"
#include "stdlib.h"

int main( ){

	char Status;
	char CarLin[7];
	// Pointer to the file you want to read and write.
	FILE *fp;
	Car c1;
	c1 =  malloc( sizeof( struct CarNode ) );
	int counter = 0; //count how many car go out

	Stack S; //Stack for Garage
	Stack T; //Stack for temp

    //open file
	fp = fopen ("DataIn.txt", "r");

	if (fp == NULL)
		printf("Unable to open file."); //check if the file opened
	else
	{
		// Stack S; //Stack for Garage
		// Stack T; //Stack for temp

		S = CreateStack( 10 );			//for car park
		T = CreateStack(9);					//for temp store

		while(!feof(fp)){

			// get the number of data items of L
			fscanf (fp, "%c", &Status);

			// get the number of data items of P
			fscanf (fp, "%s\n", CarLin);

			CarLin[6]='\0';

      if('A'==Status){ //arrival, check fp
				//Please add your code here.
				if(IsFull(S)){
					//if the Garage is full, dont let them in
					printf("Sorry, no room!\n");
				}else{
				c1 = CreateCar(CarLin); //create a car
				Push(c1, S); //push the car inside
				printf("Enter Please!\n");
				}
			}

			if('D'==Status){ //depature, check fp
				//Please add your code here.
				if(CarLin == Top(S)->CarLicense){
						Pop(S); //let the car on top of the stack go out
						printf("Moved %d, bye!\n", counter);
						counter++;
				}else{
						int carPosition = Find(CarLin, S);
						for(int j = 0; j < carPosition; j++){ //put the car before it to temp stack
								Push(TopAndPop(S), T); //move the car
						}

						Pop(S); //let the car on top of the stack go out
						printf("Moved %d, bye!\n", counter);
						counter++;

						while(!IsEmpty(T)){ //put back the car
							Push(TopAndPop(T), S);
						}
						MakeEmpty(T);
				}

			}

		}

	}
	fclose(fp);

		//testing only
		// while(!IsEmpty(S)){
		// 	c1 = TopAndPop(S);
		// 	printf("%s\n", c1->CarLicense);
		// }

    return 0;
}
