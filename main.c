#include <sched.h>
#include<stdio.h>
#include <string.h> 
#include <unistd.h>

// 1. Поменять в целом положительном числе (типа int) значение третьего байта на введенное пользователем число
// (изначальное число такжевводится с клавиатуры) через указатель (не применяя битовые операции).

// 2. В приведенном ниже коде измените только одну строку (помеченную), чтобы напечатать "Результат: 12.0".

// 3. Напишите программу, в которой определите массив типа int (размер массива 10 элементов от 1 до 10).
// Используйте указатель для вывода элементов массива на консоль (применять можно только арифметику указателей, а не индексы).

//4. Напишите программу, которая ищет введенной строке (с клавиатуры) введенную подстроку (с клавиатуры) и возвращает указатель на начало подстроки,
//если подстрока не найдена в указатель записывается NULL. В качестве срок использовать статические массивы.ю

void change_third_byte()
{
    int num; 
    unsigned char newByte;

    printf("Please, enter int value\n ");
    scanf("%d", &num);

    unsigned char *ptr = (unsigned char*)&num;
    ptr += 2; // Go to 3 byte

    printf("New 3 byte...");
    scanf("%hhu", &newByte);

    *ptr = newByte;

    ptr -=2; // Back to 0 byte
    for (int i = 0; i <= 3; i++) {
        printf("Addr: %p \t  value: %d \t i: %d \n", (ptr+i), *(ptr+i), i);
    } 
}

void second_task(void)
{ 
    float x = 5.0;
    float y = 6.0;

    printf("x = %f, ", x );
    printf("y = %f, ", y );

    float *xp = &y;
    float *yp = &y;

    printf("Result: %f\n", *xp + * yp);


}

void third_task()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10}; 
    int *p_array = array;

    for(unsigned int i = 0 ; i < 10; i++ , p_array++)    
        printf("Addr: %p \t  value: %d \t i: %d \n", (void*)p_array, *p_array, i);
    
}

void fourth_task()
{
    char str[32];
    char str2[32];
    char *pstr;

    printf("Please, enter your string.\n");    
    scanf( "%s", str );

    printf("Comparison string.\n");
    scanf(" %s", str2);

    pstr = strstr(str, str2);

    if (pstr == NULL)
        printf("Pointer = NULL!");
    else
        printf("strstr != 0 So. Addr: %p | Match found in %ld symbol", &pstr, pstr-str+1  );

}




int main()
{
    unsigned int task_num;

    printf("Please, select task from 1..4\n");
    scanf("%u", &task_num);
    printf("Task: %u\n", task_num);

    switch(task_num)
    {
        case 1:
            change_third_byte();
        break;
        case 2:
            second_task();
        break;
        case 3:
            third_task();
        break;
        case 4:
            fourth_task();
        break;

        default:
            printf("Selected task %u does not exist \n", task_num);
    }
    return 0;
}

