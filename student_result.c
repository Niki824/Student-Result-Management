#include <stdio.h>

float calculatePercentage(int total) {
    return total / 3.0;
}

char getGrade(float percentage) {
    if (percentage >= 75) {
        return 'A';
    } else if (percentage >= 65) {
        return 'B';
    } else if (percentage >= 50) {
        return 'C';
    } else {
        return 'F';
    }
}

int main() {
    char name[50];
    int marks[3];
    int total = 0;
    float percentage;
    char grade;

    printf("===== STUDENT RESULT MANAGEMENT =====\n");

    printf("Enter student name: ");
    scanf("%s", name);

    for (int i = 0; i < 3; i++) {
        printf("Enter mark %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    percentage = calculatePercentage(total);
    grade = getGrade(percentage);

    printf("\n----RESULT----\n");
    printf("Student Name: %s\n", name);
    printf("Total Marks: %d\n", total);
    printf("Percentage: %.2f\n", percentage);
    printf("Grade: %c\n", grade);

    FILE *file = fopen("student_results.txt", "a");

    if (file == NULL) {
        printf("Error opening file.\n");
    } else {
        fprintf(file, "Student Name: %s\n", name);
        fprintf(file, "Total Marks: %d\n", total);
        fprintf(file, "Percentage: %.2f\n", percentage);
        fprintf(file, "Grade: %c\n", grade);

        fclose(file);
        printf("\nResult saved successfully to student_results.txt\n");
    }

    return 0;
}