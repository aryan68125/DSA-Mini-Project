#include<stdio.h>
#include<stdlib.h> //if you are going to build a program on a linked list then this library is needed include it in your program before anything else

// functions for 1D Array Operations
//The 1D array is created in heap instead of the stack
//this will allow us to enter the size of the array during runtime

void createArray();
void displayArray();
void sortArrayAcending();
void sortArrayDecending();
void insertAscendSort();
void insertDescendSort();
void insertArray();
void rotateArray();
void ReverseArray();
void setArray();
void AvgArray();
void sumArray();
void miniArray();
void maxArray();
void BinarySearchArray();
void LinearSearchArray();
void deleteArray();
void MergeArray();
void displayArrayTwo();
void CreateArrayTwo();

int *arr;
int size;
int length;

int *brr;
int lengthb;
int sizeb;

int *crr;
int lengthc=0;
int sizec;

void createArray() //containing the logic for creaton of array with ability to enter the size dynamically during runtime
{

printf("Enter the size of an array\n");
scanf("%d",&size);
printf("Enter the number of elements you want to insert in the array\n");
scanf("%d",&length);
arr=(int*)malloc(size*sizeof(int));  //main array
brr=(int*)malloc(size*sizeof(int)); //temporary array
lengthb=length;
if (length<=size)
{
printf("Enter the elements inside the array\n");
for(int i=0;i<length;i++)
{
  scanf("%d",&arr[i]);
}

int free = size - length;
printf("Free space in array is %d\n",free);
}
if(length>size)
{
    printf("Array creation Failed!!!!\n");
    printf("Number of elements you want to enter is more than the size of the array\n");
    printf("array size =%d\n", size);
    printf("number of elements to be entered inside the array = %d\n",length);
}
}

void displayArray() //display Array function
{

printf("Printing the array elements\n");
for(int i=0;i<length;i++)
{
  printf("A[%d] = %d\n",i,arr[i]);
}

}

void sortArrayAcending()
{
  int temp;
  for(int i=0;i<length-1;i++)
  {
    for(int j=i+1;j<length;j++)
    {
      if(arr[j]<arr[i]) //sorting array in ascending order
      {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
      }
    }
  }
  printf("Sorting in ascending order complete!\n");
}

void sortArrayDecending()
{
  int temp;
  for(int i=0;i<length-1;i++)
  {
    for(int j=i+1;j<length;j++)
    {
      if(arr[j]>arr[i]) //sorting array in descending order
      {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
      }
    }
  }
  printf("Sorting in descending order complete!\n");
}

void insertAscendSort() //this function will only insert the element if the array is sorted in ascending order
{
  int num;
  printf("Use this option only after you sort the array in ascending order!!!!\n");
  printf("Enter the number you want to enter inside the sorted array\n");
  scanf("%d",&num);
  int i= length-1;
  if(length == size)
  {
    printf("there is no free space in the array\n");
    printf("Insertion failed!!!!\n");
  }
  else
  {
        while(i>=0 && arr[i]>num) //shifting elements inside the array to create free space for the new element
        {
          arr[i+1]=arr[i];
          i--;
        }
        arr[i+1]=num; //inserting the element inside the free space created after shifting
        length++;
        int free=size-length;
        printf("Free space in array is %d \n",free);

  }
  int free = size - length;
  printf("Insertion without distortion Successful\n");
  printf("free space left inside the array = %d\n",free);
}

void insertDescendSort() //this function will only insert the element if the array is sorted in descending order
{
  int num;
  printf("Use this option only after you sort the array in descending order!!!!\n");
  printf("Enter the number you want to enter inside the sorted array\n");
  scanf("%d",&num);
  int i= length-1;
  if(length == size)
  {
    printf("there is no free space in the array\n");
    printf("Insertion failed!!!!\n");
  }
  else
  {
        while(i>=0 && arr[i]<num) //shifting elements inside the array to create free space for the new element
        {
          arr[i+1]=arr[i];
          i--;
        }
        arr[i+1]=num; //inserting the element inside the free space created after shifting
        length++;
        int free=size-length;
        printf("Free space in array is %d \n",free);

  }
  int free = size - length;
  printf("Insertion without distortion Successful\n");
  printf("free space left inside the array = %d\n",free);
}

void insertArray() //this function will insert the element inside the array at the position givent by the user
{

  int pos; //it will hold the position at which we want to insert the element inside the array
  int i; //loop variable
  int num; //the element you want to insert inside of an array
  int free; //it will store the free space present inside the array to store new elements
  printf("Enter the element you want to insert inside of the array\n");
  scanf("%d",&num);
  printf("Enter the position at which you want to insert the element in the array\n");
  scanf("%d",&pos);
  printf("You want to enter element %d at position %d in the array\n",num,pos);
    if(pos>size)
    {
      printf("The desired position %d does not exist in the array......\n",pos);
      printf("Insertion of element %d FAILED!!!!!......\n",num);
      return;
    }

    if(length!=size)
    {
         for(i=length;i>pos;i--)
         {
          arr[i]=arr[i-1]; //it will shift the elements from the last to the desired position by one index
         }
         arr[pos]=num; //Inserting the element inside the desired position of the array after shifting all the elements of the array 
         length++; //updating the length of the array
         printf("Insertion of element %d is Successfull!!!!!!!!........\n",num);
         
       free = size - length; //calculation of free space present inside of an array
       printf("Available space inside the array for new element is %d\n",free);
       return;
    }
    else
    {
      printf("Cannot Insert the new element %d inside the array because there is no free space\n", num);
      printf("Maximum array capacity reached!!!!...\n");
      printf("Array Capacity = %d\n",size);
      return;
    }
}

