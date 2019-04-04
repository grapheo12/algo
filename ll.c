#include <stdio.h>
#include <stdlib.h>

struct Nodell{
  int data;
  struct Nodell* link;
};
typedef struct Nodell nodell, *llptr;

llptr createll(int data){
  //Creates a linked list with 1 node carrying data from the argument
  llptr head = (llptr)malloc(sizeof(nodell));
  head -> data = data;
  head -> link = NULL;

  return head;
}

llptr addNode(llptr head, int pos, int data){
  //Adds a node into ll pointed by head into the position pos
  //Returns the head of the ll
  llptr _head = head;
  if (pos == 0){
    //Insert at the beginning
    _head = (llptr)malloc(sizeof(nodell));
    _head -> data = data;
    _head -> link = head;
  }else if (pos == -1){
    //Insert at the end
    while (head -> link != NULL)
      head = head -> link;
    head -> link = (llptr)malloc(sizeof(nodell));
    head -> link -> data = data;
    head -> link -> link = NULL;
  }else{
    //Insert in the middle
    for (int i = 0; i < pos - 1; i++)
      head = head -> link;
    llptr next = head -> link;
    head -> link = (llptr)malloc(sizeof(nodell));
    head -> link -> link = next;
    head -> link -> data = data;
  }

  return _head;
}

llptr deleteNode(llptr head, int pos){
  //Deletes a node in the ll pointed by head at the position pos
  //Returns the head of the ll
  llptr _head = head;
  if (pos == 0){
    //Insert at the beginning
    _head = _head -> link;
    free(head);
  }else if (pos == -1){
    //Insert at the end
    while (head -> link -> link != NULL)
      head = head -> link;
    free(head -> link);
    head -> link = NULL;
  }else{
    //Insert in the middle
    for (int i = 0; i < pos - 1; i++)
      head = head -> link;
    llptr next = head -> link;
    head -> link = (llptr)malloc(sizeof(nodell));
    head -> link -> link = next;
    head -> link -> data = data;
  }

  return _head;
}

void displayll(llptr head){
  do{
    printf("%d ", head -> data);
    head = head -> link;
  }while (head != NULL);
  printf("\n");
}

int main(){
  llptr ll = createll(4);
  displayll(ll);
  ll = addNode(ll, 0, 3);
  displayll(ll);
  ll = addNode(ll, 1, 2);
  addNode(ll, -1, 5);
  displayll(ll);

  return 0;
}
