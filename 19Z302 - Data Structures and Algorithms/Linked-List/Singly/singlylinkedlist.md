# 19Z302 Data Structures
## Basic Operations on Linked Lists (Search, Insertion and Deletion)
submitted by _Akash Shanmugaraj_, 22z255

### Definition of Node
```c
struct node
{
    int data;
    struct node *next;
};
```

```c
struct node *getpointer(int data)
{
    struct node *element = (struct node *)malloc(sizeof(struct node));
    element->data = data;
    element->next = NULL;
    return element;
}
```
### Function to print contents of a Linked List
```c
void printlist(struct node *headpointer)
{
    struct node *tempnode = headpointer;
    while (tempnode->next != NULL)
    {
        printf("%d-", tempnode->data);
        tempnode = tempnode->next;
    }
    printf("%d\n\n", tempnode->data);
}
```
### Function to construct a new Linked List, returns the Head Pointer of the new list
```c
struct node * constructor(int constructorlength, int constructoroffset)
{
    struct node *HEAD;
    struct node *temphead = HEAD;
    struct node *tempelement;

    int insertlimit = constructorlength;
    for (int iterable = 0; iterable < insertlimit; iterable++)
    {
        tempelement = getpointer(constructoroffset+iterable);
        if (iterable == 0)
        {
            HEAD = tempelement;
            temphead = tempelement;
        }
        else
        {
            temphead->next = tempelement;
            temphead = tempelement;
        }
        if (iterable == insertlimit - 1)
        {
            temphead->next = NULL;
        }
    }
    
    return HEAD;
}
```
### Search function that returns the position of first occurence of element

```c
int search(struct node *headpointer, int data)
{
    struct node *tempnode = headpointer;
    int position = 0;
    for (; tempnode != NULL; tempnode = tempnode->next, position++)
    {
        if (tempnode->data == data)
        {
            printf("Element found at position: %d\n", position);
            return position;
        }
    }
    printf("Element not found in the list.\n");
}
```
### Function to insert given element (data) at the start and at the end of a Linked List
```c
struct node * insertatstart(struct node * headpointer, int data){
    struct node * newelement = getpointer(data);
    newelement -> next = headpointer;
    return newelement;
}

struct node * insertatend(struct node * headpointer, int data){
    struct node * temphead = headpointer;
    while(temphead -> next != NULL){
        temphead = temphead -> next;
    }
    struct node * element = getpointer(data);
    temphead -> next = element;

    return headpointer;
}
```
### Function to insert a given element (data) into some index of a Linked List 
```c
struct node * insertatpos(struct node * headpointer, int data, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * poselement = getpointer(tempheadpointer->data);
    poselement->next = tempheadpointer->next;
    tempheadpointer->data = data;
    tempheadpointer->next = poselement;
    
    return headpointer;
}
```
### Function to insert a given new Linked List into some index of a Linked List
```c
struct node * insertnatpos(struct node * headpointer, int offset, int position){
    int counter = 0;
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    while (tempheadpointer != NULL && counter != position){
        counter++;
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    struct node * newconstructorlist = constructor(3, offset);
    printf("NEW-CH\n");
    printlist(newconstructorlist);
    struct node * newlisttraverser = newconstructorlist;

    while (newlisttraverser->next != NULL){
        newlisttraverser = newlisttraverser -> next;
    }
    newlisttraverser->next = tempheadpointer;

    if (prev != NULL) {
        prev->next = newconstructorlist;
    } else {
        headpointer = newconstructorlist;
    }

    printlist(headpointer);
    return headpointer;
}
```
### Function to insert a given new Linked List into before some index of a Linked List
```c
struct node * insertnnodesbeforex(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * prev = NULL;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            if (prev != NULL) {
                prev->next = newlist;
            } else {
                headpointer = newlist;
            }
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer;
            break;
        }
        prev = tempheadpointer;
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}
```
### Function to insert a given new Linked List into after some index of a Linked List
```c
struct node * insertnnodesafterx(struct node * headpointer, int N, int X){
    struct node * tempheadpointer = headpointer;
    struct node * newlist = constructor(N, 1);

    while (tempheadpointer != NULL){
        if (tempheadpointer->data == X){
            struct node * newlisttraverser = newlist;
            while (newlisttraverser->next != NULL){
                newlisttraverser = newlisttraverser -> next;
            }
            newlisttraverser->next = tempheadpointer->next;
            tempheadpointer->next = newlist;
            break;
        }
        tempheadpointer = tempheadpointer -> next;
    }

    return headpointer;
}
```

