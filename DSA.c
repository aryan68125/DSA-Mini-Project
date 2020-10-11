#include<stdio.h>
#include<stdlib.h> //if you are going to build a program on a linked list then this library is needed include it in your program before anything else

// functions for 1D Array Operations
//The 1D array is created in heap instead of the stack
//this will allow us to enter the size of the array during runtime
void createArray();
void displayArray();
void AppendArray();
void insertArray();
void deleteArray();
void LinearSearchArray();
void BinarySearchArray();
void maxArray();
void miniArray();
void sumArray();
void AvgArray();
void setArray();
void ReverseArray();
void rotateArray();

//in order to create an Array inside the heap we need to first create a Structure 
struct Array // structure name
{
    int *A; // Array pointer. it is integer type it can point on an Array
    int size; //size of an array that we will enter during run time
    int length; // to store the length of an array i.e: Number of elements that the user wants to enter inside the array
};

//this array is temporary array created in heap so that we can perform binary search without have to worry about whether its sorted or not
struct Temp
{
    int *B; //Array pointer pointing to array b which is a temporary array
    int sizeB; //size of array B
    int lengthB; //length of array B
};

//declaring the arr globally will allow us to access it in any function in this program
struct Array arr; /* Initializing the structure (struct Array is not a pointer so we will access the structure members by the use of dot operation)
                         Example 1. arr.length ; 2. arr.A[i] ; 3. arr.size
                         if we take arr as a pointer for example struct Array *arr then we will get error messages like :- format specifies type 'int *' but the argument has type 'int' [-Wformat]
                         scanf("%d",arr->A[i]);
                         arr->A method of accessing structure members is only applicable if the structure is a pointer struct Array *arr */

//now setting up the array b which is a temporary array that will be used to perform binary search
    struct Temp temp; //this array will be identical in size and length to  the original array
                       //the temp should be a pointer *temp becoz we are required to modify the array b

void createArray() //containing the logic for creaton of array with ability to enter the size dynamically during runtime
{
    int n; //n will hold the number of elements that the user wants to insert inside the array
    int i; // Loop variable

    //all the steps here are required for array initialization inside the heap with dinamic memory allocation so that we can enter the size of an array during runtime
    //which allows us to choose the size of an array according to our needs during run time
    
    printf("Enter the size of an array and also the number of elements you want to enter inside the array\n");
    scanf("%d\n",&arr.size); //entering the size of an Array in runtime
                              // we can only access the struct members using arr there is no other way to do that
    scanf("%d",&n);    // Entering the number of elements the user want to enter inside the array
    arr.A=(int*)malloc(arr.size*sizeof(int)); //created an array inside the heap and making pointer *A point on that array
    arr.length=0; //setting length to zero beacause there are no elements inside array right now
    //........................................................................................................................

    if(n<=arr.size)
    {
        printf("The capacity of array is %d\n",arr.size);
        printf("The number of elements user wants to enter inside the array is %d\n",n);
        //the code below will eneter the elements inside the array
        // by using for loop we will enter the elements inside the array one by one
       printf("Enter the elements inside the Array\n");
       for(i=0;i<n;i++)
       {
        scanf("%d",&arr.A[i]);
       }
        //setting up the length of an array as n after entering the elements inside the array
        arr.length=n;
        printf("Array creation Successfull..........\n");
    }
    else
    {
        printf("The number of elements enetered by the user Exceeds the capacity of the Array\n");
        printf("The capacity of array is %d\n",arr.size);
        printf("The number of elements user wants to enter inside the array is %d\n",n);
        printf("Array creation failed..........\n");
        return;
    }
   //........................................................................................................................
}

void displayArray() //display Array function
{
int i; //loop variable
//now printing the elements entered by the user inside the Array by using for loop again
printf("printing the elements entered by the user inside the Array\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("A[%d] = %d\n",i,arr.A[i]);
    }
}