void deleteArray() //this function will delete the element from the array
{

   int num; //number that you want to delete from the array
   int i; //loop variable for linear search
   int tr=0; // this variable will store true or false value of the state wheater the element is present or not
   int j; //loop variable for shifting mechanism of the elements inside the array
   int free; //it will store the free space present inside the array to store new elements

   printf("Enter the number you want to Delete from the array\n"); //Entering the number that is to be deleted 
   scanf("%d",&num);

   printf("Searching for %d in the array....\n", num);
   for(i=0;i<length;i++)
   {
    if(num==arr[i])
    {  
      tr=1;
      break;
    }
   }

   if (tr==1)
   {
    printf("Element %d is in position %d inside the array\n", num,i);
    printf("Deleting element %d from position %d in the array........\n",num,i);
    //Applying linear search operation in the array in order to find the element and delete it from the array
   //Linear search is applied here becoz it works on sorted or unsorted array
    for(j=i;j<length-1;j++)
    {
      arr[j]=arr[j+1]; //it will shift the elements from the last to the desired position by one index
    }
    length--; //updating array length
    free = size - length; //calculation of free space present inside of an array
    printf("Available space inside the array for new element is %d\n",free);
    printf("Deletion operation successfull!!!!!!!!!.........\n");
   }
   else if(length==0)
   {
    printf("The array is empty........\n");
   }
   else
   {
    printf("Element %d is not present inside the array\n",num);
    printf("Deletion operation FAILED!!!!!!......\n");
   }
}

void LinearSearchArray()
{
  int num; //number that you want to search
  int i; //Linear search loop variable
  int tr=0; //boolean variable
  printf("Enter the number that you want to search inside the array\n");
  scanf("%d",&num);
  printf("Searching for %d in the array....\n", num);
   for(i=0;i<length;i++)
   {
    if(num==arr[i])
    {  
      tr=1; //boolean variable
      break;
    }
   }
   if(tr==1)
   {
    printf("The element %d is stored in position %d inside of the array\n",num,i);
    printf("Linear search Successfull !!!!!......\n");
   }
   else
   {
    printf("The element %d is not present inside the array\n", num);
    printf("Linear search FAILED!!!!!!!!.......\n");
   }
}

void BinarySearchArray()
{
  int num; //number that you want to search inside the array

    printf("Enter the number that you want to search inside the array\n");
    scanf("%d",&num);

  for(int i=0;i<length;i++)
  {
    brr[i]=arr[i]; //copying the elements from a array to b array
  }
  int tempo; // temporary variable that is used in swapping of elements
  for(int i=1;i<lengthb;i++)  //Bubble sorting the temporary array in ascending order
  {
    for(int j=0;j<lengthb-1;j++)
    {
      if(brr[j]>brr[i]) //this logic will sort the array in ascending order
      {// swapping logic 
        tempo=brr[j];
        brr[j]=brr[i];
        brr[i]=tempo;
      }
    }
  }

    //printing the sorted array 
    printf("Sorting the array before performing binary search.......\n");
    for(int i=0;i<lengthb;i++)
    {
      printf("%d\n",brr[i]);
    }
    
  //now we can apply binary search on the temporary array 
  int low=0; //lower bound
  int high=lengthb; //higher bound
  int mid;
  int key; //key will store mid if the num is found inside the array
  while (low<=high) // condition for the loop
  {
        mid = (low+high)/2;
        if(num == brr[mid])
        {
          key=brr[mid];
          break;
        }
        else if(num<brr[mid])
        {
          high=mid-1;
        }
        else
        {
          low=mid+1;
        }
  }

  if(key==num)
  {
        printf("The element %d is found in array\n",num);
        printf("Binary search Successfull!!!!.....\n");
    }
    else 
    {
      printf("The element %d is not present in the array\n",num);
      printf("Binary Search FAILED!!!!!.....\n");
    }
}

void maxArray() // to find th max value in the array
{

   int minimum = -32768;  //minimum value supported by integer data type
   for(int i=0;i<length;i++)
   {
    if (arr[i]>minimum)
    {

         minimum = arr[i];

    }
   }
   printf("Maximum value present inside the array is = %d\n",minimum);
  
}

void miniArray() //to find the minimum value in the array
{
  int maximum = 32768;  //minimum value supported by integer data type
   for(int i=0;i<length;i++)
   {
    if (arr[i]<maximum)
    {

         maximum = arr[i];

    }
   }
   printf("Maximum value present inside the array is = %d\n",maximum);
}

void sumArray() //it will find the sum of all elements present inside the array
{
  int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<length;i++)
   {
       sum=sum+arr[i];
   }
   printf("Sum of all the elements present in the array is %d\n",sum);
}

void AvgArray() //it will find the average of all the elements present inside the array
{
  int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<length;i++)
   {
       sum=sum+arr[i];
   }
   int avg;
   avg= sum/length;
   printf("The average of all the elements present inside the array is %d\n",avg);
}

void setArray() //it will replace the elements at a desired position in the array
{
   int num; //number that you want to set
   int pos;//position at which you want to set the number inside the array
   printf("Enter the number you want to set inside the array\n");
   scanf("%d",&num);
   printf("Enter the position at which you want to set the number in the array\n");
   scanf("%d",&pos);
   if(pos>0 && pos<=length) //Logic to check whether the position entered by the user is valid or not
   {
    printf("the Entered position is Valid......\n");
    printf("setting the %d inside the array at %d position\n",num,pos);
    arr[pos-1]=num;
   }
   else
   {
    printf("the Entered position is not valid\n");
    printf("setting up number %d inside the array FAILED!!!!....\n",num);
   }
}

