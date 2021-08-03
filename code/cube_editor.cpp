#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include "cube.h"

using namespace std;

Cube_list zbs;

void Pos(int x, int y) //设置光标位置
{
    COORD pos;
    HANDLE hOutput;
    pos.X = x;
    pos.Y = y;
    hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOutput, pos);
}
void cubeBoard(char size);
void cubeBoard(char size, int cor); //失败，没用
void arrowsU(int x, int y, char size);
void arrowsD(int x, int y, char size);
void arrowsR(int x, int y, char size);
void arrowsL(int x, int y, char size);
void demo_step(string step, char size);
void cube_disp(string step, char size);
void color_set(int i, int j); //失败，没用

void CFOP();

void demo(float speed, char size)
{
    int i = 0;
    char key;
    string step;
    float dura = 0.8 / speed;
    float inte = 0.2 / speed;
    system("cls");
    cout << " 当前公式：" << zbs.present->formula << endl;
    cout << " 实际：    " << zbs.present->fdirect << endl;
    cout << " 当前速度：" << speed << endl;
    cubeBoard(size);
    cout << "Esc退出\t空格└─ ┘ 暂停\t准备开始  ";
    while (1)
    {
        i = 0;
        if (zbs.present->fdirect[i] == '\0')
        {
            if (size == 'S')
            {
                Pos(24, 23);
            }
            else
            {
                Pos(24, 29);
            }
            cout << "没有公式！";
            Sleep(1 * 1000);
            break;
        }
        if (size == 'S')
        {
            Pos(24, 23);
        }
        else
        {
            Pos(24, 29);
        }
        cout << "准备开始  ";
        Sleep(1 * 1000);
        while (zbs.present->fdirect[i] != '\0')
        {
            if (_kbhit()) //如果有按键按下，则_kbhit()函数返回真
            {
                key = _getch(); //使用_getch()函数获取按下的键值
                cout << key;
                if (key == 27) //当按下ESC时循环，ESC键的键值时27.
                {
                    return;
                }
                if (key == ' ')
                {
                    system("pause");
                }
                if (key == 'R' || key == 'r')
                {
                    i = 0;
                }
            }
            system("cls");
            cout << " 当前公式：" << zbs.present->formula << endl;
            cout << " 实际：    " << zbs.present->fdirect << endl;
            cout << " 当前速度：" << speed << endl;
            cubeBoard(size);
            step = zbs.present->fdirect[i];
            if (zbs.present->fdirect[i] > '9' && zbs.present->fdirect[i + 1] > '9')
            {
                demo_step(step, size);
                zbs.operate(step);
                i++;
            }
            else if (zbs.present->fdirect[i] > '9' && zbs.present->fdirect[i + 1] == '\0')
            {
                demo_step(step, size);
                zbs.operate(step);
                i++;
            }
            else if (zbs.present->fdirect[i] > '9' && zbs.present->fdirect[i + 1] == '\'')
            {
                step.insert(1, "\'");
                demo_step(step, size);
                zbs.operate(step);
                i += 2;
            }
            else
            {
                i++;
            }
            cout << "Esc退出\t空格└─ ┘ 暂停\t当前：" << step;
            Pos(10 + i, 1);
            Sleep(dura * 1000);
            system("cls");
            cout << " 当前公式：" << zbs.present->formula << endl;
            cout << " 实际：    " << zbs.present->fdirect << endl;
            cout << " 当前速度：" << speed << endl;
            cubeBoard(size);
            cout << "Esc退出\t空格└─ ┘ 暂停\t当前：" << step;
            Pos(10 + i, 1);
            Sleep(inte * 1000);
        }
        system("cls");
        cout << " 当前公式：" << zbs.present->formula << endl;
        cout << " 实际：    " << zbs.present->fdirect << endl;
        cout << " 当前速度：" << speed << endl;
        cubeBoard(size);
        cout << "Esc退出\t空格└─ ┘ 暂停\t结束      ";
        Sleep(2 * 1000);
        if (size == 'S')
        {
            Pos(24, 23);
        }
        else
        {
            Pos(24, 29);
        }
        cout << "重新开始  ";
        Sleep(1 * 1000);
    }
}
void formula_remove_rotate()
{
    int i = 0;
    string dir;
    while (zbs.present->formula[i] != '\0')
    {
        if (zbs.present->formula[i] == 'X' || zbs.present->formula[i] == 'x' || zbs.present->formula[i] == 'Y' || zbs.present->formula[i] == 'y' || zbs.present->formula[i] == 'Z' || zbs.present->formula[i] == 'z')
        {
            if (zbs.present->formula[i + 1] == '\'')
            {
                dir = zbs.present->formula.substr(i, 1);
                zbs.formula = zbs.present->formula.substr(i + 2); //截取i+2以后的字符串
            }
            else
            {
                dir = zbs.present->formula.substr(i, 1);
                dir.insert(1, "\'");
                zbs.formula = zbs.present->formula.substr(i + 1); //截取i+1以后的字符串
            }
            zbs.formula_rotate(dir);
            zbs.present->formula.erase(i);               //删除i以后的字符串
            zbs.present->formula.insert(i, zbs.formula); //插入翻转后的字符串
        }
        else
        {
            i++;
        }
    }
    zbs.present->direc_sync();
}

