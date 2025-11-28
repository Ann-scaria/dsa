#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char url[100];
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct Browser {
    Node *current;
} Browser;

Browser *createBrowser() {
    Browser *browser = (Browser *)malloc(sizeof(Browser));
    browser->current = NULL;
    return browser;
}

void visitNewPage(Browser *browser, const char *url) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->url, url);
    newNode->prev = browser->current;
    newNode->next = NULL;

    if (browser->current != NULL) {
        browser->current->next = newNode;
    }

    browser->current = newNode;
    printf("Visited: %s\n", browser->current->url);
}

void goBack(Browser *browser) {
    if (browser->current == NULL || browser->current->prev == NULL) {
        printf("Cannot go back\n");
    } else {
        browser->current = browser->current->prev;
        printf("Moved back to: %s\n", browser->current->url);
    }
}

void goForward(Browser *browser) {
    if (browser->current == NULL || browser->current->next == NULL) {
        printf("Cannot go forward\n");
    } else {
        browser->current = browser->current->next;
        printf("Moved forward to: %s\n", browser->current->url);
    }
}

void displayCurrentPage(Browser *browser) {
    if (browser->current == NULL) {
        printf("No page visited yet\n");
    } else {
        printf("Current Page: %s\n", browser->current->url);
    }
}

void menu() {
    printf("\n1. Visit New Page\n");
    printf("2. Go Back\n");
    printf("3. Go Forward\n");
    printf("4. Display Current Page\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Browser *browser = createBrowser();
    int choice;
    char url[100];

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar();    // eat the '\n' after the number

        switch (choice) {
        case 1:
            printf("Enter URL: ");
            fgets(url, 100, stdin);
            url[strcspn(url, "\n")] = '\0';   // remove newline
            visitNewPage(browser, url);
            break;

        case 2:
            goBack(browser);
            break;

        case 3:
            goForward(browser);
            break;

        case 4:
            displayCurrentPage(browser);
            break;

        case 5:
            printf("Exiting Browser Simulation\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
}
