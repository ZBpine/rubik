#include <iostream>
#include "cube.h"

using namespace std;

Cube::Cube()
{
    centers[0] = 0;
    centers[1] = 1;
    centers[2] = 2;
    centers[3] = 3;
    centers[4] = 4;
    centers[5] = 5;
    edges[0][0] = 0;
    edges[0][1] = 2;
    edges[1][0] = 0;
    edges[1][1] = 4;
    edges[2][0] = 0;
    edges[2][1] = 3;
    edges[3][0] = 0;
    edges[3][1] = 5;
    edges[4][0] = 2;
    edges[4][1] = 4;
    edges[5][0] = 4;
    edges[5][1] = 3;
    edges[6][0] = 3;
    edges[6][1] = 5;
    edges[7][0] = 5;
    edges[7][1] = 2;
    edges[8][0] = 1;
    edges[8][1] = 2;
    edges[9][0] = 1;
    edges[9][1] = 4;
    edges[10][0] = 1;
    edges[10][1] = 3;
    edges[11][0] = 1;
    edges[11][1] = 5;
    corners[0][0] = 0;
    corners[0][1] = 2;
    corners[0][2] = 4;
    corners[1][0] = 0;
    corners[1][1] = 4;
    corners[1][2] = 3;
    corners[2][0] = 0;
    corners[2][1] = 3;
    corners[2][2] = 5;
    corners[3][0] = 0;
    corners[3][1] = 5;
    corners[3][2] = 2;
    corners[4][0] = 1;
    corners[4][1] = 4;
    corners[4][2] = 2;
    corners[5][0] = 1;
    corners[5][1] = 3;
    corners[5][2] = 4;
    corners[6][0] = 1;
    corners[6][1] = 5;
    corners[6][2] = 3;
    corners[7][0] = 1;
    corners[7][1] = 2;
    corners[7][2] = 5;
    face_sync();
}
void Cube::face_sync()
{
    face[0][0] = corners[3][0];
    face[0][1] = edges[0][0];
    face[0][2] = corners[0][0];
    face[0][3] = edges[3][0];
    face[0][4] = centers[0];
    face[0][5] = edges[1][0];
    face[0][6] = corners[2][0];
    face[0][7] = edges[2][0];
    face[0][8] = corners[1][0];
    face[1][0] = corners[6][0];
    face[1][1] = edges[10][0];
    face[1][2] = corners[5][0];
    face[1][3] = edges[11][0];
    face[1][4] = centers[1];
    face[1][5] = edges[9][0];
    face[1][6] = corners[7][0];
    face[1][7] = edges[8][0];
    face[1][8] = corners[4][0];
    face[2][0] = corners[7][1];
    face[2][1] = edges[8][1];
    face[2][2] = corners[4][2];
    face[2][3] = edges[7][1];
    face[2][4] = centers[2];
    face[2][5] = edges[4][0];
    face[2][6] = corners[3][2];
    face[2][7] = edges[0][1];
    face[2][8] = corners[0][1];
    face[3][0] = corners[2][1];
    face[3][1] = edges[2][1];
    face[3][2] = corners[2][2];
    face[3][3] = edges[6][0];
    face[3][4] = centers[3];
    face[3][5] = edges[5][1];
    face[3][6] = corners[6][2];
    face[3][7] = edges[10][1];
    face[3][8] = corners[5][1];
    face[4][0] = corners[4][1];
    face[4][1] = edges[9][1];
    face[4][2] = corners[5][2];
    face[4][3] = edges[4][1];
    face[4][4] = centers[4];
    face[4][5] = edges[5][0];
    face[4][6] = corners[0][2];
    face[4][7] = edges[1][1];
    face[4][8] = corners[1][1];
    face[5][0] = corners[6][1];
    face[5][1] = edges[11][1];
    face[5][2] = corners[7][2];
    face[5][3] = edges[6][1];
    face[5][4] = centers[5];
    face[5][5] = edges[7][0];
    face[5][6] = corners[2][2];
    face[5][7] = edges[3][1];
    face[5][8] = corners[3][1];
}
void Cube::U()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[8][0];
    temp2 = edges[8][1];
    edges[8][0] = edges[9][0];
    edges[8][1] = edges[9][1];
    edges[9][0] = edges[10][0];
    edges[9][1] = edges[10][1];
    edges[10][0] = edges[11][0];
    edges[10][1] = edges[11][1];
    edges[11][0] = temp1;
    edges[11][1] = temp2;
    temp3 = corners[4][0];
    temp4 = corners[4][1];
    temp5 = corners[4][2];
    corners[4][0] = corners[5][0];
    corners[4][1] = corners[5][1];
    corners[4][2] = corners[5][2];
    corners[5][0] = corners[6][0];
    corners[5][1] = corners[6][1];
    corners[5][2] = corners[6][2];
    corners[6][0] = corners[7][0];
    corners[6][1] = corners[7][1];
    corners[6][2] = corners[7][2];
    corners[7][0] = temp3;
    corners[7][1] = temp4;
    corners[7][2] = temp5;
}
void Cube::R()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[4][0];
    temp2 = edges[4][1];
    edges[4][0] = edges[1][0];
    edges[4][1] = edges[1][1];
    edges[1][0] = edges[5][1];
    edges[1][1] = edges[5][0];
    edges[5][0] = edges[9][1];
    edges[5][1] = edges[9][0];
    edges[9][0] = temp1;
    edges[9][1] = temp2;
    temp3 = corners[0][0];
    temp4 = corners[0][1];
    temp5 = corners[0][2];
    corners[0][0] = corners[1][2];
    corners[0][1] = corners[1][0];
    corners[0][2] = corners[1][1];
    corners[1][0] = corners[5][1];
    corners[1][1] = corners[5][2];
    corners[1][2] = corners[5][0];
    corners[5][0] = corners[4][2];
    corners[5][1] = corners[4][0];
    corners[5][2] = corners[4][1];
    corners[4][0] = temp4;
    corners[4][1] = temp5;
    corners[4][2] = temp3;
}
void Cube::F()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[4][0];
    temp2 = edges[4][1];
    edges[4][0] = edges[8][1];
    edges[4][1] = edges[8][0];
    edges[8][0] = edges[7][0];
    edges[8][1] = edges[7][1];
    edges[7][0] = edges[0][0];
    edges[7][1] = edges[0][1];
    edges[0][0] = temp2;
    edges[0][1] = temp1;
    temp3 = corners[0][0];
    temp4 = corners[0][1];
    temp5 = corners[0][2];
    corners[0][0] = corners[4][1];
    corners[0][1] = corners[4][2];
    corners[0][2] = corners[4][0];
    corners[4][0] = corners[7][2];
    corners[4][1] = corners[7][0];
    corners[4][2] = corners[7][1];
    corners[7][0] = corners[3][1];
    corners[7][1] = corners[3][2];
    corners[7][2] = corners[3][0];
    corners[3][0] = temp5;
    corners[3][1] = temp3;
    corners[3][2] = temp4;
}
void Cube::D()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[0][0];
    temp2 = edges[0][1];
    edges[0][0] = edges[3][0];
    edges[0][1] = edges[3][1];
    edges[3][0] = edges[2][0];
    edges[3][1] = edges[2][1];
    edges[2][0] = edges[1][0];
    edges[2][1] = edges[1][1];
    edges[1][0] = temp1;
    edges[1][1] = temp2;
    temp3 = corners[0][0];
    temp4 = corners[0][1];
    temp5 = corners[0][2];
    corners[0][0] = corners[3][0];
    corners[0][1] = corners[3][1];
    corners[0][2] = corners[3][2];
    corners[3][0] = corners[2][0];
    corners[3][1] = corners[2][1];
    corners[3][2] = corners[2][2];
    corners[2][0] = corners[1][0];
    corners[2][1] = corners[1][1];
    corners[2][2] = corners[1][2];
    corners[1][0] = temp3;
    corners[1][1] = temp4;
    corners[1][2] = temp5;
}
void Cube::L()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[6][0];
    temp2 = edges[6][1];
    edges[6][0] = edges[3][0];
    edges[6][1] = edges[3][1];
    edges[3][0] = edges[7][1];
    edges[3][1] = edges[7][0];
    edges[7][0] = edges[11][1];
    edges[7][1] = edges[11][0];
    edges[6][0] = temp1;
    edges[6][1] = temp2;
    temp3 = corners[2][0];
    temp4 = corners[2][1];
    temp5 = corners[2][2];
    corners[2][0] = corners[3][2];
    corners[2][1] = corners[3][0];
    corners[2][2] = corners[3][1];
    corners[3][0] = corners[7][1];
    corners[3][1] = corners[7][2];
    corners[3][2] = corners[7][0];
    corners[7][0] = corners[6][2];
    corners[7][1] = corners[6][0];
    corners[7][2] = corners[6][1];
    corners[6][0] = temp4;
    corners[6][1] = temp5;
    corners[6][2] = temp3;
}
void Cube::B()
{
    int temp1, temp2, temp3, temp4, temp5;
    temp1 = edges[6][0];
    temp2 = edges[6][1];
    edges[6][0] = edges[10][1];
    edges[6][1] = edges[10][0];
    edges[10][0] = edges[5][0];
    edges[10][1] = edges[5][1];
    edges[5][0] = edges[2][0];
    edges[5][1] = edges[2][1];
    edges[2][0] = temp2;
    edges[2][1] = temp1;
    temp3 = corners[2][0];
    temp4 = corners[2][1];
    temp5 = corners[2][2];
    corners[2][0] = corners[6][1];
    corners[2][1] = corners[6][2];
    corners[2][2] = corners[6][0];
    corners[6][0] = corners[5][2];
    corners[6][1] = corners[5][0];
    corners[6][2] = corners[5][1];
    corners[5][0] = corners[1][1];
    corners[5][1] = corners[1][2];
    corners[5][2] = corners[1][0];
    corners[1][0] = temp5;
    corners[1][1] = temp3;
    corners[1][2] = temp4;
}
void Cube::Mh()
{
    int temp1, temp2, temp3;
    temp1 = centers[2];
    centers[2] = centers[4];
    centers[4] = centers[3];
    centers[3] = centers[5];
    centers[5] = temp1;
    temp2 = edges[4][0];
    temp3 = edges[4][1];
    edges[4][0] = edges[5][0];
    edges[4][1] = edges[5][1];
    edges[5][0] = edges[6][0];
    edges[5][1] = edges[6][1];
    edges[6][0] = edges[7][0];
    edges[6][1] = edges[7][1];
    edges[7][0] = temp2;
    edges[7][1] = temp3;
}
void Cube::Mw()
{
    int temp1, temp2, temp3;
    temp1 = centers[0];
    centers[0] = centers[3];
    centers[3] = centers[1];
    centers[1] = centers[2];
    centers[2] = temp1;
    temp2 = edges[0][0];
    temp3 = edges[0][1];
    edges[0][0] = edges[2][1];
    edges[0][1] = edges[2][0];
    edges[2][0] = edges[10][1];
    edges[2][1] = edges[10][0];
    edges[10][0] = edges[8][1];
    edges[10][1] = edges[8][0];
    edges[8][0] = temp3;
    edges[8][1] = temp2;
}
void Cube::Mv()
{
    int temp1, temp2, temp3;
    temp1 = centers[0];
    centers[0] = centers[4];
    centers[4] = centers[1];
    centers[1] = centers[5];
    centers[5] = temp1;
    temp2 = edges[1][0];
    temp3 = edges[1][1];
    edges[1][0] = edges[9][1];
    edges[1][1] = edges[9][0];
    edges[9][0] = edges[11][1];
    edges[9][1] = edges[11][0];
    edges[11][0] = edges[3][1];
    edges[11][1] = edges[3][0];
    edges[3][0] = temp3;
    edges[3][1] = temp2;
}
void Cube::operate(string step)
{
    if (step == "U")
    {
        U();
    }
    else if (step == "U'")
    {
        U();
        U();
        U();
    }
    else if (step == "R")
    {
        R();
    }
    else if (step == "R'")
    {
        R();
        R();
        R();
    }
    else if (step == "F")
    {
        F();
    }
    else if (step == "F'")
    {
        F();
        F();
        F();
    }
    else if (step == "D")
    {
        D();
    }
    else if (step == "D'")
    {
        D();
        D();
        D();
    }
    else if (step == "L")
    {
        L();
    }
    else if (step == "L'")
    {
        L();
        L();
        L();
    }
    else if (step == "B")
    {
        B();
    }
    else if (step == "B'")
    {
        B();
        B();
        B();
    }
    else if (step == "u")
    {
        U();
        Mh();
    }
    else if (step == "u'")
    {
        U();
        Mh();
        U();
        Mh();
        U();
        Mh();
    }
    else if (step == "r")
    {
        R();
        Mw();
    }
    else if (step == "r'")
    {
        R();
        Mw();
        R();
        Mw();
        R();
        Mw();
    }
    else if (step == "f")
    {
        F();
        Mv();
    }
    else if (step == "f'")
    {
        F();
        Mv();
        F();
        Mv();
        F();
        Mv();
    }
    else if (step == "d")
    {
        D();
        Mh();
        Mh();
        Mh();
    }
    else if (step == "d'")
    {
        D();
        D();
        D();
        Mh();
    }
    else if (step == "l")
    {
        L();
        Mw();
        Mw();
        Mw();
    }
    else if (step == "l'")
    {
        L();
        L();
        L();
        Mw();
    }
    else if (step == "b")
    {
        B();
        Mv();
        Mv();
        Mv();
    }
    else if (step == "b'")
    {
        B();
        B();
        B();
        Mv();
    }
    else if (step == "E")
    {
        Mh();
        Mh();
        Mh();
    }
    else if (step == "E'")
    {
        Mh();
    }
    else if (step == "M")
    {
        Mw();
        Mw();
        Mw();
    }
    else if (step == "M'")
    {
        Mw();
    }
    else if (step == "S")
    {
        Mv();
    }
    else if (step == "S'")
    {
        Mv();
        Mv();
        Mv();
    }
    else if (step == "X" || step == "x")
    {
        R();
        Mw();
        L();
        L();
        L();
    }
    else if (step == "X'" || step == "x'")
    {
        R();
        R();
        R();
        Mw();
        Mw();
        Mw();
        L();
    }
    else if (step == "Y" || step == "y")
    {
        U();
        Mh();
        D();
        D();
        D();
    }
    else if (step == "Y'" || step == "y'")
    {
        U();
        U();
        U();
        Mh();
        Mh();
        Mh();
        D();
    }
    else if (step == "Z" || step == "z")
    {
        F();
        Mv();
        B();
        B();
        B();
    }
    else if (step == "Z'" || step == "z'")
    {
        F();
        F();
        F();
        Mv();
        Mv();
        Mv();
        B();
    }
    else
    {
        cout << "不存在的" << endl;
    }
}
cube_formula::cube_formula()
{
    formula = "\0";
    fdirect = "\0";
    fname = "\0";
}
void cube_formula::formula_set(string str, string name)
{
    formula = str;
    fname = name;
    direc_sync();
}
void cube_formula::direc_sync()
{
    int i = 0, j = 0, n = 0;
    string para, step;
    fdirect = formula; //调整公式为，如(R2'U)2UR2 ---> R'R'UR'R'UURR
    while (fdirect[i] != '\0')
    {
        if (fdirect[i] == '(')
        {
            while (fdirect[i + j] != ')' && fdirect[i + j + 1] != '\0')
            {
                step = fdirect[i + j];
                para.insert(j, step);
                j++;
            }
            step = fdirect[i + j];
            para.insert(j, step);
            if (fdirect[i + j + 1] >= '1' && fdirect[i + j + 1] <= '9')
            {
                n = fdirect[i + j + 1] - 48;
                fdirect.erase(i, para.size() + 1);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, para);
                    i += para.size();
                }
            }
            else
            {
                i += para.size();
            }
            para.clear();
            j = 0;
        }
        else
        {
            i++;
        }
    }
    i = 0;
    while (fdirect[i] != '\0')
    {
        if (fdirect[i] > '9' && fdirect[i + 1] >= '1' && fdirect[i + 1] <= '9')
        {
            n = fdirect[i + 1] - 48;
            step = fdirect[i];
            if (fdirect[i + 2] == '\'')
            {
                step.insert(1, "\'");
                fdirect.erase(i, 3);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, step);
                }
                i += n * 2;
            }
            else
            {
                fdirect.erase(i, 2);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, step);
                }
                i += n;
            }
        }
        else if (fdirect[i] == '(' || fdirect[i] == ')')
        {
            fdirect.erase(i, 1);
        }
        else
        {
            if (fdirect[i] >= '0' && fdirect[i] <= '9')
                fdirect.erase(i, 1);
            i++;
        }
    }
}
void cube_formula::formula_inverse()
{
    int i = 0, len;
    string str;
    char c = '\0';
    while (formula[i] != '\0')
    {
        if (formula[i] > '9' && formula[i + 1] == '\'')
        {
            formula.erase(i + 1, 1);
            i++;
        }
        else if (formula[i] > '9' && formula[i + 1] > '\'')
        {
            if (formula[i + 1] < '0' || formula[i + 1] > '9')
            {
                formula.insert(i, "\'");
                i += 2;
            }
            else
            {
                if (formula[i + 2] == '\'')
                {
                    formula.erase(i + 2, 1);
                    c = formula[i];
                    formula[i] = formula[i + 1];
                    formula[i + 1] = c;
                    i += 2;
                }
                else
                {
                    c = formula[i];
                    formula[i] = formula[i + 1];
                    formula[i + 1] = c;
                    formula.insert(i, "\'");
                    i += 3;
                }
            }
        }
        else
        {
            if (formula[i] == '(')
                formula[i] = ')';
            else if (formula[i] == ')')
                formula[i] = '(';
            i++;
        }
    }
    str = formula;
    len = formula.size();
    for (i = 0; i < len; i++)
    {
        formula[i] = str[len - i - 1];
    }
    direc_sync();
}
void cube_formula::formula_mirror()
{
    int i = 0;
    while (formula[i] != '\0')
    {
        if (formula[i] > '9')
        {
            if (formula[i + 1] == '\'')
            {
                if (formula[i] == 'R' || formula[i] == 'r')
                {
                    formula[i] -= 6;
                    formula.erase(i + 1, 1);
                    i++;
                }
                else if (formula[i] == 'L' || formula[i] == 'l')
                {
                    formula[i] += 6;
                    formula.erase(i + 1, 1);
                    i++;
                }
                else if (formula[i] == 'M' || formula[i] == 'X' || formula[i] == 'x')
                {
                    i += 2;
                }
                else
                {
                    formula.erase(i + 1, 1);
                    i++;
                }
            }
            else if (formula[i + 1] >= '1' && formula[i + 1] <= '9')
            {
                if (formula[i + 2] == '\'')
                {
                    if (formula[i] == 'R' || formula[i] == 'r')
                    {
                        formula[i] -= 6;
                        formula.erase(i + 2, 1);
                        i += 2;
                    }
                    else if (formula[i] == 'L' || formula[i] == 'l')
                    {
                        formula[i] += 6;
                        formula.erase(i + 2, 1);
                        i += 2;
                    }
                    else if (formula[i] == 'M' || formula[i] == 'X' || formula[i] == 'x')
                    {
                        i += 3;
                    }
                    else
                    {
                        formula.erase(i + 2, 1);
                        i += 2;
                    }
                }
                else
                {
                    if (formula[i] == 'R' || formula[i] == 'r')
                    {
                        formula[i] -= 6;
                        formula.insert(i + 2, "\'");
                        i += 3;
                    }
                    else if (formula[i] == 'L' || formula[i] == 'l')
                    {
                        formula[i] += 6;
                        formula.insert(i + 2, "\'");
                        i += 3;
                    }
                    else if (formula[i] == 'M' || formula[i] == 'X' || formula[i] == 'x')
                    {
                        i += 2;
                    }
                    else
                    {
                        formula.insert(i + 2, "\'");
                        i += 3;
                    }
                }
            }
            else
            {
                if (formula[i] == 'R' || formula[i] == 'r')
                {
                    formula[i] -= 6;
                    formula.insert(i + 1, "\'");
                    i += 2;
                }
                else if (formula[i] == 'L' || formula[i] == 'l')
                {
                    formula[i] += 6;
                    formula.insert(i + 1, "\'");
                    i += 2;
                }
                else if (formula[i] == 'M' || formula[i] == 'X' || formula[i] == 'x')
                {
                    i++;
                }
                else
                {
                    formula.insert(i + 1, "\'");
                    i += 2;
                }
            }
        }
        else
        {
            i++;
        }
    }
    direc_sync();
}
void cube_formula::rotateX()
{
    int i = 0;
    while (formula[i] != '\0')
    {
        if (formula[i] == 'U' || formula[i] == 'u')
        {
            formula[i] -= 19;
            i++;
        }
        else if (formula[i] == 'F' || formula[i] == 'f')
        {
            formula[i] += 15;
            i++;
        }
        else if (formula[i] == 'D' || formula[i] == 'd')
        {
            formula[i] += 2;
            i++;
        }
        else if (formula[i] == 'B' || formula[i] == 'b')
        {
            formula[i] += 2;
            i++;
        }
        else if (formula[i] == 'E')
        {
            formula[i] = 'S';
            i++;
        }
        else if (formula[i] == 'S')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i, 2);
                formula.insert(i, "E");
            }
            else
            {
                formula.erase(i, 1);
                formula.insert(i, "E\'");
            }
            i++;
        }
        else if (formula[i] == 'Y' || formula[i] == 'y')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i + 1, 1);
                formula[i] += 1;
            }
            else
            {
                formula[i] += 1;
                formula.insert(i + 1, "\'");
            }
            i++;
        }
        else if (formula[i] == 'Z' || formula[i] == 'z')
        {
            formula[i] -= 1;
            i++;
        }
        else
        {
            i++;
        }
    }
}
void cube_formula::rotateY()
{
    int i = 0;
    while (formula[i] != '\0')
    {
        if (formula[i] == 'R' || formula[i] == 'r')
        {
            formula[i] -= 12;
            i++;
        }
        else if (formula[i] == 'F' || formula[i] == 'f')
        {
            formula[i] += 6;
            i++;
        }
        else if (formula[i] == 'L' || formula[i] == 'l')
        {
            formula[i] -= 10;
            i++;
        }
        else if (formula[i] == 'B' || formula[i] == 'b')
        {
            formula[i] += 16;
            i++;
        }
        else if (formula[i] == 'S')
        {
            formula[i] = 'M';
            i++;
        }
        else if (formula[i] == 'M')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i, 2);
                formula.insert(i, "S");
            }
            else
            {
                formula.erase(i, 1);
                formula.insert(i, "S\'");
            }
            i++;
        }
        else if (formula[i] == 'Z' || formula[i] == 'z')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i + 1, 1);
                formula[i] -= 2;
            }
            else
            {
                formula[i] -= 2;
                formula.insert(i + 1, "\'");
            }
            i++;
        }
        else if (formula[i] == 'X' || formula[i] == 'x')
        {
            formula[i] += 2;
            i++;
        }
        else
        {
            i++;
        }
    }
}
void cube_formula::rotateZ()
{
    int i = 0;
    while (formula[i] != '\0')
    {
        if (formula[i] == 'U' || formula[i] == 'u')
        {
            formula[i] -= 3;
            i++;
        }
        else if (formula[i] == 'R' || formula[i] == 'r')
        {
            formula[i] -= 14;
            i++;
        }
        else if (formula[i] == 'D' || formula[i] == 'd')
        {
            formula[i] += 8;
            i++;
        }
        else if (formula[i] == 'L' || formula[i] == 'l')
        {
            formula[i] += 9;
            i++;
        }
        else if (formula[i] == 'E')
        {
            formula[i] = 'M';
            i++;
        }
        else if (formula[i] == 'M')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i, 2);
                formula.insert(i, "E");
            }
            else
            {
                formula.erase(i, 1);
                formula.insert(i, "E\'");
            }
            i++;
        }
        else if (formula[i] == 'Y' || formula[i] == 'y')
        {
            formula[i] -= 1;
            i++;
        }
        else if (formula[i] == 'X' || formula[i] == 'x')
        {
            if (formula[i + 1] == '\'')
            {
                formula.erase(i + 1, 1);
                formula[i] += 1;
            }
            else
            {
                formula[i] += 1;
                formula.insert(i + 1, "\'");
            }
            i++;
        }
        else
        {
            i++;
        }
    }
}
void cube_formula::formula_rotate()
{
    string dir;
    cout << "请输入方向" << endl;
    cin >> dir;
    if (dir == "X" || dir == "x")
    {
        rotateX();
    }
    else if (dir == "X'" || dir == "x'")
    {
        rotateX();
        rotateX();
        rotateX();
    }
    else if (dir == "Y" || dir == "y")
    {
        rotateY();
    }
    else if (dir == "Y'" || dir == "y'")
    {
        rotateY();
        rotateY();
        rotateY();
    }
    else if (dir == "Z" || dir == "Z")
    {
        rotateZ();
    }
    else if (dir == "Z'" || dir == "z'")
    {
        rotateZ();
        rotateZ();
        rotateZ();
    }
    else
    {
        cout << "无效输入！" << endl;
    }
    direc_sync();
}
void cube_formula::formula_rotate(string dir)
{
    if (dir == "X" || dir == "x")
    {
        rotateX();
    }
    else if (dir == "X'" || dir == "x'")
    {
        rotateX();
        rotateX();
        rotateX();
    }
    else if (dir == "Y" || dir == "y")
    {
        rotateY();
    }
    else if (dir == "Y'" || dir == "y'")
    {
        rotateY();
        rotateY();
        rotateY();
    }
    else if (dir == "Z" || dir == "Z")
    {
        rotateZ();
    }
    else if (dir == "Z'" || dir == "z'")
    {
        rotateZ();
        rotateZ();
        rotateZ();
    }
    else
    {
        cout << "无效输入！" << endl;
    }
}

