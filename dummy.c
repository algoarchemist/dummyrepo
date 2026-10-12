#include <stdio.h>

#define MAX 100

int tree[MAX];
int size = 0;

void insert(int value)
{
    if (size >= MAX)
    {
        printf("Tree is full\n");
        return;
    }

    tree[size++] = value;
    printf("Inserted %d\n", value);
}

int search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (tree[i] == value)
            return i;
    }

    return -1;
}

void delete(int value)
{
    int index = search(value);

    if (index == -1)
    {
        printf("Value not found\n");
        return;
    }

    tree[index] = tree[size - 1];
    size--;

    printf("Deleted %d\n", value);
}

void display(void)
{
    if (size == 0)
    {
        printf("Tree is empty\n");
        return;
    }

    printf("Tree elements (Level Order):\n");

    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);

    printf("\n");
}

void showParent(int index)
{
    if (index < 0 || index >= size || index == 0)
    {
        printf("No parent exists\n");
        return;
    }

    int parent = (index - 1) / 2;

    printf("Parent of %d is %d\n", tree[index], tree[parent]);
}

void showChildren(int index)
{
    if (index < 0 || index >= size)
    {
        printf("Invalid index\n");
        return;
    }

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    printf("Node: %d\n", tree[index]);

    if (left < size)
        printf("Left Child: %d\n", tree[left]);
    else
        printf("Left Child: NULL\n");

    if (right < size)
        printf("Right Child: %d\n", tree[right]);
    else
        printf("Right Child: NULL\n");
}

int main(void)
{
    int choice, value, index;

    do
    {
        printf("\n--- Binary Tree Using Array ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Show Parent\n");
        printf("6. Show Children\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            return 0;

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                index = search(value);

                if (index != -1)
                    printf("Found at index %d\n", index);
                else
                    printf("Not found\n");
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Enter index to find parent: ");
                scanf("%d", &index);
                showParent(index);
                break;

            case 6:
                printf("Enter index to find children: ");
                scanf("%d", &index);
                showChildren(index);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 7);

    return 0;
}
