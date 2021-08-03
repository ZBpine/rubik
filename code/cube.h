#ifndef CUBE_H_
#define CUBE_H_

#include <string>
using namespace std;

class Cube
{
private:
    //块存储，坐标见solidworks魔方模型
    int centers[6];    //白0，黄1，蓝2，绿3，红4，橙5；白色朝下，蓝色朝正，红色朝右
    int edges[12][2];  //坐标号所在面为[x][0],另一面为[x][1]
    int corners[8][3]; //坐标号所在面为[x][0],顺时针依次为[x][1],[x][2]

    void face_sync(); //将面存储与块存储同步，用于显示

    //对魔方的操作
    void U();
    void R();
    void F();
    void D();
    void L();
    void B();
    void Mh(); //水平中间层，同U
    void Mw(); //侧立中间层，同R
    void Mv(); //正立中间层，同F

public:
    Cube();
    void show();
    void operate(string step);
    int face[6][9]; //面存储，行标见块存储中心块标号；列标为魔方每面从左到右从上到下编号；2-正面，1-上面，4-右面
};

class cube_formula
{
private:
    void rotateX();
    void rotateY();
    void rotateZ();

public:
    string formula;
    string fdirect;
    string fname;

    cube_formula();
    void direc_sync();
    void formula_set(string str, string name);
    void formula_inverse();
    void formula_mirror();
    void formula_rotate();
    void formula_rotate(string dir);
    cube_formula *next;
};

class Cube_list : public Cube, public cube_formula
{
private:
    int len;

public:
    Cube_list();
    int formula_examine(string &str);
    void add();
    int add(int n);
    int add(string nstr, string fstr);
    int del(int n);
    int change(int n);
    void traver();
    int present_set();
    int present_at();
    int search();
    cube_formula *head;
    cube_formula *present;
};

#endif
