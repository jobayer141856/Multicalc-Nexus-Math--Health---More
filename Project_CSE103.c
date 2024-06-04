#include<stdio.h>
#include<math.h>
#include <string.h>
int add(int a, int b)
{
    int sum = a+b;
    return sum;
}
float add2(float a, float b)
{
    float sum = a+b;
    return sum;
}
int sub(int a, int b)
{
    int sub = a-b;
    return sub;
}
float sub2(float a, float b)
{
    float sub = a-b;
    return sub;
}
int mult(int a, int b)
{
    int mul = a*b;
    return mul;
}
float mult2(float a, float b)
{
    float mul = a*b;
    return mul;
}
double div(int a, int b)
{
    double div = a/(double)b;
    return div;
}
float div2(float a, float b)
{
    float div = a/b;
    return div;
}

float bmi(float weight, float height)
{
    float bmi = weight / (height * height);
    return bmi;
}
float celTofar(float cel)
{
    float far = (cel * 9 / 5) + 32;
    return far;
}
float farTocel(float far)
{
    float cel = (far - 32) * 5 / 9;
    return cel;
}

struct StudentManagement
{
    char name[50];
    int id;
    char course1[50],course2[50],course3[50];
    float marks1,marks2,marks3,avg;

};
void writeStudentInfoToFile(struct StudentManagement student)
{
    FILE *file = fopen("students.txt", "a");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }
    fprintf(file, "%s %d %s %s %s %.2f %.2f %.2f %.2f\n", student.name, student.id, student.course1, student.course2, student.course3, student.marks1,student.marks2, student.marks3, student.avg );
    fclose(file);
}

