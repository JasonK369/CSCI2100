#include <stdio.h>
#include "list.h"

// Pointer to the file you want to read and write.
FILE *fp;

// Function need to be implemented by students
void PrintLots(const List L, const List P )
{
  ElementType temp_store;
  while(!IsEmpty(P)){
    Position temp_ptr = First(L); //contain the first pointer of List L
    ElementType temp_store = Retrieve(First(P)); //contain the number in first element in List P
    //move the pointer for certain times
    for(int i = 1; i < temp_store; i++){
      temp_ptr = Advance(temp_ptr);
    }

    printf("Selected data item: %d\n", Retrieve(temp_ptr)); //print the required number
    Delete(Retrieve(First(P)), P); //Delete the first node of List P
  }

}

// Print the list
void PrintList( const List L )
{
    Position P = Header( L );

    if( IsEmpty( L ) )
        printf( "PrintEmpty\n" );
    else
    {
        do
        {
            P = Advance( P );
            printf( "%d ", Retrieve( P ) );
        } while( !IsLast( P, L ) );
        printf( "\n" );
    }
}

//to read list
void ReadList( List L, int size )
{
	//start;
	int i =0;
	Position Pt = Header( L );

	while (i<size)
	{
		int tempC;
		fscanf(fp, "%d", &tempC);
		Insert(tempC,L,Pt);
		Pt = Advance(Pt);
		//printf("%d\n",tempC);
		i++;
	}

}

int main(){
	//size of the list
	int size1 = 0, size2 = 0;

	// Linked list
    List L;
    List P;

	L = MakeEmpty( NULL );
    P = MakeEmpty( NULL );

	//open file
	fp = fopen ("DataIn.txt", "r");

    if (fp == NULL)
		printf("Unable to open file."); //check if the file opened
	else
	{
		// get the number of data items of L
		fscanf (fp, "%d", &size1);

		// get the number of data items of P
		fscanf (fp, "%d", &size2);


        if(size1<size2)
		{
			printf("Error in the sequence size!"); //check if the file opened
		}
		else
		{
			ReadList(L,size1);
			ReadList(P,size2);

			PrintList( L ); //long
			PrintList( P ); //short


            // Pritnt the list L based on P
			// Check whether there are positions larger than the size of L!!
			PrintLots(L,P);
		}

	}

	fclose(fp);

    DeleteList( L );
	DeleteList( P );

    return 0;
}
