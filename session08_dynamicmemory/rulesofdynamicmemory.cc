int main() {
    int a;

//    delete &a; // do not delete what was not allocated with new

   int* p = new int;        // if you allocate one....
   delete p;                // delete one

   p = new int[1000];       // if you allocate an array...
//    delete p; // implementation defined what happens
   delete [] p;             // delete an array

//   delete [] p; // DO NOT DELETE TWICE! CRASH...
   p = new int[10];
   p++;
//   delete []p; // delete the pointer you were given. CRASH

   p = new int[10]; // allocates 48 bytes (40 bytes + 8 telling the size of the block at p[-1])
   p[-1] = 99999999;
 //  delete [] p; //congratulations, we just found another HUGE block of memory to reuse (CRASH)

   p = new int[2];
   delete [] p;
   delete [] p; // don't delete twice (CRASH)
}