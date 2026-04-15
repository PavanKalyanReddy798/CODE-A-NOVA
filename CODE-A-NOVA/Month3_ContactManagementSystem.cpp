#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing contact details
struct Contact {
    char name[50];
    char phone[15];
};

// Function declarations
void addContact();
void displayContacts();
void searchContact();
void deleteContact();
void editContact();

int main() {
    int choice;

    while (1) {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function to add a new contact
void addContact() {
    FILE *fp;
    struct Contact c;

    fp = fopen("contacts.txt", "a"); // append mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);

    printf("Enter Phone: ");
    scanf("%s", c.phone);

    fwrite(&c, sizeof(c), 1, fp); // write structure to file

    fclose(fp);
    printf("Contact added successfully!\n");
}

// Function to display all contacts
void displayContacts() {
    FILE *fp;
    struct Contact c;

    fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("\n--- Contact List ---\n");

    while (fread(&c, sizeof(c), 1, fp)) {
        printf("Name: %s | Phone: %s\n", c.name, c.phone);
    }

    fclose(fp);
}

// Function to search contact by name
void searchContact() {
    FILE *fp;
    struct Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("No contacts found!\n");
        return;
    }

    printf("Enter name to search: ");
    scanf(" %[^\n]", name);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("Found: Name: %s | Phone: %s\n", c.name, c.phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found!\n");
    }

    fclose(fp);
}

// Function to delete a contact
void deleteContact() {
    FILE *fp, *temp;
    struct Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter name to delete: ");
    scanf(" %[^\n]", name);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) != 0) {
            fwrite(&c, sizeof(c), 1, temp); // keep others
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.txt");        // delete original file
    rename("temp.txt", "contacts.txt"); // rename temp file

    if (found)
        printf("Contact deleted successfully!\n");
    else
        printf("Contact not found!\n");
}

// Function to edit a contact
void editContact() {
    FILE *fp, *temp;
    struct Contact c;
    char name[50];
    int found = 0;

    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter name to edit: ");
    scanf(" %[^\n]", name);

    while (fread(&c, sizeof(c), 1, fp)) {
        if (strcmp(c.name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", c.phone);
            found = 1;
        }
        fwrite(&c, sizeof(c), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        printf("Contact updated successfully!\n");
    else
        printf("Contact not found!\n");
}
