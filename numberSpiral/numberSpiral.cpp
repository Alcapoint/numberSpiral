#include <iostream> 
#include <conio.h>  
#include <windows.h> 
#pragma warning(disable : 4996) 

void menu()
{
    system("cls");
    printf("   ___<=___\n   ______ |\n 1.| __ | |\n   | |__| |\n   |______|\n\n");
    printf("   ___=>___\n   ______ |\n 2.| __ | |\n   | |__| |\n   |______|\n\n");
    printf("   ___=>___\n   | ______\n 3.| | __ |\n   | |__| |\n   |______|\n\n");
    printf("   ___<=___\n   | ______\n 4.| | __ |\n   | |__| |\n   |______|\n\n");
    printf(" 5.Изменить размер спирали\n");
    printf(" 6.Выход\n");
}
void fuck(int xpos, int ypos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos; scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
}
int main()
{
    system("color 3F");
    system("cls");
    setlocale(LC_ALL, "Russian");
    using std::cout;
    using std::cin;

    const int nmi = 26;
    int n = 0;
    int amix = 2;
    int ch = 0;
    bool exit = false;
Povtor:
    int x, y;
    printf("\n\n\nВведите размер спирали, где первое число - кол-во строк второе число - кол-во столбцов\n");
    while (!(cin >> x) || !(cin >> y) || (cin.peek() != '\n') || ((x > 20) || (x <= 0)) || ((y > 20) || (y <= 0)))
    {
        cin.clear();
        while (cin.get() != '\n');
        printf("Введены неккоректные данные\n");
    }

    while (!exit)
    {

        menu();
        fuck(0, amix); cout << "=>";
        ch = getch();
        if (ch == 224)
            ch = getch();
        switch (ch)
        {
        case 27: exit = true; break;
        case 72: amix--; break;
        case 80: amix++; break;
        case 13:
            if (amix == 2)
            {
                int ar[22][22];
                for (int i = 0; i < (x + 2); ++i) {
                    for (int j = 0; j < y + 2; ++j) {
                        if (i == 0 || i == x + 1) ar[i][j] = 1;
                        else {
                            if (j == 0 || j == y + 1) ar[i][j] = 1;
                            else ar[i][j] = -1;
                        }
                    }
                }
                int dx = 0, dy = 0;

                int count, f = 1;
                int r = 1;
                if (f == 1) {
                    count = x * y;
                    ar[1][1] = x * y;


                    if (r == 1) dy = 1;

                }

                int cx = 1, cy = 1;
                while (ar[cx + 1][cy] == -1 || ar[cx][cy - 1] == -1 || ar[cx - 1][cy] == -1 || ar[cx][cy + 1] == -1) {
                    while (ar[cx + dx][cy + dy] == -1) {
                        if (f == 1)
                            --count;
                        else ++count;
                        cx = cx + dx;
                        cy = cy + dy;
                        ar[cx][cy] = count;
                    }
                    if (ar[cx + 1][cy] == -1) {
                        dx = 1;
                        dy = 0;
                    }
                    else
                        if (ar[cx][cy + 1] == -1) {
                            dx = 0;
                            dy = 1;
                        }
                        else
                            if (ar[cx - 1][cy] == -1) {
                                dx = -1;
                                dy = 0;
                            }
                            else
                                if (ar[cx][cy - 1] == -1) {
                                    dx = 0;
                                    dy = -1;
                                }
                }
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                for (int i = 1; i < x + 1; ++i) {
                    cout << std::endl;
                    for (int j = 1; j < y + 1; ++j)
                    {
                        printf("%4d", ar[i][j]);
                    }
                }
                n = getch();
            }
            else if (amix == 8) {
                int ar[22][22];
                for (int i = 0; i < (x + 2); ++i) {
                    for (int j = 0; j < y + 2; ++j) {
                        if (i == 0 || i == x + 1) ar[i][j] = 1;
                        else {
                            if (j == 0 || j == y + 1) ar[i][j] = 1;
                            else ar[i][j] = -1;
                        }
                    }
                }

                int dx = 0, dy = 0; int f = 2;

                int count;
                int r = 2;
                if (f == 2) {
                    count = 1;
                    ar[1][1] = 1;
                    if (r == 2) dy = 1;
                }
                int cx = 1, cy = 1;
                while (ar[cx + 1][cy] == -1 || ar[cx][cy - 1] == -1 || ar[cx - 1][cy] == -1 || ar[cx][cy + 1] == -1) {
                    while (ar[cx + dx][cy + dy] == -1) {
                        if (f == 1)
                            --count;
                        else ++count;
                        cx = cx + dx;
                        cy = cy + dy;
                        ar[cx][cy] = count;
                    }
                    if (ar[cx + 1][cy] == -1) {
                        dx = 1;
                        dy = 0;
                    }
                    else
                        if (ar[cx][cy + 1] == -1) {
                            dx = 0;
                            dy = 1;
                        }
                        else
                            if (ar[cx - 1][cy] == -1) {
                                dx = -1;
                                dy = 0;
                            }
                            else
                                if (ar[cx][cy - 1] == -1) {
                                    dx = 0;
                                    dy = -1;
                                }
                } printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                for (int i = 1; i < x + 1; ++i) {
                    cout << std::endl;
                    for (int j = 1; j < y + 1; ++j)
                        printf("%4d", ar[i][j]);
                }
                n = getch();
            }

            else if (amix == 14)
            {
                int ar[22][22];
                for (int i = 0; i < (x + 2); ++i) {
                    for (int j = 0; j < y + 2; ++j) {
                        if (i == 0 || i == x + 1) ar[i][j] = 1;
                        else {
                            if (j == 0 || j == y + 1) ar[i][j] = 1;
                            else ar[i][j] = -1;
                        }
                    }
                }
                int dx = 0, dy = 0;

                int count;
                int r = 2, f = 1;
                if (f == 1) {
                    count = x * y;
                    ar[1][1] = x * y;
                    if (r == 2) dx = 1;
                }

                int cx = 1, cy = 1;
                while (ar[cx + 1][cy] == -1 || ar[cx][cy - 1] == -1 || ar[cx - 1][cy] == -1 || ar[cx][cy + 1] == -1) {
                    while (ar[cx + dx][cy + dy] == -1) {
                        if (f == 1)
                            --count;
                        else ++count;
                        cx = cx + dx;
                        cy = cy + dy;
                        ar[cx][cy] = count;
                    }
                    if (ar[cx + 1][cy] == -1) {
                        dx = 1;
                        dy = 0;
                    }
                    else
                        if (ar[cx][cy + 1] == -1) {
                            dx = 0;
                            dy = 1;
                        }
                        else
                            if (ar[cx - 1][cy] == -1) {
                                dx = -1;
                                dy = 0;
                            }
                            else
                                if (ar[cx][cy - 1] == -1) {
                                    dx = 0;
                                    dy = -1;
                                }
                } printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
                for (int i = 1; i < x + 1; ++i) {
                    cout << std::endl;
                    for (int j = 1; j < y + 1; ++j)
                        printf("%4d", ar[i][j]);
                }


                n = getch();
            }
            else if (amix == 20)
            {
                int ar[22][22];
                for (int i = 0; i < (x + 2); ++i) {
                    for (int j = 0; j < y + 2; ++j) {
                        if (i == 0 || i == x + 1) ar[i][j] = 1;
                        else {
                            if (j == 0 || j == y + 1) ar[i][j] = 1;
                            else ar[i][j] = -1;
                        }
                    }
                }
                int dx = 0, dy = 0;
                int f = 2;

                int count;
                int r = 2;

                if (f == 2) {
                    count = 1;
                    ar[1][1] = 1;
                    if (r == 1) dx = 1;

                }
                int cx = 1, cy = 1;
                while (ar[cx + 1][cy] == -1 || ar[cx][cy - 1] == -1 || ar[cx - 1][cy] == -1 || ar[cx][cy + 1] == -1) {
                    while (ar[cx + dx][cy + dy] == -1) {
                        if (f == 1)
                            --count;
                        else ++count;
                        cx = cx + dx;
                        cy = cy + dy;
                        ar[cx][cy] = count;
                    }
                    if (ar[cx + 1][cy] == -1) {
                        dx = 1;
                        dy = 0;
                    }
                    else
                        if (ar[cx][cy + 1] == -1) {
                            dx = 0;
                            dy = 1;
                        }
                        else
                            if (ar[cx - 1][cy] == -1) {
                                dx = -1;
                                dy = 0;
                            }
                            else
                                if (ar[cx][cy - 1] == -1) {
                                    dx = 0;
                                    dy = -1;
                                }
                } printf("\n\n\n\n\n\n\n\n");
                for (int i = 1; i < x + 1; ++i) {
                    cout << std::endl;
                    for (int j = 1; j < y + 1; ++j)
                        printf("%4d", ar[i][j]);
                }
                n = getch();
            }
            else if (amix == 24)
            {
                goto Povtor;
            }
            else if (amix == 25)
            {
                _Exit(1);
            }
            break;
        }
        if (amix < 0) amix = 25;
        if (amix > nmi - 1) amix = 2;
        if ((amix > 2) && (amix < 4)) amix = 8;
        if ((amix > 8) && (amix < 10)) amix = 14;
        if ((amix > 14) && (amix < 16)) amix = 20;
        if ((amix > 20) && (amix < 22)) amix = 24;
        if (amix == 23) amix = 20;
        if (amix == 19) amix = 14;
        if (amix == 13) amix = 8;
        if (amix == 7) amix = 2;
        if (amix == 1) amix = 25;
        if (ch == 49) amix = 2;
        if (ch == 50) amix = 8;
        if (ch == 51) amix = 14;
        if (ch == 52) amix = 20;
        if (ch == 53) amix = 24;
        if (ch == 54) amix = 253;
    }
    return 3;
}