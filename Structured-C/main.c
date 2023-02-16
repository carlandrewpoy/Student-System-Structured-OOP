#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char id[10];
    char name[50];
    char gender[10];
    char course[10];
    char year[10];
}student;

typedef struct {
    char subCode[10];
    char description[50];
    char unit[10];
}subject;

typedef struct {
    char id[10];
    char subCode[10];
}enrollment;

bool isValidStudent(char id[20]) {

    bool found = false;
    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    fpStud = fopen("student.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(id, array[0]) == 0) {
            found = true;
            break;
        }
    }
    fclose(fpStud);
    return found;
}

bool isValidStudentName(char name[50]) {

    bool found = false;
    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    fpStud = fopen("student.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(name, array[1]) == 0) {
            found = true;
            break;
        }
    }
    fclose(fpStud);
    return found;
}

bool isValidSubject(char subCode[20]) {

    bool found = false;
    FILE *fpSub;
    char str[200];
    int i = 0;
    char *p;
    char *array[4];

    fpSub = fopen("subject.txt", "r");
    while(fgets (str, 200, fpSub) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(subCode, array[0]) == 0) {
            found = true;
            break;
        }
    }
       // printf("%d", found);
    fclose(fpSub);
    return found;
}
bool isValidSubjectDescription(char description[50]) {

    bool found = false;
    FILE *fpSub;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    fpSub = fopen("subject.txt", "r");
    while(fgets (str, 200, fpSub) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(description, array[1]) == 0) {
            found = true;
            break;
        }
    }
    fclose(fpSub);
    return found;
}
bool isValidEnroll(char id[20]) {

    bool found = false;
    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[3];

    fpStud = fopen("enrollment.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(id, array[0]) == 0) {
            found = true;
            break;
        }
    }
    fclose(fpStud);
    return found;
}
bool isValidEnrollSub(char id[50], char subCode[50]) {

    bool found = false;
    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    fpStud = fopen("enrollment.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok (str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok (NULL, ",");
        }
        i = 0;
        if(strcmpi(id, array[0]) == 0 && strcmpi(subCode, array[1]) == 0) {
            found = true;
            break;
        }
    }
    fclose(fpStud);
    return found;
}
void addStudent() {

    FILE *fpStud;
    student stud;

    printf("\n\tAdd Student");

    printf("\n\tID\t: ");
    scanf("%s", stud.id);

    if(isValidStudent(stud.id)) {
        printf("\n\tStudent ID. %s already added!\n", stud.id);
    }else {
        printf("\tName\t: ");
        fflush(stdin);
        gets(stud.name);

        if(isValidStudentName(stud.name)) {
            printf("\n\tStudent Name: %s already in use!\n", stud.name);
        }else {
            printf("\tGender\t: ");
            scanf("%s", stud.gender);

            printf("\tCourse\t: ");
            scanf("%s", stud.course);

            printf("\tYear\t: ");
            scanf("%s", stud.year);

            printf("\n\tStudent ID. %s added successfully!\n", stud.id);

            fpStud = fopen("student.txt", "a");
            fprintf(fpStud, "%s,%s,%s,%s,%s\n",stud.id, stud.name, stud.gender, stud.course, stud.year);
            fclose(fpStud);
        }
    }
}

void addSubject() {

    FILE *fpSub;
    subject subj;

    printf("\n\tAdd Subject");

    printf("\n\tSubject code\t: ");
    fflush(stdin);
    gets(subj.subCode);

    if(isValidSubject(subj.subCode)) {
        printf("\n\tSubject Code: %s already added!\n", subj.subCode);
    }else {
        printf("\tDescription\t: ");
        fflush(stdin);
        gets(subj.description);

        if(isValidSubjectDescription(subj.description)) {
            printf("\n\tSubject Description: %s already in use!\n", subj.description);
        }else {
              printf("\tUnit\t\t: ");
            scanf("%s", subj.unit);

            printf("\n\tSubject %s added successfully!\n", subj.subCode);

            fpSub = fopen("subject.txt", "a");
            fprintf(fpSub, "%s,%s,%s\n",subj.subCode, subj.description, subj.unit);
            fclose(fpSub);
        }


    }



}

void displayStudent(char id[]) {

    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    printf("\n\t|ID\t   |Name\t\t\t\t    |Gender\t   |Course\t  |Year\n");

    fpStud = fopen("student.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok(str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok(NULL, ",");
        }
        i = 0;

        if(strcmp(id, array[0]) == 0) {
            printf("\t %-10s %-40s %-14s %-14s %-9s", array[0], array[1], array[2], array[3], array[4]);
        }
    }
}

void displayAllStudent() {

    FILE *fpStud;
    char str[200];
    int i = 0;
    char *p;
    char *array[5];

    printf("\n\tStudent List");
    printf("\n\t|ID\t   |Name\t\t\t\t    |Gender\t   |Course\t  |Year\n");

    fpStud = fopen("student.txt", "r");
    while(fgets (str, 200, fpStud) != NULL) {
        p = strtok(str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok(NULL, ",");
        }
        i = 0;
        printf("\t %-10s %-40s %-14s %-14s %-9s", array[0], array[1], array[2], array[3], array[4]);
    }
}

