#include<stdio.h>
#include<stdlib.h>
typedef struct term {
 int coeff;
 int pow;
 struct term * next;
} poly;

void create_poly(poly **);
void display(poly *);
void add(poly **, poly *, poly *);
int main()
{
 poly * poly1, * poly2, * poly3;
 create_poly(&poly1);
 create_poly(&poly2);
display(poly1);
 display(poly2);
 add(&poly3, poly1, poly2);
 display(poly3);
 return 0;
}
void create_poly(poly ** node) {
 int flag;
 int coeff, pow;
 poly * tmp_node;
 tmp_node = (poly *) malloc(sizeof(poly));
 *node = tmp_node;
 do {


 scanf("%d", &coeff);
 tmp_node->coeff = coeff;

 scanf("%d", &pow);
 tmp_node->pow = pow;
 tmp_node->next = NULL;
 scanf("%d", &flag);

 if(flag) {
 tmp_node->next = (poly *) malloc(sizeof(poly)); //Grow the list
 tmp_node = tmp_node->next;
 tmp_node->next = NULL;
 }
 } while (flag);
}

void display(poly * node) {
 printf("\nThe polynomial expression is:\n");
 while(node != NULL) {
 printf("%dx^%d", node->coeff, node->pow);
 node = node->next;
 if(node != NULL)
 printf(" + ");
 }
printf("\n");
}

void add(poly ** result,poly * poly1,poly * poly2) {
    poly * temp;
    temp = (poly *) malloc(sizeof(poly));
    temp->next = NULL;
    *result = temp;

    while(poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        else {
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff + poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

            if(poly1 && poly2) {
            temp->next = (poly *) malloc(sizeof(poly));
            temp = temp->next;
            temp->next = NULL;
        }
    }


    while(poly1 || poly2) {
        temp->next = (poly *) malloc(sizeof(poly));
        temp = temp->next;
        temp->next = NULL;

        if(poly1) {
            temp->pow = poly1->pow;
            temp->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2) {
            temp->pow = poly2->pow;
            temp->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
    }

    printf("\nAddition Complete");
}