//p.a	//#include<stdio.h>
////#include<stdlib.h>
////
////struct node{
////	int data;
////	struct node *next;
////}
////
////int main(){
////	struct node *start1, *start2, *p1 = start1, *p2 = start2, *p, *start;
////	
////	int ex1,ex2,cof1,cof2,ex,cof;
////	
////	
////	while(p1->next != NULL && p2->next != NULL){
////		if(ex1 > ex2){
////			cof = cof1;
////			ex = ex1;
////			p1 = p1->next;
////		}
////		else if(ex1 < ex2){
////			cof = cof2;
////			ex = ex2;
////			p2 = p2->next;
////		}
////		else{
////			cof = cof1 + cof2;
////			ex = ex1;
////			p1 = p13333333333333333333333333333333333333333333333333..........................................->next;
////			p2 = p2->next;
////		}
////}
//
//#include <stdio.h>
//#include <stdlib.h>
//
//// Node structure for a node in a polynomial
//struct node {
//    int coef;
//    int expo;
//    struct node* next;
//};
//
//// Function to add two polynomials
//struct node* add_poly(struct node* poly1, struct node* poly2) {
//    struct node* result = NULL;
//    struct node* cur_result = NULL;
//
//    while (poly1 != NULL || poly2 != NULL) {
//        struct node* n = (struct node*)malloc(sizeof(struct node));
//        n->next = NULL;
//
//        if (poly1 == NULL || (poly2 != NULL && poly1->expo < poly2->expo)) {
//            n->coef = poly2->coef;
//            n->expo = poly2->expo;
//            poly2 = poly2->next;
//        } else if (poly2 == NULL || (poly1 != NULL && poly1->expo > poly2->expo)) {
//            n->coef = poly1->coef;
//            n->expo = poly1->expo;
//            poly1 = poly1->next;
//        } else {
//            n->coef = poly1->coef + poly2->coef;
//            n->expo = poly1->expo;
//            poly1 = poly1->next;
//            poly2 = poly2->next;
//        }
//
//        if (result == NULL) {
//            result = n;
//            cur_result = result;
//        } else {
//            cur_result->next = n;
//            cur_result = n;
//        }
//    }
//
//    return result;
//}
//
//// Function to print a polynomial
//void printPolynomial(struct node* poly) {
//    while (poly != NULL) {
//        printf("%dx^%d", poly->coef, poly->expo);
//        poly = poly->next;
//        if (poly != NULL) {
//            printf(" + ");
//        }
//    }
//    printf("\n");
//}
//
//// Function to create a new node in the polynomial
//struct node* create_node(int coef, int expo) {
//    struct node* n = (struct node*)malloc(sizeof(struct node));
//    n->coef = coef;
//    n->expo = expo;
//    n->next = NULL;
//    return n;
//}
//
//int main() {
//    // Example usage
//    struct node* poly1 = create_node(3, 2);
//    poly1->next = create_node(4, 1);
//    poly1->next->next = create_node(5, 0);
//
//    struct node* poly2 = create_node(2, 3);
//    poly2->next = create_node(1, 2);
//    poly2->next->next = create_node(2, 0);
//
//    printf("Polynomial 1: ");
//    printPolynomial(poly1);
//
//    printf("Polynomial 2: ");
//    printPolynomial(poly2);
//
//    struct node* result = add_poly(poly1, poly2);
//
//    printf("Sum of Polynomials: ");
//    printPolynomial(result);
//
//    // Don't forget to free the memory allocated for the nodes
//    while (poly1 != NULL) {
//        struct node* temp = poly1;
//        poly1 = poly1->next;
//        free(temp);
//    }
//
//    while (poly2 != NULL) {
//        struct node* temp = poly2;
//        poly2 = poly2->next;
//        free(temp);
//    }
//
//    while (result != NULL) {
//        struct node* temp = result;
//        result = result->next;
//        free(temp);
//    }
//
//    return 0;
//}                                                                                                     