void readStudentInfoById(int Id)
{
    FILE *file = fopen("students.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    struct StudentManagement student;

    int found = 0;

    while (fscanf(file, "%s %d %s %s %s %f %f %f %f", student.name, &student.id, student.course1, student.course2, student.course3, &student.marks1, &student.marks2,&student.marks3, &student.avg) != EOF)
    {
        if (student.id == Id)
        {
            printf("\t\t\t\t\tName: %s\n\t\t\t\t\tID: %d\n\t\t\t\t\tCourse1: %s %.2f\n\n\t\t\t\t\tCourse2: %s %.2f\n\n\t\t\t\t\tCourse3: %s %.2f\n\n\t\t\t\t\tAvg: %.2f\n ", student.name, student.id, student.course1, student.marks1, student.course2, student.marks2, student.course3, student.marks3,student.avg);
            found = 1;
            return found;
            break;
        }
    }

    if (found==0)
    {
        printf("Student with ID %d not found.\n",Id);
    }

    fclose(file);
}

int readStudentInfoById2(int Id)
{
    FILE *file = fopen("students.txt", "r");

    if (file == NULL)
    {
        printf("Error opening the file.\n");
        return;
    }

    struct StudentManagement student;

    while (fscanf(file, "%s %d %s %s %s %f %f %f %f", student.name, &student.id, student.course1, student.course2, student.course3, &student.marks1, &student.marks2,&student.marks3, &student.avg) != EOF)
    {
        if (student.id == Id)
        {
            fclose(file);
            return 1;

        }
    }

}

int main()
{
    while(1)
    {
        printf("\n\n\t\t\t\t\t\tChoose the type\n\n");
        printf("\t\t\t\t\tEnter 1 Simple Calculataion\n\t\t\t\t\tEnter 2 BMI Calculation\n\t\t\t\t\tEnter 3 Temperature Converter\n\t\t\t\t\tEnter 4 Matrix Calculation\n\t\t\t\t\tEnter 5 Student Management\n\t\t\t\t\tEnter 0 for Exit\nEnter your choice: ");
        int n;
        scanf("%d", &n);
        if(n==1)
        {
            printf("\n");
            printf("\t\t\t\t\tChoose Calculation  type\n\n");
            printf("\t\t\t\t\tEnter 1 Addition\n");
            printf("\t\t\t\t\tEnter 2 Substraction\n");
            printf("\t\t\t\t\tEnter 3 Multiplication\n");
            printf("\t\t\t\t\tEnter 4 Division\n\n");
            int x;
            printf("Enter your choice: ");
            scanf("%d",&x);
            if(x==1)
            {
                printf("\n");
                printf("\t\t\t\t\tChoose Calculation  type\n\n");
                printf("\t\t\t\t\tEnter 1 Integer Addition\n");
                printf("\t\t\t\t\tEnter 2 Float Addition\n");

                int n;
                printf("Enter your choice: ");
                scanf("%d",&n);
                if(n==1)
                {
                    int a,b,result;
                    printf("\t\t\t\t\tInput First Integer Number : ");
                    scanf("%d",&a);
                    printf("\t\t\t\t\tInput Second Integer Number : ");
                    scanf("%d",&b);
                    result = add(a,b);
                    printf("\n\n\t\t\t\t\tResult of Integer Addition: %d \n\n", result);
                    continue;

                }
                if(n==2)
                {
                    float a, b, result;
                    printf("\t\t\t\t\tInput First Float Number : ");
                    scanf("%f",&a);
                    printf("\t\t\t\t\tInput Second Float Number : ");
                    scanf("%f",&b);
                    result = add2(a,b);
                    printf("\n\n\t\t\t\t\tResult of Float Addition: %.2f \n\n", result);
                    continue;

                }
                if(n!=1 || n!=2)
                {
                    printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                    continue;

                }
            }
            if(x==2)
            {
                printf("\n");
                printf("\t\t\t\t\tChoose Calculation  type\n\n");
                printf("\t\t\t\t\tEnter 1 Integer Addition\n");
                printf("\t\t\t\t\tEnter 2 Float Addition\n");
                int n;
                printf("Enter your choice: ");
                scanf("%d",&n);
                if(n==1)
                {
                    int a,b,result;
                    printf("\t\t\t\t\tInput First Integer Number : ");
                    scanf("%d",&a);
                    printf("\t\t\t\t\tInput Second Integer Number : ");
                    scanf("%d",&b);
                    result = sub(a,b);
                    printf("\n\n\t\t\t\t\tResult of Integer Substraction: %d \n\n", result);
                    continue;

                }
                if(n==2)
                {
                    float a, b, result;
                    printf("\t\t\t\t\tInput First Float Number : ");
                    scanf("%f",&a);
                    printf("\t\t\t\t\tInput Second Float Number : ");
                    scanf("%f",&b);
                    result = sub2(a,b);
                    printf("\n\n\t\t\t\t\tResult of Float Substraction: %.2f \n\n", result);
                    continue;

                }
                if(n!=1 || n!=2)
                {
                    printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                    continue;

                }

            }
            if(x==3)
            {
                printf("\n");
                printf("\t\t\t\t\tChoose Calculation  type\n\n");
                printf("\t\t\t\t\tEnter 1 Integer Multiplication\n");
                printf("\t\t\t\t\tEnter 2 Float Multiplication\n");
                int n;
                printf("Enter your choice: ");
                scanf("%d",&n);
                if(n==1)
                {
                    int a,b,result;
                    printf("\t\t\t\t\tInput First Integer Number : ");
                    scanf("%d",&a);
                    printf("\t\t\t\t\tInput Second Integer Number : ");
                    scanf("%d",&b);
                    result = mult(a,b);
                    printf("\n\n\t\t\t\t\tResult of Integer Multiplication: %d \n\n", result);
                    continue;

                }
                if(n==2)
                {
                    float a, b, result;
                    printf("\t\t\t\t\tInput First Float Number : ");
                    scanf("%f",&a);
                    printf("\t\t\t\t\tInput Second Float Number : ");
                    scanf("%f",&b);
                    result = mult2(a,b);
                    printf("\n\n\t\t\t\t\tResult of Float Multiplication: %.2f \n\n", result);
                    continue;

                }
                if(n!=1 || n!=2)
                {
                    printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                    continue;

                }
            }
            if(x==4)
            {
                printf("\n");
                printf("\t\t\t\t\tChoose Calculation  type\n\n");
                printf("\t\t\t\t\tEnter 1 Integer Division\n");
                printf("\t\t\t\t\tEnter 2 Float Division\n");
                int n;
                printf("Enter your choice: ");
                scanf("%d",&n);
                if(n==1)
                {
                    int a,b,result;
                    printf("\t\t\t\t\tInput First Integer Number : ");
                    scanf("%d",&a);
                    printf("\t\t\t\t\tInput Second Integer Number : ");
                    scanf("%d",&b);
                    result = div(a,b);
                    printf("\n\n\t\t\t\t\tResult of Integer Division: %d \n\n", result);
                    continue;

                }
                if(n==2)
                {
                    float a, b, result;
                    printf("\t\t\t\t\tInput First Float Number : ");
                    scanf("%f",&a);
                    printf("\t\t\t\t\tInput Second Float Number : ");
                    scanf("%f",&b);
                    result = div2(a,b);
                    printf("\n\n\t\t\t\t\tResult of Float Division: %.2f \n\n", result);
                    continue;

                }
                if(n!=1 || n!=2)
                {
                    printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                    continue;

                }
            }

            if(x!=1 || x!=2 || x!=3 || x!=4)
            {
                printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                continue;

            }

        }

        if(n==2)
        {
            float height, weight, BMI;

            printf("\t\t\t\t\tEnter height in meter: ");
            scanf("%f", &height);

            printf("\t\t\t\t\tEnter weight in kg: ");
            scanf("%f", &weight);


            printf("\n\n\t\t\t\t\tYour Body Mass Index(BMI) is %f kg/m2\n", bmi(weight,height));

            if(bmi(weight,height) < 15)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Starvation\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 15.1 && bmi(weight,height) <= 17.5)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Anorexic\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 17.6 && bmi(weight,height) <= 18.5)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Underweight\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 18.6 && bmi(weight,height) <= 24.9)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Ideal\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 25 && bmi(weight,height) <= 25.9)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Overweight\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 30 && bmi(weight,height) <= 30.9)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Obese\n\n");
                continue;
            }
            else if(bmi(weight,height) >= 40)
            {
                printf("\t\t\t\t\tResult: Your BMI category is: Morbidly Obese\n\n");
                continue;
            }
            else
            {
                printf("\t\t\t\t\tWrong entry\n\n");
                continue;
            }

        }
        if(n==3)
        {
            printf("\n");
            printf("\t\t\t\t\tChoose Calculation  type\n\n");
            printf("\t\t\t\t\tEnter 1 Celsius to Fahrenheit\n");
            printf("\t\t\t\t\tEnter 2 Fahrenheit to Celsius\n");
            int x;
            printf("Enter your choice: ");
            scanf("%d",&x);
            if(x==1)
            {
                printf("\n");
                float cel;
                printf("\t\t\t\t\tEnter temperature in Celsius: ");
                scanf("%f", &cel);
                printf("\n");
                printf("\t\t\t\t\t%.2f Celsius = %.2f Fahrenheit \n\n", cel, celTofar(cel));
                continue;
            }
            if(x==2)
            {
                printf("\n");
                float far;
                printf("\t\t\t\t\tEnter temperature in Fahrenheit: ");
                scanf("%f", &far);
                printf("\n");
                printf("\t\t\t\t\t%.2f Fahrenheit = %.2f Celsius \n\n", far, farTocel(far));
                continue;

            }
            if(x!=1 || x!=2 )
            {
                printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                continue;

            }
        }
        if(n==4)
        {
            printf("\n");
            printf("\t\t\t\t\tChoose Calculation  type\n\n");
            printf("\t\t\t\t\tEnter 1 Matrix Addition\n");
            printf("\t\t\t\t\tEnter 2 Matrix Multiplication\n");
            printf("\t\t\t\t\tEnter 3 Identity Matrix Check\n");
            int x;
            printf("Enter your choice: ");
            scanf("%d",&x);
            if(x==1)
            {
                int r, c, a[100][100], b[100][100], sum[100][100], i, j;
                printf("\t\t\t\t\tEnter the number of rows: ");
                scanf("%d", &r);
                printf("\t\t\t\t\tEnter the number of columns: ");
                scanf("%d", &c);
                printf("\nEnter elements of 1st matrix:\n");
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        printf("\t\t\t\t\tEnter element a %d %d: ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\nEnter elements of 2nd matrix:\n");
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        printf("\t\t\t\t\tEnter element b %d %d: ", i + 1, j + 1);
                        scanf("%d", &b[i][j]);
                    }
                }
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        sum[i][j] = a[i][j] + b[i][j];
                    }
                }
                printf("\n\t\t\t\t\tSum of two matrices is:\n");
                for (i = 0; i < r; ++i)
                {
                    printf("\t\t\t\t\t\t");
                    for (j = 0; j < c; ++j)
                    {
                        printf("%d   ", sum[i][j]);
                        if (j == c - 1)
                        {
                            printf("\n\n");
                        }
                    }
                }
                continue;
            }
            if(x==2)
            {
                int r, c, k,a[100][100], b[100][100], mult[100][100], i, j;
                printf("\t\t\t\t\tEnter the number of rows: ");
                scanf("%d", &r);
                printf("\t\t\t\t\tEnter the number of columns: ");
                scanf("%d", &c);
                printf("\nEnter elements of 1st matrix:\n");
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        printf("\t\t\t\t\tEnter element a %d %d: ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }
                printf("\nEnter elements of 2nd matrix:\n");
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        printf("\t\t\t\t\tEnter element b %d %d: ", i + 1, j + 1);
                        scanf("%d", &b[i][j]);
                    }
                }

                for(i=0; i<r; i++)
                {
                    for(j=0; j<c; j++)
                    {
                        mult[i][j]=0;
                        for(k=0; k<c; k++)
                        {
                            mult[i][j]+=a[i][k]*b[k][j];
                        }
                    }
                }
                printf("\n\t\t\t\t\tMultiply of two matrices is:\n");
                for (i = 0; i < r; ++i)
                {
                    printf("\t\t\t\t\t\t");
                    for (j = 0; j < c; ++j)
                    {
                        printf("%d   ", mult[i][j]);
                        if (j == c - 1)
                        {
                            printf("\n\n");
                        }
                    }
                }
                continue;

            }
            if(x==3)
            {
                int r, c, k,a[100][100], i,j, flag=0;
                printf("\t\t\t\t\tEnter the number of rows: ");
                scanf("%d", &r);
                printf("\t\t\t\t\tEnter the number of columns: ");
                scanf("%d", &c);
                printf("\nEnter elements of  matrix:\n");
                for (i = 0; i < r; ++i)
                {
                    for (j = 0; j < c; ++j)
                    {
                        printf("\t\t\t\t\tEnter element a %d %d: ", i + 1, j + 1);
                        scanf("%d", &a[i][j]);
                    }
                }

                for (i = 0; i < r; i++)
                {
                    for (j = 0; j < c; j++)
                    {
                        if (i == j && a[i][j] != 1)
                        {
                            flag = -1;
                            break;
                        }
                        else if (i != j && a[i][j] != 0)
                        {
                            flag = -1;
                            break;
                        }
                    }
                }
                if (flag == 0)
                {
                    printf ("\n\t\t\t\t\tIt is a IDENTITY MATRIX\n");
                }
                else
                {
                    printf ("\n\t\t\t\t\tIt is NOT an identity matrix\n");
                }

                continue;

            }
            if(x!=1 || x!=2 || x!=3 )
            {
                printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                continue;

            }
        }
        if(n==5)
        {
            struct StudentManagement student;
            printf("\n");
            printf("\t\t\t\t\tChoose type\n\n");
            printf("\t\t\t\t\tEnter 1 Add student information\n");
            printf("\t\t\t\t\tEnter 2 Search student by ID\n");
            int x;
            printf("Enter your choice: ");
            scanf("%d",&x);

            if(x==1)
            {
                printf("\t\t\t\t\tEnter student name: ");
                scanf("%s", student.name);
                printf("\n\t\t\t\t\tEnter student ID: ");
                scanf("%d", &student.id);
                if(readStudentInfoById2(student.id) == 1)
                {
                    printf("\n\t\t\t\t\tStudent ID already exists. Please input another ID.\n");
                    continue;
                }
                printf("\n\t\t\t\t\tEnter student course1: ");
                scanf("%s", student.course1);
                printf("\t\t\t\t\tEnter student marks1: ");
                scanf("%f", &student.marks1);
                printf("\n\t\t\t\t\tEnter student course2: ");
                scanf("%s", student.course2);
                printf("\t\t\t\t\tEnter student marks2: ");
                scanf("%f", &student.marks2);
                printf("\n\t\t\t\t\tEnter student course3: ");
                scanf("%s", student.course3);
                printf("\t\t\t\t\tEnter student marks3: ");
                scanf("%f", &student.marks3);
                student.avg = (student.marks1+student.marks2+student.marks3)/3.0;
                writeStudentInfoToFile(student);
                continue;
            }
            if(x==2)
            {
                printf("Enter student ID to search: ");
                int Id;
                scanf("%d", &Id);
                readStudentInfoById(Id);
                continue;
            }
            if(x!=1 || x!=2)
            {
                printf("\t\t\t\t\tInvalid choice. Please try again.\n");
                continue;

            }


        }
        if(n==0)
        {
            break;
        }
        if(n!=1 || n!=2 || n!=3 || n!=4 || n!=5 || n!=0)
        {
            printf("\t\t\t\t\tInvalid choice. Please try again.\n");
            continue;

        }

    }

}
