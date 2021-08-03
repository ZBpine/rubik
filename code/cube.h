#ifndef CUBE_H_
#define CUBE_H_

#include <string>
using namespace std;

class Cube
{
private:
    //��洢�������solidworksħ��ģ��
    int centers[6];    //��0����1����2����3����4����5����ɫ���£���ɫ��������ɫ����
    int edges[12][2];  //�����������Ϊ[x][0],��һ��Ϊ[x][1]
    int corners[8][3]; //�����������Ϊ[x][0],˳ʱ������Ϊ[x][1],[x][2]

    void face_sync(); //����洢���洢ͬ����������ʾ

    //��ħ���Ĳ���
    void U();
    void R();
    void F();
    void D();
    void L();
    void B();
    void Mh(); //ˮƽ�м�㣬ͬU
    void Mw(); //�����м�㣬ͬR
    void Mv(); //�����м�㣬ͬF

public:
    Cube();
    void show();
    void operate(string step);
    int face[6][9]; //��洢���б����洢���Ŀ��ţ��б�Ϊħ��ÿ������Ҵ��ϵ��±�ţ�2-���棬1-���棬4-����
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
