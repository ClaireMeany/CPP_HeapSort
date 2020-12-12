/*
Programmer: Claire Meany
Assignment 2
IT 279
Description:
  Reads longs from a file into an array, sorts array
  with heap sort and writes to file
*/
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <iomanip>

 using namespace std;

 void writeFile(string fileName, long arr[], int size);
 int readFile(string fileName, long arr[]);
 void heapSort(long arr[], int size);
 void buildHeap(long arr[], int size, int index);


 //reads file and creates an array
 int readFile(string fileName, long arr[]){
    ifstream readFile;
    readFile.open(fileName);
    long temp=0;
    int size=0;

    while(readFile>>temp){
      arr[size]=temp;
      size++;
    }
    return size;
 }

 void heapSort(long arr[], int size){
   long temp=0;
   for(int i = size/2-1; i>=0; i-- ){
     buildHeap(arr, size, i);
   }
   for(int i=size-1;i>=0;i--){
     temp=arr[0];
     arr[0]=arr[i];
     arr[i]=temp;
     buildHeap(arr, i, 0);
   }
 }

 void buildHeap(long arr[], int size, int index){
   int max=index;
   long temp=0;
   int left = index*2 + 1;
   int right = index*2 + 2;

   //if left is larger than root
   if(left<size && arr[left]>arr[max]){
     max=left;
   }
   //if right is larger
   if(right<size && arr[right] > arr[max]){
     max=right;
   }
   //make root the max
   if(max!=index){
     temp=arr[index];
     arr[index]=arr[max];
     arr[max]=temp;

     //buildheap for for rest
     buildHeap(arr, size, max);
   }
 }

 void writeFile(string fileName, long arr[], int size){
   ofstream file;
   file.open(fileName);

   for(int i=0;i<size;i++){
     file<<arr[i] << endl;
   }
  file.close();
 }

 int main(int argc, char** argv){

   long arr[1000000]={0};
   int size=0;

   if (argc < 3){  
       cout << "Usage: " << argv[0] /* program name */ << " infile outfile" << endl;
       exit(1);
     }
   char* fileNameInput = argv[1];
   char* fileNameOutput = argv[2];

   //read from file into array
   size=readFile(fileNameInput, arr);

   //sort array
   heapSort(arr, size);

   //print to file
   writeFile(fileNameOutput, arr, size);

   return 0;

 }