void editmenu()
{
    cout << "*************************" << endl;
    cout << "*  1\t公式倒置\t*" << endl;
    cout << "*  2\t公式镜像\t*" << endl;
    cout << "*  3\t公式翻转\t*" << endl;
    cout << "*  4\t公式去翻转\t*" << endl;
    cout << "*  5\t公式演示\t*" << endl;
    cout << "*  6\t演示设置\t*" << endl;
    cout << "*  7\t清屏\t\t*" << endl;
    cout << "*  8\t返回\t\t*" << endl;
    cout << "*************************" << endl;

    cout << " 当前公式： " << zbs.present->fname << endl;
    cout << " " << zbs.present->formula << endl;
    cout << "*************************" << endl;
}
void edit()
{
    int i = 0;
    char dir;
    float speed = 1;
    char size = 'B';
    system("cls");
    editmenu();
    while (1)
    {
        cout << "\n请选择功能：";
        cin >> i;
        switch (i)
        {
        case 1:
            zbs.present->formula_inverse();
            cout << "反转后：\n"
                 << zbs.present->formula << endl;
            break;
        case 2:
            zbs.present->formula_mirror();
            cout << "镜像后：\n"
                 << zbs.present->formula << endl;
            break;
        case 3:
            zbs.present->formula_rotate();
            cout << "翻转后：\n"
                 << zbs.present->formula << endl;
            break;
        case 4:
            formula_remove_rotate();
            cout << "去翻转后：\n"
                 << zbs.present->formula << endl;
            break;
        case 5:
            demo(speed, size);
            system("cls");
            editmenu();
            break;
        case 6:
            cout << "请输入速度：" << endl;
            cin >> speed;
            cout << "请选择大小（大：B ；小：S）" << endl;
            cin >> size;
            if (size == 's')
                size = 'S';
            if (size != 'B' && size != 'S')
                size = 'B';
            break;
        case 7:
            system("cls");
            editmenu();
            break;
        case 8:
            return;
        default:
            while (getchar() != '\n')
                getchar();
            printf("无效选项");
            break;
        }
    }
}
void file_opera()
{
    int i = 0;
    if (!(GetFileAttributes(TEXT("lib")) == FILE_ATTRIBUTE_DIRECTORY))
    {
        bool flag = CreateDirectory(TEXT("lib"), NULL);
        // flag 为 true 说明创建成功
        system("cls");
        if (flag)
        {
            cout << "lib文件夹创建成功" << endl;
        }
        else
        {
            cout << "创建失败" << endl;
        }
        CFOP();
        cout << "lib\\CFOP创建成功" << endl;
        Sleep(500);
    } /*
    else
    {
        cout << "lib文件夹已存在" << endl;
    }*/
    system("cls");
    cout << "*****************" << endl;
    cout << "*  1\t读取\t*" << endl;
    cout << "*  2\t保存\t*" << endl;
    cout << "*  3\t返回\t*" << endl;
    cout << "*****************" << endl;

    while (1)
    {
        cout << "\n请选择功能：";
        cin >> i;
        getchar(); //读取回车
        switch (i)
        {
        case 1:
        {
            string fname;
            ifstream fin;
            cout << "请输入文件名（默认formula_data）：" << endl;
            getline(cin, fname);
            if (fname.empty())
            {
                fname = "formula_data";
            }
            if (fname.find(":") == fname.npos && fname.find("\\") == fname.npos) //如果不是绝对路径或相对路径
            {
                fname = "lib\\" + fname;
            }
            fin.open(fname, ios::in);
            if (!fin.is_open())
            {
                cout << "无法打开文件！" << fname << endl;
                break;
            }
            string n, f;
            string line;
            while (getline(fin, line))
            {
                if (line.empty())
                    continue;
                if (line.find("#") != line.npos) //注释
                    continue;
                stringstream word(line);
                word >> n >> f;
                if (zbs.add(n, f))
                {
                    cout << "文件格式错误！" << endl;
                    break;
                }
            }
            fin.close();
            break;
        }
        case 2:
        {
            string fname;
            ofstream fout;
            cout << "请输入文件名（默认formula_data）：" << endl;
            getline(cin, fname);
            if (fname.empty())
            {
                fname = "formula_data";
            }
            if (fname.find(":") == fname.npos && fname.find("\\") == fname.npos) //如果不是绝对路径或相对路径
            {
                fname = "lib\\" + fname;
            }
            fout.open(fname, ios::out);
            if (!fout.is_open())
            {
                cout << "无法打开文件！" << fname << endl;
                break;
            }
            cube_formula *pre = zbs.head->next;
            while (pre != nullptr)
            {
                fout << pre->fname << "\t " << pre->formula << endl;
                pre = pre->next; //循环输出
            }
            fout.close();
            break;
        }
        case 3:
            return;
        default:
            while (getchar() != '\n')
                getchar();
            printf("无效选项");
            break;
        }
    }
}

void menu()
{
    cout << "****************************" << endl;
    cout << "*      魔方公式编辑器      *" << endl;
    cout << "****************************" << endl;
    cout << "*  1\t所有公式\t   *" << endl;
    cout << "*  2\t切换公式\t   *" << endl;
    cout << "*  3\t添加公式\t   *" << endl;
    cout << "*  4\t修改公式\t   *" << endl;
    cout << "*  5\t删除公式\t   *" << endl;
    cout << "*  6\t搜索公式\t   *" << endl;
    cout << "*  7\t编辑公式\t   *" << endl;
    cout << "*  8\t文件\t\t   *" << endl;
    cout << "*  9\t清屏\t\t   *" << endl;
    cout << "*  10\t退出\t\t   *" << endl;
    cout << "****************************" << endl;

    cout << " 当前公式： " << zbs.present->fname << endl;
    cout << " " << zbs.present->formula << endl;
    cout << "****************************" << endl;
}
int main()
{
    int i = 0;
    system("color f0");
    menu();
    while (1)
    {
        cout << "\n请选择功能：";
        cin >> i;
        switch (i)
        {
        case 1:
            zbs.traver();
            break;
        case 2:
            zbs.present_set();
            system("cls");
            menu();
            break;
        case 3:
            zbs.add();
            break;
        case 4:
            zbs.change(zbs.present_at());
            break;
        case 5:
            if (zbs.del(zbs.present_at()) == 0)
            {
                system("cls");
                menu();
                cout << "\n删除成功！" << endl;
            }
            break;
        case 6:
            zbs.search();
            break;
        case 7:
            edit();
            system("cls");
            menu();
            break;
        case 8:
            file_opera();
            system("cls");
            menu();
            break;
        case 9:
            system("cls");
            menu();
            break;
        case 10:
            return 0;
        default:
            while (getchar() != '\n')
                getchar();
            printf("无效选项");
            break;
        }
    }
    return 0;
}

