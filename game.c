#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct player{
    char name[30];
    int pts;
    struct player *next;
}*head=NULL;
int num,i;
void createplayer(){
    struct player *newplayer=(struct player*)malloc(sizeof(struct player));
    printf("Enter name:");
    scanf("%s",newplayer->name);
    newplayer->pts=50;
    newplayer->next=NULL;
    if(head==NULL)
     head=newplayer;
     else{
         struct player *temp=head;
         while(temp->next!=NULL)
           temp=temp->next;
         temp->next=newplayer; 
     }
}
void eliminate(int pos){
    if(pos==1)
    {
        if(head->next==NULL)
        {
         printf("%s got eliminated\n",head->name);
         num--;
         free(head);
        }
        else
         {
         printf("%s got eliminated\n",head->name);
         struct player *temp=head;
         head=head->next;
         num--;
         free(temp);
         }
    }
    else if(pos==num)
    {
        struct player *temp=head;
        while(temp->next->next!=NULL)
         temp=temp->next;
        printf("%s got eliminated\n",temp->next->name);
        free(temp->next);
        temp->next=NULL;
        num--;
    }
    else{
        struct player *temp1=head,*temp2=head;
        for(i=1;i<pos;i++)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        printf("%s got eliminated\n",temp1->name);
        struct player *temp=temp1;
        temp2->next=temp1->next;
        free(temp);
        num--;
    }
}
void play(){
    int pos=1,play;
    struct player *temp=head;
    while(temp!=NULL)
    {
        printf("%s enter the number:",temp->name);
        scanf("%d",&play);
        play+=2;
        play/=2;
        play*=2;
        temp->pts-=play;
        if(temp->pts<=0)
        {
            eliminate(pos);
        }
        temp=temp->next;
        pos++;
    }
}
void sort(){
    struct player *temp=head;
    int temp2;
    char na[30];
    struct player *temp1;
    while(temp!=NULL)
    {
     temp1=temp->next;
        while(temp1!=NULL)
        {
            if(temp->pts>temp1->pts)
            {
                temp2=temp->pts;
                temp->pts=temp1->pts;
                temp1->pts=temp2;
                strcpy(na,temp->name);
                strcpy(temp->name,temp1->name);
                strcpy(temp1->name,na);
            }
            temp1=temp1->next;
        }
        
        temp=temp->next;
    }
}
void result(){
    i=1;
    struct player *temp=head;
    while(temp!=NULL)
    {
        printf("%d) Name: %s Points: %d\n",i,temp->name,temp->pts);
        i++;
       temp=temp->next; 
    }
}
int main()
{
    printf("Enter the total number of players:");
    scanf("%d",&num);
    for(i=0;i<num;i++)
     createplayer();
    for(i=0;i<5;i++)
     play();
    sort();
    result();
    return 0;
}
