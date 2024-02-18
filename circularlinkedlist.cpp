#include <stdio.h>
#include <stdlib.h>

class List {
private:
    struct Node {
        int data;
        struct Node* Next;
    };
    struct Node* Head;
public:
    List() {
        Head = nullptr;
    }
    struct Node* CreateNode();
    void DeleteNode(struct Node*);
    int IsEmpty();
    int Insert_Beg_Node(int);
    int Append_Node(int);
    int Insert_Pos_Node(int, int);
    int Delete_Beg_Node();
    int Delete_End_Node();
    int Delete_Pos_Node(int);
    int SearchNode(int);
    void Display();
};

struct List::Node* List::CreateNode() {
    return (struct Node*)malloc(sizeof(struct Node));
}

void List::DeleteNode(struct Node* del) {
    free(del);
}

int List::IsEmpty() {
    if (Head == nullptr) {
        return 1;
    }
    else {
        return 0;
    }
}

int List::Insert_Beg_Node(int val) {
    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;

    if (Head == nullptr) {
        Head = NewNode;
        NewNode->Next = NewNode;
    }
    else {
        NewNode->Next = Head;
        struct Node* last = Head;
        while (last->Next != Head) {
            last = last->Next;
        }
        last->Next = NewNode;
        Head = NewNode;
    }

    return 1;
}

int List::Append_Node(int val) {
    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;

    if (Head == nullptr) {
        Head = NewNode;
        NewNode->Next = NewNode;
    }
    else {
        struct Node* last = Head;
        while (last->Next != Head) {
            last = last->Next;
        }
        last->Next = NewNode;
        NewNode->Next = Head;
    }

    return 1;
}

int List::Insert_Pos_Node(int val, int pos) {
    if (pos < 1) {
        return 0;
    }

    struct Node* NewNode = CreateNode();
    if (NewNode == nullptr) {
        return 0;
    }
    NewNode->data = val;

    if (pos == 1 || Head == nullptr) {
        if (Head == nullptr) {
            Head = NewNode;
            NewNode->Next = NewNode;
        }
        else {
            NewNode->Next = Head;
            struct Node* last = Head;
            while (last->Next != Head) {
                last = last->Next;
            }
            last->Next = NewNode;
            Head = NewNode;
        }
        return 1;
    }

    struct Node* temp = Head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->Next;
        if (temp == Head) {
            return 0;
        }
    }

    NewNode->Next = temp->Next;
    temp->Next = NewNode;

    return 1;
}

int List::Delete_Beg_Node() {
    if (Head == nullptr) {
        return 0;
    }

    struct Node* temp = Head;
    if (Head->Next == Head) {
        Head = nullptr;
    }
    else {
        struct Node* last = Head;
        while (last->Next != Head) {
            last = last->Next;
        }
        Head = Head->Next;
        last->Next = Head;
    }
    DeleteNode(temp);

    return 1;
}

int List::Delete_End_Node() {
    if (Head == nullptr) {
        return 0;
    }

    struct Node* temp = Head;
    struct Node* prev = nullptr;
    while (temp->Next != Head) {
        prev = temp;
        temp = temp->Next;
    }

    if (prev == nullptr) {
        Head = nullptr;
    }
    else {
        prev->Next = Head;
    }
    DeleteNode(temp);

    return 1;
}

int List::Delete_Pos_Node(int pos) {
    if (pos < 1 || Head == nullptr) {
        return 0;
    }

    struct Node* temp = Head;
    struct Node* prev = nullptr;
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->Next;
        if (temp == Head) {
            return 0;
        }
    }

    if (prev == nullptr) {
        Head = temp->Next;
    }
    else {
        prev->Next = temp->Next;
    }
    DeleteNode(temp);

    return 1;
}

int List::SearchNode(int val) {
    if (Head == nullptr) {
        return 0;
    }

    struct Node* temp = Head;
    int pos = 1;
    do {
        if (temp->data == val) {
            return pos;
        }
        temp = temp->Next;
        pos++;
    } while (temp != Head);

    return 0;
}

void List::Display() {
    if (Head == nullptr) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = Head;
    do {
        printf("%d ", temp->data);
        temp = temp->Next;
    } while (temp != Head);
    printf("\n");
}

int main() {
    List NewList;
    int opt, var, pos, variable;
    while (true) {
        system("cls");
        printf("\n-------------------------------------------------\nOptions : \n\t0-Exit\n\t1-Insert At Beginning\n\t2-Appending\n\t3-Insertion\n\t4-Delete beginning\n\t5-Delete end\n\t6-Deletetion\n\t7-Search\n\t8-Display\n>>> ");
        scanf("%d", &opt);
        system("cls");
        switch (opt) {
        case 0:
            return 0;
        case 1:
            printf("\nValue : ");
            scanf("%d", &var);
            if (NewList.Insert_Beg_Node(var) == 1) {
                printf("\nInserted Successfully");
            }
            else {
                printf("\nList is Full : ");
            }
            break;
        case 2:
            printf("Value to append :  ");
            scanf("%d", &var);
            if (NewList.Append_Node(var) == 1) {
                printf("\nInserted Successfully");
            }
            else {
                printf("\nList is Full :(");
            }
            break;
        case 3:
            printf("Value to Insert :  ");
            scanf("%d", &var);
            printf("Position to Insert :  ");
            scanf("%d", &pos);
            variable = NewList.Insert_Pos_Node(var, pos);
            if (variable == 1) {
                printf("\nInserted Successfully");
            }
            else if (variable == 0) {
                printf("\nList is Full :(");
            }
            else {
                printf("Invalid Position");
            }
            break;
        case 4:
            if (NewList.Delete_Beg_Node() == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 5:
            if (NewList.Delete_End_Node() == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 6:
            printf("Position to Remove :  ");
            scanf("%d", &pos);
            if (NewList.Delete_Pos_Node(pos) == 1) {
                printf("\nDeleted Successfully");
            }
            else {
                printf("\nList is Empty :(");
            }
            break;
        case 7:
            printf("Element to search :  ");
            scanf("%d", &var);
            pos = NewList.SearchNode(var);
            if (pos != 0) {
                printf("\nFound Element In index :%d", pos);
            }
            else {
                printf("\nElement Not Found in List");
            }
            break;
        case 8:
            printf("Values in List : ");
            NewList.Display();
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
    return 0;
}
