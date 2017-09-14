#include <graphics.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <fstream>

#define MAX_INPUT 80

using namespace std;

static int score = 0;
static int bullets = 0;
static int bullets2 = 0;
static int score2 = 0;

struct file {
   char Name[MAX_INPUT];
   int score;
   int score2;
}structFile[10], temp;

class levels {
   int i, upper, lower, maxx, maxy, speed;
   int mid;
   int mX, mY;
   int gunX, gunY;
   int breakpoint;
   char a[20], b[20];
   int currenti, previousi;
   public:
      levels() {
         maxx = getmaxx();
         maxy = getmaxy();
         gunX = maxx;
         gunY = maxy;
      }

   void level1(char name[MAX_INPUT]) {
      static default_random_engine randomEngine(time(NULL));
      uniform_int_distribution < int > j(200, 400);

      previousi = 0;
      speed = 2;
      mid = j(randomEngine);

      while (1) {
         begin2:
             if(bullets2 >= 15)
             {
                 outtextxy(maxx/2-100, maxy/2, "Game over");
                 sprintf(a, "Your \'level 2\' Score: %d", score2);
                 outtextxy(maxx/2-100, maxy/2+30, a);
                 getch();
                 break;
             }
         previousi = 0;
         maxx = getmaxx();
         //for forward
         while (previousi <= maxx) {
            for (i = previousi; i < previousi + 200; i += speed) {
               mid += speed;
               POINT cursorPosition;

               breakpoint = 0;

               GetCursorPos( & cursorPosition);
               mX = cursorPosition.x;
               mY = cursorPosition.y;

               outtextxy(1000, 20, name);

               sprintf(a, "Score: %d", score2);
               outtextxy(400, 20, a);

               sprintf(b, "Bullets spend: %d", bullets2);
               outtextxy(550, 20, b);

               circle(mX, mY, 7);
               line(mX, mY - 4, mX, mY - 10);
               line(mX, mY + 4, mX, mY + 10);
               line(mX - 4, mY, mX - 10, mY);
               line(mX + 4, mY, mX + 10, mY);


               setcolor(6);
               circle(i, mid, 1);
               circle(i, mid, 3);
               circle(i, mid, 6);
               circle(i, mid, 9);
               circle(i, mid, 12);
               circle(i, mid, 15);
               circle(i, mid, 18);

               setcolor(2);
               //base
               line(mX - 10, gunY, mX - 10, gunY - 95);
               line(mX + 10, gunY, mX + 10, gunY - 95);
               line(mX - 35, gunY, mX - 40, gunY - 100);
               line(mX + 35, gunY, mX + 40, gunY - 100);
               line(mX + 40, gunY - 100, mX + 10, gunY - 95);
               line(mX - 40, gunY - 100, mX - 10, gunY - 95);
               line(mX - 10, gunY - 95, mX + 10, gunY - 95);

               //back
               line(mX - 40, gunY - 100, mX - 40, gunY - 120);
               line(mX + 40, gunY - 100, mX + 40, gunY - 120);
               line(mX - 40, gunY - 120, mX + 40, gunY - 120);
               rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
               rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

               //head
               line(mX - 40, gunY - 120, mX - 30, gunY - 180);
               line(mX + 40, gunY - 120, mX + 30, gunY - 180);
               line(mX - 20, gunY - 120, mX - 12, gunY - 183);
               line(mX + 20, gunY - 120, mX + 12, gunY - 183);
               line(mX - 30, gunY - 180, mX - 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX - 12, gunY - 183, mX + 12, gunY - 183);
               rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

               if (score2 > 5) {
                  speed = (score2 * 2) / 10 + 1;
               }

               delay(1);
               cleardevice();
               int xpointer, ypointer;
               if (GetAsyncKeyState(VK_LBUTTON)) {
                  xpointer = mX;
                  ypointer = mY;

                  if (GetAsyncKeyState(VK_RBUTTON)) {
                     outtextxy(mX, mY, "Wrong button!");
                  }

                  if (xpointer >= i - 30 && xpointer <= i + 30 && ypointer >= mid - 30 && ypointer <= mid + 30) {
                     maxx = xpointer;
                     score2 = score2 + 2;
                     breakpoint = 1;
                  } else {
                     outtextxy(mX, mY, "MISSED!");
                  }
                  Sleep(150);
                  if(breakpoint == 1)
                  {
                      goto begin1;
                  } else {
                      bullets2 += 1;
                  }
               }
            }

            breakpoint = 0;
            previousi = i;

            for (i = previousi; i < previousi + 200; i += speed) {
               mid -= speed;
               POINT cursorPosition;

               GetCursorPos( & cursorPosition);

               mX = cursorPosition.x;
               mY = cursorPosition.y;

               outtextxy(1000, 20, name);

               sprintf(a, "Score: %d", score2);
               outtextxy(400, 20, a);

               sprintf(b, "Bullets spend: %d", bullets2);
               outtextxy(550, 20, b);

                if(bullets2 >= 15)
                {
                 outtextxy(maxx/2-100, maxy/2, "Game over");
                 sprintf(a, "Your \'level 2\' Score: %d", score2);
                 outtextxy(maxx/2-100, maxy/2+30, a);
                 getch();
                 break;
                }

               circle(mX, mY, 7);
               line(mX, mY - 4, mX, mY - 10);
               line(mX, mY + 4, mX, mY + 10);
               line(mX - 4, mY, mX - 10, mY);
               line(mX + 4, mY, mX + 10, mY);


                setcolor(6);
               circle(i, mid, 1);
               circle(i, mid, 3);
               circle(i, mid, 6);
               circle(i, mid, 9);
               circle(i, mid, 12);
               circle(i, mid, 15);
               circle(i, mid, 18);

               setcolor(2);
               //base
               line(mX - 10, gunY, mX - 10, gunY - 95);
               line(mX + 10, gunY, mX + 10, gunY - 95);
               line(mX - 35, gunY, mX - 40, gunY - 100);
               line(mX + 35, gunY, mX + 40, gunY - 100);
               line(mX + 40, gunY - 100, mX + 10, gunY - 95);
               line(mX - 40, gunY - 100, mX - 10, gunY - 95);
               line(mX - 10, gunY - 95, mX + 10, gunY - 95);

               //back
               line(mX - 40, gunY - 100, mX - 40, gunY - 120);
               line(mX + 40, gunY - 100, mX + 40, gunY - 120);
               line(mX - 40, gunY - 120, mX + 40, gunY - 120);
               rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
               rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

               //head
               line(mX - 40, gunY - 120, mX - 30, gunY - 180);
               line(mX + 40, gunY - 120, mX + 30, gunY - 180);
               line(mX - 20, gunY - 120, mX - 12, gunY - 183);
               line(mX + 20, gunY - 120, mX + 12, gunY - 183);
               line(mX - 30, gunY - 180, mX - 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX - 12, gunY - 183, mX + 12, gunY - 183);
               rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

               delay(1);
               cleardevice();
               int xpointer, ypointer;
               if (GetAsyncKeyState(VK_LBUTTON)) {
                  xpointer = mX;
                  ypointer = mY;

                  if (GetAsyncKeyState(VK_RBUTTON)) {
                     outtextxy(mX, mY, "Wrong button!");
                  }

                  if (xpointer >= i - 30 && xpointer <= i + 30 && ypointer >= mid - 30 && ypointer <= mid + 30) {
                     maxx = xpointer;
                     score2 = score2 + 1;
                     breakpoint = 1;
                     //goto begin1;
                  } else {
                     outtextxy(xpointer, ypointer, "MISSED!");
                  }
                  Sleep(150);
                  if(breakpoint == 1) {
                      goto begin1;
                  } else {
                      bullets2 += 1;
                  }

               }
            }
            previousi = i;
         }

        begin1:
            if(bullets2 >= 11)
             {
                 outtextxy(maxx/2-100, maxy/2, "Game over");
                 sprintf(a, "Your \'level 2\' Score: %d", score2);
                 outtextxy(maxx/2-100, maxy/2+30, a);
                 getch();
                 break;
             }
         mid = j(randomEngine);
         //for backward
         previousi = getmaxx();
         while (previousi > 0) {
            outtextxy(100, 100, "done");
            for (i = previousi; i > previousi - 200; i -= speed) {
               mid -= speed;
               POINT cursorPosition;
               breakpoint = 0;

               GetCursorPos( & cursorPosition);

               mX = cursorPosition.x;
               mY = cursorPosition.y;

               outtextxy(1000, 20, name);

               sprintf(a, "Score: %d", score2);
               outtextxy(400, 20, a);

               sprintf(b, "Bullets spend: %d", bullets2);
               outtextxy(550, 20, b);

               circle(mX, mY, 7);
               line(mX, mY - 4, mX, mY - 10);
               line(mX, mY + 4, mX, mY + 10);
               line(mX - 4, mY, mX - 10, mY);
               line(mX + 4, mY, mX + 10, mY);

               setcolor(6);
               circle(i, mid, 1);
               circle(i, mid, 3);
               circle(i, mid, 6);
               circle(i, mid, 9);
               circle(i, mid, 12);
               circle(i, mid, 15);
               circle(i, mid, 18);

               //base
               setcolor(2);
               line(mX - 10, gunY, mX - 10, gunY - 95);
               line(mX + 10, gunY, mX + 10, gunY - 95);
               line(mX - 35, gunY, mX - 40, gunY - 100);
               line(mX + 35, gunY, mX + 40, gunY - 100);
               line(mX + 40, gunY - 100, mX + 10, gunY - 95);
               line(mX - 40, gunY - 100, mX - 10, gunY - 95);
               line(mX - 10, gunY - 95, mX + 10, gunY - 95);

               //back
               line(mX - 40, gunY - 100, mX - 40, gunY - 120);
               line(mX + 40, gunY - 100, mX + 40, gunY - 120);
               line(mX - 40, gunY - 120, mX + 40, gunY - 120);
               rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
               rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

               //head
               line(mX - 40, gunY - 120, mX - 30, gunY - 180);
               line(mX + 40, gunY - 120, mX + 30, gunY - 180);
               line(mX - 20, gunY - 120, mX - 12, gunY - 183);
               line(mX + 20, gunY - 120, mX + 12, gunY - 183);
               line(mX - 30, gunY - 180, mX - 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX - 12, gunY - 183, mX + 12, gunY - 183);
               rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

               delay(1);
               cleardevice();
               int xpointer, ypointer;
               if (GetAsyncKeyState(VK_LBUTTON)) {
                  xpointer = mX;
                  ypointer = mY;

                  if (GetAsyncKeyState(VK_RBUTTON)) {
                     outtextxy(mX, mY, "Wrong button!");
                  }

                  if (xpointer >= i - 30 && xpointer <= i + 30 && ypointer >= mid - 30 && ypointer <= mid + 30) {
                     maxx = xpointer;
                     score2 = score2 + 1;
                     //goto begin2;
                     breakpoint = 1;
                  } else {
                     outtextxy(mX, mY, "MISSED!");
                  }
                  Sleep(150);
                  if(breakpoint == 1)
                  {
                      goto begin2;
                  } else {
                      bullets2 += 1;
                  }

               }
            }
            previousi = i;
            for (i = previousi; i > previousi - 200; i -= speed) {
               mid += speed;
               POINT cursorPosition;

               breakpoint = 0;

               GetCursorPos( & cursorPosition);

               mX = cursorPosition.x;
               mY = cursorPosition.y;

               outtextxy(1000, 20, name);

               sprintf(a, "Score: %d", score2);
               outtextxy(400, 20, a);

               sprintf(b, "Bullets spend: %d", bullets2);
               outtextxy(550, 20, b);

               circle(mX, mY, 7);
               line(mX, mY - 4, mX, mY - 10);
               line(mX, mY + 4, mX, mY + 10);
               line(mX - 4, mY, mX - 10, mY);
               line(mX + 4, mY, mX + 10, mY);

               setcolor(6);
               circle(i, mid, 1);
               circle(i, mid, 3);
               circle(i, mid, 6);
               circle(i, mid, 9);
               circle(i, mid, 12);
               circle(i, mid, 15);
               circle(i, mid, 18);

               //base
               setcolor(2);
               line(mX - 10, gunY, mX - 10, gunY - 95);
               line(mX + 10, gunY, mX + 10, gunY - 95);
               line(mX - 35, gunY, mX - 40, gunY - 100);
               line(mX + 35, gunY, mX + 40, gunY - 100);
               line(mX + 40, gunY - 100, mX + 10, gunY - 95);
               line(mX - 40, gunY - 100, mX - 10, gunY - 95);
               line(mX - 10, gunY - 95, mX + 10, gunY - 95);

               //back
               line(mX - 40, gunY - 100, mX - 40, gunY - 120);
               line(mX + 40, gunY - 100, mX + 40, gunY - 120);
               line(mX - 40, gunY - 120, mX + 40, gunY - 120);
               rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
               rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

               //head
               line(mX - 40, gunY - 120, mX - 30, gunY - 180);
               line(mX + 40, gunY - 120, mX + 30, gunY - 180);
               line(mX - 20, gunY - 120, mX - 12, gunY - 183);
               line(mX + 20, gunY - 120, mX + 12, gunY - 183);
               line(mX - 30, gunY - 180, mX - 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX + 30, gunY - 180, mX + 12, gunY - 183);
               line(mX - 12, gunY - 183, mX + 12, gunY - 183);
               rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

               delay(1);
               cleardevice();
               int xpointer, ypointer;
               if (GetAsyncKeyState(VK_LBUTTON)) {
                  xpointer = mX;
                  ypointer = mY;

                  if (GetAsyncKeyState(VK_RBUTTON)) {
                     outtextxy(mX, mY, "Wrong button!");
                  }

                  if (xpointer >= i - 30 && xpointer <= i + 30 && ypointer >= mid - 30 && ypointer <= mid + 30) {
                     maxx = xpointer;
                     score2 = score2 + 1;
                     breakpoint = 1;
                  } else {
                     outtextxy(mX, mY, "MISSED!");
                  }
                  Sleep(150);
                  if(breakpoint == 1)
                  {
                      goto begin2;
                  } else {
                      bullets2 += 1;
                  }

               }
            }
            previousi = i;
         }
      }
   }

/*   void level2() {
      static default_random_engine randomEngine(time(NULL));
      uniform_int_distribution < int > j(150, 500);

      int i;
      int temp;
      mid = j(randomEngine);
      speed = 1;

      POINT cursorPosition;
      while (1) {
         for (i = 1; i < maxx; i += speed) {
            if (i % 150 == 0) {
               mid = j(randomEngine);
            }
            circle(i, mid, 1);
            circle(i, mid, 3);
            circle(i, mid, 6);
            circle(i, mid, 9);
            circle(i, mid, 12);
            circle(i, mid, 15);
            circle(i, mid, 18);
            delay(1);
            cleardevice();
         }
         for (i = maxx; i > 0; i -= speed) {
            if (i % 150 == 0) {
               mid = j(randomEngine);
            }
            circle(i, mid, 1);
            circle(i, mid, 3);
            circle(i, mid, 6);
            circle(i, mid, 9);
            circle(i, mid, 12);
            circle(i, mid, 15);
            circle(i, mid, 18);
            delay(1);
            cleardevice();
         }
         speed++;
      }
   }*/
};

