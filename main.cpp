//Gian van Zijl 38098806

#include <iostream>

using namespace std;

int ReadFiles(char*, char*);  //method prototypes
void MergeArrays(char*, char*, char*, int);
void WriteFile(char*, int);

int main()  //Question 1.4 - main(void)
{
    char input1[7];  //create arrays, variable
    char input2[7];
    char mergeinput[14];
    int n = 0;

    n = ReadFiles(input1, input2);  //Question 1.1 - ReadFiles(char*,char*)

    MergeArrays(input1, input2, mergeinput, n/2);  //Question 1.2 - MergeArrays(char*,char*,char*,int)

    WriteFile(mergeinput, n);  //Question 1.3 - WriteFile(char*,int)

    cout << "Completed";

    return 0;
}

int ReadFiles(char* ArrInput1, char* ArrInput2)  //ReadFiles() method
{
    FILE *IN1 = fopen("Input1.txt", "r");  //open files, declare variables
    FILE *IN2 = fopen("Input2.txt", "r");
    int m = 0, n = 0, i = 0;
    char input1, input2;

    if (IN1 == NULL || IN2 == NULL)
    {
        cout << "ERROR! Can't read the file";  //file can not be read error
        exit(1);
    }
    else
    {
        while(fscanf(IN1, "%c", &input1)  != EOF)  //read file 1 to EOF
        {
            if (input1 != '\n')  //remove /n
            {
                *(ArrInput1 + m) = input1;  //read char to arr
                m++;
            }
        }
        while(fscanf(IN2, "%c", &input2)  != EOF)  //read file 2 to EOF
        {
            if (input2 != '\n')  //remove /n
            {
                *(ArrInput2 + n) = input2;  //read char to arr
                n++;
            }
        }
    }
    fclose(IN1);  //close files, add total number of entries
    fclose(IN2);
    i = m + n;

    return i;  //return total number of entries
}

void MergeArrays(char* ArrInput1, char* ArrInput2, char* ArrMergeInput, int n)  //MergeArrays() method
{
    int k = 0, l = 1;  //declare variables

    for (int i = 0; i < n; i++)  //merge arrays
    {
        *(ArrMergeInput + k) = *(ArrInput1 + i);
        k += 2;
        *(ArrMergeInput + l) = *(ArrInput2 + i);
        l += 2;
    }
}

void WriteFile(char* ArrMergeInput,int k)  //WriteFile() method
{
    FILE *OUT = fopen("Output.txt", "w");  //create/open output file

    for (int i = 0; i < k; i++)  //write output to file
    {
        fprintf(OUT, "%c", ArrMergeInput[i]);
    }

    fclose(OUT);  //close file
}