void displaySubject(char subCode[]) {

    FILE *fpSub;
    char str[200];
    int i = 0;
    char *p;
    char *array[3];

    fpSub = fopen("subject.txt", "r");
    while(fgets (str, 200, fpSub) != NULL) {
        p = strtok(str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok(NULL, ",");
        }
        i = 0;
        if(strcmpi(subCode, array[0]) == 0) {
            printf("\t %-20s %-50s %-5s", array[0], array[1], array[2]);
        }
    }
}

void displayAllSubject() {

    FILE *fpSub;
    char str[200];
    int i = 0;
    char *p;
    char *array[3];

    printf("\n\tSubject List");
    printf("\n\t|Subject Code\t     |Description\t\t\t\t        |Unit\n");

    fpSub = fopen("subject.txt", "r");
    while(fgets (str, 200, fpSub) != NULL) {
        p = strtok(str, ",");
        while(p != NULL) {
            array[i++] = p;
            p = strtok(NULL, ",");
        }
        i = 0;
            printf("\t %-20s %-50s %-5s", array[0], array[1], array[2]);

    }
}


void enrollStudent() {
    enrollment enroll;

    FILE *fpEnroll;

    printf("\n\tEnroll Student");

    fflush(stdin);
    printf("\n\tID\t     : ");
    scanf("%[^5\n]s", enroll.id);

    if(!isValidStudent(enroll.id)) {
        printf("\tStudent ID not found!\n");
    }else {
        fflush(stdin);
        printf("\tSubject Code : ");
        scanf("%[^5\n]s", enroll.subCode);

        if(!isValidSubject(enroll.subCode)) {
            printf("\tSubject Code not found!\n\n");
        }else if(isValidEnrollSub(enroll.id, enroll.subCode)) {
            printf("\tSubject Code: %s already enrolled!\n\n", enroll.subCode);
        }else{
        fpEnroll = fopen("enrollment.txt", "a");
        fprintf(fpEnroll, "%s,%s,%s\n", enroll.id, enroll.subCode, "-");

        printf("\n\t%s enrolled successfully!\n", enroll.subCode);

        fclose(fpEnroll);
        }
    }
}

void displayEnrolledSubs() {

    char id[20];
    FILE *fpEnroll;
    char str[200];
    int i = 0;
    char *p;
    char *array[4];

    fflush(stdin);
    printf("\n\tID\t: ");
    scanf("%[^\n]s", id);

    if(!isValidEnroll(id)) {
        printf("\tStudent ID. %s is not already enrolled!\n", id);

    }else {
        printf("\n\tStudent Information");
        displayStudent(id);

        printf("\n\tSubject Enrolled List");
        printf("\n\t|Subject Code\t     |Description\t\t\t\t        |Unit\n");

        fpEnroll = fopen("enrollment.txt", "r");
        while(fgets (str, 200, fpEnroll) != NULL) {
            p = strtok(str, ",");
            while(p != NULL) {
                array[i++] = p;
                p = strtok(NULL, ",");
            }
            i = 0;

            if(strcmpi(id, array[0]) == 0) {
                displaySubject(array[1]);
            }
        }
        fclose(fpEnroll);
    }
}

void studentMenu() {
    int menu;

    do{
        printf("\n 1. Student Menu");
        printf("\n\t 1. Add");
        printf("\n\t 2. Display");
        printf("\n\t 3. Back");
        printf("\n Select: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
                addStudent();
                break;

            case 2:
                displayAllStudent();
                break;

            case 3:
                break;
        }
    }while(menu != 3);

}

void subjectMenu() {
    int menu;
    do{
        printf("\n 2. Subject Menu");
        printf("\n\t 1. Add");
        printf("\n\t 2. Display");
        printf("\n\t 3. Back");
        printf("\n Select: ");
        scanf("%d", &menu);

        switch(menu) {
            case 1:
            addSubject();
            break;

            case 2:
            displayAllSubject();
            break;

            case 3:
            break;
        }
    }while(menu != 3);

}

int main(){
   int menu;
//   isValidSubject("SE 105");

    do{
        printf("\n Main Menu");
        printf("\n\t 1. Student Menu");
        printf("\n\t 2. Subject Menu");
        printf("\n\t 3. Enroll Student");
        printf("\n\t 4. Display Subject Enrolled");
        printf("\n\t 5. Exit Program");
        printf("\n Select: ");
        scanf("%d", &menu);

        switch(menu) {
        case 1:
            studentMenu();
            break;
        case 2:
            subjectMenu();
            break;
        case 3:
            enrollStudent();
            break;
        case 4:
            displayEnrolledSubs();
            break;
        case 5:
            printf("\n Exit!\n");
            break;
        default:
            printf("\n Invalid input!\n");
        }
    }while(menu != 5);
    return 0;
}
