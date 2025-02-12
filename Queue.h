typedef struct {
	 NodePtr headPtr,tailPtr;
	int size;
}Queue;


void enqueue_struct(Queue* q, int x){
  Node* new_node=(Node*) malloc(sizeof(Node));

  if(new_node && (q->headPtr == NULL)){ 
    /*Finish enqueue */ 
    q->headPtr = new_node;
    q->headPtr->data = x;
    q->tailPtr = new_node;
  }
  else if(new_node){
    q->tailPtr->nextPtr = new_node;
    q->tailPtr = new_node;
    q->tailPtr->data = x;
  }
  q->size++;
}


int dequeue_struct(Queue *q){
  int value;
  if(q->size>0)
  {  
    NodePtr t = q->headPtr;
    value = t->data;
    q->headPtr = q->headPtr->nextPtr;
    q->size--;
    free(t);
    return value;
  }
  else
  {
    q->tailPtr = NULL;
    printf("Empty queue\n");
    return 0;
  }
}