void ReverseArray() //this function will reverse the elements inside the array and then save it inside the original array
{
  
  int j = length; //it will store the length of the array
                      //by doing that we will be able to get the last position of the element in the array
  for(int i=0;i<length;i++)
  {
    brr[j-1]=arr[i]; //copying the elements inside the temporary array in reverse order
    j--;
  }
    for(int i=0;i<length;i++)
    {
      arr[i]=brr[i]; //copying the temp array inside the original array A 
    }
    printf("elements Reversal inside the array is Successful!!!...\n");
}

void rotateArray() //this function will rotate the elements inside the array
{

   int tempo; //temporary variable that will hold the element inside the array at 0th position temporaily
              //as in this operation we will be shifting the elements inside the array forward by one position
              //and in doing so we will loose the first element so inorder to prevent it. It is crucial to take the backup of the first element inside the array
   tempo = arr[0];
   int j;
   for(int i=0;i<length;i++)
   {
    j=i+1;
    arr[i] = arr[j];    //logic for shifting of elements inside the array forward by one position
    j++;
   }

   arr[length-1]=tempo; //now copying the element that used to be at the 0th positon in the array to the last position in the array
   printf("Rotation of array elements SUCESSFUL!!!!!.....\n");

}

//from here on out functions of binary operations on array starts

void CreateArrayTwo() //this function will merge the elements of arrayA and arrayB in ascending order in ArrayC
{
  //creation of Array A
 printf("Enter the size of Array A\n");
 scanf("%d",&size);
 printf("Enter the number of elements you want to insert in Array A\n");
 scanf("%d",&length);
 arr=(int*)malloc(size*sizeof(int));  //Array A
 if (length<=size)
 {
  printf("Enter the elements inside Array A\n");
  for(int i=0;i<length;i++)
 {
  scanf("%d",&arr[i]);
 }

  int freeA = size - length;
  printf("Free space in Array A is %d\n",freeA);
 }
  if(length>size)
  {
    printf("Array A creation Failed!!!!\n");
    printf("Number of elements you want to enter is more than the size of Array A\n");
    printf("Array A size =%d\n", size);
    printf("number of elements to be entered inside Array A = %d\n",length);
  }

  //creation of Array B
 printf("Enter the size of Array B\n");
 scanf("%d",&sizeb);
 printf("Enter the number of elements you want to insert in Array B\n");
 scanf("%d",&lengthb);
 brr=(int*)malloc(sizeb*sizeof(int));  //Array B
 if (lengthb<=sizeb)
 {
  printf("Enter the elements inside Array B\n");
  for(int i=0;i<lengthb;i++)
 {
  scanf("%d",&brr[i]);
 }

  int freeB = sizeb - lengthb;
  printf("Free space in Array B is %d\n",freeB);
 }
  if(lengthb>sizeb)
  {
    printf("Array B creation Failed!!!!\n");
    printf("Number of elements you want to enter is more than the size of Array B\n");
    printf("Array B size =%d\n", sizeb);
    printf("number of elements to be entered inside Array B = %d\n",lengthb);
  }

  //creation of Array C
 crr=(int*)malloc(sizec*sizeof(int));  //Array C
 sizec = size + sizeb;
 lengthc=0;

}

void displayArrayTwo()
{
  printf("Printing Array A\n");
  for(int i=0;i<length;i++)
  {
    printf("A[%d] = %d\n",i,arr[i]);
  }
  printf("Printing Array B\n");
  for(int j=0;j<lengthb;j++)
  {
    printf("B[%d] = %d\n",j,brr[j]);
  }
  if(lengthc == 0)
  {
    printf("Array C is empty\n");
  }
  else
  {
    printf("Printing Array C\n");
    for(int k=0;k<lengthc;k++)
  {
    printf("C[%d] = %d\n",k,crr[k]);
  }
  }
}

void MergeArray()
{
   int i; //for Traversing array A
   int j; //for traversing Array B
   int k=0; //for traversing Array C
   while(i<length && j<lengthb)
   {
    if(arr[i]<brr[j])
    {
      crr[k]=arr[i];
      k++;
      i++;
    }
    else
    {
      crr[k]=brr[j];
      k++;
      j++;
    }
   }
   //for entering the remaining elements inside the Array C
   for(;i<length;i++)
   {
    crr[k]=arr[i];
    k++;
   }
   for(;j<lengthb;j++)
   {
    crr[k]=brr[j];
    k++;
   }
  lengthc = length + lengthb;
  printf("Merging of Array A and Array B Successfull!!!!\n");
}

//1D array operation functions end here


//functions for 2D Array Operations
int inputa(int a[10][10] , int row, int column)
{
    printf("input elements of mairix a\n");
    for(int i=0;i<row;i++)
    {
    for(int j=0;j<column;j++)
    {
    scanf("%d", &a[i][j]);
    }
    }
    return 0;
}// inputa closed

int inputb(int b[10][10] , int row, int column)
{
    printf("\ninput elements of mairix b\n");
    for(int i=0;i<row;i++)
    {
    for(int j=0;j<column;j++)
    {
    scanf("%d", &b[i][j]);
    }
    }
    return 0;
}// inputb closed

int displaya(int a[10][10], int row, int column)
{
    printf("\ndisplaying elements of mairix a\n");
    for(int i=0;i<row;i++)
    {
    for(int j=0;j<column;j++)
    {
    printf("%d \t\t", a[i][j]);
    }
    printf("\n");
    }
  return 0;
} //displaya closed

int displayb(int b[10][10] , int row, int column)
{
    printf("\ndisplaying elements of mairix b\n");
    for(int i=0;i<row;i++)
    {
    for(int j=0;j<column;j++)
    {
    printf("%d \t\t", b[i][j]);
    }
    printf("\n");
    }
   return 0;
}//displayb closed

int sumOfTwoArray(int a[10][10] , int b[10][10] , int res[10][10], int row, int column)
{

for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        res[i][j]=a[i][j] + b[i][j];
    }
}

