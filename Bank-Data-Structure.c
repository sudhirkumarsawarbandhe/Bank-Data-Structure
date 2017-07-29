#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
typedef enum {SUCCESS,FAILURE}status;
typedef struct Details
{
    long int acc_num;
    char cust_name[50];
    char branch_id[10];
    long int deposite;
    char address[50];
    long int pan_no;
    long int phone;
}Details;
typedef struct link_list
{
    Details rec;
    struct link_list *next;
}bank_rec;
bank_rec* create_node();
status insert_rec(bank_rec**,bank_rec*);
status delete_rec(bank_rec**,char [],char []);
void print_list(bank_rec *);
int getNumRecords(bank_rec *);
void isEmpty(bank_rec *);
void list_unique(bank_rec *);
void get_Max_Deposite(char [],bank_rec *);
bank_rec* initialise();
bank_rec* list_union(bank_rec *,bank_rec *);
bank_rec* list_intersection(bank_rec *,bank_rec *);
bank_rec* list_difference(bank_rec *,bank_rec *);
bank_rec* list_symmetric_difference(bank_rec *,bank_rec *);
int main()
{
    bank_rec *list1=NULL,*list2=NULL,*list3=NULL,*nptr=NULL;
    char name[50],branch_id[10];
    int choice,ch,exit=1,num;
    status sc;
    printf("Welcome to V.N.I.T Bank!\n");
    while(exit)
          {
                printf("Enter your choice....\n1.INSERT RECORD\n2.DELETE RECORD\n3.GET NUMBER OF RECORDs\n4.CHECK WEATHER EMPTY\n5.LIST UNIQUE\n6.GET MAXIMUM DEPOSITE\n7.LIST UNION\n8.LIST INTERSECTION\n9.LIST DIFFERENCE\n10.LIST SYMMETRIC DIFFERENCE\n11.Print..\n12.EXIT\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                        {
                            nptr=NULL;
                            nptr=(bank_rec*)malloc(sizeof(bank_rec));
                            nptr=create_node();
                            printf("Enter the list number in which you have to enter the details...\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            sc=insert_rec(&list1,nptr);
                            if(ch==2)
                            sc=insert_rec(&list2,nptr);
                            if(sc==SUCCESS)
                            {
                                printf("Insertion was successfull.\n");
                            }
                            if(sc==FAILURE)
                            {
                                printf("Data could not be inserted.\n");
                            }
                            break;
                        }
                    case 2:// delete:
                        {
                            printf("Enter the list number from which you want to delete the details...\n");
                            scanf("%d",&ch);
                            printf("Enter the name and branch id...\n");
                            scanf("%s",name);
                            scanf("%s",branch_id);
                            if(ch==1)
                            sc=delete_rec(&list1,name,branch_id);
                            if(ch==2)
                            sc=delete_rec(&list2,name,branch_id);
                            if(sc=SUCCESS)
                                printf("SUCCESSFULLY deleted...\n");
                            else
                                printf("THE RECORD DOES NOT EXISTS...\n");
                            break;
                        }
                    case 3:// get number of records..
                        {
                            printf("Enter the list number...\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            num=getNumRecords(list1);
                            if(ch==2)
                            num=getNumRecords(list2);
                            printf("Number of records = %d\n",num);
                            break;
                        }
                    case 4://is empty..
                        {
                            printf("Enter the list number...\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            isEmpty(list1);
                            if(ch==2)
                            isEmpty(list2);
                            break;
                        }
                    case 5:
                        {
                            printf("Enter the list number...\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            list_unique(list1);
                            if(ch==2)
                            list_unique(list2);
                            break;
                        }
                    case 6:
                        {
                            printf("Enter the branch Id...\n");
                            scanf("%s",branch_id);
                            printf("Enter the list number...\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            get_Max_Deposite(branch_id,list1);
                            if(ch==2)
                            get_Max_Deposite(branch_id,list2);
                            break;
                        }
                    case 7:
                        {
                            list3=initialise();
                            list3=list_union(list1,list2);
                            break;
                        }
                    case 8:
                        {
                            list3=initialise();
                             list3=list_intersection(list1,list2);
                            break;
                        }
                    case 9:
                        {
                            list3=initialise();
                            list3=list_difference(list1,list2);
                            break;
                        }
                    case 10:
                        {
                            list3=initialise();
                            list3=list_symmetric_difference(list1,list2);
                            break;
                        }
                    case 11:
                        {
                            printf("Enter the list to be printed..\n");
                            scanf("%d",&ch);
                            if(ch==1)
                            print_list(list1);
                            if(ch==2)
                            print_list(list2);
                            if(ch==3)
                            print_list(list3);
                            break;
                        }
                    case 12:
                        {
                            exit=0;
                        }
                    default:
                        {
                            break;
                        }
                }
          }

    return 0;
}
bank_rec* initialise()
{
     bank_rec *ptr;
     ptr=(bank_rec*)malloc(sizeof(bank_rec));
     ptr->rec.acc_num=0;
     ptr->rec.phone=0.0;
     ptr->rec.pan_no=0;
     ptr->rec.deposite=0;
     ptr->rec.cust_name[0]='\0';
     ptr->rec.address[0]='\0';
     ptr->rec.branch_id[0]='\0';
     ptr->next=NULL;
     return ptr;
}
bank_rec* create_node()
{
    char name[10],id[10],add[50];
    long int acc_no,dep,pan,ph;    int i;
    bank_rec *nptr=NULL;
    printf("Enter the details:\n1.Name:\t");
    scanf("%s",name);
    printf("2.Branch Id:\t");
    scanf("%s",id);
    printf("3.Account number:\t");
    scanf("%d",&acc_no);
    printf("4.Deposite:\t");
    scanf("%d",&dep);
    printf("5.Address:\t");
    scanf("%s",add);
    printf("6.Pan number:\t");
    scanf("%d",&pan);
    printf("7.Phone number:\t");
    scanf("%d",&ph);
    nptr=(bank_rec*)malloc(sizeof(bank_rec));
    strcpy(nptr->rec.cust_name,name);
    strcpy(nptr->rec.branch_id,id);
    strcpy(nptr->rec.address,add);
    nptr->rec.acc_num=acc_no;
    nptr->rec.deposite=dep;
    nptr->rec.phone=ph;
    nptr->rec.pan_no=pan;

return nptr;
}
status insert_rec(bank_rec **lptr,bank_rec *nptr)
{
   bank_rec *ptr=NULL;
   ptr=*lptr;
   status sc=SUCCESS;
   int found=0;
   if(ptr==NULL)
   {
       ptr=nptr;
       found=1;
   }
   else{
    while(ptr->next!=NULL&&found==0)
    {
        if((strcmp(ptr->rec.cust_name,nptr->rec.cust_name)==0)&&(strcmp(ptr->rec.branch_id,nptr->rec.branch_id)==0))
        {
            ptr->rec.acc_num=nptr->rec.acc_num;
            ptr->rec.deposite=ptr->rec.deposite;
            ptr->rec.pan_no=ptr->rec.pan_no;
            strcpy(ptr->rec.address,nptr->rec.address);
            ptr->rec.phone=nptr->rec.phone;
            found=1;
        }
        else
        ptr=ptr->next;
    }
    ptr=*lptr;
    if(found==0)
    {
        nptr->next=ptr;
        ptr=nptr;
    }
    }//else loop...
   *lptr=ptr;
   return sc;
}
//delete function..
status delete_rec(bank_rec **lpptr,char name[],char branch_id[])
{
    bank_rec *prev,*ptr,*lptr;
    status sc=FAILURE;
    lptr=*lpptr;
    if(lptr!=NULL)
    {
        if(lptr->next==NULL)//for single node
        {
            if((strcmp(lptr->rec.cust_name,name)==0)&&(strcmp(lptr->rec.branch_id,branch_id)==0))
            {
                free(lptr);
                lptr=NULL;
                sc=SUCCESS;
            }
        }
        else//if not a single node
        {
            while(lptr->next!=NULL&&sc==FAILURE)
            {
                if((strcmp(lptr->rec.cust_name,name)==0)&&(strcmp(lptr->rec.branch_id,branch_id)==0))
                {
                    prev=lptr;
                    ptr=lptr->next;
                    lptr=ptr->next;
                    prev->next=lptr;
                    free(ptr);
                    ptr=NULL;
                    sc=SUCCESS;
                }
                else
                {
                    lptr=lptr->next;
                }
            }

        }
    }
    return sc;

}
int getNumRecords(bank_rec *lptr)
{
    int num=1;
    if(lptr!=NULL)
    {
        while(lptr->next!=NULL)
        {
            lptr=lptr->next;
            num++;
        }
    }
    else{
        num=0;
    }
    return num;
}
void print_list(bank_rec *lptr)
{
    bank_rec *ptr=NULL;
    ptr=lptr;
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
        {
            printf("Name of account holder:\t%s\n",ptr->rec.cust_name);
            printf("Branch Id:\t%s\n",ptr->rec.branch_id);
            printf("Account number:\t%d\n",ptr->rec.acc_num);
            printf("Deposited money:\t%d\n",ptr->rec.deposite);
            printf("Address of the customer:\t%s\n",ptr->rec.address);
            printf("Pan number:\t%d\n",ptr->rec.pan_no);
            printf("Phone number:\t%d\n",ptr->rec.phone);
            ptr=ptr->next;
        }
    }
    else
    printf("\nlist is Empty..\n\n");
}
void isEmpty(bank_rec *lptr)
{
    if(lptr==NULL)
        printf("The list is empty\n");
    else
        printf("The list is not empty\n");
}
void list_unique(bank_rec *lptr)
{
    int i,j;
    bank_rec *ptr=lptr,*nextnode;
    if(ptr!=NULL)
    {
        nextnode=ptr->next;
        while(nextnode!=NULL)
        {
                          i=strcmp(ptr->rec.cust_name,nextnode->rec.cust_name);
                          j=strcmp(ptr->rec.acc_num,nextnode->rec.acc_num);
                          if(i!=0&&j!=0)
                          {
                                        ptr=nextnode;
                                        nextnode=nextnode->next;
                          }
                          else
                          {
                                        ptr->next=nextnode->next;
                                        free(nextnode);
                                        nextnode=ptr->next;
                          }
        }
    }
}
void get_Max_Deposite(char branch_id[],bank_rec *lptr)
{
     bank_rec *ptr=lptr,*temp=lptr;
     int max_dep=0,c=0;
     int x;
     while(ptr!=NULL)
     {
                           if(strcmp(ptr->rec.branch_id,branch_id)==0&&ptr->rec.deposite>max_dep)
                           {
                                        max_dep=ptr->rec.deposite;
                                        c=1;

                           }
                           ptr=ptr->next;
     }
     if(c==0)
     {
             printf("There is no such branch id\n");
     }
     else
     {

         while(temp!=NULL)
         {
                      if(strcmp(ptr->rec.branch_id,branch_id)==0&&temp->rec.deposite==max_dep)
                      {
                                                    printf("Customer %s has maximum deposite of %s with %d deposite\n",temp->rec.cust_name,temp->rec.branch_id,temp->rec.deposite);
                      }
                      temp=temp->next;
         }
     }
}
bank_rec* list_union(bank_rec *lptr1,bank_rec *lptr2)
{
     int ;
     bank_rec *ptr1=lptr1,*ptr2=lptr2,*temp,*newnode;
     temp=initialise();
     list_unique(ptr1);
     list_unique(ptr2);
     bank_rec *lptr3=temp;
     if(ptr1==NULL&&ptr2==NULL)
     {
                               printf("Both lists are empty\n");
     }
     else
     {
         while(ptr1!=NULL&&ptr2!=NULL)
         {

                                  if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)>0)||(strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)>0))
                                  {
                                                     newnode=create_node(ptr2);
                                                     temp->next=newnode;
                                                     temp=newnode;
                                                     ptr2=ptr2->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)<0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)<0)))
                                  {
                                                     newnode=create_node(ptr1);
                                                     temp->next=newnode;
                                                     temp=newnode;
                                                     ptr1=ptr1->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)==0))
                                  {
                                       newnode=create_node(ptr1);
                                       temp->next=newnode;
                                       temp=newnode;
                                       ptr1=ptr1->next;
                                       ptr2=ptr2->next;
                                  }
         }
     }
     if(ptr1!=NULL)
     {
                   while(ptr1!=NULL)
                   {
                                    newnode=create_node(ptr1);
                                    temp->next=newnode;
                                    temp=newnode;
                                    ptr1=ptr1->next;
                   }
     }
     else if(ptr2!=NULL)
     {
                   while(ptr2!=NULL)
                   {
                                    newnode=create_node(ptr2);
                                    temp->next=newnode;
                                    temp=newnode;
                                    ptr2=ptr2->next;
                   }
     }
     temp->next=NULL;
     temp=lptr3;
     lptr3=lptr3->next;
     free(temp);
     return lptr3;
}
bank_rec* list_intersection(bank_rec *lptr1,bank_rec *lptr2)
{

     bank_rec *ptr1=lptr1,*ptr2=lptr2,*temp,*newnode;
     temp=initialise();
     list_unique(ptr1);
     list_unique(ptr2);
     bank_rec *lptr3=temp;
     if(ptr1==NULL&&ptr2==NULL)
     {
                               printf("Both lists are empty\n");
     }
     else
     {
         while(ptr1!=NULL&&ptr2!=NULL)
         {

                                  if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)>0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)>0)))
                                  {
                                                     ptr2=ptr2->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)<0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)<0)))
                                  {
                                                     ptr1=ptr1->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)==0))
                                  {
                                       newnode=create_node(ptr1);
                                       temp->next=newnode;
                                       temp=newnode;
                                       ptr1=ptr1->next;
                                       ptr2=ptr2->next;
                                  }
         }
     }
     temp->next=NULL;
     temp=lptr3;
     lptr3=lptr3->next;
     free(temp);
     return lptr3;
}
bank_rec* list_difference(bank_rec *lptr1,bank_rec *lptr2)
{
     bank_rec *ptr1=lptr1,*ptr2=lptr2,*temp,*newnode;
     temp=initialise();
     list_unique(ptr1);
     list_unique(ptr2);
     bank_rec *lptr3=temp;
     if(ptr1==NULL&&ptr2==NULL)
     {
                               printf("Both lists are empty\n");
     }
     else
     {
         while(ptr1!=NULL&&ptr2!=NULL)
         {

                                  if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)>0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)>0)))
                                  {
                                                     ptr2=ptr2->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)<0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)<0)))
                                  {
                                                     newnode=create_node(ptr1);
                                                     temp->next=newnode;
                                                     temp=newnode;
                                                     ptr1=ptr1->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.branch_id,ptr2->rec.branch_id)==0))
                                  {
                                       ptr1=ptr1->next;
                                       ptr2=ptr2->next;
                                  }
         }
         if(ptr1!=NULL)
         {
                   while(ptr1!=NULL)
                   {
                                    newnode=create_node(ptr1);
                                    temp->next=newnode;
                                    temp=newnode;
                                    ptr1=ptr1->next;
                   }
         }
     }
     temp->next=NULL;
     temp=lptr3;
     lptr3=lptr3->next;
     free(temp);
     return lptr3;
}
bank_rec* list_symmetric_difference(bank_rec *lptr1,bank_rec *lptr2)
{
     bank_rec *ptr1=lptr1,*ptr2=lptr2,*temp,*newnode;
     temp=initialise();
     list_unique(ptr1);
     list_unique(ptr2);
     bank_rec *lptr3=temp;
     if(ptr1==NULL&&ptr2==NULL)
     {
                               printf("Both lists are empty\n");
     }
     else
     {
         while(ptr1!=NULL&&ptr2!=NULL)
         {

                                  if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)>0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)>0)))
                                  {
                                                     newnode=create_node(ptr2);
                                                     temp->next=newnode;
                                                     temp=newnode;
                                                     ptr2=ptr2->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)<0)||((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)<0)))
                                  {
                                                     newnode=create_node(ptr1);
                                                     temp->next=newnode;
                                                     temp=newnode;
                                                     ptr1=ptr1->next;
                                  }
                                  else if((strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0)&&(strcmp(ptr1->rec.cust_name,ptr2->rec.cust_name)==0))
                                  {
                                       ptr1=ptr1->next;
                                       ptr2=ptr2->next;
                                  }
         }
         if(ptr1!=NULL)
         {
                   while(ptr1!=NULL)
                   {
                                    newnode=create_node(ptr1);
                                    temp->next=newnode;
                                    temp=newnode;
                                    ptr1=ptr1->next;
                   }
         }
         if(ptr2!=NULL)
         {
                   while(ptr2!=NULL)
                   {
                                    newnode=create_node(ptr2);
                                    temp->next=newnode;
                                    temp=newnode;
                                    ptr2=ptr2->next;
                   }
         }
     }
     temp->next=NULL;
     temp=lptr3;
     lptr3=lptr3->next;
     free(temp);
     return lptr3;
}
