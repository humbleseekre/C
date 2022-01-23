-----------------CB A--------------CB B--------------CB C-------------------------------| Execute all the callbacks that were registered |--------------CB D---------------| 
--------------------------------------time----------------------------------------------|	timer expires and event gets triggered	       |---------------------------------|

typedef void (*callback)(void);
sem_t lock;

typedef struct linkedList_t{
  callback func;
  struct linkedList_t *next;
}callbackList;

static callbackList *timerCallback; //head of ll

bool isTimerActive = true;

void register_callback(callback func)
{
	if(func == NULL){
  	return;
  }
  if(isTimerActive == false){
  	(*func)();	
  }
  sem_wait(lock);
	if(timerCallback == NULL){
  	timerCallback = (callbackList *) malloc(sizeof(callbackList));
		timerCallback->next = NULL;
    timerCallback->func = func;
  }
  else{
  	callbackList *newNode = (callbackList *) malloc(sizeof(callbackList));
    newNode->next = timerCallback;
    newNode->func = func;
    timerCallback = newNode;
  }
  sem_post(lock);
}

void event_execute()
{	
	sem_wait(lock);
	isTimerActive = false;
  sem_post(lock);
	callbackList *head = timerCallback; 
	while(head != NULL){
  	head->func();
    head = head->next;
  }
}