for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        printf("%d \t\t", res[i][j]);
    }
    printf("\n");
}
 return 0;
} //sumOdTwoArray closed

int subtractionOfTwoArray(int a[10][10] , int b[10][10] , int res[10][10], int row, int column)
{

for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        res[i][j]=a[i][j] - b[i][j];
    }
}

for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        printf("%d \t\t", res[i][j]);
    }
    printf("\n");
}
 return 0;
}//subtractionOfTwoArray closed

int MultiplyTwoArray(int a[10][10] , int b[10][10] , int res[10][10], int row, int column, int row1, int column1)
{

    int i, j, k;
    for(i =0;i<row;i++) //row of matrix a
    {
        for(j=0;j<column1;j++) //column of matrix b
        {
            for(k=0;k<column;k++) //column of matrix a
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i=0;i<row;i++) //row of matrix a
{
    for(int j=0;j<column1;j++) //column of matrix b
    {
        printf("%d \t\t", res[i][j]);
    }
    printf("\n");
}

return 0;
}

int transposeA(int a[10][10] ,int transA[10][10], int row, int column)
{

for(int i=0;i<row;i++)
{
    for(int j=0;j<column;j++)
    {
        transA[j][i] = a[i][j];
    }
}

printf("\nTranspose of Matrix A\n");
for(int i=0;i<column;i++)
{
    for(int j=0;j<row;j++)
    {
        printf("%d \t\t", transA[i][j]);
    }
    printf("\n");
}
return 0;
}//transposeA closed

int transposeB(int b[10][10] ,int transB[10][10], int row1, int column1)
{

for(int i=0;i<row1;i++)
{
    for(int j=0;j<column1;j++)
    {
        transB[j][i] = b[i][j];
    }
}

printf("\nTranspose of Matrix B\n");
for(int i=0;i<column1;i++)
{
    for(int j=0;j<row1;j++)
    {
        printf("%d \t\t", transB[i][j]);
    }
    printf("\n");
}
return 0;
}//transposeB closed

//.......................functions of Singly Linked List operation........................
void createOne();
void displayOne();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void reverse();
void SumOfAllSinglyLL();
void GreatestSinglyLinkedList();
void SmallestSinglyLinkedList();

struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;

void createOne()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\n");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void displayOne()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d\n",ptr->info );
                        ptr=ptr->next ;
                }
        }
}

void reverse()
{
        struct node * prevnode, * currentnode, * nextnode;
        prevnode=NULL;
        currentnode = nextnode = start;
        while(nextnode != NULL)
        {
                nextnode = nextnode->next; //updating next node pointer to point to the next node
                currentnode->next = prevnode;
                prevnode = currentnode;
                currentnode = nextnode;
        }
        start = prevnode;
}

int count()
{
        struct node * ptr;
       ptr = start;
       int count = 0;
       if(start==NULL)
       {
        printf("\nList is Empty\n");
        printf("\n");
        return 0;
       }
       else
       {
       while(ptr!=NULL)
       {
        count++;
        ptr = ptr->next;
       }
       return count;
}

}

void SumOfAllSinglyLL()
{
   int sum; //to store the sum of all the elements present inside the Linked List
   struct node *ptr;
   ptr = start;
   if(start == NULL)
   {
    printf("\nList is empty\n");
   }
   else
   {
    while(ptr!=NULL)
    {
      sum = sum + ptr->info;
      ptr=ptr->next;
    }
   }
   printf("Sum of all the elements present inside the Singly Linked List is %d\n",sum);

}

void GreatestSinglyLinkedList()
{
   int max = -32768; //-32768 is the minimum integer value that is there in int data type
                     //we will compare all the elements inside the linked list with this max variable to find out the maximum value present inside the linked list
   struct node *ptr;
   ptr=start;
   if(start==NULL)
   {
    printf("\nList is empity\n");
   }
   else
   {
    while(ptr!=NULL)
    {
      if(ptr->info>max)
      {
        max=ptr->info;
      }
      ptr=ptr->next;
    }
   }
   printf("The maximum value present inside the Linked List is %d\n",max);
}

void SmallestSinglyLinkedList()
{
   int mini = 32768; //32768 is the max integer value that is there in int data type
                     //we will compare all the elements inside the linked list with this mini variable to find out the minimum value present inside the linked list
   struct node *ptr;
   ptr=start;
   if(start==NULL)
   {
    printf("\nList is empity\n");
   }
   else
   {
    while(ptr!=NULL)
    {
      if(ptr->info<mini)
      {
        mini=ptr->info;
      }
      ptr=ptr->next;
    }
   }
   printf("The minimum value present inside the Linked List is %d\n",mini);
}

void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\n" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}

void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\n" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}

void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        int c; //to store the Number of nodes in the Singly Linked List
        c=count();
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\n");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\n");
        scanf("%d",&temp->info) ;
  
        temp->next=NULL;
        if(pos==1)
        {

                if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }

        }

        else if(pos == c)
        {

            if(start==NULL)
        {
                start=temp;
        }

        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }

        }
        else
        {
                for(i=1,ptr=start;i<pos-1;i++) 
                { 
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void delete_begin()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\n",ptr->info);
                free(ptr);
        }
}

void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:\n");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d\n",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\n",ptr->info);
                free(ptr);
        }
}

