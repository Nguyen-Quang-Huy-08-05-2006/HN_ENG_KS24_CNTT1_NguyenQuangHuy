#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int answer;
    do
    {
        printf("——————————— TERMINAL HISTORY—————————\n");
        printf("1.INSERT : Gõ lệnh mới (nhập một chuỗi lệnh\n");
        printf("2.UNDO: Hoàn tác lệnh gần nhất (xóa lệnh vừa gõ khỏi lịch sử)\n");
        printf("3.REDO: Phục hồi lệnh vừa undo\n");
        printf("4.HIỂN THỊ: In toàn bộ lịch sử lệnh (mới nhất đến cũ nhất)\n");
        printf("5.THOÁT: Kết thúc chương trình\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &answer);

        switch (answer)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Dang thoat chuong trinh...");
            return 0;
        default:
            break;
        }

    } while (answer != 5);

    return 0;
}