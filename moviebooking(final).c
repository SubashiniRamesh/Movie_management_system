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
int icecream(){
	int ch1,total1;
	while(ch1!=6){
	printf("\n1.Chocolate-60\n2.Venilla-30\n3.Butter pecan-80\n4.cotton candy-100\n5.cherry-65\n6.Exit");
	printf("\nEnter your fav:");
	scanf("%d",&ch1);
	switch(ch1){
		case 1:
			total1=total1+60;
			break;
		case 2:
			total1=total1+30;
			break;
		case 3:
			total1=total1+80;
			break;
		case 4:
			total1=total1+100;
			break;
		case 5:
			total1=total1+65;
			break;
		case 6:
			printf("\nthank you");
			
			break;
		}	
	}
	return total1;
	
}
void snacks() {
    struct book s1;
    int ch, total;
    int res;
    FILE *fp;
    fp = fopen("data.txt", "a"); // Open file in append mode
    if (fp == NULL) {
        printf("File not found!");
        return;
    }
    while (ch != 6) {
        printf("1.Chips-medium size-30\n2.popcorn-medium-70\n3.ice cream\n4.cold coffee-80\n5.puffs-55\n6.exit");
        printf("\nEnter your items:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                total = total + 30;
                break;
            case 2:
                total = total + 70;
                break;
            case 3:
                res = icecream();
                total = total + res;
                break;
            case 4:
                total = total + 80;
                break;
            case 5:
                total = total + 55;
                break;
            case 6:
                printf("Thank you");
                break;
        }
    }
    printf("Your total amount for snacks is %d\n",total);
    
    // Write total amount for snacks to file
    fprintf(fp, "Total amount for snacks: %d\n", total);
    fclose(fp); // Close the file
}

void addMov() {
    struct book b;
    char op;
    FILE *fp;
    printf("Enter Movie Booking Number (XXXX): ");
    scanf("%d", &b.mnum);
    while (b.mnum < 1 || b.mnum > 9999) {
        printf("Re-enter Movie Booking Number! It should be between 0001 to 9999!: ");
        scanf("%d", &b.mnum);
    };
    printf("Enter Name of Customer: ");
    getchar(); // to clear the input buffer
    fgets(b.cname, sizeof(b.cname), stdin);
    b.cname[strcspn(b.cname, "\n")] = '\0'; // remove newline character
    printf("Enter Name of Movie: ");
    fgets(b.mname, sizeof(b.mname), stdin);
    b.mname[strcspn(b.mname, "\n")] = '\0'; // remove newline character
    printf("Enter Movie Schedule (DD-MM-YYYY): ");
    scanf("%s", b.mdate);
    printf("Enter Time (XXXX): ");
    scanf("%d", &b.mtime);
    while (b.mtime < 1000 || b.mtime > 2300) {
        printf("Re-enter Time! It should be in 24-hour format and between 1000 to 2300!: ");
        scanf("%d", &b.mtime);
    };
    printf("Enter Number of Guests: ");
    scanf("%d", &b.guestsnum);
    printf("Enter House Number: ");
    scanf("%d", &b.housenum);
    printf("Enter Ticket Type: ");
    scanf("%s", b.ttype);
    printf("Enter Total Fee: ");
    scanf("%d", &b.fee);
    fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("File not found!");
    } else {
        fprintf(fp, "%d,%s,%s,%s,%d,%d,%d,%s,%d\n", b.mnum, b.cname, b.mname, b.mdate, b.mtime, b.guestsnum, b.housenum, b.ttype, b.fee);
        printf("Record insert successful!\n");
    }
    fclose(fp);
}

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
                printf("Movie Schedule : %s", mdate);
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

int main() {
    int option;
    printf("\n\t*** Movie Ticketing System ***\n");
    do {
        printf("\n\n--<:Main Menu:>--\n");
        printf("\n 1. Add New Ticket Record(s)\n");
        printf("\n 2. Display All Ticket Records\n");
        printf("\n 3. Search Movie Ticketing Record(s)\n");
        printf("\n 4.Add Snacks\n");
        printf("\n 5. Quit\n");
        printf("\nWhat is your option (1-4)? ");
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
            case 5:
                printf("See you next time :)\n");
                exit(0);
            default:
                printf("Please select a correct number (1-5)!\n");
        }
    } while (option != 5);
    return 0;
}