void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        int c=count(); //stores the number of node in Singly Linked List
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\n");
                scanf("%d",&pos);
                if(pos==1)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\n",ptr->info  );
                        free(ptr);
                }

               else if(pos==c)
                {
                    if(start->next ==NULL)
                    {
                       ptr=start;
                       start=NULL;
                       printf("\nThe deleted element is:%d\n",ptr->info);
                       free(ptr);
                    }
                    else
                    {
                       ptr=start;
                       while(ptr->next!=NULL)
                       {
                        temp=ptr;
                        ptr=ptr->next;
                       }
                        temp->next=NULL;
                        printf("\nThe deleted element is:%d\n",ptr->info);
                        free(ptr);
                    }
                }    

                else
                {
                        ptr=start;
                        for(i=0;i<pos-1;i++) 
                        { temp=ptr; 
                          ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\n",ptr->info );
                        free(ptr);
                }
        }
} 

//singly Linked List Ends here..........................................................

//Functions of Doubly Linked List
void create_DoublyLinkedList();
 void Display_DoublyLinkedList();
 void Insert_begin__DoublyLinkedList();
 void Insert_End__DoublyLinkedList();
 void Insert_Pos__DoublyLinkedList();
 void Delete_Begin_DoublyLinkedList();
 void Delete_End_DoublyLinkedList();
 void Delete_POS_DoublyLinkedList();

 struct node_two
 {
    int info_two;
    struct node_two* next_two;
    struct node_two* prev_two;
};
struct node_two *start_two = NULL;
struct node_two *tail_two = NULL;

void create_DoublyLinkedList()
{
    struct node_two *ptr_two;
    struct node_two *temp_two;
    temp_two= (struct node_two*)malloc(sizeof(struct node_two));
    if(temp_two == NULL)
    {
        printf("Out of memory \n");
    }

    printf("Enter the data in newly created node\n");
    scanf("%d",&temp_two->info_two);
    temp_two->next_two=NULL;
    temp_two->prev_two=NULL;
    printf("\n");

    if(start_two==NULL)
    {
        start_two = temp_two;
        tail_two = temp_two;
    }
    else
    {   
        tail_two->next_two=temp_two;
        temp_two->prev_two=tail_two;
        tail_two=temp_two;
    }
}

void Display_DoublyLinkedList()
{
    struct node_two *ptr_two;
    if(start_two == NULL)
    {
        printf("The Doubly Linked List is Empity\n");
        printf("\n");
    }
    else
    {
        ptr_two=start_two;
        while(ptr_two!=NULL)
        {
            printf("%d\n",ptr_two->info_two);
            ptr_two=ptr_two->next_two;
        }

    }
}

void Insert_begin__DoublyLinkedList()
{
struct node_two *temp_two;
temp_two = (struct node_two*)malloc(sizeof(struct node_two));
if(temp_two==NULL)
{
    printf("Out of memory\n");
}

printf("Enter the data in newly created node\n");
    scanf("%d",&temp_two->info_two);
    temp_two->next_two=NULL;
    temp_two->prev_two=NULL;
printf("Inserting the newly created node at the beginning of the Doubly Linked list\n");
    printf("\n");

    if(start_two==NULL)
    {
        start_two = temp_two;
        tail_two = temp_two;
    }
    else
    {   
        temp_two->next_two=start_two;
        start_two->prev_two=temp_two;
        start_two=temp_two;
    }

}

void Insert_End__DoublyLinkedList()
{
struct node_two *temp_two;
temp_two = (struct node_two*)malloc(sizeof(struct node_two));
if(temp_two==NULL)
{
    printf("Out of memory\n");
}

printf("Enter the data in newly created node\n");
    scanf("%d",&temp_two->info_two);
    temp_two->next_two=NULL;
    temp_two->prev_two=NULL;
    printf("Inserting the newly created node at the ending of the Doubly Linked list\n");
    printf("\n");

    if(start_two==NULL)
    {
        start_two = temp_two;
        tail_two = temp_two;
    }
    else
    {   
        tail_two->next_two=temp_two;
        temp_two->prev_two=tail_two;
        tail_two=temp_two;
    }

}

int lengthDoublyLinkedList()
{
struct node_two *ptr_two;
int count=0;
if(start_two==NULL)
{
    printf("The Doubly Linked List is Empity\n");
        printf("\n");
    return 0;
}
else
{
    ptr_two=start_two;
    while(ptr_two!=NULL)
    {
        count++;
        ptr_two=ptr_two->next_two;
    }
    return count;
}
}

void Insert_Pos__DoublyLinkedList()
{
struct node_two *temp_two;
struct node_two *ptr_two;
int i; //loop variable
int pos; //position at which the newly created node is tobe inserted
int c; //stores the number of nodes in a doubly linked list
temp_two = (struct node_two*)malloc(sizeof(struct node_two));
c=lengthDoublyLinkedList();

if(temp_two==NULL)
{
    printf("Out of memory\n");
}

printf("Enter the position at which the newly created node is to be inserted\n");
scanf("%d",&pos);
printf("Enter the data in newly created node\n");
    scanf("%d",&temp_two->info_two);
    temp_two->next_two=NULL;
    temp_two->prev_two=NULL;
printf("Inserting the newly created node at the position specified by the user in the Doubly Linked list\n");
    printf("\n");

if(pos < 1 || pos > c)
{
    printf("Invalid Position Entered by the user\n");
    printf("\n");
}
else if(pos == 1)
{
    if(start_two==NULL)
    {
        start_two = temp_two;
        tail_two = temp_two;
    }
    else
    {   
        temp_two->next_two=start_two;
        start_two->prev_two=temp_two;
        start_two=temp_two;
    }
}
else if(pos==c)
{
    if(start_two==NULL)
    {
        start_two = temp_two;
        tail_two = temp_two;
    }
    else
    {   
        tail_two->next_two=temp_two;
        temp_two->prev_two=tail_two;
        tail_two=temp_two;
    }
}
else
{
    ptr_two = start_two;
    for(i=1;i<pos-1;i++)
    {
        ptr_two=ptr_two->next_two;
    }
    temp_two->prev_two=ptr_two;
    temp_two->next_two=ptr_two->next_two;
    ptr_two->next_two=temp_two;
    temp_two->next_two->prev_two=temp_two;
}

}