void cubeBoard(char size)
{
    if (size == 'S')
    {
        cout << "┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘" << endl;
        cout << "┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘" << endl;
    }
    else
    {
        cout << "┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘" << endl;
        cout << "┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘" << endl;
    }
}
void cubeBoard(char size, int cor) //失败，没法用
{
    system("color 70");
    if (size == 'S')
    {
        cout << "┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     │" << endl;
        cout << "│     │     │     │" << endl;
        cout << "└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘" << endl;
        cout << "┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐┌ ─ ─ ┬ ─ ─ ┬ ─ ─ ┐" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤├ ─ ─ ┼ ─ ─ ┼ ─ ─ ┤" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "│     │     │     ││     │     │     │" << endl;
        cout << "└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘└ ─ ─ ┴ ─ ─ ┴ ─ ─ ┘" << endl;
        if (cor)
        {
            color_set(1, 0);
            Pos(2, 4);
            cout << "■■";
            Pos(2, 5);
            cout << "■■";
            color_set(1, 1);
            Pos(8, 4);
            cout << "■■";
            Pos(8, 5);
            cout << "■■";
            color_set(1, 2);
            Pos(14, 4);
            cout << "■■";
            Pos(14, 5);
            cout << "■■";
            color_set(1, 3);
            Pos(2, 7);
            cout << "■■";
            Pos(2, 8);
            cout << "■■";
            color_set(1, 4);
            Pos(8, 7);
            cout << "■■";
            Pos(8, 8);
            cout << "■■";
            color_set(1, 5);
            Pos(14, 7);
            cout << "■■";
            Pos(14, 8);
            cout << "■■";
            color_set(1, 6);
            Pos(2, 10);
            cout << "■■";
            Pos(2, 11);
            cout << "■■";
            color_set(1, 7);
            Pos(8, 10);
            cout << "■■";
            Pos(8, 11);
            cout << "■■";
            color_set(1, 8);
            Pos(14, 10);
            cout << "■■";
            Pos(14, 11);
            cout << "■■";

            color_set(2, 0);
            Pos(2, 14);
            cout << "■■";
            Pos(2, 15);
            cout << "■■";
            color_set(2, 1);
            Pos(8, 14);
            cout << "■■";
            Pos(8, 15);
            cout << "■■";
            color_set(2, 2);
            Pos(14, 14);
            cout << "■■";
            Pos(14, 15);
            cout << "■■";
            color_set(2, 3);
            Pos(2, 17);
            cout << "■■";
            Pos(2, 18);
            cout << "■■";
            color_set(2, 4);
            Pos(8, 17);
            cout << "■■";
            Pos(8, 18);
            cout << "■■";
            color_set(2, 5);
            Pos(14, 17);
            cout << "■■";
            Pos(14, 18);
            cout << "■■";
            color_set(2, 6);
            Pos(2, 20);
            cout << "■■";
            Pos(2, 21);
            cout << "■■";
            color_set(2, 7);
            Pos(8, 20);
            cout << "■■";
            Pos(8, 21);
            cout << "■■";
            color_set(2, 8);
            Pos(14, 20);
            cout << "■■";
            Pos(14, 21);
            cout << "■■";

            color_set(4, 0);
            Pos(21, 14);
            cout << "■■";
            Pos(21, 15);
            cout << "■■";
            color_set(4, 1);
            Pos(27, 14);
            cout << "■■";
            Pos(27, 15);
            cout << "■■";
            color_set(4, 2);
            Pos(33, 14);
            cout << "■■";
            Pos(33, 15);
            cout << "■■";
            color_set(4, 3);
            Pos(21, 17);
            cout << "■■";
            Pos(21, 18);
            cout << "■■";
            color_set(4, 4);
            Pos(27, 17);
            cout << "■■";
            Pos(27, 18);
            cout << "■■";
            color_set(4, 5);
            Pos(33, 17);
            cout << "■■";
            Pos(33, 18);
            cout << "■■";
            color_set(4, 6);
            Pos(21, 20);
            cout << "■■";
            Pos(21, 21);
            cout << "■■";
            color_set(4, 7);
            Pos(27, 20);
            cout << "■■";
            Pos(27, 21);
            cout << "■■";
            color_set(4, 8);
            Pos(33, 20);
            cout << "■■";
            Pos(33, 21);
            cout << "■■";
        }
        Pos(0, 23);
    }
    else
    {
        cout << "┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "│       │       │       │" << endl;
        cout << "└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘" << endl;
        cout << "┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐┌ ─ ─ ─ ┬ ─ ─ ─ ┬ ─ ─ ─ ┐" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤├ ─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─ ┤" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "│       │       │       ││       │       │       │" << endl;
        cout << "└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘└ ─ ─ ─ ┴ ─ ─ ─ ┴ ─ ─ ─ ┘" << endl;
        if (cor)
        {
            color_set(1, 0);
            Pos(2, 4);
            cout << "■■■";
            Pos(2, 5);
            cout << "■■■";
            Pos(2, 6);
            cout << "■■■";
            color_set(1, 1);
            Pos(10, 4);
            cout << "■■■";
            Pos(10, 5);
            cout << "■■■";
            Pos(10, 6);
            cout << "■■■";
            color_set(1, 2);
            Pos(18, 4);
            cout << "■■■";
            Pos(18, 5);
            cout << "■■■";
            Pos(18, 6);
            cout << "■■■";
            color_set(1, 3);
            Pos(2, 8);
            cout << "■■■";
            Pos(2, 9);
            cout << "■■■";
            Pos(2, 10);
            cout << "■■■";
            color_set(1, 4);
            Pos(10, 8);
            cout << "■■■";
            Pos(10, 9);
            cout << "■■■";
            Pos(10, 10);
            cout << "■■■";
            color_set(1, 5);
            Pos(18, 8);
            cout << "■■■";
            Pos(18, 9);
            cout << "■■■";
            Pos(18, 10);
            cout << "■■■";
            color_set(1, 6);
            Pos(2, 12);
            cout << "■■■";
            Pos(2, 13);
            cout << "■■■";
            Pos(2, 14);
            cout << "■■■";
            color_set(1, 7);
            Pos(10, 12);
            cout << "■■■";
            Pos(10, 13);
            cout << "■■■";
            Pos(10, 14);
            cout << "■■■";
            color_set(1, 8);
            Pos(18, 12);
            cout << "■■■";
            Pos(18, 13);
            cout << "■■■";
            Pos(18, 14);
            cout << "■■■";

            color_set(2, 0);
            Pos(2, 17);
            cout << "■■■";
            Pos(2, 18);
            cout << "■■■";
            Pos(2, 19);
            cout << "■■■";
            color_set(2, 1);
            Pos(10, 17);
            cout << "■■■";
            Pos(10, 18);
            cout << "■■■";
            Pos(10, 19);
            cout << "■■■";
            color_set(2, 2);
            Pos(18, 17);
            cout << "■■■";
            Pos(18, 18);
            cout << "■■■";
            Pos(18, 19);
            cout << "■■■";
            color_set(2, 3);
            Pos(2, 21);
            cout << "■■■";
            Pos(2, 22);
            cout << "■■■";
            Pos(2, 23);
            cout << "■■■";
            color_set(2, 4);
            Pos(10, 21);
            cout << "■■■";
            Pos(10, 22);
            cout << "■■■";
            Pos(10, 23);
            cout << "■■■";
            color_set(2, 5);
            Pos(18, 21);
            cout << "■■■";
            Pos(18, 22);
            cout << "■■■";
            Pos(18, 23);
            cout << "■■■";
            color_set(2, 6);
            Pos(2, 25);
            cout << "■■■";
            Pos(2, 26);
            cout << "■■■";
            Pos(2, 27);
            cout << "■■■";
            color_set(2, 7);
            Pos(10, 25);
            cout << "■■■";
            Pos(10, 26);
            cout << "■■■";
            Pos(10, 27);
            cout << "■■■";
            color_set(2, 8);
            Pos(18, 25);
            cout << "■■■";
            Pos(18, 26);
            cout << "■■■";
            Pos(18, 27);
            cout << "■■■";

            color_set(4, 0);
            Pos(27, 17);
            cout << "■■■";
            Pos(27, 18);
            cout << "■■■";
            Pos(27, 19);
            cout << "■■■";
            color_set(4, 1);
            Pos(35, 17);
            cout << "■■■";
            Pos(35, 18);
            cout << "■■■";
            Pos(35, 19);
            cout << "■■■";
            color_set(4, 2);
            Pos(43, 17);
            cout << "■■■";
            Pos(43, 18);
            cout << "■■■";
            Pos(43, 19);
            cout << "■■■";
            color_set(4, 3);
            Pos(27, 21);
            cout << "■■■";
            Pos(27, 22);
            cout << "■■■";
            Pos(27, 23);
            cout << "■■■";
            color_set(4, 4);
            Pos(35, 21);
            cout << "■■■";
            Pos(35, 22);
            cout << "■■■";
            Pos(35, 23);
            cout << "■■■";
            color_set(4, 5);
            Pos(43, 21);
            cout << "■■■";
            Pos(43, 22);
            cout << "■■■";
            Pos(43, 23);
            cout << "■■■";
            color_set(4, 6);
            Pos(27, 25);
            cout << "■■■";
            Pos(27, 26);
            cout << "■■■";
            Pos(27, 27);
            cout << "■■■";
            color_set(4, 7);
            Pos(35, 25);
            cout << "■■■";
            Pos(35, 26);
            cout << "■■■";
            Pos(35, 27);
            cout << "■■■";
            color_set(4, 8);
            Pos(43, 25);
            cout << "■■■";
            Pos(43, 26);
            cout << "■■■";
            Pos(43, 27);
            cout << "■■■";
        }
        Pos(0, 29);
    }
    system("color 70");
}