class object {
   public:
      float i, temp, temp2; //temporary variables
   char b12[10], b2[20], a1[10], b1[10]; //for printing
   float speed; //for speed
   int min1, w;
   int maxX, maxY;

   object() {
      speed = 1.0;
      min1 = 0;
      temp = 1.0;
   }

   void moving(int maxX, int maxY, char name[MAX_INPUT]) {
      static default_random_engine randomEngine(time(NULL));
      uniform_int_distribution < int > j(50, 450);

      int gunX, gunY;

      gunX = maxX;
      gunY = maxY;

      levels levelone;

      int mX, mY;
      int hold1;
      int hold2;

      while (1) {
         hold1 = j(randomEngine);
         maxX = getmaxx();
         for (i = 0.0; i < maxX; i = i + speed) {
            POINT cursorPosition;

            setfillstyle(WIDE_DOT_FILL, RED);
            bar(0, 50, gunX, 50);

            GetCursorPos( & cursorPosition);

            mX = cursorPosition.x;
            mY = cursorPosition.y;

            outtextxy(gunX-150, 20, name);
            outtextxy(100, 20, "Level 1");

            sprintf(b12, "Score: %d", score);
            outtextxy(gunX/2 - 150, 20, b12);

            sprintf(b2, "Bullets spend: %d", bullets);
            outtextxy(gunX/2, 20, b2);

            circle(mX, mY, 7);
            line(mX, mY - 4, mX, mY - 10);
            line(mX, mY + 4, mX, mY + 10);
            line(mX - 4, mY, mX - 10, mY);
            line(mX + 4, mY, mX + 10, mY);

            setcolor(10);
            line(0, 45, gunX, 45);
            line(0, 500, gunX, 500);

            if (score > 5) {
               speed = score / 10 + 1;
            }

        if (bullets >= 10) {
            cleardevice();
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            if(score >= 30 && score2 == 0 && bullets2 == 0)
            {
                outtextxy(gunX/2 -100, gunY/2+60, "Play Level 2?");
                outtextxy(gunX/2 -100, gunY/2+80, "Press 'y' for yes and any key for no.");
                w = getch();
            switch (w) {
            case 'y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            case 'Y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            default :
                break;
            }
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            }
            getch();
            cleardevice();
            break;
         }

            setcolor(6);
            circle(i, hold1, 1);
            circle(i, hold1, 3);
            circle(i, hold1, 6);
            circle(i, hold1, 9);
            circle(i, hold1, 12);
            circle(i, hold1, 15);
            circle(i, hold1, 18);

            //base
            setcolor(GREEN);
            line(mX - 10, gunY, mX - 10, gunY - 95);
            line(mX + 10, gunY, mX + 10, gunY - 95);
            line(mX - 35, gunY, mX - 40, gunY - 100);
            line(mX + 35, gunY, mX + 40, gunY - 100);
            line(mX + 40, gunY - 100, mX + 10, gunY - 95);
            line(mX - 40, gunY - 100, mX - 10, gunY - 95);
            line(mX - 10, gunY - 95, mX + 10, gunY - 95);

            //back
            line(mX - 40, gunY - 100, mX - 40, gunY - 120);
            line(mX + 40, gunY - 100, mX + 40, gunY - 120);
            line(mX - 40, gunY - 120, mX + 40, gunY - 120);
            rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
            rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

            //head
            line(mX - 40, gunY - 120, mX - 30, gunY - 180);
            line(mX + 40, gunY - 120, mX + 30, gunY - 180);
            line(mX - 20, gunY - 120, mX - 12, gunY - 183);
            line(mX + 20, gunY - 120, mX + 12, gunY - 183);
            line(mX - 30, gunY - 180, mX - 12, gunY - 183);
            line(mX + 30, gunY - 180, mX + 12, gunY - 183);
            line(mX + 30, gunY - 180, mX + 12, gunY - 183);
            line(mX - 12, gunY - 183, mX + 12, gunY - 183);
            rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

        setcolor(GREEN);
        if (score >= 30)
         {
             outtextxy(gunX-100, gunY-50, "Level 2");
             rectangle(gunX - 110, gunY - 50, gunX, gunY);
         }

            temp2 = maxX;
            delay(5);
            cleardevice();


            int xpointer, ypointer;

            if (GetAsyncKeyState(VK_LBUTTON)) {
               xpointer = mX;
               ypointer = mY;

               if (GetAsyncKeyState(VK_RBUTTON)) {
                  outtextxy(mX, mY, "Wrong Button");
               }

               if (xpointer >= i - 20 && xpointer <= i + 20 && ypointer >= hold1 - 20 && ypointer <= hold1 + 20) {
                  maxX = xpointer;
                  score = score + 1;
               } else if(score >= 30 && xpointer >= gunX-400 && xpointer <= gunX && ypointer >= gunY - 50 && ypointer <= gunX) {
                  cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
               }
               else {
                  bullets = bullets + 1;
                  outtextxy(mX, mY, "MISSED!");
               }
               Sleep(150);
            }
            xpointer = 0;
            ypointer = 0;

            if (i == temp2 - 1) {
               score--;
            }
         }
         //if
         hold2 = j(randomEngine);
         temp2 = gunX;
        if (bullets >= 10) {
            cleardevice();
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            if(score >= 30 && score2 == 0 && bullets2 == 0)
            {
                outtextxy(gunX/2 -100, gunY/2+60, "Play Level 2?");
                outtextxy(gunX/2 -100, gunY/2+80, "Press 'y' for yes and any key for no.");
                w = getch();
            switch (w) {
            case 'y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            case 'Y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            default :
                break;
            }
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            }            getch();
            cleardevice();
            break;
         }

         min1 = 0;

         for (i = gunX - 5; i > min1; i = i - temp) {
            POINT cursorPosition;
            int mX, mY;
            outtextxy(gunX-150, 20, name);
            outtextxy(100, 20, "Level 1");

            sprintf(b12, "Score: %d", score);
            outtextxy(gunX/2 - 150, 20, b12);

            sprintf(b2, "Bullets spend: %d", bullets);
            outtextxy(gunX/2, 20, b2);

            GetCursorPos( & cursorPosition);

            mX = cursorPosition.x;
            mY = cursorPosition.y;

            circle(mX, mY, 7);
            line(mX, mY - 4, mX, mY - 10);
            line(mX, mY + 4, mX, mY + 10);
            line(mX - 4, mY, mX - 10, mY);
            line(mX + 4, mY, mX + 10, mY);

            if (score > 5) {
               speed = score / 10 + 1;
            }

            setcolor(10);
            line(0, 45, gunX, 45);
            line(0, 500, gunX, 500);

        if (bullets >= 10) {
            cleardevice();
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            if(score >= 30 && score2 == 0 && bullets2 == 0)
            {
                outtextxy(gunX/2 -100, gunY/2+60, "Play Level 2?");
                outtextxy(gunX/2 -100, gunY/2+80, "Press 'y' for yes and any key for no.");
                w = getch();
            switch (w) {
            case 'y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            case 'Y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            default :
                break;
            }
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            }            getch();
            cleardevice();
            break;
         }
            temp = speed;

            setcolor(6);
            circle(i, hold2, 1);
            circle(i, hold2, 3);
            circle(i, hold2, 6);
            circle(i, hold2, 9);
            circle(i, hold2, 12);
            circle(i, hold2, 15);
            circle(i, hold2, 18);

            delay(5);
            cleardevice();

            temp2 = i;

            setcolor(2);
            //base
            line(mX - 10, gunY, mX - 10, gunY - 95);
            line(mX + 10, gunY, mX + 10, gunY - 95);
            line(mX - 35, gunY, mX - 40, gunY - 100);
            line(mX + 35, gunY, mX + 40, gunY - 100);
            line(mX + 40, gunY - 100, mX + 10, gunY - 95);
            line(mX - 40, gunY - 100, mX - 10, gunY - 95);
            line(mX - 10, gunY - 95, mX + 10, gunY - 95);

            //back
            line(mX - 40, gunY - 100, mX - 40, gunY - 120);
            line(mX + 40, gunY - 100, mX + 40, gunY - 120);
            line(mX - 40, gunY - 120, mX + 40, gunY - 120);
            rectangle(mX - 10, gunY - 125, mX - 5, gunY - 115);
            rectangle(mX + 10, gunY - 125, mX + 5, gunY - 115);

            //head
            line(mX - 40, gunY - 120, mX - 30, gunY - 180);
            line(mX + 40, gunY - 120, mX + 30, gunY - 180);
            line(mX - 20, gunY - 120, mX - 12, gunY - 183);
            line(mX + 20, gunY - 120, mX + 12, gunY - 183);
            line(mX - 30, gunY - 180, mX - 12, gunY - 183);
            line(mX + 30, gunY - 180, mX + 12, gunY - 183);
            line(mX + 30, gunY - 180, mX + 12, gunY - 183);
            line(mX - 12, gunY - 183, mX + 12, gunY - 183);
            rectangle(mX - 2.5, gunY - 186, mX + 2.5, gunY - 182);

        if (score >= 30)
         {
             outtextxy(gunX-100, gunY-50, "Level 2");
             rectangle(gunX - 110, gunY - 50, gunX, gunY);
         }

            int xpointer, ypointer;

            if (GetAsyncKeyState(VK_LBUTTON)) {
               xpointer = mX;
               ypointer = mY;

               if (GetAsyncKeyState(VK_RBUTTON)) {
                  outtextxy(mX, mY, "Wrong button!");
               }

               if (xpointer >= i - 20 && xpointer <= i + 20 && ypointer >= hold2 - 20 && ypointer <= hold2 + 20) {
                  min1 = xpointer;
                  score = score + 1;

               } else if(score >= 30 && xpointer >= gunX-400 && xpointer <= gunX && ypointer >= gunY - 50 && ypointer <= gunX) {
                  cleardevice();
                  outtextxy(gunX/2-400, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
               }
               else {
                  outtextxy(mX, mY, "MISSED!");
                  bullets = bullets + 1;
                  cleardevice();
               }
               Sleep(150);
            }

            xpointer = 0;
            ypointer = 0;
            if (i == 1) {
               score--;
            }
         }
        if (bullets >= 10) {
            cleardevice();
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            if(score >= 30 && score2 == 0 && bullets2 == 0)
            {
                outtextxy(gunX/2 -100, gunY/2+60, "Play Level 2?");
                outtextxy(gunX/2 -100, gunY/2+80, "Press 'y' for yes and any key for no.");
                w = getch();
            switch (w) {
            case 'y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            case 'Y' :
                cleardevice();
                  outtextxy(gunX/2-200, gunY/2, "Press any key to continue to level 2...");
                  getch();
                  levelone.level1(name);
                  break;
            default :
                break;
            }
            outtextxy(gunX/2-100, gunY/2, "Game Over");
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(gunX/2-50, gunY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(gunX/2-50, gunY/2+ 45, b12);
            }            getch();
            cleardevice();
            break;
         }
         if (score >= 30)
         {
             outtextxy(maxX-300, maxY-50, "You can proceed to next level here.");
         }
      }
   }
};

class open_close {
   int i, j, z, k, Temp, maxX, maxY, c;
   int xpointer, ypointer;
   char che[20], b12[20];
   public:

   void displayFile(int maxX) {
      char abc[MAX_INPUT];
      maxY = getmaxy();
      char scr[6], scr_2[6];
      i = 0;
      ifstream scoreFile("Scores.txt", ios::out | ios::in );
         while (scoreFile) {
        scoreFile.getline(abc, 20);
        strcpy(structFile[i].Name, abc);
        scoreFile.getline(scr, 6);
        scoreFile.getline(scr_2, 6);
        structFile[i].score = atoi(scr);
        structFile[i].score2 = atoi(scr_2);
        i++;
    }
    scoreFile.close();

    int z = i;

    for (int i = 0; i < z; ++i)
        for (int j = 0; j < z - i - 1; ++j)
            if (structFile[j].score < structFile[j + 1].score) {
                temp.score = structFile[j].score;
                structFile[j].score = structFile[j + 1].score;
                structFile[j + 1].score = temp.score;

                strcpy(temp.Name, structFile[j].Name);
                strcpy(structFile[j].Name, structFile[j + 1].Name);
                strcpy(structFile[j + 1].Name, temp.Name);
            }

    for (int i = 0; i < z; ++i)
        for (int j = 0; j < z - i - 1; ++j)
            if (structFile[j].score2 < structFile[j + 1].score2) {
                temp.score2 = structFile[j].score2;
                structFile[j].score2 = structFile[j + 1].score2;
                structFile[j + 1].score2 = temp.score2;

                strcpy(temp.Name, structFile[j].Name);
                strcpy(structFile[j].Name, structFile[j + 1].Name);
                strcpy(structFile[j + 1].Name, temp.Name);
            }

        cleardevice();
       setcolor(BLUE);
       outtextxy(maxX/2-20, 50, "Scores");
       outtextxy(300, 75, "Level 1 Scores");
        for (int Temp = 0, k = 0; k < z - 1 && k < 10; Temp = Temp + 25) {
        outtextxy(200, 100 + Temp, structFile[k].Name);
        sprintf(che, "%d", structFile[k].score);
        outtextxy(400, 100 + Temp, che);
        k++;
    }

       outtextxy(700, 75, "Level 2 Scores");
        for (int Temp = 0, k = 0; k < z - 1 && k < 10; Temp = Temp + 25) {
        outtextxy(600, 100 + Temp, structFile[k].Name);
        sprintf(che, "%d", structFile[k].score2);
        outtextxy(800, 100 + Temp, che);
        k++;
    }
            sprintf(b12, "Your \'level 1\' Score = %d", score);
            outtextxy(maxX/2-50, maxY/2+ 25, b12);
            sprintf(b12, "Your \'level 2\' Score = %d", score2);
            outtextxy(maxX/2-50, maxY/2+ 45, b12);
    getch();
   }


};

class gameEngine {
   int maxX;
   int maxY;
   char playerName[MAX_INPUT] = "";
   int input_pos;
   int c;
   int the_end;
   public:
      void beginGame() {
         the_end = 0;
         input_pos = 0;
         ofstream scorefile;
         scorefile.open("Scores.txt", ios::app);

         DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
         DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);

         initwindow(screenWidth, screenHeight, "Shoot 'Em Down", -3, -3);

         maxX = getmaxx();
         maxY = getmaxy();

         object one;
        open_close open;

         int abc = 0;

         setbkcolor(BLACK);
         setfillstyle(WIDE_DOT_FILL, GREEN);
         //rectangle(maxX/2-175, 250, maxX/2 +300, 500);
         setcolor(GREEN);
         //outtextxy(maxX - 40, 25, "?");
         for(int i = 200; i > 0; i-=2){
            settextstyle(BOLD_FONT, HORIZ_DIR, 5);
            outtextxy(maxX / 2 - 150, 500+i, "Shoot \'Em Down!");
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
            outtextxy(maxX / 2 - 150, 575+i, "Please enter your username:");
            delay(5);
            cleardevice();
         }
            setbkcolor(BLACK);
            setfillstyle(WIDE_DOT_FILL, GREEN);
            floodfill(100, 100, 7);
            settextstyle(BOLD_FONT, HORIZ_DIR, 5);
            outtextxy(maxX / 2 - 150, 300, "Shoot \'Em Down!");
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
            outtextxy(maxX / 2 - 150, 375, "Please enter your username:");
         do {
            outtextxy(maxX / 2 - 150, 425, playerName);
            c = getch();
            switch (c) {
            case 8: // backspace
               if (input_pos) {
                  input_pos--;
                  cleardevice();
                  setbkcolor(BLACK);
            setfillstyle(WIDE_DOT_FILL, GREEN);
            floodfill(100, 100, 7);
            settextstyle(BOLD_FONT, HORIZ_DIR, 5);
            outtextxy(maxX / 2 - 150, 300, "Shoot \'Em Down!");
            settextstyle(COMPLEX_FONT, HORIZ_DIR, 2);
            outtextxy(maxX / 2 - 150, 375, "Please enter your username:");
                  playerName[input_pos] = 0;
               }
               break;
            case 13: // returN
               the_end = 1;
               break;
            case 27: // Escape = Abort
               playerName[0] = 0;
               the_end = 1;
               break;
            default:
               if (input_pos < 9 && c >= ' ' && c <= '~') {
                  playerName[input_pos] = c;
                  input_pos++;
                  playerName[input_pos] = 0;
               }
            }
         } while (!the_end);

         levels levelone;
         one.moving(maxX, maxY, playerName);
         //levelone.level1(playerName);

         scorefile << playerName << endl << score << endl << score2 << endl;
         open.displayFile(maxX);
         //showFile();
      }
};

int main() {
   gameEngine game;
   game.beginGame();
   return 0;
}