void Delete_Begin_DoublyLinkedList()
{
    struct node_two* ptr_two; //ptr pointer
    if(start_two==NULL)
    {
        printf("The Doubly Linked List is Empity\n");
        printf("\n");
    }
    else
    {
        ptr_two=start_two;
        start_two=start_two->next_two;
        start_two->prev_two=NULL;
        ptr_two->next_two=NULL;
        free(ptr_two);
    }
}

void Delete_End_DoublyLinkedList()
{
    struct node_two* ptr_two; //ptr pointer
    if(start_two==NULL)
    {
        printf("The Doubly Linked List is Empity\n");
        printf("\n");
    }
    else
    {
        ptr_two=tail_two;
        tail_two=tail_two->prev_two;
        tail_two->next_two=NULL;
        ptr_two->prev_two=NULL;
        free(ptr_two);
    }
}

void Delete_POS_DoublyLinkedList()
{
 struct node_two* ptr_two; //ptr pointer
 int i; //while loop variable
 int c; // variable to store the length of a doubly linked list
 c=lengthDoublyLinkedList();
 int pos; //position of the node that you want to delete
 printf("Enter the position of the node that you want to delete from the doubly Linked List\n");
 scanf("%d",&pos);
 printf("\n");
    if(start_two==NULL)
    {
        printf("The Doubly Linked List is Empity\n");
        printf("\n");
    }
    if(pos <1 || pos >c)
    {
        printf("The Position entered by the user is Invalid\n");
        printf("\n");
    }
    else if(pos==1)  //logic of deleting first node
    {
        ptr_two=start_two;
        start_two=start_two->next_two;
        start_two->prev_two=NULL;
        ptr_two->next_two=NULL;
        free(ptr_two);
    }
    else if(pos==c) //logic for deletion at the end
    {
        ptr_two=tail_two;
        tail_two=tail_two->prev_two;
        tail_two->next_two=NULL;
        ptr_two->prev_two=NULL;
        free(ptr_two);
    }
    else
    {
        ptr_two=start_two;
        while(i<pos-1)
        {
            ptr_two=ptr_two->next_two;
            i++;
        }
        ptr_two->prev_two->next_two=ptr_two->next_two;
        ptr_two->next_two->prev_two=ptr_two->prev_two;
        ptr_two->next_two=NULL;
        ptr_two->prev_two=NULL;
        free(ptr_two);
    }
}

