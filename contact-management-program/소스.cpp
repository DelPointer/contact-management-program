#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


int main()
{
    //1) ����ó �˻�
    //2) ����ó �߰�
    //3) ����ó ����
    //4) ������

    //variables
    int length = 0, input;
    char name[100][10] = { }; //�ִ� 10����Ʈ 100��
    int num[100] = { 0 }; //0���� �ʱ�ȭ NULL���ֱ� ����
    int birth[100] = { 0 };
    int sequence[100] = { 0 };

    //initial screen(choosing functions)
inp:
    system("cls");
    puts("1) ����ó �˻�");
    puts("2) ����ó �߰�");
    puts("3) ����ó ����");
    puts("4) ������");
    printf("����� ����: ");
    scanf("%d", &input);
    if (!(1 <= input && input <= 4)) goto inp; //1~4 �Է� �� ������ �ݺ�

    //each function
    system("cls");
    if (input == 1) {       //����ó �˻�
        if (length == 0) puts("�Էµ� ����ó�� �����ϴ�.");
        else {
            for (int i = 0; i < length; i++) {
                int a, b;
                printf("[%d]", i);
                for (a = 0; a < sequence[i]; a++) printf("��");
                for (b = a; b < 5; b++) printf("��");
                printf("\n�̸�: %s\n", name[i]);
                printf("��ȭ��ȣ: %011d\n", num[i]);

                switch (birth[i] / 10000 % 12) {
                case 0: printf("�������: %8d(�����̶�)\n", birth[i]); break;
                case 1: printf("�������: %8d(�߶�)\n", birth[i]); break;
                case 2: printf("�������: %8d(����)\n", birth[i]); break;
                case 3: printf("�������: %8d(������)\n", birth[i]); break;
                case 4: printf("�������: %8d(���)\n", birth[i]); break;
                case 5: printf("�������: %8d(�Ҷ�)\n", birth[i]); break;
                case 6: printf("�������: %8d(ȣ���̶�)\n", birth[i]); break;
                case 7: printf("�������: %8d(�䳢��)\n", birth[i]); break;
                case 8: printf("�������: %8d(���)\n", birth[i]); break;
                case 9: printf("�������: %8d(���)\n", birth[i]); break;
                case 10: printf("�������: %8d(����)\n", birth[i]); break;
                case 11: printf("�������: %8d(���)\n", birth[i]); break;
                }

            }
            printf("[Enter�� ���� �ʱ�ȭ������ ���ư���.]");
            goto sc;
        }
        printf("[Enter�� ���� �ʱ�ȭ������ ���ư���.]");
    sc:
        char a = _getch();
        if (a == 13) goto inp;
        else goto sc;
    }
    else if (input == 2) {  //����ó �߰�
        int count;

        printf("�Է��� ����ó ����: ");
        scanf("%d", &count);
        for (int i = 0; i + length < count + length; i++) {
            printf("�̸�: ");
            scanf("%s", &name[i + length]);

            printf("��ȭ��ȣ: ");
            scanf("%d", &num[i + length]);

            printf("�������(yyyymmdd): ");
            scanf("%d", &birth[i + length]);

            printf("���� ��(1 ~ 5): ");
            scanf("%d", &sequence[i + length]);
            puts("");
        }
        length += count;
        printf("[Enter�� ���� �ʱ�ȭ������ ���ư���.]");
    ac:
        char a = _getch();
        if (a == 13) goto inp;
        else goto ac;
    }
    else if (input == 3) {  //����ó ����
        if (length != 0) {
            int n;
            for (int i = 0; i < length; i++) {
                int a, b;
                printf("[%d]", i);
                for (a = 0; a < sequence[i]; a++) printf("��");
                for (b = a; b < 5; b++) printf("��");
                printf("\n�̸�: %s\n", name[i]);
                printf("��ȭ��ȣ: %011d\n", num[i]);

                switch (birth[i] / 10000 % 12) {
                case 0: printf("�������: %8d(�����̶�)\n", birth[i]); break;
                case 1: printf("�������: %8d(�߶�)\n", birth[i]); break;
                case 2: printf("�������: %8d(����)\n", birth[i]); break;
                case 3: printf("�������: %8d(������)\n", birth[i]); break;
                case 4: printf("�������: %8d(���)\n", birth[i]); break;
                case 5: printf("�������: %8d(�Ҷ�)\n", birth[i]); break;
                case 6: printf("�������: %8d(ȣ���̶�)\n", birth[i]); break;
                case 7: printf("�������: %8d(�䳢��)\n", birth[i]); break;
                case 8: printf("�������: %8d(���)\n", birth[i]); break;
                case 9: printf("�������: %8d(���)\n", birth[i]); break;
                case 10: printf("�������: %8d(����)\n", birth[i]); break;
                case 11: printf("�������: %8d(���)\n", birth[i]); break;
                }

            }
            printf("\n������ ����ó �ѹ�: ");
            scanf("%d", &n);
            for (int i = n; i < length; i++) {
                strcpy(name[i], name[i + 1]);
                num[i] = num[i + 1];
                birth[i] = birth[i + 1];
                sequence[i] = sequence[i + 1];
            }
            printf("[Enter�� ���� �ʱ�ȭ������ ���ư���.]");
        dc:
            char a = _getch();
            if (a == 13) goto inp;
            else goto dc;
        }
        else {
            printf("����� ����ó�� �����ϴ�.\n");
            printf("[Enter�� ���� �ʱ�ȭ������ ���ư���.]");
        dc1:
            char a = _getch();
            if (a == 13) goto inp;
            else goto dc1;
        }
    }
    else if (input == 4) {  //������
        printf("�����մϴ�.");
        exit(1);
    }

    return 0;
}
