#include <bits/stdc++.h>
using namespace std;

struct priority{
    string thing;
    int score;
};
typedef struct priority Priority;
typedef Priority * PriorityPtr;

void inputData( int *, PriorityPtr * );
void insert_max_heap( int, PriorityPtr, PriorityPtr * );
Priority delete_max_heap( int *, PriorityPtr * );

int main()
{
    int num_thing = 0;
    PriorityPtr thinglist;
    inputData( &num_thing, &thinglist );

    PriorityPtr max_heap = new Priority[ num_thing+1 ];
    insert_max_heap( num_thing, thinglist, &max_heap );

    
    int num_heap = num_thing;
    Priority item;
  	cout << "First three things to do:" << endl;
    for ( int i = 0 ; i < 3 && i <= num_thing-1 ; i++ )
    {
        item = delete_max_heap( &num_heap, &max_heap );
        cout << item.thing << endl;
    }

    return 0;
}

void inputData( int *num, PriorityPtr *thinglist )
{
    cin >> *num;
    *thinglist = new Priority[ *num ];
    for ( int i = 0 ; i < *num ; i++ )
        cin >> (*thinglist)[i].thing >> (*thinglist)[i].score;
}

void insert_max_heap( int num, PriorityPtr thinglist, PriorityPtr *heap )
{
    int total = 0;
    int j;

    for ( int i = 0 ; i < num ; i++ )
    {
        j = ++total;
        while( (j != 1) && (thinglist[i].score > (*heap)[j/2].score) )
        {
            (*heap)[j] = (*heap)[j/2];
            j /= 2;
        }
        (*heap)[j] = thinglist[i];
    }
}

Priority delete_max_heap( int *num, PriorityPtr *heap )
{
    Priority item; 
    Priority temp;
    int parent, child;

    item = (*heap)[1];

    temp = (*heap)[(*num)--];
    parent = 1;
    child = 2;

    while ( child <= (*num) )
    {
        if ( child < (*num) && (*heap)[child].score < (*heap)[child+1].score )
            child++;
        if ( temp.score >= (*heap)[child].score )
            break;

        (*heap)[parent] = (*heap)[child];
        parent = child;
        child *= 2;
    }

    (*heap)[parent] = temp;
    return item;
}