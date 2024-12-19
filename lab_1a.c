#include <stdio.h>

void main() {
    struct {
        char name[10];
        int day;
        char activity[50];
    } calendar[7] = {
        {"Monday", 1, "Work 9-5"},
        {"Tuesday", 2, "Meeting 10 AM"},
        {"Wednesday", 3, "Gym 6 PM"},
        {"Thursday", 4, "Dinner 7 PM"},
        {"Friday", 5, "Movie 8 PM"},
        {"Saturday", 6, "Getaway"},
        {"Sunday", 7, "Relax"}
    };

    for (int i = 0; i < 7; i++)
        printf("%s [Day: %d]: %s\n", calendar[i].name, calendar[i].day, calendar[i].activity);
}
