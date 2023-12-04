// #include <iostream>
// #include "console.h"
// using namespace std;

// void box(int x, int y, int w, int h, string content)
// {

//     int ym = (2 * y + h) / 2;
//     int xm = (2 * x + w - content.size()) / 2;
//     TextColor(7);
//     gotoXY(xm, ym);
//     cout << content;
//     if (h <= 1 || w <= 1)
//         return;

//     for (int ix = x; ix <= x + w; ix++)
//     {
//         gotoXY(ix, y);
//         cout << char(196);
//         gotoXY(ix, y + h);
//         cout << char(196);
//     }
//     for (int iy = y; iy <= y + h; iy++)
//     {
//         gotoXY(x, iy);
//         cout << char(179);
//         gotoXY(x + w, iy);
//         cout << char(179);
//     }
//     gotoXY(x, y);
//     cout << char(218);
//     gotoXY(x + w, y);
//     cout << char(191);
//     gotoXY(x, y + h);
//     cout << char(192);
//     gotoXY(x + w, y + h);
//     cout << char(217);
// }
// void box_customer()
// {
//     int n ;
//     int m = 11;
//     int w = 17;
//     int h = 2;
//     int x = 3;
//     int y = 3;
//     int xx = x, yy = y;
//     for (int j = 0; j < m; j++)
//     {
//         if (j == 0) {
//             box(xx,yy,w/2+4,h,"CustomerID");
//             xx+= w/2+4;
//         }
//         else if (j == 1) {
//             box(xx,yy,w/2,h,"RoomID");
//             xx+=w/2;
//         }
//         else if (j == 2) {
//             box(xx,yy,w,h,"Name");
//             xx+= w;
//         }
//         else if (j == 3) {
//             box(xx,yy,w-3,h,"DateofBirth");
//             xx += w-3;
//         }
//         else if (j == 4) {
//             box(xx,yy,w-3,h,"DateCheckIn");
//             xx += w-3;
//         }
//         else if (j == 5) {
//             box(xx,yy,w/2,h,"Gender");
//             xx += w/2;
//         }
//         else if (j == 6) {
//             box(xx,yy,w,h,"Email");
//             xx += w;
//         }
//         else if (j == 7) {
//             box(xx,yy,w/2+2,h,"Address");
//             xx+= w/2+2;
//         }
//         else if (j == 8){
//             box(xx,yy,w-2,h,"Phone");
//             xx += w-2;
//         }
//         else if (j == 9) {
//             box(xx,yy,w,h,"UserName");
//             xx += w;
//         }
//         else if (j == 10) {
//             box(xx,yy,w/2+2,h,"Password");
//             xx += w/2+4;
//         }
//     }
//     // yy += h;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     xx = x;
//     //     for (int j = 0; j < m; j++)
//     //     {

//     //         if (j <= 1 || j == 7 || j == 10)
//     //         {
//     //             box(xx, yy, w / 2, h, "Long");
//     //             xx += w / 2;
//     //         }
//     //         else
//     //         {
//     //             box(xx, yy, w, h, "Dang Phuc Long");
//     //             xx += w;
//     //         }
//     //     }
//     //     yy += h;

//         // for (int j = 0; j < m; j++)
//         // {       if (i > 0 && j > 0) {
//         //         gotoXY(x+j*w,y+i*h);
//         //         cout << char(197);
//         //     }
//         // }
//         // gotoXY(x,y+(i+1)*h);
//         // cout << char(195);
//         // gotoXY(x + m*w,y+(i+1)*h);
//     //     // cout << char(180);
//     // }
// }
// int main()
// {   
//     system("cls");
//     box_customer();
//     gotoXY(0,0);
//     return 0;
// }
#include<iostream>
#include "List.cpp"
using namespace std;
int main()
{
    List<int> t;

}