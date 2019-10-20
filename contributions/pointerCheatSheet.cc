#include <iostream>
using namespace std;


#if 0

p++;         //use it then move to the next position
*p++;        //use it then move to the next position 
*(p)++;      //use it then move to the next position

++p;         //move to the next position then use it
*++p;        //move to the next position then use it
*(++p);      //move to the next position then use it

++(*p);      //increment the value by 1 then use it
++*p;        //increment the value by 1 then use it
++*(p);      //increment the value by 1 then use it 

(*p)++;      //use it then increment the value by 1

#endif

//EXAMPLE FUNCTIONS
//example of "use it then move to the next position"
void initZero(int a[], int SIZE){
    //first set the array element that is being pointed at to 0 (use it)
    //then point to the next element of the array

    int* p = a; //pointer points to the first element of the array
    for(int i = 0; i < SIZE; i++)
        *p++ = 0;
}

void incrementArray(int a[], int SIZE){
    //first add 5 to the array element that is being pointed to (use it)
    //then point to the next element of the array
    
    int* p = a; //pointer points to the first element of the array
    for(int i = 0; i < SIZE; i++)
        *p++ += (i+5);
}

void print(int a[], int SIZE){
    //first print the array element that is being pointed to (use it)
    //then point to the next element of the array

    int* p = a; //pointer points to the first element of the array
    for(int i = 0; i < SIZE; i++)
        cout << *p++ <<'\t';
    cout << '\n';
}

//examples of "move it to the next position then use it"
void label(int a[], int SIZE){
    //first point to the next element of the array
    //then add i to the element (use it)
    int* p = a;

    for(int i = 0; i < SIZE; i++)
        *++p += (i+1);
}

void incrementValueAfter(int a[], int SIZE){
    //first point to the second element of the array
    //set the first element equal to the pointer (use it)
    //then add 1 to the value of the element being pointed to
    int* p = a;
    p++;

    for(int i = 0; i < 10; i++){
        a[0] = (*p)++;
        print(a, SIZE);
    }
}

void incrementValueBefore(int a[], int SIZE){
    //first add 1 to the first element of the array
    //then set the second element of the array eqaul to 2 times the first (use it)
    int* p = a;
    for(int i = 0; i < 10; i++){
        a[1] = ++*p * 2;
        print(a, SIZE);
    }
}

int main() {
    const int TEN = 10;
    const int TWO = 2;

    cout << "\nexample of use it then move to the next position\n";
    int w[TEN];
   
    initZero(w, TEN);
    incrementArray(w, TEN);
    print(w, TEN);

    cout << "\nexamples of move to the next position then use it\n";
    int x[TEN];

    initZero(x, TEN);
    label(x, TEN);
    print(x, TEN);

    cout << "\nexample of use it then incrememnt the value by 1\n";
    int y[TWO];
    initZero(y, TWO);
    incrementValueAfter(y, TWO);

    cout << "\nincrement the value by 1 then use it\n";
    int z[TWO];
    initZero(z,TWO);
    incrementValueBefore(z, TWO);
}