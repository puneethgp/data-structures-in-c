
//raw concept of adding elemnts to list
// adding elements to the list

struct* Node{
    int data;
    Node* link;
    };


//declaring and intializing a pointer to the linked list
Node* A;
A=NULL;

//creating or adding elements at the end
Node* temp = (Node *)malloc(sizeof(Node));
temp->data = 2;// equvivalent to (*temp ).data =2
temp->link = NULL;

//assinging pointer to linked list with the address of first element
A = temp;

//adding elements
temp ->data=4;
temp->link =Null;

//linking address of the previous node to the current address
Node *temp1 = A;
//traverse through the list and find out first Null link element
while(temp1->link!NULL) temp1=temp1->link;

//assign previous element link to current address
temp1->link =temp;