void arrowsU(int x, int y, char size)
{
    if (size == 'S')
    {
        if (x <= 3)
            x = x * 6 - 4;
        else
            x = x * 6 - 3;
        if (y == 1)
            y = 4;
        else
            y = 14;
        Pos(x, y);
        cout << "╱ ╲";
        Pos(x, y + 1);
        cout << "│ │";
        Pos(x, y + 2);
        cout << "┼ ┼";
        Pos(x, y + 3);
        cout << "│ │";
        Pos(x, y + 4);
        cout << "│ │";
        Pos(x, y + 5);
        cout << "┼ ┼";
        Pos(x, y + 6);
        cout << "│ │";
        Pos(x, y + 7);
        cout << "│ │";
        Pos(0, 23);
    }
    else
    {
        if (x <= 3)
            x = x * 8 - 4;
        else
            x = x * 8 - 3;
        if (y == 1)
            y = 4;
        else
            y = 17;
        Pos(x, y);
        cout << "┼";
        Pos(x, y + 1);
        cout << "│";
        Pos(x, y + 2);
        cout << "│";
        Pos(x, y + 3);
        cout << "┼";
        Pos(x, y + 4);
        cout << "│";
        Pos(x, y + 5);
        cout << "│";
        Pos(x, y + 6);
        cout << "│";
        Pos(x, y + 7);
        cout << "┼";
        Pos(x, y + 8);
        cout << "│";
        Pos(x, y + 9);
        cout << "│";
        Pos(x, y + 10);
        cout << "│";
        Pos(0, 29);
    }
}
void arrowsD(int x, int y, char size)
{
    if (size == 'S')
    {
        if (x <= 3)
            x = x * 6 - 4;
        else
            x = x * 6 - 3;
        if (y == 1)
            y = 4;
        else
            y = 14;
        Pos(x, y);
        cout << "│ │";
        Pos(x, y + 1);
        cout << "│ │";
        Pos(x, y + 2);
        cout << "┼ ┼";
        Pos(x, y + 3);
        cout << "│ │";
        Pos(x, y + 4);
        cout << "│ │";
        Pos(x, y + 5);
        cout << "┼ ┼";
        Pos(x, y + 6);
        cout << "│ │";
        Pos(x, y + 7);
        cout << "╲ ╱";
        Pos(0, 23);
    }
    else
    {
        if (x <= 3)
            x = x * 8 - 4;
        else
            x = x * 8 - 3;
        if (y == 1)
            y = 4;
        else
            y = 17;
        Pos(x, y);
        cout << "│";
        Pos(x, y + 1);
        cout << "│";
        Pos(x, y + 2);
        cout << "│";
        Pos(x, y + 3);
        cout << "┼";
        Pos(x, y + 4);
        cout << "│";
        Pos(x, y + 5);
        cout << "│";
        Pos(x, y + 6);
        cout << "│";
        Pos(x, y + 7);
        cout << "┼";
        Pos(x, y + 8);
        cout << "│";
        Pos(x, y + 9);
        cout << "│";
        Pos(x, y + 10);
        cout << "┼";
        Pos(0, 29);
    }
}
void arrowsR(int x, int y, char size)
{
    if (size == 'S')
    {
        if (x == 1)
            x = 2;
        else
            x = 21;
        if (y <= 3)
            y = y * 3 + 1;
        else
            y = y * 3 + 2;
        Pos(x, y);
        cout << "─ ─ ┼ ─ ─ ┼ ─ ╲";
        Pos(x, y + 1);
        cout << "─ ─ ┼ ─ ─ ┼ ─ ╱";
        Pos(0, 23);
    }
    else
    {
        if (x == 1)
            x = 2;
        else
            x = 27;
        if (y <= 3)
            y = y * 4 + 1;
        else
            y = y * 4 + 2;
        Pos(x, y);
        cout << "─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ┼";
        Pos(0, 29);
    }
}
void arrowsL(int x, int y, char size)
{
    if (size == 'S')
    {
        if (x == 1)
            x = 2;
        else
            x = 21;
        if (y <= 3)
            y = y * 3 + 1;
        else
            y = y * 3 + 2;
        Pos(x, y);
        cout << "╱ ─ ┼ ─ ─ ┼ ─ ─";
        Pos(x, y + 1);
        cout << "╲ ─ ┼ ─ ─ ┼ ─ ─";
        Pos(0, 23);
    }
    else
    {
        if (x == 1)
            x = 2;
        else
            x = 27;
        if (y <= 3)
            y = y * 4 + 1;
        else
            y = y * 4 + 2;
        Pos(x, y);
        cout << "┼ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─";
        Pos(0, 29);
    }
}
void demo_step(string step, char size)
{
    if (step == "U")
    {
        arrowsL(1, 4, size);
        arrowsL(2, 4, size);
    }
    else if (step == "U'")
    {
        arrowsR(1, 4, size);
        arrowsR(2, 4, size);
    }
    else if (step == "R")
    {
        arrowsU(3, 1, size);
        arrowsU(3, 2, size);
    }
    else if (step == "R'")
    {
        arrowsD(3, 1, size);
        arrowsD(3, 2, size);
    }
    else if (step == "F")
    {
        arrowsR(1, 3, size);
        arrowsD(4, 2, size);
    }
    else if (step == "F'")
    {
        arrowsL(1, 3, size);
        arrowsU(4, 2, size);
    }
    else if (step == "D")
    {
        arrowsR(1, 6, size);
        arrowsR(2, 6, size);
    }
    else if (step == "D'")
    {
        arrowsL(1, 6, size);
        arrowsL(2, 6, size);
    }
    else if (step == "L")
    {
        arrowsD(1, 1, size);
        arrowsD(1, 2, size);
    }
    else if (step == "L'")
    {
        arrowsU(1, 1, size);
        arrowsU(1, 2, size);
    }
    else if (step == "B")
    {
        arrowsL(1, 1, size);
        arrowsU(6, 2, size);
    }
    else if (step == "B'")
    {
        arrowsR(1, 1, size);
        arrowsD(6, 2, size);
    }
    else if (step == "u")
    {
        arrowsL(1, 4, size);
        arrowsL(2, 4, size);
        arrowsL(1, 5, size);
        arrowsL(2, 5, size);
    }
    else if (step == "u'")
    {
        arrowsR(1, 4, size);
        arrowsR(2, 4, size);
        arrowsR(1, 5, size);
        arrowsR(2, 5, size);
    }
    else if (step == "r")
    {
        arrowsU(3, 1, size);
        arrowsU(3, 2, size);
        arrowsU(2, 1, size);
        arrowsU(2, 2, size);
    }
    else if (step == "r'")
    {
        arrowsD(3, 1, size);
        arrowsD(3, 2, size);
        arrowsD(2, 1, size);
        arrowsD(2, 2, size);
    }
    else if (step == "f")
    {
        arrowsR(1, 3, size);
        arrowsD(4, 2, size);
        arrowsR(1, 2, size);
        arrowsD(5, 2, size);
    }
    else if (step == "f'")
    {
        arrowsL(1, 3, size);
        arrowsU(4, 2, size);
        arrowsL(1, 2, size);
        arrowsU(5, 2, size);
    }
    else if (step == "d")
    {
        arrowsR(1, 6, size);
        arrowsR(2, 6, size);
        arrowsR(1, 5, size);
        arrowsR(2, 5, size);
    }
    else if (step == "d'")
    {
        arrowsL(1, 6, size);
        arrowsL(2, 6, size);
        arrowsL(1, 5, size);
        arrowsL(2, 5, size);
    }
    else if (step == "l")
    {
        arrowsD(1, 1, size);
        arrowsD(1, 2, size);
        arrowsD(2, 1, size);
        arrowsD(2, 2, size);
    }
    else if (step == "l'")
    {
        arrowsU(1, 1, size);
        arrowsU(1, 2, size);
        arrowsU(2, 1, size);
        arrowsU(2, 2, size);
    }
    else if (step == "b")
    {
        arrowsL(1, 1, size);
        arrowsU(6, 2, size);
        arrowsL(1, 2, size);
        arrowsU(5, 2, size);
    }
    else if (step == "b'")
    {
        arrowsR(1, 1, size);
        arrowsD(6, 2, size);
        arrowsR(1, 2, size);
        arrowsD(5, 2, size);
    }
    else if (step == "E")
    {
        arrowsR(1, 5, size);
        arrowsR(2, 5, size);
    }
    else if (step == "E'")
    {
        arrowsL(1, 5, size);
        arrowsL(2, 5, size);
    }
    else if (step == "M")
    {
        arrowsD(2, 1, size);
        arrowsD(2, 2, size);
    }
    else if (step == "M'")
    {
        arrowsU(2, 1, size);
        arrowsU(2, 2, size);
    }
    else if (step == "S")
    {
        arrowsR(1, 2, size);
        arrowsD(5, 2, size);
    }
    else if (step == "S'")
    {
        arrowsL(1, 2, size);
        arrowsU(5, 2, size);
    }
    else if (step == "X" || step == "x")
    {
        arrowsU(1, 1, size);
        arrowsU(1, 2, size);
        arrowsU(2, 1, size);
        arrowsU(2, 2, size);
        arrowsU(3, 1, size);
        arrowsU(3, 2, size);
    }
    else if (step == "X'" || step == "x'")
    {
        arrowsD(1, 1, size);
        arrowsD(1, 2, size);
        arrowsD(2, 1, size);
        arrowsD(2, 2, size);
        arrowsD(3, 1, size);
        arrowsD(3, 2, size);
    }
    else if (step == "Y" || step == "y")
    {
        arrowsL(1, 4, size);
        arrowsL(2, 4, size);
        arrowsL(1, 5, size);
        arrowsL(2, 5, size);
        arrowsL(1, 6, size);
        arrowsL(2, 6, size);
    }
    else if (step == "Y'" || step == "y'")
    {
        arrowsR(1, 4, size);
        arrowsR(2, 4, size);
        arrowsR(1, 5, size);
        arrowsR(2, 5, size);
        arrowsR(1, 6, size);
        arrowsR(2, 6, size);
    }
    else if (step == "Z" || step == "z")
    {
        arrowsR(1, 3, size);
        arrowsD(4, 2, size);
        arrowsR(1, 2, size);
        arrowsD(5, 2, size);
        arrowsR(1, 1, size);
        arrowsD(6, 2, size);
    }
    else if (step == "Z'" || step == "z'")
    {
        arrowsL(1, 3, size);
        arrowsU(4, 2, size);
        arrowsL(1, 2, size);
        arrowsU(5, 2, size);
        arrowsL(1, 1, size);
        arrowsU(6, 2, size);
    }
    else
    {
        cout << "不存在的" << endl;
    }
}

