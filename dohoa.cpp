#include <iostream>
#include "console.h"
using namespace std;
void thanh_sang(int x, int y, int w, int h, int b_color, string content)
{
    TextColor(b_color);
    for (int ix = x + 1; ix <= x + w - 1; ix++)
    {
        for (int iy = y + 1; iy <= y + h - 1; iy++)
        {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    int ym = (2 * y + h) / 2;
    int xm = (2 * x + w - content.size()) / 2;
    TextColor(7);
    gotoXY(xm, ym);
    cout << content;
}
void box(int x, int y, int w, int h, int t_color, int b_color, string content)
{

    BackgroundColor(b_color);
    for (int ix = x + 1; ix <= x + w - 1; ix++)
    {
        for (int iy = y + 1; iy <= y + h - 1; iy++)
        {
            gotoXY(ix, iy);
            cout << " ";
        }
    }
    int ym = (2 * y + h) / 2;
    int xm = (2 * x + w - content.size()) / 2;
    TextColor(7);
    gotoXY(xm, ym);
    cout << content;

    TextColor(t_color);
    if (h <= 1 || w <= 1)
        return;

    for (int ix = x; ix <= x + w; ix++)
    {
        gotoXY(ix, y);
        cout << char(196);
        gotoXY(ix, y + h);
        cout << char(196);
    }
    for (int iy = y; iy <= y + h; iy++)
    {
        gotoXY(x, iy);
        cout << char(179);
        gotoXY(x + w, iy);
        cout << char(179);
    }
    gotoXY(x, y);
    cout << char(218);
    gotoXY(x + w, y);
    cout << char(191);
    gotoXY(x, y + h);
    cout << char(192);
    gotoXY(x + w, y + h);
    cout << char(217);
}
void n_box(int x, int y, int w, int h, int t_color, int b_color, int n)
{

    for (int i = 0; i < n; i++)
    {
        box(x, y + i * h, w, h, t_color, b_color, "Long");
    }
    TextColor(t_color);
    for (int i = 1; i < n; i++)
    {
        gotoXY(x, y + i * h);
        cout << char(195);
        gotoXY(x + w, y + i * h);
        cout << char(180);
    }
}
int main()
{
    // n_box(50, 5, 20, 2, 12, BACKGROUND_RED, 4);

    thanh_sang(50, 5, 20, 2,BACKGROUND_RED, "Long");
    return 0;
}