int main()
{
//variables related to 1D Array Operations
    int key; //choice for menue switch case
    int O=0; // menue loop variable
    int choice15;//choice variable for menue of Binary operations on array
    int Q=0;//do while loop variable for 
//variables relayed to 2D Array operations
int a[10][10];
    int b[10][10];

    int res[10][10]; //to store result
    int transA[10][10]; //to store transpose of matrix A
    int transB[10][10]; //to store transpose of matrix B
    
    int row;    //for matrix a
    int column;

    int row1;
    int column1; //for matrix b

    int choice ;
 
 //Menue variable
    int u = 0; //menue loop variable

    //variables for main menue loop
    int menue; //choice variable main menue between 1D and 2D array operations 

    int g=0; //variable of main menue loop

//variables of Singly Linked List
    int choose; //choice variable for Linked List Menue

    int A; //Loop variable for Linked List

    int c; //to store the number of nodes present in the Singly Linked List

//variables of Doubly Linked List
    int T=0; //menue variable of the doubly linked list
    int c2=0; //to store the number of nodes in a doubly linked list
    int choice3; //menue choice variable for doubly linked list menue

//main menue loop
do{
    
printf("\n               MENUE                \n");
printf("Press 1 to perform 1D Array operations\n");
printf("Press 2 to perform 2D Array operations\n");
printf("Press 3 to perform Singly Linked List operations\n");
printf("Press 4 to perform Doubly Linked List operations\n");
printf("Press 5 to exit program\n");
scanf("%d", &menue);
printf("\n");
switch(menue)
{
case 1:
printf("you chose 1D Array operations \n");
printf("initializing 1D Array operations program\n");
printf("\n");
// menue loop for 1D Array
//....................................................................................
  
  do
  {
    printf("---------------------------Menue--------------------------------\n");
    printf("Press 1 to Create the Array\n");
    printf("Press 2 to Display the Array\n");
    printf("Press 3 to sort the array in ascending array\n");
    printf("Press 4 to sort the array in descending array\n");
    printf("Press 5 to insert the element inside the sorted array in ascending without distorting the element sequence\n");
    printf("Press 6 to insert the element inside the sorted array in descending without distorting the element sequence\n");
    printf("Press 7 to insert the element inside the array in a user defined position\n");
    printf("Press 8 to delete an element from the array\n");
    printf("Press 9 to perform linear search on the array\n");
    printf("Press 10 to perform binary search on the array\n");
    printf("Press 11 to find the maximum value present inside the array\n");
    printf("Press 12 to find the minimum value present inside the array\n");
    printf("Press 13 to print the sum of all the elements present inside the array\n");
    printf("Press 14 to print the average of all the elements present inside the array\n");
    printf("Press 15 to replace the element in a user defined position inside an array\n");
    printf("Press 16 to reverse the sequence of elements inside the array \n");
    printf("Press 17 to rotate the elements inside the array\n");
    printf("Press 18 to Exit the program\n");
    scanf("%d",&key);
    printf("\n");
    switch(key)
    {

      case 0:
      printf("---------------BINARY OPERATIONS ON 1D ARRAY-----------------\n");
      do
      {
      printf("Press 1 to Create Array A and Array B\n");
      printf("Press 2 to Display array A; B & C \n");
      printf("Press 3 to Merge Array A and Array B in Array C in ascending order\n");
      printf("Press 4 to Go to the main Array menue\n");
      scanf("%d",&choice15);
      switch(choice15)
      {
        case 1:
        CreateArrayTwo();
        printf("\n");
        break;

        case 2:
        displayArrayTwo();
        printf("\n");
        break;

        case 3:
        MergeArray();
        printf("\n");
        break;

        case 4:
        printf("------------------------Developer info----------------------\n");
        printf("Name:- Aditya Kumar\n");
        printf("Course:-B.Tech CS\n");
        printf("Year:-2nd tear\n");
        printf("Roll Number:-1901230100001\n");
        printf("college code:-123\n");
        printf("\n");
        printf("Program terminated by the user........\n");
        Q=4000;
        printf("\n");
        break;

        default:
        printf("Wrong choice!!!!...\n");
        break;
        }
        }while(Q<3000);
      printf("\n");
      break;

      case 1:
      createArray(); //create array
      printf("\n");
      break;
      case 2:
      displayArray(); //display elements in array
      printf("\n");
      break;
      case 3:
      sortArrayAcending();
      printf("\n");
      break;
      case 4:
      sortArrayDecending();
      printf("\n");
      break;
      case 5:
      insertAscendSort();
      printf("\n");
      break;
      case 6:
      insertDescendSort();
      printf("\n");
      break;
      case 7:
      insertArray();
      printf("\n");
      break;
      case 8:
      deleteArray();
      printf("\n");
      break;
      case 9:
      LinearSearchArray();
      printf("\n");
      break;
      case 10:
      BinarySearchArray();
      printf("\n");
      break;
      case 11:
      maxArray();
      printf("\n");
      break;
      case 12:
      miniArray();
      printf("\n");
      break;
      case 13:
      sumArray();
      printf("\n");
      break;
      case 14:
      AvgArray();
      printf("\n");
      break;
      case 15:
      setArray();
      printf("\n");
      break;
      case 16:
      ReverseArray();
      printf("\n");
      break;
      case 17:
      rotateArray();
      printf("\n");
      break;
      case 18:
      printf("------------------------Developer info----------------------\n");
      printf("Name:- Aditya Kumar\n");
      printf("Course:-B.Tech CS\n");
      printf("Year:-2nd tear\n");
      printf("Roll Number:-1901230100001\n");
      printf("college code:-123\n");
      printf("\n");
      printf("Program terminated by the user........\n");
      O=4000;
      printf("\n");
      break;
      default:
      printf("wrong choice\n");
      printf("\n");
      break;
    }

  }while(O<3000);

break;

case 2:
printf("\nyou chose 2D Array operations \n");
printf("\ninitializing 2D Array operations program\n");
printf("\n");
//menue loop for 2D Array
 do
    {
    printf("\n               MENUE                \n");
    printf("Press 1 to enter matrix a\n");
    printf("Press 2 to enter matrix b\n");
    printf("Press 3 to display matrix a\n");
    printf("Press 4 to display matrix b\n");
    printf("Press 5 for matrix a + matrix b\n");
    printf("Press 6 for matrix a - matrix b\n");
    printf("Press 7 for matrix a * matrix b\n");
    printf("Press 8 to calculate transpose of matrix A\n");
    printf("Press 9 to calculate transpose of matrix B\n");
    printf("Press 10 to see developer information\n");
    printf("Press 11 to exit program\n");
    scanf("%d", &choice);
    printf("\n");
    printf("\nyou chose option %d \n", choice);

    switch(choice)
    {
     case 1:
    printf("\ninput row of the matrix a it should be less than 10\n");
    scanf("%d", &row);
    printf("\ninput column of matrix a it should be less than 10\n");
    scanf("%d", &column);
    inputa(a , row, column);
     printf("\n");
     break;
     
     case 2:
    printf("\ninput row of the matrix b it should be less than 10\n");
    scanf("%d", &row1);
    printf("\ninput column of matrix b it should be less than 10\n");
    scanf("%d", &column1);
    inputb(b , row1, column1);
     printf("\n");
     break;
    
    case 3:
    printf("\nDisplaying Matrix a\n");
    displaya(a, row, column);
     printf("\n");
     break;
    
     case 4:
    printf("\nDisplaying Matrix b\n");
    displayb(b , row1, column1);
     printf("\n");
     break;
     
     case 5:
     if( row == row1 && column == column1)
    {
        printf("\nperforming Addition of matrix A and matrix B \n");
        sumOfTwoArray( a, b, res, row, column);
    }
    else 
    {
        printf("\nAddition of Matrix A and Matrix B is not possible \n");
    }
    printf("\n");
    break;

    case 6:
     if( row == row1 && column == column1)
    {
        printf("\nperforming subtraction of matrix A and matrix B \n");
        subtractionOfTwoArray( a, b, res, row, column);
    }
    else 
    {
        printf("\nsubtraction of Matrix A and Matrix B is not possible \n");
    }
    printf("\n");
    break;

    case 7:
    // the number of columns in the first matrix must be equal to the number of rows in the second matrix
    if( column == row1)
    {
        printf("\nperforming multiplication of matrix A and matrix B \n");
        MultiplyTwoArray(a , b ,res, row, column, row1, column1);
    }
    else 
    {
        printf("\nmultiplication of Matrix A and Matrix B is not possible \n");
    }
    printf("\n");
    break;

    case 8:
    transposeA(a ,transA, row, column);
    printf("\n");
    break;

    case 9:
    transposeB(b ,transB, row1, column1);
    printf("\n");
    break;

    case 10:
    printf(" Name :- Aditya Kumar\n");
printf("Roll number:- 1901230100001\n");
printf("Course:- B.Tech\n");
printf("Stream:- Computer science\n");
printf("\n");
    break;

    case 11:
    printf("\n2D Array Operations Program Terminated by the user!!!...\n");
    printf("\nSwitching to main menue...\n");
    printf("\n");
    u=2000;
    break;

    default:
    printf("\nWrong choice...Please try again!!!\n");
    printf("\n");
    break;
}
} while(u<1000); //2D array menue loop closed
break;

case 3: 
printf("\nyou chose Singly Linked List Operation\n");
printf("\ninitializing Singly Linked List operations program\n");
printf("\n");
        do{
               // menue of Singly Linked List Operation
                printf("\n                MENU                             \n");
                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.To see the number of elements inside the Linked list     \n");
                printf("\n 10.Reverse the linked list     \n");
                printf("\n 11.Sum of All the elements\n");
                printf("\n 12.Find the greates number\n");
                printf("\n 13.Find the smallest number\n");
                printf("\n 14.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("\nEnter your choice:\n");
                scanf("%d",&choose);
                switch(choose)
                {
                        case 1:
                                        createOne();
                                        break;
                        case 2:
                                        displayOne();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        case 9:
                                        c=count();
                                        printf("Number of elements in the linkd list is = %d", c);
                                        printf("\n");
                                        break; 
                        case 10:
                                        reverse();
                                        break;     
                        case 11:
                                        SumOfAllSinglyLL();
                                        break;   
                        case 12:       
                                        GreatestSinglyLinkedList();
                                        printf("\n");
                                        break;    
                        case 13:     
                                        SmallestSinglyLinkedList();
                                        printf("\n");
                                        break;   
                        
                        case 14:
                                        printf("This piece of program was written by\n");
                                        printf("Name : Aditya Kumar\n");
                                        printf("Roll number : 1901230100001\n");
                                        printf("College code: 123\n");
                                        printf("College Name : SITM\n");
                                        printf("Course: B.Tech\n");
                                        printf("Branch : Computer science\n");
                                        printf("Year : 2nd Year\n");
                                        printf("Singly Linked List operation program Terminated by the user !!!\n");
                                        printf("\nSwitching to main menue...\n");
                                        A = 2000;
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        } while(A<1000);// linked list menue loop closed
break;

case 4: // menue loop of Doubly Linked List
printf("\nyou chose Doubly Linked List Operation\n");
printf("\ninitializing Doubly Linked List operations program\n");
printf("\n");
do
{
printf("-----------------------MENUE----------------------\n");
printf("Press 1 to create a node in Doubly Linked List\n");
printf("Press 2 to display all the nodes of Doubly Linked List\n");
printf("Press 3 to Insert the newly created node at the beginning of the Doubly Linked list\n");
printf("Press 4 to Insert the newly created node at the ending of the Doubly Linked list\n");
printf("Press 5 to Insert the newly created node at the specific position Entered by the user in the Doubly Linked list\n");
printf("Press 6 to count the number of nodes of the Doubly Linked list\n");
printf("Press 7 to delete the First node of the Doubly Linked list\n");
printf("Press 8 to delete the Last node of the Doubly Linked list\n");
printf("Press 9 to delete the node of the Doubly Linked list at a specified position\n");
printf("Press 10 to terminate the program\n");
scanf("%d",&choice3);
printf("\n");
switch(choice3)
{
case 1:
printf("Creating a new node in Doubly Linked List\n");
create_DoublyLinkedList();
printf("\n");
break;

case 2:
printf("Printing the nodes in Doubly Linked List\n");
Display_DoublyLinkedList();
printf("\n");
break;

case 3:
Insert_begin__DoublyLinkedList();
printf("Insertion at beginning complete!!!..");
printf("\n");
break;

case 4:
Insert_End__DoublyLinkedList();
printf("Insertion at ending complete!!!..");
printf("\n");
break;

case 5:
Insert_Pos__DoublyLinkedList();
printf("Insertion at the specified position complete!!!..");
printf("\n");
break;

case 6:
c2=lengthDoublyLinkedList();
printf("The number of nodes present inside the Doubly linked list is = %d\n", c2);
printf("\n");
break;

case 7:
Delete_Begin_DoublyLinkedList();
printf("Deletion at beginning complete!!!..");
printf("\n");
break;

case 8:
Delete_End_DoublyLinkedList();
printf("Deletion at Ending complete!!!..");
printf("\n");
break;

case 9:
Delete_POS_DoublyLinkedList();
printf("Deletion at the specified position complete!!!..");
printf("\n");
break;

case 10:
printf("---------DEVELOPER INFO-------------\n");
printf("NAME: Aditya Kumar\n");
printf("COURSE: B.Tech\n");
printf("BRANCH: Computer Science\n");
printf("ROLL NO: 1901230100001\n");
printf("COLLEGE CODE: 123\n");
printf("College Name: Saroj Institute of Technology and Management\n");
printf("\nDoubly Linked List Program terminated by the user\n");
printf("\nswitching to main menue...\n");
printf("\n");
T=3000;
break;

default:
printf("Wrong choice\n");
printf("\n");
break;

}

}while(T<2000);
break;

case 5:
printf("This piece of program was written by\n");
printf("Name : Aditya Kumar\n");
printf("Roll number : 1901230100001\n");
printf("College code: 123\n");
printf("College Name : SITM\n");
printf("Course: B.Tech\n");
printf("Branch : Computer science\n");
printf("Year : 2nd Year\n");
printf("\nProgram Terminated by the user!!!...\n");
printf("\n");
g=2000;
break;

default:
printf("\nWrong choice...Please try again!!!\n");
printf("\n");
break;

}//main meue switch closed

}while(g<1000);//main menue loop closed

    return 0;
}//main closed