void color_set(int i, int j)
{
    int color = zbs.face[i][j];
    switch (color)
    {
    case 0:
        system("color 7f");
        break;
    case 1:
        system("color 76");
        break;
    case 2:
        system("color 71");
        break;
    case 3:
        system("color 72");
        break;
    case 4:
        system("color 74");
        break;
    case 5:
        system("color 7c");
        break;
    default:
        break;
    }
}

void CFOP()
{
    string str;
    ofstream CFOP;
    CFOP.open("lib\\CFOP", ios::out);
    CFOP << "#所有公式来源于魔方小站" << endl;

    CFOP << "#F2L公式" << endl;
    str = "(R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L1-1\t" << str << endl;
    str = "y’ (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L1-2\t" << str << endl;
    str = "y’ U’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L1-3\t" << str << endl;
    str = "U R U’ R’";
    zbs.formula_examine(str);
    CFOP << "F2L1-4\t" << str << endl;
    str = "U’ (R U R’ U) (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L2-1\t" << str << endl;
    str = "d (R’ U2 R) d’ (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L2-2\t" << str << endl;
    str = "U’ (R U’ R’ U) (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L2-3\t" << str << endl;
    str = "U y’ (R’ U’ R U’) (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L2-4\t" << str << endl;
    str = "U’ (R U2’ R’) d (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L2-5\t" << str << endl;
    str = "d (R’ U R U’) (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L2-6\t" << str << endl;
    str = "U’ (R U2’ R’) U2 (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L3-1\t" << str << endl;
    str = "(U’ R U R’) U2 (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L3-2\t" << str << endl;
    str = "d (R’ U2 R) U2’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L3-3\t" << str << endl;
    str = "d (R’ U’ R) U2’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L3-4\t" << str << endl;
    str = "y’ U’ (R’ U2 R) U’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L4-1\t" << str << endl;
    str = "U R U2 R2’ (F R F’)";
    zbs.formula_examine(str);
    CFOP << "F2L4-2\t" << str << endl;
    str = "U2 (R U R’ U) (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L4-3\t" << str << endl;
    str = "y’ U2 (R’ U’ R U’) (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L4-4\t" << str << endl;
    str = "U (R U’ R’) U’ (F’ U F)";
    zbs.formula_examine(str);
    CFOP << "F2L5-1\t" << str << endl;
    str = "U’ (F’ U F) U (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L5-2\t" << str << endl;
    str = "d (R’ U’ R) d’ (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L6-1\t" << str << endl;
    str = "U’ (R U R’) d (R’U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L6-2\t" << str << endl;
    str = "U’ (R U2’ R’) U (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L6-3\t" << str << endl;
    str = "(U’ R U’ R’) U2 (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L6-4\t" << str << endl;
    str = "(R U2’ R’) U’ (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L7-1\t" << str << endl;
    str = "y’ (R’ U2 R) U (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L7-2\t" << str << endl;
    str = "(R U’ R’ U) d (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L8-1\t" << str << endl;
    str = "y’ (R’ U R U’) d’ (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L8-2\t" << str << endl;
    str = "(R U’ R’) d (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L9-1\t" << str << endl;
    str = "(R U R’ U’)2 (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L9-2\t" << str << endl;
    str = "(R U’ R’ U) (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L10-1\t" << str << endl;
    str = "y’ (R’ U R) U’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L10-2\t" << str << endl;
    str = "(R U R’U’) (R U R’)";
    zbs.formula_examine(str);
    CFOP << "F2L10-3\t" << str << endl;
    str = "y L’ U’ L U L’ U’ L";
    zbs.formula_examine(str);
    CFOP << "F2L10-4\t" << str << endl;
    str = "(R U R’) d (R’ U R U’) (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L11-1\t" << str << endl;
    str = "U2 R2 U2 (R’ U’ R U’) R2";
    zbs.formula_examine(str);
    CFOP << "F2L11-2\t" << str << endl;
    str = "(R U’ R’ U) (R U2’ R’) U (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L12-1\t" << str << endl;
    str = "(R U’ R’ U) d (R’ U’ R U’) (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "F2L12-2\t" << str << endl;
    str = "(R U’ R’) U’ (R U R’) U2 (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "F2L12-3\t" << str << endl;
    str = "(R U’ R’ U’) (R U’ R’) U (F’ U’ F)";
    zbs.formula_examine(str);
    CFOP << "F2L12-4\t" << str << endl;
    str = "(R U’ U’ R’ U)2 y’ (R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "F2L12-5\t" << str << endl;

    CFOP << "#OLL公式" << endl;
    str = "R’ U2 R U R’ U R";
    zbs.formula_examine(str);
    CFOP << "OLL1-1\t" << str << endl;
    str = "R U’ U’ R’ U’ R U’ R’";
    zbs.formula_examine(str);
    CFOP << "OLL1-2\t" << str << endl;
    str = "(r U R’ U’) (r’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL1-3\t" << str << endl;
    str = "F’ (r U R’ U’) (r’ F R)";
    zbs.formula_examine(str);
    CFOP << "OLL1-4\t" << str << endl;
    str = "(R2 D’) (R U’ U’) (R’ D) (R U’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "OLL1-5\t" << str << endl;
    str = "(R U U R’ U’) (R U R’ U’) (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL1-6\t" << str << endl;
    str = "R U’ U’ (R2’ U’) (R2 U’) R2’ U2 R";
    zbs.formula_examine(str);
    CFOP << "OLL1-7\t" << str << endl;
    str = "F (R U R’ U’) F’";
    zbs.formula_examine(str);
    CFOP << "OLL2-1\t" << str << endl;
    str = "f (R U R’ U’) f’";
    zbs.formula_examine(str);
    CFOP << "OLL2-2\t" << str << endl;
    str = "B’ U’ (R’ U R B)";
    zbs.formula_examine(str);
    CFOP << "OLL2-3\t" << str << endl;
    str = "(R U R’ U’) (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL2-4\t" << str << endl;
    str = "F (RU R’ U’)2 F’";
    zbs.formula_examine(str);
    CFOP << "OLL2-5\t" << str << endl;
    str = "F’ (L’ U’ L U)2 F";
    zbs.formula_examine(str);
    CFOP << "OLL2-6\t" << str << endl;
    str = "(RU R’ U’)2 f’";
    zbs.formula_examine(str);
    CFOP << "OLL2-7\t" << str << endl;
    str = "(F R U R’ U’ F’) (f R U R’ U’ f’)";
    zbs.formula_examine(str);
    CFOP << "OLL3-1\t" << str << endl;
    str = "(f R U R’ U’ f’) U’ (F R U R’ U’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL3-2\t" << str << endl;
    str = "(f R U R’ U’ f’) U (F R U R’ U’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL3-3\t" << str << endl;
    str = "(R U’ U’) (R2’ F R F’) U2 (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL3-4\t" << str << endl;
    str = "(r’ U2) (R U R’ U) r";
    zbs.formula_examine(str);
    CFOP << "OLL3-5\t" << str << endl;
    str = "(r U’ U’) (R’ U’ R U’ r’)";
    zbs.formula_examine(str);
    CFOP << "OLL3-6\t" << str << endl;
    str = "r U R’ U R U U r’";
    zbs.formula_examine(str);
    CFOP << "OLL3-7\t" << str << endl;
    str = "r’ U’ R U’ R’ U2 r";
    zbs.formula_examine(str);
    CFOP << "OLL3-8\t" << str << endl;
    str = "F (R U’ R’ U’) (R U R’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL4-1\t" << str << endl;
    str = "R U’ U’ (R2’ F R F’)(R U’ U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL4-2\t" << str << endl;
    str = "(R B’) (R2 F) (R2 B) (R2 F’) R";
    zbs.formula_examine(str);
    CFOP << "OLL4-3\t" << str << endl;
    str = "(R’ F) (R2 B’) (R2 F’) (R2 B) R’";
    zbs.formula_examine(str);
    CFOP << "OLL4-4\t" << str << endl;
    str = "r’ U2 (R U R’ U’) (R U R’ U) r";
    zbs.formula_examine(str);
    CFOP << "OLL4-5\t" << str << endl;
    str = "r U (R’ UR U’)2 U’ r’";
    zbs.formula_examine(str);
    CFOP << "OLL4-6\t" << str << endl;
    str = "(R U R’ U) (R’ F R F’) U2 (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL4-7\t" << str << endl;
    str = "F (R U R’ U) y’ (R’ U2) (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL4-8\t" << str << endl;
    str = "(M  U) (R U R’ U’) M’ (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL4-9\t" << str << endl;
    str = "(R U R’ U’) (R’ F) (R2U R’ U’) F’";
    zbs.formula_examine(str);
    CFOP << "OLL5-1\t" << str << endl;
    str = "(R U R’ U) (R’ F R F’) (R U’ U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL5-2\t" << str << endl;
    str = "(r U R’ U’) (r’ R) (U R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL5-3\t" << str << endl;
    str = "(R U R’ U’) r R’ (U R U’ r’)";
    zbs.formula_examine(str);
    CFOP << "OLL5-4\t" << str << endl;
    str = "(R’ U’) (R’ F R F’) (U R)";
    zbs.formula_examine(str);
    CFOP << "OLL5-5\t" << str << endl;
    str = "(R U R’ U’) x D’ (R’ U R) E’";
    zbs.formula_examine(str);
    CFOP << "OLL5-6\t" << str << endl;
    str = "(R U R’ U) (R U’ R’ U’) (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "OLL5-7\t" << str << endl;
    str = "(R’ U’ R U’) (R’ U R U) (l U’ R’ U)";
    zbs.formula_examine(str);
    CFOP << "OLL5-8\t" << str << endl;
    str = "(F R U R’ U’ F’) U (F R U R’ U’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL5-9\t" << str << endl;
    str = "(r U R’ U) (R’ F R F’) R U2 r’";
    zbs.formula_examine(str);
    CFOP << "OLL5-10\t" << str << endl;
    str = "(R U) (B’ U’) (R’URB R’)";
    zbs.formula_examine(str);
    CFOP << "OLL6-1\t" << str << endl;
    str = "(R’ U’ F) (U R U’) (R’ F’ R)";
    zbs.formula_examine(str);
    CFOP << "OLL6-2\t" << str << endl;
    str = "R’ F (R U R’ U’) F’ (U R)";
    zbs.formula_examine(str);
    CFOP << "OLL6-3\t" << str << endl;
    str = "L F’ (L’ U’ L U) F (U’ L’)";
    zbs.formula_examine(str);
    CFOP << "OLL6-4\t" << str << endl;
    str = "(R U R’ U R U2 R’) (F R U R’ U’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL6-5\t" << str << endl;
    str = "(R’ U’ R U’ R’ U2 R) (F R U R’ U’ F’)";
    zbs.formula_examine(str);
    CFOP << "OLL6-6\t" << str << endl;
    str = "(r’ U2 R U R’ U r) (R U2 R’ U’ R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL6-7\t" << str << endl;
    str = "(r U2 R’ U’ R U’ r’) (R’ U2 R U R’ U R)";
    zbs.formula_examine(str);
    CFOP << "OLL6-8\t" << str << endl;
    str = "(r U r’) (R U R’ U’) (r U’ r’)";
    zbs.formula_examine(str);
    CFOP << "OLL7-1\t" << str << endl;
    str = "(l’ U’ l) (L’ U’ L U) (l’ U l)";
    zbs.formula_examine(str);
    CFOP << "OLL7-2\t" << str << endl;
    str = "R’ F (R U R’ F’ R) y’ (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL7-3\t" << str << endl;
    str = "F (U R U’) (R2’ F’) (R U R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "OLL7-4\t" << str << endl;
    str = "(R’ U’ R U’) (R’ U) y’ (R’ U R B)";
    zbs.formula_examine(str);
    CFOP << "OLL7-5\t" << str << endl;
    str = "(r U r’) (UR U’ R’)2 (r U’ r’)";
    zbs.formula_examine(str);
    CFOP << "OLL7-6\t" << str << endl;
    str = "R’ F (U R U’) (R2’ F’) (R2 U R’ U’ R)";
    zbs.formula_examine(str);
    CFOP << "OLL7-7\t" << str << endl;
    str = "(r’ R U) (R U R’ U’) (r2 R2’) (U R U’ r’)";
    zbs.formula_examine(str);
    CFOP << "OLL7-8\t" << str << endl;

    CFOP << "#PLL公式" << endl;
    str = "(R U’ R) U (R U R U’) (R’ U’ R2)";
    zbs.formula_examine(str);
    CFOP << "PLL1-1\t" << str << endl;
    str = "(R2’ U) (R U R’ U’) (R’ U’) (R’ U R’)";
    zbs.formula_examine(str);
    CFOP << "PLL1-2\t" << str << endl;
    str = "M2 U M2 U2 M2 U M2";
    zbs.formula_examine(str);
    CFOP << "PLL1-3\t" << str << endl;
    str = "(M2 U M2 U) (M U2) (M2 U2) (M U2)";
    zbs.formula_examine(str);
    CFOP << "PLL1-4\t" << str << endl;
    str = "x’ R2 D2 (R’ U’ R) D2 (R’ U R’) x";
    zbs.formula_examine(str);
    CFOP << "PLL1-5\t" << str << endl;
    str = "x’ (R U’ R) D2 (R’ U R) D2 R2 x";
    zbs.formula_examine(str);
    CFOP << "PLL1-6\t" << str << endl;
    str = "(R2 U R’ U’) y (R U R’ U’)2 (R U R’) y’ (R U’ R2)";
    zbs.formula_examine(str);
    CFOP << "PLL1-7\t" << str << endl;
    str = "(R U R’ U’) (R’ F R2 U’ R’ U’) (R U R’ F’)";
    zbs.formula_examine(str);
    CFOP << "PLL2-1\t" << str << endl;
    str = "(R U R’ F’) (R U R’ U’) (R’ F R2 U’ R’ U’)";
    zbs.formula_examine(str);
    CFOP << "PLL2-2\t" << str << endl;
    str = "z (U’ R D’) (R2 U R’ U’) (R2 U) D R’";
    zbs.formula_examine(str);
    CFOP << "PLL2-3\t" << str << endl;
    str = "F (R U’ R’ U’) (R U R’ F’) (R U R’ U’) (R’ F R F’)";
    zbs.formula_examine(str);
    CFOP << "PLL2-4\t" << str << endl;
    str = "U’ (R’ U R U’) R2’ b’ x (R’ U R) y’ (R U R’ U’ R2)";
    zbs.formula_examine(str);
    CFOP << "PLL2-5\t" << str << endl;
    str = "(R’ U R’ d’) (R’ F’) (R2 U’ R’ U) (R’ F R F)";
    zbs.formula_examine(str);
    CFOP << "PLL2-6\t" << str << endl;
    str = "(R U’ U’) (R’ U2) (R B’ R’ U’) (R U R B) R2’ U";
    zbs.formula_examine(str);
    CFOP << "PLL2-7\t" << str << endl;
    str = "(R’ U2) (R U’ U’) (R’ F R U R’ U’) (R’ F’ R2 U’)";
    zbs.formula_examine(str);
    CFOP << "PLL2-8\t" << str << endl;
    str = "z (R’ U R’) z’ (R U2 L’ U R’) z (U R’) z’ (R U2 L’ U R’)";
    zbs.formula_examine(str);
    CFOP << "PLL3-1\t" << str << endl;
    str = "z (U’ R D’) (R2 U R’ U’) z’ (R U R’) z (R2 U R’) D R’";
    zbs.formula_examine(str);
    CFOP << "PLL3-2\t" << str << endl;
    str = "(R2’ u’) (R U’ R) U (R’ u R2’) y (R U’ R’)";
    zbs.formula_examine(str);
    CFOP << "PLL3-3\t" << str << endl;
    str = "(R U R’) y’ (R2’ u’) (R U’ R’ U) (R’ u R2)";
    zbs.formula_examine(str);
    CFOP << "PLL3-4\t" << str << endl;
    str = "(R2’ u R’) (U R’ U’) (R u’ R2’) y’ (R’ U R)";
    zbs.formula_examine(str);
    CFOP << "PLL3-5\t" << str << endl;
    str = "(R’ d’ F) (R2’ u R’) U (R U’ R) u’ R2";
    zbs.formula_examine(str);
    CFOP << "PLL3-6\t" << str << endl;
}