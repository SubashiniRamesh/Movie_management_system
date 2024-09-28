#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    int mnum;
    char cname[30];
    char mname[30];
    char mdate[12];
    int mtimehour;
    int mtime;
    char ttype[30];
    int guestsnum;
    int housenum;
    int fee;
};

// Function for ice cream menu
int icecream(){
    int ch1, total1 = 0;
    while (ch1 != 6) {
        printf("\n1. Chocolate-60\n2. Vanilla-30\n3. Butter pecan-80\n4. Cotton candy-100\n5. Cherry-65\n6. Exit");
        printf("\nEnter your favorite: ");
        scanf("%d", &ch1);
        switch (ch1) {
            case 1:
                total1 += 60;
                break;
            case 2:
                total1 += 30;
                break;
            case 3:
                total1 += 80;
                break;
            case 4:
                total1 += 100;
                break;
            case 5:
                total1 += 65;
                break;
            case 6:
                printf("\nThank you");
                break;
            default:
                printf("\nInvalid choice, please try again.");
                break;
        }
    }
    return total1;
}

// Function for snack menu
void snacks() {
    int ch, total = 0, res;
    while (ch != 6) {
        printf("1. Chips-medium size-30\n2. Popcorn-medium-70\n3. Ice cream\n4. Cold coffee-80\n5. Puffs-55\n6. Exit");
        printf("\nEnter your items: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                total += 30;
                break;
            case 2:
                total += 70;
                break;
            case 3:
                res = icecream();
                total += res;
                break;
            case 4:
                total += 80;
                break;
            case 5:
                total += 55;
                break;
            case 6:
                printf("Thank you");
                break;
            default:
                printf("Invalid choice, please try again.");
                break;
        }
    }
    printf("Your total amount for snacks is %d\n", total);
}

// Function to add a new movie booking record
// Function to add a new movie booking record
void addMov() {
    struct book b;
    int ttype_choice; // Variable to store ticket type choice
    FILE *fp;
    
    // Movie Booking Number Input
    printf("Enter Movie Booking Number (XXXX): ");
    scanf("%d", &b.mnum);
    while (b.mnum < 1 || b.mnum > 9999) {
        printf("Re-enter Movie Booking Number! It should be between 0001 to 9999!: ");
        scanf("%d", &b.mnum);
    }

    // Customer Name Input
    printf("Enter Name of Customer: ");
    getchar(); // to clear the input buffer
    fgets(b.cname, sizeof(b.cname), stdin);
    b.cname[strcspn(b.cname, "\n")] = '\0'; // remove newline character
    
    // Movie Name Input
    printf("Enter Name of Movie: ");
    fgets(b.mname, sizeof(b.mname), stdin);
    b.mname[strcspn(b.mname, "\n")] = '\0'; // remove newline character
    
    // Movie Schedule Input
    printf("Enter Movie Schedule (DD-MM-YYYY): ");
    scanf("%s", b.mdate);
    
    // Movie Time Input
    printf("Enter Time (XXXX): ");
    scanf("%d", &b.mtime);
    while (b.mtime < 1000 || b.mtime > 2300) {
        printf("Re-enter Time! It should be in 24-hour format and between 1000 to 2300!: ");
        scanf("%d", &b.mtime);
    }

    // Number of Guests Input
    printf("Enter Number of Guests: ");
    scanf("%d", &b.guestsnum);

    // House Number Input
    printf("Enter House Number: ");
    scanf("%d", &b.housenum);

    // Ticket Type Input with options
    printf("Select Ticket Type: \n");
    printf("1. Premium (200 per guest)\n");
    printf("2. First Class (150 per guest)\n");
    printf("3. Second Class (100 per guest)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &ttype_choice);

    // Store the corresponding ticket type in b.ttype and calculate the fee based on guests
    switch (ttype_choice) {
        case 1:
            strcpy(b.ttype, "Premium");
            b.fee = 200 * b.guestsnum;  // Premium ticket fee
            break;
        case 2:
            strcpy(b.ttype, "First Class");
            b.fee = 150 * b.guestsnum;  // First Class ticket fee
            break;
        case 3:
            strcpy(b.ttype, "Second Class");
            b.fee = 100 * b.guestsnum;  // Second Class ticket fee
            break;
        default:
            printf("Invalid choice! Defaulting to Second Class.\n");
            strcpy(b.ttype, "Second Class");
            b.fee = 100 * b.guestsnum;  // Default to Second Class ticket fee
            break;
    }

    // Display the calculated fee
    printf("Total Fee for %d guests: %d\n", b.guestsnum, b.fee);

    // Save the record to file
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("File not found!\n");
    } else {
        fprintf(fp, "%d,%s,%s,%s,%d,%d,%d,%s,%d\n", b.mnum, b.cname, b.mname, b.mdate, b.mtime, b.guestsnum, b.housenum, b.ttype, b.fee);
        printf("Record insert successful!\n");
    }
    fclose(fp);
}


// Function to display all movie ticket records
void dispMov() {
    char ch;
    FILE *fp;
    printf("\n");
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
        exit(1);
    } else {
        while ((ch = fgetc(fp)) != EOF) {
            printf("%c", ch);
        }
    }
    fclose(fp);
}

// Function to search for a specific movie ticket record
void findMov() {
    char bk[100], line[250];
    char bnum[250], cname[250], mname[250], mdate[250], mtime[250], guestsnum[250], housenum[250], ttype[250], fee[250];
    printf("Enter booking number: ");
    scanf("%s", bk);
    FILE *fp;
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("File not found!");
    } else {
        int found = 0;
        while (fgets(line, sizeof(line), fp) != NULL) {
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s", bnum, cname, mname, mdate, mtime, guestsnum, housenum, ttype, fee);
            if (strcmp(bk, bnum) == 0) {
                printf("\nRecord found.\n\nBooking number: %s", bnum);
                printf("\nName: %s", cname);
                printf("Movie name: %s", mname);
                printf("Movie Schedule: %s", mdate);
                printf("Time: %s", mtime);
                printf("Number of Guests: %s", guestsnum);
                printf("House Number: %s", housenum);
                printf("Type: %s", ttype);
                printf("Total fee: %s\n", fee);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("\nRecord not found!\n");
        }
    }
    fclose(fp);
}

// Main menu
int main() {
    int option;
    printf("\n\t*** Movie Ticketing System ***\n");
    do {
        printf("\n\n--<:Main Menu:>--\n");
        printf("\n 1. Add New Ticket Record(s)\n");
        printf("\n 2. Display All Ticket Records\n");
        printf("\n 3. Search Movie Ticketing Record(s)\n");
        printf("\n 4. Add Snacks\n");
        printf("\n 5. Quit\n");
        printf("\nWhat is your option (1-5)? ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addMov();
                break;
            case 2:
                dispMov();
                break;
            case 3:
                findMov();
                break;
            case 4:
                snacks();
                break;
            case 5:
                printf("See you next time :)\n");
                exit(0);
            default:
                printf("Please select a correct number (1-5)!\n");
        }
    } while (option != 5);
    return 0;
}