Cube_list::Cube_list()
{
    head = new cube_formula;
    head->next = nullptr;
    present = head;
    len = 2;
}
void Cube_list::traver()
{
    int i = 1;
    cube_formula *pre = head->next;
    while (pre != nullptr)
    {
        cout << i << "\t" << pre->fname << "\t " << pre->formula << endl;
        pre = pre->next; //循环输出
        i++;
    }
}
int Cube_list::formula_examine(string &fstr)
{
    int i = 0;
    while (fstr[i] != '\0')
    {
        if (fstr[i] == ' ')
        {
            fstr.erase(i, 1);
        }
        else if (fstr[i] < 0)
        {
            if (fstr[i] == -95 && fstr[i + 1] == -81)
            {
                fstr.erase(i, 2);
                fstr.insert(i, "\'");
            }
            else if (fstr[i] == -93 && fstr[i + 1] == -88)
            {
                fstr.erase(i, 2);
                fstr.insert(i, "(");
            }
            else if (fstr[i] == -93 && fstr[i + 1] == -87)
            {
                fstr.erase(i, 2);
                fstr.insert(i, ")");
            }
            else
                return 1;
        }
        else
        {
            i++;
        }
    }
    i = 0;
    if (fstr[0] == '\'' || (fstr[0] >= '0' && fstr[0] <= '9'))
        return 1;
    while (fstr[i] != '\0')
    {
        if ((fstr[i] < '1' && fstr[i] != '\'' && fstr[i] != '(' && fstr[i] != ')') || (fstr[i] > '9' && fstr[i] != 'B' && fstr[i] != 'D' && fstr[i] != 'E' && fstr[i] != 'F' && fstr[i] != 'L' && fstr[i] != 'M' && fstr[i] != 'R' && fstr[i] != 'S' && fstr[i] != 'U' && fstr[i] != 'X' && fstr[i] != 'Y' && fstr[i] != 'Z' && fstr[i] != 'b' && fstr[i] != 'd' && fstr[i] != 'f' && fstr[i] != 'l' && fstr[i] != 'r' && fstr[i] != 'u' && fstr[i] != 'x' && fstr[i] != 'y' && fstr[i] != 'z'))
            return 1;
        i++;
    }
    i = 0;
    int j = 0, n = 0;
    string para, step;
    fdirect = fstr; //调整公式为，如(R'U)R2U ---> R'URRU
    while (fdirect[i] != '\0')
    {
        if (fdirect[i] == '(')
        {
            while (fdirect[i + j] != ')')
            {
                if (fdirect[i + j] == '\0')
                {
                    return 1;
                }
                step = fdirect[i + j];
                para.insert(j, step);
                j++;
            }
            step = fdirect[i + j];
            para.insert(j, step);
            if (fdirect[i + j + 1] >= '1' && fdirect[i + j + 1] <= '9')
            {
                n = fdirect[i + j + 1] - 48;
                fdirect.erase(i, para.size() + 1);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, para);
                    i += para.size();
                }
            }
            else
            {
                i += para.size();
            }
            para.clear();
            j = 0;
        }
        else
        {
            i++;
        }
    }
    i = 0;
    while (fdirect[i] != '\0')
    {
        if (fdirect[i] > '9' && fdirect[i + 1] >= '1' && fdirect[i + 1] <= '9')
        {
            n = fdirect[i + 1] - 48;
            step = fdirect[i];
            if (fdirect[i + 2] == '\'')
            {
                step.insert(1, "\'");
                fdirect.erase(i, 3);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, step);
                }
                i += n * 2;
            }
            else
            {
                fdirect.erase(i, 2);
                for (j = 0; j < n; j++)
                {
                    fdirect.insert(i, step);
                }
                i += n;
            }
        }
        else if (fdirect[i] == '(' || fdirect[i] == ')')
        {
            fdirect.erase(i, 1);
        }
        else
        {
            if (fdirect[i] >= '0' && fdirect[i] <= '9')
            {
                return 1;
            }

            i++;
        }
    }
    return 0;
}
void Cube_list::add()
{
    int i = 0;
    string str, name;
    cube_formula *pre = head;
    while (pre->next != nullptr) //将指针移向尾部
    {
        pre = pre->next;
        i++;
    }
    getchar(); //读取回车
    cout << "请输入公式：" << endl;
    getline(cin, str);
    while (formula_examine(str))
    {
        cout << "无效公式，请重新输入：" << endl;
        str = "\0";
        getline(cin, str);
    }
    cout << "您输入的公式：" << str << endl;
    cout << "命名(默认：***)：" << endl;
    getline(cin, name);
    if (name.empty())
    {
        name = "***";
    }
    pre->next = new cube_formula; //新建一个节点
    pre = pre->next;
    pre->next = nullptr; //尾部置空
    len++;               //长度加一
    pre->formula_set(str, name);
}
int Cube_list::add(int n)
{
    if (n <= 0 || n > len + 1)
    {
        cout << "无效位置！" << endl;
        return 1;
    }
    int i = 0;
    string str, name;
    cube_formula *pre = head;
    cube_formula *s = nullptr;

    while (pre != nullptr && i < n - 1)
    {
        pre = pre->next;
        i++;
    }
    cout << "请输入公式：" << endl;
    getline(cin, str);
    while (formula_examine(str))
    {
        cout << "无效公式，请重新输入：" << endl;
        str = "\0";
        getline(cin, str);
    }
    cout << "您输入的公式：" << str << endl;
    cout << "命名(默认：***)：" << endl;
    getline(cin, name);
    if (name.empty())
    {
        name = "***";
    }
    s = new cube_formula; //新建一个节点
    s->formula_set(str, name);
    s->next = pre->next;
    pre->next = s;
    len++; //长度加一
    return 0;
}
int Cube_list::add(string nstr, string fstr)
{
    if (formula_examine(fstr))
        return 1;
    int i = 0;
    cube_formula *pre = head;
    while (pre->next != nullptr) //将指针移向尾部
    {
        pre = pre->next;
        i++;
    }
    pre->next = new cube_formula; //新建一个节点
    pre = pre->next;
    pre->next = nullptr; //尾部置空
    len++;               //长度加一
    pre->formula_set(fstr, nstr);
    return 0;
}
int Cube_list::del(int n)
{
    if (n <= 0 || n > len)
    {
        cout << "无效序号！" << endl;
        getchar();
        return 1;
    }
    int i = 0;
    cube_formula *pre = head;
    cube_formula *s = nullptr;

    while (pre != nullptr && i < n - 1)
    {
        pre = pre->next;
        i++;
    }
    s = pre->next;
    pre->next = s->next;
    delete s;
    len--; //长度减一
    present = head;
    return 0;
}
int Cube_list::change(int n)
{
    if (n <= 0 || n > len)
    {
        cout << "无效序号！" << endl;
        return 1;
    }
    getchar();
    int i = 0;
    string str, name;
    cube_formula *pre = head;

    while (pre != nullptr && i < n)
    {
        pre = pre->next;
        i++;
    }
    cout << "请输入公式：" << endl;
    getline(cin, str);
    while (formula_examine(str))
    {
        cout << "无效公式，请重新输入" << endl;
        str = "\0";
        getline(cin, str);
    }
    if (str.empty())
    {
        str = pre->formula;
        cout << "您未修改公式：" << str << endl;
    }
    else
    {
        cout << "您输入的公式：" << str << endl;
    }
    cout << "重命名(默认不修改)：" << endl;
    getline(cin, name);
    if (name.empty())
    {
        name = pre->fname;
    }
    pre->formula_set(str, name);
    return 0;
}
int Cube_list::present_set()
{
    int n;
    cout << "请输入序号" << endl;
    cin >> n;
    if (n <= 0 || n > len)
    {
        cout << "无效序号！" << endl;
        return 1;
    }
    int i = 0;
    present = head;

    while (present != nullptr && i < n)
    {
        present = present->next;
        i++;
    }
    return 0;
}
int Cube_list::present_at()
{
    int i = 0;
    cube_formula *pre = head;
    while (pre != present)
    {
        pre = pre->next;
        i++;
    }
    return i;
}
int Cube_list::search()
{
    int i = 1;
    string name;
    cube_formula *pre = head->next;
    cout << "请输入名字" << endl;
    cin >> name;
    while (pre != nullptr && name != pre->fname)
    {
        i++;
        pre = pre->next;
    }
    if (pre == nullptr)
    {
        cout << "未找到影片" << endl;
        return 1;
    }
    else
    {
        cout << "序号：\t" << i << endl;
        cout << "名字：\t" << pre->fname << endl;
        cout << "公式：\t" << pre->formula << endl;
    }
    return 0;
}