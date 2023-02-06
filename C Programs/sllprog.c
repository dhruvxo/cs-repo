
//Menu Driven Single Linked List//
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL, *ptr;

void insert_begin(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}

void insert_end(int value)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;

	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->next != NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->next=NULL;
	}
}

void insert_After_specified_ele(int value,int ele)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	if (head== NULL)
	{
		head=temp;
	}
	else
	{
		ptr=head;
		while(ptr->data != ele)
		{
			ptr=ptr->next;
		}
		temp->next=ptr->next;
		ptr->next=temp;
	}

}

void delete_begin()
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		ptr=head;
		head=head->next;
		ptr->next=NULL;
		free(ptr);
	}
}

void delete_end()
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p;
		ptr=head;
		while(ptr->next != NULL)
		{
		p=ptr;
		ptr=ptr->next;
		}
		p->next=NULL;
		free(ptr);
	}
}

void delete_middle(int ele)
{
	if (head== NULL)
	{
		printf("List if Empty, Deletion is not Possible");
	}
	else
	{
		struct node *p;
		ptr=head;
		while(ptr->data != ele)
		{
			p=ptr;
			ptr=ptr->next;
		}
		p->next=ptr->next;
		free(ptr);
	}
}

void display()
{
	if (head== NULL)
	{
		printf("List if Empty");
	}
	else
	{
		ptr=head;
		while( ptr != NULL)
		{
			printf("-> %d", ptr->data);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search?\n");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("item found at location %d\n",i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
    }
}

void reverse()
{
	struct node *p=NULL,*c, *n=NULL;
	c=p->head;
	while(c!=NULL)
	{
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
}

void main()
{
	int value,ele,ch;
	printf("1. Insert_begin \n");
	printf("2. Insert_end \n");
	printf("3. Insert_after_specified_element \n");
	printf("4. Delete_begin \n");
	printf("5. Delete_end \n");
	printf("6. Delete_middle \n");
	printf("7. Exit \n");
    printf("8. Search \n");
	printf("9. Reverse \n");

	while(1)
	{
		printf("Enter the Choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					printf("Enter the value");
					scanf("%d",&value);
					insert_begin(value);
					display();
					break;
				}
				case 2:
				{
					printf("Enter the value");
					scanf("%d",&value);
					insert_end(value);
					display();
					break;
				}
				case 3:
					{
					printf("Enter the value");
					scanf("%d",&value);
					printf("After which element u want to insert");
					scanf("%d",&ele);
					insert_After_specified_ele(value,ele);
					display();
					break;
				}
				case 4:
					{
					delete_begin();
					display();
					break;
				}
				case 5:
				{
					delete_end();
					display();
					break;
				}
				case 6:
				{
					printf("Enter the element you want to delete");
					scanf("%d",&ele);
					delete_middle(ele);
					display();
					break;
				}

				case 7:
				{
					exit(0);

				}
				case 8:
				{
				    search();
                }
				case 9:
				{
					reverse();
				}
		}
	}
}	