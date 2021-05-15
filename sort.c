#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NUM 100

typedef struct Student
{
    char name[255];
    char phone[20];
    char email[255];
} Student;

Student studentList[MAX_NUM];
int studentNum;
int numberOfComps = 0;

void load();
void insertion_sort(Student list[], int n);
void printStudent(Student list[], int n);

int main()
{
    load();
    insertion_sort(studentList, studentNum);
    printStudent(studentList, studentNum);
    printf("Total number of comparisons: %d", numberOfComps);
}

void load()
{
    FILE *f = fopen("data.txt", "r");
    fscanf(f, " %d", &studentNum);
    for (int i = 0; i < studentNum; i++)
    {
        Student thisStudent;
        fscanf(f, "%s%s%s", &thisStudent.name, &thisStudent.phone, &thisStudent.email);
        studentList[i] = thisStudent;
    }
}

void insertion_sort(Student list[], int n)
{
    int i, j;
    Student next;
    for (i = 1; i < n; i++)
    {
        next = list[i];

        for (j = i - 1; j >= 0 && strcmp(next.name, list[j].name) < 0; j--) {
            list[j + 1] = list[j];
            numberOfComps++;
        }

        list[j + 1] = next;
    }
}

void printStudent(Student list[], int n) {
    char filename[255];
    printf("Enter filename: ");
    scanf("%s", &filename);
    printf("Write outout to filename: %s \n", filename);
    FILE* f = fopen(filename, "w+");

    for (int i = 0; i < n; i++) {
        fprintf(f, "%s  %s  %s \n", list[i].name, list[i].phone, list[i].email);
    }
}

