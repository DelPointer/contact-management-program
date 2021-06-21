#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int main()
{
    //1) 연락처 검색
    //2) 연락처 추가
    //3) 연락처 삭제
    //4) 나가기

    //variables
    int length = 0, input;
    char name[100][10] = { }; //최대 10바이트 100개
    int num[100] = { 0 }; //0으로 초기화 NULL없애기 위해
    int birth[100] = { 0 };
    int sequence[100] = { 0 };

    //initial screen(choosing functions)
inp:
    system("cls");
    puts("1) 연락처 검색");
    puts("2) 연락처 추가");
    puts("3) 연락처 삭제");
    puts("4) 나가기");
    printf("기능을 선택: ");
    scanf("%d", &input);
    if (!(1 <= input && input <= 4)) goto inp; //1~4 입력 될 때까지 반복

    //each function
    system("cls");
    if (input == 1) {       //연락처 검색
        if (length == 0) puts("입력된 연락처가 없습니다.");
        else {
            for (int i = 0; i < length; i++) {
                int a, b;
                printf("[%d]", i);
                for (a = 0; a < sequence[i]; a++) printf("★");
                for (b = a; b < 5; b++) printf("☆");
                printf("\n이름: %s\n", name[i]);
                printf("전화번호: %011d\n", num[i]);

                switch (birth[i] / 10000 % 12) {
                case 0: printf("생년월일: %8d(원숭이띠)\n", birth[i]); break;
                case 1: printf("생년월일: %8d(닭띠)\n", birth[i]); break;
                case 2: printf("생년월일: %8d(개띠)\n", birth[i]); break;
                case 3: printf("생년월일: %8d(돼지띠)\n", birth[i]); break;
                case 4: printf("생년월일: %8d(쥐띠)\n", birth[i]); break;
                case 5: printf("생년월일: %8d(소띠)\n", birth[i]); break;
                case 6: printf("생년월일: %8d(호랑이띠)\n", birth[i]); break;
                case 7: printf("생년월일: %8d(토끼띠)\n", birth[i]); break;
                case 8: printf("생년월일: %8d(용띠)\n", birth[i]); break;
                case 9: printf("생년월일: %8d(뱀띠)\n", birth[i]); break;
                case 10: printf("생년월일: %8d(말띠)\n", birth[i]); break;
                case 11: printf("생년월일: %8d(양띠)\n", birth[i]); break;
                }

            }
            printf("[Enter를 눌러 초기화면으로 돌아가기.]");
            goto sc;
        }
        printf("[Enter를 눌러 초기화면으로 돌아가기.]");
    sc:
        char a = _getch();
        if (a == 13) goto inp;
        else goto sc;
    }
    else if (input == 2) {  //연락처 추가
        int count;

        printf("입력할 연락처 개수: ");
        scanf("%d", &count);
        for (int i = 0; i + length < count + length; i++) {
            printf("이름: ");
            scanf("%s", &name[i + length]);

            printf("전화번호: ");
            scanf("%d", &num[i + length]);

            printf("생년월일(yyyymmdd): ");
            scanf("%d", &birth[i + length]);

            printf("연락 빈도(1 ~ 5): ");
            scanf("%d", &sequence[i + length]);
            puts("");
        }
        length += count;
        printf("[Enter를 눌러 초기화면으로 돌아가기.]");
    ac:
        char a = _getch();
        if (a == 13) goto inp;
        else goto ac;
    }
    else if (input == 3) {  //연락처 삭제
        if (length != 0) {
            int n;
            for (int i = 0; i < length; i++) {
                int a, b;
                printf("[%d]", i);
                for (a = 0; a < sequence[i]; a++) printf("★");
                for (b = a; b < 5; b++) printf("☆");
                printf("\n이름: %s\n", name[i]);
                printf("전화번호: %011d\n", num[i]);

                switch (birth[i] / 10000 % 12) {
                case 0: printf("생년월일: %8d(원숭이띠)\n", birth[i]); break;
                case 1: printf("생년월일: %8d(닭띠)\n", birth[i]); break;
                case 2: printf("생년월일: %8d(개띠)\n", birth[i]); break;
                case 3: printf("생년월일: %8d(돼지띠)\n", birth[i]); break;
                case 4: printf("생년월일: %8d(쥐띠)\n", birth[i]); break;
                case 5: printf("생년월일: %8d(소띠)\n", birth[i]); break;
                case 6: printf("생년월일: %8d(호랑이띠)\n", birth[i]); break;
                case 7: printf("생년월일: %8d(토끼띠)\n", birth[i]); break;
                case 8: printf("생년월일: %8d(용띠)\n", birth[i]); break;
                case 9: printf("생년월일: %8d(뱀띠)\n", birth[i]); break;
                case 10: printf("생년월일: %8d(말띠)\n", birth[i]); break;
                case 11: printf("생년월일: %8d(양띠)\n", birth[i]); break;
                }

            }
            printf("\n삭제할 연락처 넘버: ");
            scanf("%d", &n);
            for (int i = n; i < length; i++) {
                strcpy(name[i], name[i + 1]);
                num[i] = num[i + 1];
                birth[i] = birth[i + 1];
                sequence[i] = sequence[i + 1];
            }
            printf("[Enter를 눌러 초기화면으로 돌아가기.]");
        dc:
            char a = _getch();
            if (a == 13) goto inp;
            else goto dc;
        }
        else {
            printf("저장된 연락처가 없습니다.\n");
            printf("[Enter를 눌러 초기화면으로 돌아가기.]");
        dc1:
            char a = _getch();
            if (a == 13) goto inp;
            else goto dc1;
        }
    }
    else if (input == 4) {  //나가기
        printf("종료합니다.");
        exit(1);
    }

    return 0;
}
