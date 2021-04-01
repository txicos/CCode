/*
 ============================================================================
 Name        : main.c
 Author      :
 Version     :
 Copyright   :
 Description : List in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DynamicList {
   int data;
   struct DynamicList *next;
   struct DynamicList *prev;
};

typedef struct DynamicList *gNode;

gNode head = NULL;
gNode current = NULL;


void printData() {
    gNode p;
    p = head;
    if(head==NULL)
    {
        printf("vazia\n");
    }
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

gNode createNode(){
    gNode temp;
    temp = (gNode)malloc(sizeof(struct DynamicList));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}


int firstNode()
{
    return head->data;
}

int lastNode()
{
    return current->data;
}

void putNode(int value) {
    gNode temp,p;
    temp = createNode();
    temp->data = value;
    if(head == NULL)
    {
        head = temp;
    }
    else{
        p  = head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
    current=temp;
}


void isEmpty() {
   if (head == NULL)
   {
        printf("vazia \n");
   }
}

int length() {
    int i;
    if (head==NULL)
    {
        return 0;
    }
    i=1;
    gNode p;
    p = head;
    while(p != NULL)
    {
        p = p->next;
        i+=1;
    }
    return i;
}


int getNode(int key) {
    if (head==NULL)
    {
        return -1;
    }
    int  k = 1;
    gNode p;
    p = head;
    while(p != NULL){
        if (k==key)
        {
            return p->data;
        }
        k += 1;
        p = p->next;
    }
    return -1;
}


int removeNode(int key) {
    if (head==NULL)
    {
        return -1;
    }
    int  k = 1;
    gNode p;
    p = head;
    if(k==key)
    {
        int value = p->data;
        head=p->next;
        p->next->prev=NULL;
        free(p);
        return value;
    }

    if (key==length())
    {
        int value = p->data;
        current=p->prev;
        p->prev->next=NULL;
        free(p);
        return value;
    }

    while(p != NULL)
    {
        if (k==key)
        {
            int value = p->data;
            p->prev->next = p->next;
            p->next->prev = p->prev;
            free(p);
            return value;
        }
        k+=1;
        p = p->next;
    }
    return -1;
}

void clearNodes(){

    if (head==NULL)
    {
        return;
    }

    gNode p;
    p = head;
    int i =1;
    while(p != NULL)
    {
        //printf("%d ",i);
        head = p->next;
        if(head==NULL)
        {
            break;
        }
        p->next->prev = NULL;
        free(p);
        p = head;
        i+=1;
    }
    head = NULL;
    current = NULL;
}


// use to debug
//void print_entry(char *entry) {
//	printf("You entered: %s\n", entry);
//}

int main(int argc, char *argv[]) {
	char input[201];

	while(1) {
		printf("prompt> ");
		if (fgets(input, 200, stdin) == NULL) {
			printf("An error ocurred.\n");
			break;
		}

		if (strncmp(input, "exit\n", 5) == 0) {
			printf("Leaving. Good bye.\n");
			break;
		}

		//print_entry(input);

        char str [20];
        int i;

        sscanf (input,"%s  %d",str,&i);

        if (strncmp(str, "put", 3) == 0)
        {
            putNode(i);
            printData();
        }
        else if(strncmp(str, "get", 3) == 0)
        {
            int r = getNode(i);
            if (r ==-1)
            {
                printf("not found");
            }
            else
            {
                printf("%d\n",r);
            }
        }
        else if(strncmp(str, "remove", 6) == 0)
        {
            int r = removeNode(i);
            if (r ==-1)
            {
                printf("not found");
            }
            else
            {
                printf("%d\n",r);
                printData();
            }
        }
        else if(strncmp(str, "first", 4) == 0)
        {
            int r = firstNode();
            printf("%d\n",r);
        }
        else if(strncmp(str, "last", 4) == 0)
        {
            int r = lastNode();
            printf("%d\n",r);
        }
        else if(strncmp(str, "list", 4) == 0)
        {
            printData();
        }
        else if(strncmp(str, "clear", 4) == 0)
        {
            clearNodes();
        }
        else
        {
            printf("unknown command %s",str);
        }
	}

	return EXIT_SUCCESS;
}
