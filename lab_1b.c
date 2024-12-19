#include <stdio.h>

struct Day { char name[10]; int day; char activity[50]; };

void create(struct Day cal[7]) {
    for (int i = 0; i < 7; i++) {
        printf("Enter details for %s: ", cal[i].name);
        scanf("%d %[^\n]", &cal[i].day, cal[i].activity);
    }
}

void read(struct Day cal[7]) {
    FILE *f = fopen("calendar.txt", "r");
    if (!f) { perror("Error opening file"); return; }
    for (int i = 0; i < 7 && fscanf(f, "%d %[^\n]", &cal[i].day, cal[i].activity) == 2; i++);
    fclose(f);
}

void display(const struct Day cal[7]) {
    for (int i = 0; i < 7; i++)
        printf("%s (Date: %d): %s\n", cal[i].name, cal[i].day, cal[i].activity);
}

void main() {
    struct Day cal[7] = {{"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}, {"Sunday"}};
    int ch;
    printf("1. Create Calendar\n2. Read Calendar from File\nEnter choice: ");
    if (scanf("%d", &ch) != 1 || (ch < 1 || ch > 2)) {
        printf("Invalid choice.\n");
        return;
    }
    if (ch == 1) create(cal);
    else read(cal);
    display(cal);
}
