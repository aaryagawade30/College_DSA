#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int data;
    struct bst *left;
    struct bst *right;
} node;

node *getnode()
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->left = NULL;
    temp->right = NULL;

    printf("Enter new data: ");
    scanf("%d", &temp->data);
    return temp;
}

node *createbst(node *root)
{
    node *newNode = NULL;
    node *oldNode = NULL;
    char ch;

    do
    {
        newNode = getnode();
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            oldNode = root;
            while (1)
            {
                if (newNode->data < oldNode->data)
                {
                    if (oldNode->left == NULL)
                    {
                        oldNode->left = newNode;
                        break;
                    }
                    else
                    {
                        oldNode = oldNode->left;
                    }
                }
                else if (newNode->data > oldNode->data)
                {
                    if (oldNode->right == NULL)
                    {
                        oldNode->right = newNode;
                        break;
                    }
                    else
                    {
                        oldNode = oldNode->right;
                    }
                }
                else
                {
                    printf("Duplicate node can't be created.\n");
                    free(newNode);
                    break;
                }
            }
        }
        printf("Do you want to create more nodes? (y/n): ");
        scanf(" %c", &ch); // Note the space before %c to consume leftover newline.
    } while (ch != 'n');
    return root;
}

void inorder(node *node)
{
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(node *node)
{
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

node *search(node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
            return p;
        else if (key > p->data)
            p = p->right;
        else
            p = p->left;
    }
    return NULL;
}

node *del(node *root)
{
    int no;

    node *temp, *prev, *x, *succ;
    printf("\n\t enter the data to be deleted:");
    scanf("%d", &no);

    temp = root;

    prev = temp;

    while (temp != NULL)

    {

        if (temp->data == no)

            break;
        prev = temp;
        if (no < temp->data)

            temp = temp->left;

        else

            temp = temp->right;
    }

    if (temp->left == NULL && temp->right == NULL)
    {

        if (prev->left == temp)
            prev->left = NULL;

        else

            prev->right = NULL;

        printf("\n Leaf node is deleted\n");
    }

    else if (temp->right != NULL && temp->left == NULL)
    {

        if (prev->left == temp)
            prev->left = temp->right;
        else

            prev->right = temp->right;
        printf("Node with right subtree is deleted");
    }
    else if (temp->right == NULL && temp->left != NULL)
    {
        if (prev->left == temp)
            prev->left = temp->left;
        else

            prev->right = temp->left;
        printf("\n Node with left subtree is deleted");
    }

    else if (temp->left != NULL && temp->right != NULL)

    {
        succ = temp;
        x = temp->right;
        while (x != NULL)
        {

            prev = succ;

            succ = x;
            x = x->left;
        }
        temp->data = succ->data;

        if (temp->right != succ)
            prev->left = succ->right;
        else
            prev->right = succ->right;
        temp = succ;
    printf("\n Node with both subtree is deleted using inoreder successor method\n");
    }
    free(temp);
    return root;
}
int main()
{
    node *root = NULL;
    int ch = 0, key = 0;

    do
    {
        printf("\n1. Create tree\n");
        printf("2. Inorder with recursion\n");
        printf("3. Preorder with recursion\n");
        printf("4. Postorder with recursion\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            root = createbst(root);
            break;

        case 2:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 4:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 5:
            printf("Enter key to be searched: ");
            scanf("%d", &key);
            if (search(root, key))
                printf("%d Found\n", key);
            else
                printf("%d Not found\n", key);
            break;

        case 6:
            del(root);
            break;

        case 7:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 7);

    return 0;
}
