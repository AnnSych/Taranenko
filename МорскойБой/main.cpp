#include <string.h>
#include <cstdlib>
#include <iostream>
 int main()
{
    using namespace std;
 setlocale(LC_ALL, "rus");
const int N=5;
int map [N] [N] = {0};
int x, y; //���������� ����������

for (int i=0; i<5; i++)
{
    x = rand() % N;
    y = rand() % N;
    map [x][y] = 1;
} //������������� �����

for (int i=0; i<N; i++)
{
    for (int j=0; j<N; j++)
    {
        cout << map[j][i];
    }
    cout << endl; //����� ����� �� �����
}

while (true)
{
    cout << "������� ���������� ��� �����:" << endl;

    cin >> x;
    cin >> y; //����������

    if (map [x][y]== 1)
    {
        cout << "���������" << endl;
        map [x][y] = 0;
    }
    else
    {
        cout << "������" << endl;
    } //��������

} //������� ���� ���������
}
