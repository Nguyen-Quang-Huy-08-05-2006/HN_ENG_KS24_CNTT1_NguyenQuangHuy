#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book
{
    int id;
    char title[100];
    char author[100];
    char category[50];
    float price;
} Book;

struct Node
{
    Book data;
    struct Node *next;
};

struct Node *
createNode(Book data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    printf("Danh sach sach: \n");
    while (temp != NULL)
    {
        printf("ID: %d, Ten sach: %s, Tac gia: %s, The loai: %s, Gia: %.2f\n",
               temp->data.id,
               temp->data.title,
               temp->data.author,
               temp->data.category,
               temp->data.price);
        temp = temp->next;
    }
}

int validId(struct Node **head, int id)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        if (id == temp->data.id)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Helper function to flush input buffer
void flushInput()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

void deleteBookById(struct Node **head, int id)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            if (prev == NULL)
            {
                *head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("Đã xóa sách có ID %d.\n", id);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Không tìm thấy sách có ID %d.\n", id);
}

void updateBook(struct Node **head, int id)
{
    struct Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            printf("Nhập vào tên sách mới: ");
            fgets(temp->data.title, sizeof(temp->data.title), stdin);
            temp->data.title[strcspn(temp->data.title, "\n")] = 0;

            printf("Nhập vào tên tác giả mới: ");
            fgets(temp->data.author, sizeof(temp->data.author), stdin);
            temp->data.author[strcspn(temp->data.author, "\n")] = 0;

            printf("Nhập vào thể loại sách mới: ");
            fgets(temp->data.category, sizeof(temp->data.category), stdin);
            temp->data.category[strcspn(temp->data.category, "\n")] = 0;

            printf("Nhập vào giá sách mới: ");
            scanf("%f", &temp->data.price);
            flushInput();
            return;
        }
    }
}

int main(void)
{
    int answer = 0;
    Book book;
    struct Node *head = NULL;
    do
    {
        printf("—————————— BOOK MANAGER ——————————\n");
        printf("1. Thêm sách.\n");
        printf("2. Hiển thị danh sách tất cả quyển sách.\n");
        printf("3. Xóa sách.\n");
        printf("4. Cập nhật thông tin một quyển sách.\n");
        printf("5. Đánh dấu sách đã đọc xong.\n");
        printf("6. Sắp xếp sách theo giá tăng dần.\n");
        printf("7. Tìm kiếm sách theo tiêu đề.\n");
        printf("8. Thoát chương trình.\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            do
            {
                printf("Nhập vào ID sách: ");
                scanf("%d", &book.id);
                if (validId(&head, book.id))
                {
                    printf("ID bạn vừa nhập đã bị trùng, vui lòng nhập lại.\n");
                }
            } while (validId(&head, book.id));

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            printf("Nhập vào tên sách: ");
            fgets(book.title, sizeof(book.title), stdin);
            book.title[strcspn(book.title, "\n")] = 0;

            printf("Nhập vào tên tác giả: ");
            fgets(book.author, sizeof(book.author), stdin);
            book.author[strcspn(book.author, "\n")] = 0;

            printf("Nhập vào thể loại sách: ");
            fgets(book.category, sizeof(book.category), stdin);
            book.category[strcspn(book.category, "\n")] = 0;

            printf("Nhập vào giá sách: ");
            scanf("%f", &book.price);
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
            if (head == NULL)
            {
                head = createNode(book);
            }
            else
            {
                struct Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = createNode(book);
            }
            break;
        case 2:
            printList(head);
            break;
        case 3:
            int deleteId;
            printf("Nhập id bạn muốn xóa: ");
            scanf("%d", &deleteId);
            deleteBookById(&head, deleteId);
            break;
        case 4:
            int fixBookId;
            printf("Nhập id sách bạn muốn cập nhật thông tin:\n");
            scanf("%d", &fixBookId);
            updateBook(&head, fixBookId);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            printf("Đang thoát chương trình....\n");
            break;
        default:
            printf("Sai cú pháp.");
            break;
        }

    } while (answer != 8);

    return 0;
}
