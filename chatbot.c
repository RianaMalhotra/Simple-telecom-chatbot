#include <stdio.h>
#include <string.h>

// Define functions for question flow
void askServiceType();
void askIssueType(char service[]);
void provideSolution(char service[], char issue[]);

int main() {
    printf("Welcome to TelecomBot! Let's get started.\n\n");
    askServiceType();
    return 0;
}

// Function to ask for the type of service
void askServiceType() {
    char service[20];

    printf("Chatbot: What service are you experiencing an issue with? (mobile, internet, TV): ");
    scanf("%s", service);

    if (strcmp(service, "mobile") == 0 || strcmp(service, "internet") == 0 || strcmp(service, "TV") == 0) {
        askIssueType(service);  // Pass the service type to the next function
    } else {
        printf("Chatbot: Sorry, I didn’t recognize that service. Please type 'mobile', 'internet', or 'TV'.\n");
        askServiceType();  // Repeat the question
    }
}

// Function to ask for the issue type based on service
void askIssueType(char service[]) {
    char issue[20];

    printf("Chatbot: What kind of issue are you experiencing? (connectivity, billing, technical): ");
    scanf("%s", issue);

    if (strcmp(issue, "connectivity") == 0 || strcmp(issue, "billing") == 0 || strcmp(issue, "technical") == 0) {
        provideSolution(service, issue);  // Pass both service and issue to the next function
    } else {
        printf("Chatbot: Sorry, I didn’t recognize that issue type. Please type 'connectivity', 'billing', or 'technical'.\n");
        askIssueType(service);  // Repeat the question
    }
}

// Function to provide a solution based on the gathered information
void provideSolution(char service[], char issue[]) {
    printf("\nChatbot: Here’s what I recommend based on your selections:\n");

    if (strcmp(service, "mobile") == 0) {
        if (strcmp(issue, "connectivity") == 0) {
            printf("Solution: Please check your network settings and make sure mobile data is enabled.\n");
        } else if (strcmp(issue, "billing") == 0) {
            printf("Solution: You can view and pay your mobile bill by logging into your account online.\n");
        } else {
            printf("Solution: For technical issues, please try restarting your device. If the problem persists, contact support.\n");
        }
    } else if (strcmp(service, "internet") == 0) {
        if (strcmp(issue, "connectivity") == 0) {
            printf("Solution: Try rebooting your modem. If the issue persists, check for any service outages in your area.\n");
        } else if (strcmp(issue, "billing") == 0) {
            printf("Solution: You can check your internet bill and make payments through your online account.\n");
        } else {
            printf("Solution: For technical issues, please contact support for troubleshooting assistance.\n");
        }
    } else if (strcmp(service, "TV") == 0) {
        if (strcmp(issue, "connectivity") == 0) {
            printf("Solution: Ensure your set-top box is connected to the network and try rebooting it.\n");
        } else if (strcmp(issue, "billing") == 0) {
            printf("Solution: You can view and pay your TV subscription bill by logging into your account.\n");
        } else {
            printf("Solution: For technical issues with your TV, try resetting the set-top box or contact support.\n");
        }
    }

    printf("Chatbot: Thank you for using TelecomBot! If you need further assistance, please call customer support.\n");
}
