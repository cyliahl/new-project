#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
void createCustomer(Customer *customer) {
    printf("Enter customer ID: ");
    scanf("%d", &customer->customerID);
    printf("Enter first name: ");
    scanf("%s", customer->firstName);
    printf("Enter last name: ");
    scanf("%s", customer->lastName);
    printf("Enter contact info: ");
    scanf("%s", customer->contactInfo);
}

void displayCustomer(Customer customer) {
    printf("ID: %d, Name: %s %s, Contact: %s\n", 
        customer.customerID, customer.firstName, customer.lastName, customer.contactInfo);
}