void AppendArray()//this Append funtion will insert the element at the end of the array i.e the next free space inside the array
{
    int num; //the number that the user want to append inside the array
    printf("Enter the element that you want to Append inside the array\n");
    scanf("%d",&num);
    if(arr.length!=arr.size)
    {
      arr.A[arr.length]= num;
      printf("the appending of %d inside the array is Successfull!!!!.....\n",num);
      arr.length++; //updating the length of the array
      printf("The number of elements inside the array is %d\n",arr.length);
      int free; //it will store the free space present inside the array to store new elements
      free = arr.size - arr.length;
      printf("Available space inside the array for new element is %d\n",free);
      return;
    }
    else
    {
        printf("Cannot Append the new element %d inside the array because there is no free space\n", num);
        printf("Maximum array capacity reached!!!!...\n");
        printf("Array Capacity = %d\n",arr.size);
        return;
    }

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
    if(pos>arr.size)
    {
        printf("The desired position %d does not exist in the array......\n",pos);
        printf("Insertion of element %d FAILED!!!!!......\n",num);
        return;
    }

    if(arr.length!=arr.size)
    {
         for(i=arr.length;i>pos;i--)
         {
            arr.A[i]=arr.A[i-1]; //it will shift the elements from the last to the desired position by one index
         }
         arr.A[pos]=num; //Inserting the element inside the desired position of the array after shifting all the elements of the array 
         arr.length++; //updating the length of the array
         printf("Insertion of element %d is Successfull!!!!!!!!........\n",num);
         
         free = arr.size - arr.length; //calculation of free space present inside of an array
         printf("Available space inside the array for new element is %d\n",free);
         return;
    }
    else
    {
        printf("Cannot Insert the new element %d inside the array because there is no free space\n", num);
        printf("Maximum array capacity reached!!!!...\n");
        printf("Array Capacity = %d\n",arr.size);
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
   for(i=0;i<arr.length;i++)
   {
    if(num==arr.A[i])
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
    for(j=i;j<arr.length-1;j++)
    {
        arr.A[j]=arr.A[j+1]; //it will shift the elements from the last to the desired position by one index
    }
    arr.length--; //updating array length
    free = arr.size - arr.length; //calculation of free space present inside of an array
    printf("Available space inside the array for new element is %d\n",free);
    printf("Deletion operation successfull!!!!!!!!!.........\n");
   }
   else if(arr.length==0)
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
   for(i=0;i<arr.length;i++)
   {
    if(num==arr.A[i])
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

    temp.B=(int*)malloc(arr.size*sizeof(int)); //creating temporary array inside the heap
    // now while accessing the members we should use -> method becoz now we are using *temp instead of temp
    temp.lengthB=arr.length;

    for(int i=0;i<arr.length;i++)
    {
        temp.B[i]=arr.A[i]; //copying the elements from a array to b array
    }
    int tempo; // temporary variable that is used in swapping of elements
    for(int i=1;i<temp.lengthB;i++)  //Bubble sorting the temporary array in ascending order
    {
        for(int j=0;j<temp.lengthB-1;j++)
        {
            if(temp.B[j]>temp.B[i]) //this logic will sort the array in ascending order
            {// swapping logic 
                tempo=temp.B[j];
                temp.B[j]=temp.B[i];
                temp.B[i]=tempo;
            }
        }
    }

    //printing the sorted array 
    printf("Sorting the array before performing binary search.......\n");
    for(int i=0;i<temp.lengthB;i++)
    {
        printf("%d\n",temp.B[i]);
    }
    
    //now we can apply binary search on the temporary array 
    int low=0; //lower bound
    int high=temp.lengthB; //higher bound
    int mid;
    int key; //key will store mid if the num is found inside the array
    while (low<=high) // condition for the loop
    {
        mid = (low+high)/2;
        if(num == temp.B[mid])
        {
            key=temp.B[mid];
            break;
        }
        else if(num<temp.B[mid])
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
temp.B=(int*)malloc(arr.size*sizeof(int)); //creating temporary array inside the heap
    // now while accessing the members we should use -> method becoz now we are using *temp instead of temp
    temp.lengthB=arr.length;

    for(int i=0;i<arr.length;i++)
    {
        temp.B[i]=arr.A[i]; //copying the elements from a array to b array
    }
    int tempo; // temporary variable that is used in swapping of elements
    for(int i=1;i<temp.lengthB;i++)  //Bubble sorting the temporary array in ascending order
    {
        for(int j=0;j<temp.lengthB-1;j++)
        {
            if(temp.B[j]>temp.B[i]) //this logic will sort the array in ascending order
            {// swapping logic 
                tempo=temp.B[j];
                temp.B[j]=temp.B[i];
                temp.B[i]=tempo;
            }
        }
    }
    int last=temp.lengthB;
    printf("Maximum value in array is %d\n",temp.B[last-1]);
}

void miniArray() //to find the minimum value in the array
{
    temp.B=(int*)malloc(arr.size*sizeof(int)); //creating temporary array inside the heap
    // now while accessing the members we should use -> method becoz now we are using *temp instead of temp
    temp.lengthB=arr.length;

    for(int i=0;i<arr.length;i++)
    {
        temp.B[i]=arr.A[i]; //copying the elements from a array to b array
    }
    int tempo; // temporary variable that is used in swapping of elements
    for(int i=1;i<temp.lengthB;i++)  //Bubble sorting the temporary array in ascending order
    {
        for(int j=0;j<temp.lengthB-1;j++)
        {
            if(temp.B[j]>temp.B[i]) //this logic will sort the array in ascending order
            {// swapping logic 
                tempo=temp.B[j];
                temp.B[j]=temp.B[i];
                temp.B[i]=tempo;
            }
        }
    }
    int last=temp.lengthB;
    printf("Minimum value in array is %d\n",temp.B[0]);
}

void sumArray() //it will find the sum of all elements present inside the array
{
    int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<arr.length;i++)
   {
       sum=sum+arr.A[i];
   }
   printf("Sum of all the elements present in the array is %d\n",sum);
}

void AvgArray() //it will find the average of all the elements present inside the array
{
    int sum; //for storing the sum of all the elements present inside thae array
   for(int i=0;i<arr.length;i++)
   {
       sum=sum+arr.A[i];
   }
   int avg;
   avg= sum/arr.length;
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
   if(pos>0 && pos<=arr.length) //Logic to check whether the position entered by the user is valid or not
   {
    printf("the Entered position is Valid......\n");
    printf("setting the %d inside the array at %d position\n",num,pos);
    arr.A[pos-1]=num;
   }
   else
   {
    printf("the Entered position is not valid\n");
    printf("setting up number %d inside the array FAILED!!!!....\n",num);
   }
} 

void ReverseArray() //this function will reverse the elements inside the array and then save it inside the original array
{
    temp.B=(int*)malloc(arr.size*sizeof(int)); //creating temporary array inside the heap
    // now while accessing the members we should use -> method becoz now we are using *temp instead of temp
    temp.lengthB=arr.length;
    int j = arr.length; //it will store the length of the array
                        //by doing that we will be able to get the last position of the element in the array
    for(int i=0;i<arr.length;i++)
    {
        temp.B[j-1]=arr.A[i]; //copying the elements inside the temporary array in reverse order
        j--;
    }
    for(int i=0;i<arr.length;i++)
    {
        arr.A[i]=temp.B[i]; //copying the temp array inside the original array A 
    }
    printf("elements Reversal inside the array is Successful!!!...\n");
}

void rotateArray() //this function will rotate the elements inside the array
{

   int tempo; //temporary variable that will hold the element inside the array at 0th position temporaily
              //as in this operation we will be shifting the elements inside the array forward by one position
              //and in doing so we will loose the first element so inorder to prevent it. It is crucial to take the backup of the first element inside the array
   tempo = arr.A[0];
   int j;
   for(int i=0;i<arr.length;i++)
   {
    j=i+1;
    arr.A[i] = arr.A[j];    //logic for shifting of elements inside the array forward by one position
    j++;
   }

   arr.A[arr.length-1]=tempo; //now copying the element that used to be at the 0th positon in the array to the last position in the array
   printf("Rotation of array elements SUCESSFUL!!!!!.....\n");

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
    int arr[100]; // declaring array of capacity to hold 100 elements

    int brr[100]; // temporary array for bubble sorting

    int size ; //number of elements to store inside the array

int ch; //choice in switch statement

int k=1; //menue loop variable

int element; //element to be inserted inside the array

int position; //define the position at which you want to insert the element

int index; //index of array where the element is found in linear search

int mid; //to hold the mid value returned by binary search function

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
    u=0;
    k=0;
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
int key; //choice for menue switch case
    int O=0; // menue loop variable
    do
    {
    printf("---------------------------Menue--------------------------------\n");
    printf("Press 1 to Create the Array\n");
    printf("Press 2 to Display the Array\n");
    printf("Press 3 to Append the number inside the array\n");
    printf("Press 4 to Insert the element at the desired position inside the Array\n");
    printf("Press 5 to Delete the element from the array\n");
    printf("Press 6 to Find the element using Linear Searching method in the array\n");
    printf("Press 7 to Find the element using Binary Searching method in the array\n");
    printf("Press 8 to Find the maximum value present inside the array\n");
    printf("Press 9 to find the minimum value present inside the array\n");
    printf("Press 10 to Print the sum of all the elements present inside the array\n");
    printf("Press 11 to find the average of all the elements present inside the array\n");
    printf("Press 12 to Replace a number inside the array at a desired position\n");
    printf("Press 13 to Reverse the elements inside the array\n");
    printf("Press 14 to Rotate the elements inside the array\n");
    printf("Press 15 to Exit the program\n");
    scanf("%d",&key);
    printf("\n");
    switch(key)
    {
        case 1:
        createArray(); //create array
        printf("\n");
        break;
        case 2:
        displayArray(); //display elements in array
        printf("\n");
        break;
        case 3:
        AppendArray(); //Append elements in array
        printf("\n");
        break;
        case 4:
        insertArray(); //Insert elements in array
        printf("\n");
        break;
        case 5:
        deleteArray(); //delete elements in array
        printf("\n");
        break;
        case 6:
        LinearSearchArray(); //Linear search in array
        printf("\n");
        break;
        case 7:
        BinarySearchArray(); //Binary search in array
        break;
        case 8:
        maxArray();
        printf("\n");
        break;
        case 9:
        miniArray();
        printf("\n");
        break;
        case 10:
        sumArray();
        printf("\n");
        break;
        case 11:
        AvgArray();
        printf("\n");
        break;
        case 12:
        setArray();
        printf("\n");
        break;
        case 13:
        ReverseArray();
        printf("\n");
        break;
        case 14:
        rotateArray();
        printf("\n");
        break;
        case 15:
        printf("------------------------Developer info----------------------\n");
        printf("Name:- Aditya Kumar\n");
        printf("Course:-B.Tech CS\n");
        printf("Year:-2nd tear\n");
        printf("Roll Number:-1901230100001\n");
        printf("college code:-123\n");
        printf("\n");
        printf("Program terminated by the user........\n");
        printf("Switchig to main menue................\n");
        O=4000;
        printf("\n");
        break;
        default:
        printf("wrong choice\n");
        printf("\n");
        break;
    }//switch closed

    }while(O<3000); //do while loop closed
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
                printf("\n 12.Exit       \n");
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