#include <stdlib.h> 
#include <stdio.h> 
#include <string.h>
#include "../interview/Point.h"
  
//  리턴값이 
//  < 0 이면, _elem1이 _elem2보다 작다. 
//  = 0   이면, _elem1이 _elem2와 같다.  
//  > 0 이면, _elem1이 _elem2보다 크다.
int ComparePoint( const void *_elem1, const void *_elem2 ) 
{ 
    int* elem1 = (int*)_elem1; 
    int* elem2 = (int*)_elem2; 
 
    if ( *elem1 > *elem2) 
        return 1; 
    else if ( *elem1 < *elem2) 
        return -1; 
    else 
        return 0;     
}

int ComparePointDescend( const void *_elem1, const void *_elem2 )
{
    int* elem1 = (int*)_elem1;
    int* elem2 = (int*)_elem2;

    if ( *elem1 < *elem2)
        return 1;
    else if ( *elem1 > *elem2)
        return -1;
    else
        return 0;
}

int main( void ) 
{

    int Length = sizeof DataSet / sizeof DataSet[0];

    qsort((void*)DataSet, Length, sizeof (Point), ComparePointDescend );
    Point  eventPoint = DataSet[14141];

    printf("고객 ID %d \n",eventPoint.id);
    printf("구매포인트 %f",eventPoint.point);
    return 0;
}
