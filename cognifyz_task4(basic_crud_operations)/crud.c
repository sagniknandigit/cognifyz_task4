#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 10
#define TITLE_LEN 100
#define DESC_LEN 200

typedef struct
{
    int task_id;
    char title[TITLE_LEN];
    char description[DESC_LEN];
} Task;
Task tasks[MAX_TASKS];
int next_id = 1;
int task_count = 0;

void create_task()
{
    if (task_count >= MAX_TASKS)
    {
        printf("Task list is full \n");
        return;
    }

    Task new_task;
    new_task.task_id = next_id++;
    printf("Enter title:");
    fgets(new_task.title, TITLE_LEN, stdin);
    new_task.title[strcspn(new_task.title, "\n")] = 0;
    printf("Enter description:");
    fgets(new_task.description, DESC_LEN, stdin);
    new_task.description[strcspn(new_task.description, "\n")] = 0;

    tasks[task_count++] = new_task;
    printf("Task created successfully \n");
}

void read_tasks()
{
    if (task_count == 0)
    {
        printf("No task to display!\n");
        return;
    }
    for (int i = 0; i < task_count; ++i)
    {
        printf("ID:%d, Title:%s,Description:%s\n", tasks[i].task_id, tasks[i].title, tasks[i].description);
    }
}

void update_task()
{
    int task_id;
    printf("Enter task id to update:");
    scanf("%d", &task_id);
    getchar();

    for (int i = 0; i < task_count; ++i)
    {
        if (tasks[i].task_id == task_id)
        {
            printf("Enter new title:");
            fgets(tasks[i].title, TITLE_LEN, stdin);
            tasks[i].title[strcspn(tasks[i].title, "\n")] == 0;
            printf("Enter new description:");
            fgets(tasks[i].description, DESC_LEN, stdin);
            tasks[i].description[strcspn(tasks[i].description, "\n")] = 0;
            printf("Task updated successfully! \n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", task_id);
}

void delete_task()
{
    int task_id;
    printf("Enter task ID to delete: ");
    scanf("%d", &task_id);
    getchar();

    for (int i = 0; i < task_count; ++i)
    {
        if (tasks[i].task_id == task_id)
        {
            for (int j = i; j < task_count - 1; ++j)
            {
                tasks[j] = tasks[j + 1];
            }
            --task_count;
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task with ID %d not found!\n", task_id);
}

void print_menu()
{
    printf("\nTask Manager\n");
    printf("1. Create a new task\n");
    printf("2. Read all tasks\n");
    printf("3. Update a task\n");
    printf("4. Delete a task\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main()
{
    int choice;

    while (1)
    {
        print_menu();
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            create_task();
            break;
        case 2:
            read_tasks();
            break;
        case 3:
            update_task();
            break;
        case 4:
            delete_task();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
