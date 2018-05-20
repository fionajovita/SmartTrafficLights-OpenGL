#include <GL/glut.h>
#include<windows.h>
#include "GL/freeglut.h"
#include <math.h>
#include<stdio.h>
void DrawCircle(float cx, float cy, float r, int num_segments);
float x_bus=-15,y_bus=0,x_car1_position=50,y_car1_position =0,x_car2_position=50,y_car2_position=0;
float x_line_pos=0,y_line_pos=0,x=0,x_car3_position=0,y_car3_position=50,x_car4_position=0,y_car4_position=0;
float x_truck1_position=0,y_truck1_position=0;
GLubyte red_off[]={219,123,43};
GLubyte yellow_off[]={234, 207, 89};
GLubyte green_off[]={153,193,64};
GLubyte red_on[]={247,7,7};
GLubyte yellow_on[]={247, 239, 17};
GLubyte green_on[]={15,191,38};
int state=-1;
void drawBox();
void drawCar_D();
void drawTree();
void frontscreen();
void DrawCircleDash();
void drawSensors();
void draw_traffic_lights();
GLint roadDimen[8][2] = {{15,-25},{25,150},{50,150},{55,-25},{-50,40},{-50,75},{100,75},{100,40}};
GLint roadLines[][2] = {{17,-25},{20,42},{-50,42},{-50,73},{22,73},{27,150},{49,150},{51,73},{100,73},{100,42},{52,42},{53,-25}};
GLfloat center1[4][2] = {{35,0},{35,12},{36.5,12},{36.5,0}},center2[4][2] = {{-20,55},{-20,57},{-12,57},{-12,55}};
GLfloat traffic_lights[][2]={{50,10},{50,75},{52,75},{52,10},{52,70},{70,70},{70,58.5},{52,58.5},{36,56.5},{50,70},{50,58.5},{36,45}};
GLfloat box[][2]={{8,15},{8,30},{16,30},{16,15},{10,33},{18,33},{18,19}};
GLfloat tree[][2] = {{20,80},{20,87},{22,87},{22,80}};
void DrawCircle(float cx, float cy, float r, int num_segments){
    glVertex2i(0,0);
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta =(float) (2.0 * 3.1415926 * float(ii)) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void SemiCircle(float cx, float cy, float r, int num_segments){
    glVertex2i(0,0);
    glBegin(GL_POLYGON);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta =(float) (3.1415926 * float(ii)) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void DrawCircleDash(float cx, float cy, float r, int num_segments){
    glVertex2i(0,0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta =float(2.0*3.1415926*float(ii))/float(num_segments);//get the current angle

        float x=r*cosf(theta);//calculate the x component
        float y=r*sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    switch(state)
    {
    case -1:
        x=x+1;
        if(x==250){
            state=0;
            x=0;
        }
        break;
    case 0:
        x=x+1;
        if(x==250){
            state=1;
            x=0;
        }
        break;
    case 1:
    if(x_car1_position!=0)
    {
        x_car1_position-=0.5,y_car1_position+=0.01;
    }
    if(x_car2_position!=0)
    {
            x_car2_position-=0.5,y_car2_position+=0.01;
    }
    if(x_bus!=0)
    {
        x_bus-=0.5; y_bus+=0.01;
    }
    if(y_car3_position!=250){
    y_car3_position+=0.5;x_car3_position+=0.1;
    }
    else
        state=2;

    break;
    case 2:
        x=x+1;
        if(x==250){
            state=3;
            x=0;
        }
        break;

    case 3:
        if(y_car3_position<=850){

        x_car3_position+=0.1,y_car3_position+=0.5;
        }
        else{
            state=4;
        }
        break;
    case 4:
        x=x+1;
        if(x==250){
            state=5;
            x=0;
        }
        break;
    case 5:
        x_car1_position-=0.5,y_car1_position+=0.01;
        x_car2_position-=0.5,y_car2_position+=0.01;
        x_bus-=1;y_bus+=0.01;
        if(x_car1_position<-1000||x_car2_position<-1000||x_bus<-1000)
            state=6;
        break;
    case 6:
        x=x+1;
        if(x==250){
            state=7;
            x=0;
            x_car1_position=50;
            y_car1_position =0;
            x_car2_position=100;
            y_car2_position=-35;
            x_car3_position=0;
            y_car3_position=0;
            x_car4_position=0;
            y_car4_position=0;
            x_truck1_position=0;
            y_truck1_position=0;
        }
        break;
    case 7:
        if(x_car1_position!=0){
        x_car1_position-=0.5;y_car1_position+=0.01;
        }
        if(x_car2_position!=50)
        {
         x_car2_position-=0.5;y_car2_position+=0.01;
        }
        if(x_truck1_position>-100){
        x_truck1_position-=0.5;y_truck1_position+=0.01;
        }
        if(y_car4_position!=250){
            y_car4_position+=0.5;x_car4_position+=0.1;

        }
        if(y_car3_position!=250){
            y_car3_position+=0.5;x_car3_position+=0.1;

        }
        else
            state=8;
        break;
    case 8:
        x=x+1;
        if(x_line_pos>=-2)
        {
            x_line_pos-=0.05;
            y_line_pos+=0.01;
        }
        else
        {
            x_line_pos=0;
            y_line_pos=0;
        }
        if(x==150){
            state=9;
            x=0;
        }
        break;
    case 9:

        x_car1_position-=0.5;y_car1_position+=0.01;
        x_car2_position-=0.5;y_car2_position+=0.01;
        x_truck1_position-=0.5;y_truck1_position+=0.01;
        if(x_car1_position<-400||x_car2_position<-400||x_truck1_position>700)
            state=10;
        break;
    case 10:
        if(y_car3_position<=850||y_car4_position<=850){

        x_car3_position+=0.1,y_car3_position+=0.5;
        x_car4_position+=0.1,y_car4_position+=0.5;
        }
        else{
            state=11;
        }
        break;
    case 11:
            x+=1;
            x_car1_position=50;
            y_car1_position =0;
            x_car2_position=100;
            y_car2_position=-35;
            x_car3_position=0;
            y_car3_position=0;
            x_car4_position=0;
            y_car4_position=0;
            x_truck1_position=0;
            y_truck1_position=0;
            x_bus=-25;
            y_bus=0;
            if(x==250)
            {
                x=0;
                state=12;
            }
            break;
    case 12:
        if(x_bus!=0)
        {
            x_bus-=0.5; y_bus+=0.01;
        }
        if(x_truck1_position>-100){
        x_truck1_position-=0.5;y_truck1_position+=0.01;
        }
        if(y_car4_position!=250){
            y_car4_position+=0.5;x_car4_position+=0.1;

        }
        if(y_car3_position!=250){
            y_car3_position+=0.5;x_car3_position+=0.1;

        }
        else
            state=13;
        break;
    case 13:
        x=x+1;
        if(x_line_pos>=-2)
        {
            x_line_pos-=0.05;
            y_line_pos+=0.01;
        }
        else
        {
            x_line_pos=0;
            y_line_pos=0;
        }
        if(x==150){
            state=14;
            x=0;
        }
        break;
    case 14:
        x_bus-=2;y_bus+=0.01;
        x_truck1_position-=1;y_truck1_position+=0.01;
        if(x_bus<-1500||x_truck1_position<-1000)
            state=15;
        break;
    case 15:
        if(y_car3_position<=800||y_car4_position<=800){

        x_car3_position+=0.1,y_car3_position+=0.5;
        x_car4_position+=0.1,y_car4_position+=0.5;
        }
        else{
            state=16;
        }
        break;
    case 16:
        x+=1;
        if(x==250)
        {
            x=0;
        }
    }


}
void traffic_light_color_change(){
    switch(state){
        case 1:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 2:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_on);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 3:

        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_on);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_on);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 4:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_on);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 5:
        glColor3ubv(red_on);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_on);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 7:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 8:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_on);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 9:
        glColor3ubv(red_on);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_on);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 10:
        case 15:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_on);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_on);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 12:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 13:
        glColor3ubv(red_off);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_on);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_on);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_off);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
        case 14:
        glColor3ubv(red_on);
        DrawCircle(55, 65, 2, 40);//front red

        glColor3ubv(yellow_off);
        DrawCircle(60, 65, 2, 40);//front yellow

        glColor3ubv(green_off);
        DrawCircle(65, 65, 2, 40);//front green

        glColor3ubv(red_off);
        DrawCircle(39, 53, 2, 40);//side red

        glColor3ubv(yellow_off);
        DrawCircle(43, 57, 2, 40); //side yellow

        glColor3ubv(green_on);
        DrawCircle(47, 61.5, 2, 40); //side green
        break;
    }


}

void bus()
{


    glBegin(GL_POLYGON);
	glColor3ub(196, 3, 3);
    glVertex2i(20,50);
    glVertex2i(20,70);
    glVertex2i(20,75);
    glVertex2i(30,150);
    glVertex2i(230,150);
    glVertex2i(230,50);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub(119, 111, 110);
    glVertex2i(15,40);
    glVertex2i(60,40);
    glVertex2i(65,50);
    glVertex2i(15,50);
    glEnd();

    glColor3ub(196, 3, 3);
    glBegin(GL_POLYGON);
    glVertex2i(90,40);
    glVertex2i(160,40);
    glVertex2i(165,50);
    glVertex2i(85,50);
    glEnd();

    glColor3ub(119, 111, 110);
    glBegin(GL_POLYGON);
    glVertex2i(232,40);
    glVertex2i(232,50);
    glVertex2i(185,50);
    glVertex2i(190,40);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2i(40,75);
    glVertex2i(110,75);
    glVertex2i(110,85);
    glVertex2i(40,85);
    glEnd();

    glColor3f(0.0,0.0,0.70);
    glBegin(GL_POLYGON);
    glVertex2i(165,75);
    glVertex2i(225,75);
    glVertex2i(225,85);
    glVertex2i(165,85);
    glEnd();


    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(40,100);
    glVertex2i(70,110);
    glVertex2i(70,140);
    glVertex2i(40,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(80,110);
    glVertex2i(110,110);
    glVertex2i(110,140);
    glVertex2i(80,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(165,110);
    glVertex2i(190,110);
    glVertex2i(190,140);
    glVertex2i(165,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(195,110);
    glVertex2i(220,110);
    glVertex2i(220,140);
    glVertex2i(195,140);
    glEnd();

    glColor3ub(249, 108, 0);
    glBegin(GL_POLYGON);
    glVertex2i(120,60);
    glVertex2i(155,60);
    glVertex2i(155,140);
    glVertex2i(120,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(125,80);
    glVertex2i(135,80);
    glVertex2i(135,135);
    glVertex2i(125,135);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(140,80);
    glVertex2i(150,80);
    glVertex2i(150,135);
    glVertex2i(140,135);
    glEnd();

    glColor3ub(243, 255, 33);
    glBegin(GL_POLYGON);
    glVertex2i(20,55);
    glVertex2i(40,55);
    glVertex2i(40,70);
    glVertex2i(20,70);
    glEnd();

    glColor3ub(237, 237, 237);
    glBegin(GL_POLYGON);
    glVertex2i(30,55);
    glVertex2i(40,55);
    glVertex2i(40,70);
    glVertex2i(30,70);
    glEnd();

    glColor3ub(255, 250, 5);
    glBegin(GL_POLYGON);
    glVertex2i(210,60);
    glVertex2i(230,60);
    glVertex2i(230,70);
    glVertex2i(210,70);
    glEnd();

    glColor3ub(237, 237, 237);
    glBegin(GL_POLYGON);
    glVertex2i(210,60);
    glVertex2i(220,60);
    glVertex2i(220,70);
    glVertex2i(210,70);
    glEnd();

    glColor3ub(255, 63, 0);
    glBegin(GL_POLYGON);
    glVertex2i(70,150);
    glVertex2i(100,150);
    glVertex2i(100,155);
    glVertex2i(70,155);
    glEnd();

    glColor3ub(255, 63, 0);
    glBegin(GL_POLYGON);
    glVertex2i(180,150);
    glVertex2i(210,150);
    glVertex2i(210,155);
    glVertex2i(180,155);
    glEnd();


    glColor3ub(35, 35, 32);
    glBegin(GL_POLYGON);
    glVertex2i(5,115);
    glVertex2i(10,115);
    glVertex2i(10,135);
    glVertex2i(5,135);
    glEnd();

    glColor3ub(35, 35, 32);
    glBegin(GL_LINE_LOOP);
    glVertex2i(7,135);
    glVertex2i(7,145);
    glEnd();

    glColor3ub(35, 35, 32);
    glBegin(GL_LINE_LOOP);
    glVertex2i(7,145);
    glVertex2i(29,145);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_POLYGON);
    glVertex2i(22,90);
    glVertex2i(30,90);
    glVertex2i(37,140);
    glVertex2i(29,140);
    glEnd();






    glBegin(GL_LINE_LOOP);
	glColor3ub(196, 3, 3);
    glVertex2i(20,50);
    glVertex2i(20,70);
    glVertex2i(20,75);
    glVertex2i(30,150);
    glVertex2i(230,150);
    glVertex2i(230,50);
    glEnd();

    glBegin(GL_LINE_LOOP);
	glColor3ub(119, 111, 110);
    glVertex2i(15,40);
    glVertex2i(60,40);
    glVertex2i(65,50);
    glVertex2i(15,50);
    glEnd();

    glColor3ub(196, 3, 3);
    glBegin(GL_LINE_LOOP);
    glVertex2i(90,40);
    glVertex2i(160,40);
    glVertex2i(165,50);
    glVertex2i(85,50);
    glEnd();

    glColor3ub(119, 111, 110);
    glBegin(GL_LINE_LOOP);
    glVertex2i(232,40);
    glVertex2i(232,50);
    glVertex2i(185,50);
    glVertex2i(190,40);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(40,75);
    glVertex2i(110,75);
    glVertex2i(110,85);
    glVertex2i(40,85);
    glEnd();

    glColor3f(0.0,0.0,0.70);
    glBegin(GL_LINE_LOOP);
    glVertex2i(165,75);
    glVertex2i(225,75);
    glVertex2i(225,85);
    glVertex2i(165,85);
    glEnd();


    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(40,100);
    glVertex2i(70,110);
    glVertex2i(70,140);
    glVertex2i(40,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(80,110);
    glVertex2i(110,110);
    glVertex2i(110,140);
    glVertex2i(80,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(165,110);
    glVertex2i(190,110);
    glVertex2i(190,140);
    glVertex2i(165,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(195,110);
    glVertex2i(220,110);
    glVertex2i(220,140);
    glVertex2i(195,140);
    glEnd();

    glColor3ub(249, 108, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(120,60);
    glVertex2i(155,60);
    glVertex2i(155,140);
    glVertex2i(120,140);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(125,80);
    glVertex2i(135,80);
    glVertex2i(135,135);
    glVertex2i(125,135);
    glEnd();

    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(140,80);
    glVertex2i(150,80);
    glVertex2i(150,135);
    glVertex2i(140,135);
    glEnd();

    glColor3ub(243, 255, 33);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20,55);
    glVertex2i(40,55);
    glVertex2i(40,70);
    glVertex2i(20,70);
    glEnd();

    glColor3ub(237, 237, 237);
    glBegin(GL_LINE_LOOP);
    glVertex2i(30,55);
    glVertex2i(40,55);
    glVertex2i(40,70);
    glVertex2i(30,70);
    glEnd();

    glColor3ub(255, 250, 5);
    glBegin(GL_LINE_LOOP);
    glVertex2i(210,60);
    glVertex2i(230,60);
    glVertex2i(230,70);
    glVertex2i(210,70);
    glEnd();

    glColor3ub(237, 237, 237);
    glBegin(GL_LINE_LOOP);
    glVertex2i(210,60);
    glVertex2i(220,60);
    glVertex2i(220,70);
    glVertex2i(210,70);
    glEnd();

    glColor3ub(255, 63, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(70,150);
    glVertex2i(100,150);
    glVertex2i(100,155);
    glVertex2i(70,155);
    glEnd();

    glColor3ub(255, 63, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(180,150);
    glVertex2i(210,150);
    glVertex2i(210,155);
    glVertex2i(180,155);
    glEnd();


    glColor3ub(35, 35, 32);
    glBegin(GL_LINE_LOOP);
    glVertex2i(5,115);
    glVertex2i(10,115);
    glVertex2i(10,135);
    glVertex2i(5,135);
    glEnd();


    glColor3ub(175, 233, 255);
    glBegin(GL_LINE_LOOP);
    glVertex2i(22,90);
    glVertex2i(30,90);
    glVertex2i(37,140);
    glVertex2i(29,140);
    glEnd();




    glColor3ub(53,54,56);
    DrawCircle(75,40,15,40);
    glColor3ub(53,54,56);
    DrawCircle(175,40,15,40);
    glColor3ub(249,249,249);
    DrawCircle(75,40,8,40);
    glColor3ub(249,249,249);
    DrawCircle(175,40,8,40);


}
void draw_bus()
{
    glLineWidth(3);
    glPushMatrix();
    glScalef(0.12,0.165,1.0);
    glRotatef(-6,0,0,1);
    glTranslatef(875+x_bus,310+y_bus,0);
    bus();
    glPopMatrix();
}
void *currentfont;
void setFont(void *font)
{
	currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
    int j;
	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}

}
void renderStrokeFontString(
		float x,
		float y,
		float z,
		void *font,
		char *string) {

	char *c;
	glPushMatrix();
	glTranslatef(x,y,z);
    glScalef(0.5,0.5,0);
	for (c=string; *c != '\0'; c++) {
		glutStrokeCharacter(font, *c);
	}

	glPopMatrix();
}
void frontscreen(void)
{

    glBegin(GL_POLYGON);
    glColor3ub(135, 43, 10);
    glVertex2f(0,0);
    glColor3ub(66, 9, 0);
    glVertex2f(1000,0);
    glColor3ub(193, 40, 17);
    glVertex2f(1000,1000);
    glColor3ub(239, 83, 35);
    glVertex2f(0,1000);
    glEnd();

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0,0,0);
    drawstring(350.0,900.0,0.0,"ST JOSEPH ENGINEERING COLLEGE ");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(0.7,0,1);
    drawstring(300,800,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(1,0.5,0);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(400,700,0.0,"A MINI PROJECT ON");
    glColor3f(0.6,0.60,0.1);
    renderStrokeFontString(170,590,0,GLUT_STROKE_ROMAN,"SMART TRAFFIC LIGHTS");
    glColor3f(1,0.5,0);
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawstring(200,400,0.0,"BY:");
    glColor3f(1,1,1);
    drawstring(100,300,0.0,"FIONA JOVITA SALDANHA     4SO15CS040");
    glColor3f(1,1,1);
    drawstring(100,240,0.0,"COLIN NICKIL FERNANDES    4SO15CS027");
    glColor3f(1,0.5,0);
    drawstring(730,400,0.0,"PROJECT GUIDE:");
    glColor3f(1,1,1);
    drawstring(730,300,0.0,"MS. NISHA J ROCHE");
    glColor3f(1,1,1);
    drawstring(710,250,0.0,"ASSISTANT PROFESSOR");

    if(state==0)
    {
    glBegin(GL_POLYGON);
    glColor3ub(15, 43, 10);
    glVertex2f(0,0);
    glColor3ub(66, 249, 0);
    glVertex2f(1000,0);
    glColor3ub(193, 4, 17);
    glVertex2f(1000,1000);
    glColor3ub(29, 83, 3);
    glVertex2f(0,1000);
    glEnd();
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1,1,1);
    renderStrokeFontString(150,490,0,GLUT_STROKE_ROMAN,"CURRENT SCENARIO");    }
    if(state==6)
    {
    glBegin(GL_POLYGON);
    glColor3ub(239, 68, 57);
    glVertex2f(0,0);
    glColor3ub(237, 26, 11);
    glVertex2f(1000,0);
    glColor3ub(239, 214, 55);
    glVertex2f(1000,1000);
    glColor3ub(242, 213, 26);
    glVertex2f(0,1000);
    glEnd();
    glColor3f(0,0,0);
    renderStrokeFontString(250,490,0,GLUT_STROKE_ROMAN,"Smart Traffic Lights");

    glColor3f(0,0,0);
    renderStrokeFontString(300,400,0,GLUT_STROKE_ROMAN,"Scenario - 1");

 //   drawstring(370,540,0.0,"SCENARIO 1");
    }
    if(state==11)
    {
   /* glBegin(GL_POLYGON);
    glColor3ub(15, 43, 10);
    glVertex2f(0,0);
    glColor3ub(66, 249, 0);
    glVertex2f(1000,0);
    glColor3ub(193, 4, 17);
    glVertex2f(1000,1000);
    glColor3ub(29, 83, 3);
    glVertex2f(0,1000);
    glEnd();*/
    glColor3ub(8,152,219);
    glRectf(0,0,1000,200);
    glColor3ub(182, 237, 4);
    glRectf(0,200,1000,400);
    glColor3ub(183, 45, 45);
    glRectf(0,400,1000,600);
    glColor3ub(204, 149, 30);
    glRectf(0,600,1000,800);

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0,0,0);
    drawstring(370,590,0.0,"SMART TRAFFIC LIGHTS");
    glColor3f(0,0,0);
    drawstring(370,540,0.0,"SCENARIO 2");
    }
    if(state==16)
    {
    glBegin(GL_POLYGON);
    glColor3ub(60, 234, 199);
    glVertex2f(0,0);
    glColor3ub(216, 19, 134);
    glVertex2f(1000,0);
    glColor3ub(181, 10, 110);
    glVertex2f(1000,1000);
    glColor3ub(11, 191, 155);
    glVertex2f(0,1000);
    glEnd();
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0,0,0);
    drawstring(370,590,0.0,"THANK YOU");
    }
    glFlush();
}

void draw_Truck_D()
{

    glBegin(GL_POLYGON);
    glColor3ub(65,44,82);
    glVertex2i(20,10);
    glVertex2i(110,10);
    glVertex2i(110,70);
    glColor3ub(177,3,254);
    glVertex2i(60,70);
    glVertex2i(40,40);
    glVertex2i(20,25);
    glEnd();
    glColor3f(0,0,0);
    DrawCircle(95,10,7.5,40);
    DrawCircle(35,10,7.5,40);
    glRectf(20,20,110,25);
    glBegin(GL_POLYGON);
    glVertex2i(70,60);
    glVertex2i(59,60);
    glVertex2i(50,40);
    glVertex2i(70,40);
    glEnd();
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2i(75,70);
    glVertex2i(75,20);
    glEnd();

}
void draw_Truck()
{
    glPushMatrix();
    glScalef(0.30,0.35,0);
    glRotatef(-6,0,0,1);
    glTranslatef(300+x_truck1_position,155+y_truck1_position,0);
    draw_Truck_D();
    glPopMatrix();
}
void draw_traffic_lights(){
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2fv(traffic_lights[0]);
    glVertex2fv(traffic_lights[1]);
    glVertex2fv(traffic_lights[2]);
    glVertex2fv(traffic_lights[3]);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2fv(traffic_lights[4]);
    glVertex2fv(traffic_lights[5]);
    glVertex2fv(traffic_lights[6]);
    glVertex2fv(traffic_lights[7]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2fv(traffic_lights[8]);
    glVertex2fv(traffic_lights[9]);
    glVertex2fv(traffic_lights[10]);
    glVertex2fv(traffic_lights[11]);
    glEnd();
    SemiCircle(51,75,1,40);
    SemiCircle(51,10,-1,40);
    traffic_light_color_change();


}
void drawCar_D1(){
    glColor3f(1,0,0);
    glLineWidth(5);
    glBegin(GL_POLYGON);
    glVertex2f(10,3);
    glVertex2f(5,20);
    glColor3ub(201,45,28);
    glVertex2f(16,20);
    glVertex2f(17,25);
    glVertex2f(19,36);
    glVertex2f(40,36);
    glVertex2f(42,25);
    glVertex2f(43,20);
    glVertex2f(55,20);
    glVertex2f(50,3);
    glVertex2f(45,3);
    glVertex2f(40,3);
    glColor3ub(160,39,25);
    glVertex2f(20,3);
    glVertex2f(22,33);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(5,20);
        glVertex2f(9,25);
        glVertex2f(17,25);
        glVertex2f(16,20);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(160,39,25);
        glVertex2f(42,25);
        glVertex2f(51,25);
        glVertex2f(55,20);
        glVertex2f(43,20);
    glEnd();
    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
        glVertex2f(22,33);
        glVertex2f(29,33);
        glVertex2f(29,23);
        glVertex2f(20,23);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(31,33);
        glVertex2f(38,33);
        glVertex2f(40,23);
        glVertex2f(31,23);
    glEnd();






    glColor3f(0,0,0);
    DrawCircle(19,3,5,40);
    DrawCircle(42,3,5,40);

}
void drawCar1(){
    glPushMatrix();
    glScalef(0.40,0.40,0);
    glRotatef(-9,0,0,1);
    glTranslatef(130+x_car1_position,115+y_car1_position,0);
    drawCar_D1();
    glPopMatrix();
}
void drawCar_D2(){
    glColor3f(0.154,0.68,0.3);
    glLineWidth(5);
    glBegin(GL_POLYGON);
    glVertex2f(10 ,3);
    glVertex2f(5 ,20);
    glVertex2f(16 ,20);
    glVertex2f(17 ,25);
    glVertex2f(19 ,36);
    glVertex2f(40 ,36);
    glColor3f(0.3142,0.254,0);
    glVertex2f(42 ,25);
    glVertex2f(43 ,20);
    glVertex2f(55 ,20);
    glVertex2f(50 ,3);
    glVertex2f(45 ,3);
    glColor3f(0.21,0.62,0.1);
    glVertex2f(40 ,3);
    glVertex2f(20 ,3);
    glVertex2f(22 ,33);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(5 ,20);
        glVertex2f(9 ,25);
        glVertex2f(17 ,25);
        glVertex2f(16 ,20);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(42 ,25);
        glVertex2f(51 ,25);
        glVertex2f(55 ,20);
        glVertex2f(43 ,20);
    glEnd();
    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
        glVertex2f(22 ,33);
        glVertex2f(29 ,33);
        glVertex2f(29 ,23);
        glVertex2f(20 ,23);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(31 ,33);
        glVertex2f(38 ,33);
        glVertex2f(40 ,23);
        glVertex2f(31 ,23);
    glEnd();





    glColor3f(0,0,0);
    DrawCircle(19 ,3,5,40);
    DrawCircle(42 ,3,5,40);
}
void drawCar2(){
    glPushMatrix();
    glScalef(0.40,0.40,0);
    glRotatef(-9,0,0,1);
    glTranslatef(135+x_car2_position,145+y_car2_position,0);
    drawCar_D2();
    glPopMatrix();
}
void drawTree(){

    glColor3f(0.5f, 0.35f, 0.05f);
    glBegin(GL_POLYGON);
    glVertex2fv(tree[0]);
    glVertex2fv(tree[1]);
    glVertex2fv(tree[2]);
    glVertex2fv(tree[3]);
    glEnd();
    glColor3f(0.184314,0.309804,0.184314);
    DrawCircle(21,91,3,40);
    DrawCircle(21,88,2,40);
    DrawCircle(19,93,2,40);
    DrawCircle(19,90,2,40);
    DrawCircle(21,94,2,40);
    DrawCircle(23,92,2,40);
    DrawCircle(23,89,2,40);

}
void drawBox(){
    glBegin(GL_POLYGON);
    glVertex2fv(box[0]);
    glVertex2fv(box[1]);
    glVertex2fv(box[2]);
    glVertex2fv(box[3]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2fv(box[1]);
    glVertex2fv(box[4]);
    glVertex2fv(box[5]);
    glVertex2fv(box[2]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2fv(box[3]);
    glVertex2fv(box[2]);
    glVertex2fv(box[5]);
    glVertex2fv(box[6]);
    glEnd();
    glLineWidth(1.0);
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(box[0]);
    glVertex2fv(box[1]);
    glVertex2fv(box[2]);
    glVertex2fv(box[3]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2fv(box[1]);
    glVertex2fv(box[4]);
    glVertex2fv(box[5]);
    glVertex2fv(box[2]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2fv(box[3]);
    glVertex2fv(box[2]);
    glVertex2fv(box[5]);
    glVertex2fv(box[6]);
    glEnd();
    glColor3f(0,1,0);
    DrawCircle(10,25,0.5,40);
    glColor3f(1,0,0);
    DrawCircle(13,25,0.5,40);
}
void woman(){
	//face
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540,495,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
glPushMatrix();
	glTranslatef(540,494,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540,494);
 		glVertex2i(540,490); //nose
  		glVertex2i(531,498);
		glVertex2i(532,499);
 		glVertex2i(532,499);
		glVertex2i(537,498);//eyebrow
  	    glVertex2i(549,498);
		glVertex2i(548,499);
		glVertex2i(548,499);
 		glVertex2i(543,498);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14,494+1);
	glVertex2i(540-14,490+1);
	glVertex2i(538-14,489+1);
	glVertex2i(538-14,495+1);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554,495);
	glVertex2i(556,496);
	glVertex2i(556,491);
	glVertex2i(554,490);
	glEnd();
	//ear ring right
	glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(539-14,492);
	glVertex2i(542-14,485);
	glVertex2i(536-14,485);

	glEnd();
	//ear ring left
   glBegin(GL_POLYGON);
	glColor3ub(255,85,90);
	glVertex2i(551,485);
	glVertex2i(555,492);
	glVertex2i(558,485);
	glEnd();

//hair
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(525,499);
	glVertex2i(549,509);
	glVertex2i(540,512);
	glVertex2i(528,507);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3ub(0,0,0);
	glVertex2i(540,507);
	glVertex2i(549,509);
	glVertex2i(552,507);
	glVertex2i(555,499);
	glEnd();
	// eyes
        glBegin(GL_POLYGON);
 		glVertex2i(533,496);
 		glVertex2i(535,496);
 		glVertex2i(535,494);
 		glVertex2i(533,494);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545,496);
 		glVertex2i(547,496);
     	glVertex2i(547,494);
 		glVertex2i(545,494);
glEnd();
//mouth
glBegin(GL_POLYGON);
 		glColor3ub(150,50,50);
        glVertex2i(534,487);
 		glVertex2i(540,484);
 		glVertex2i(546,487);
 		glVertex2i(540,485);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(160,150,250);
        glVertex2i(529,480);
 		glVertex2i(551,480);
 		glVertex2i(566,469);
 		glVertex2i(561,460);
 		glVertex2i(556,465);
        glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,465);
 		glVertex2i(519,460);
 		glVertex2i(514,469);
glEnd();
//neck
    glBegin(GL_POLYGON);
        glColor3ub(255,190,128);
        glVertex2i(533,480);
        glVertex2i(547,480);
        glVertex2i(545,471);
        glVertex2i(535,471);
    glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565,468);
 		glVertex2i(575,453);
 		glVertex2i(567,454);
 		glVertex2i(562,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575,453);
 		glVertex2i(556,438);
 		glVertex2i(556,445);
 		glVertex2i(567,454);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515,468);
 		glVertex2i(505,453);
 		glVertex2i(513,454);
 		glVertex2i(518,462);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505,453);
   		glVertex2i(524,438);
   		glVertex2i(524,445);
   		glVertex2i(513,454);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(10,120,130);
 		glVertex2i(556,445);
 		glVertex2i(524,445);
 		glVertex2i(524,440);
 		glVertex2i(556,440);
glEnd();


	/// leg
glBegin(GL_POLYGON);
		glColor3ub(255,190,128);
glVertex2i(555,440);
glVertex2i(525,440);
glVertex2i(520,405);
glVertex2i(530,405);
glVertex2i(533,438);
glVertex2i(550,405);
glVertex2i(560,405);
	glEnd();
//skirt
    glBegin(GL_POLYGON);
	    glColor3ub(180,80,90);
		glVertex2i(524,440);
		glVertex2i(556,440);
		glVertex2i(566,410);
		glVertex2i(514,410);
    glEnd();
	//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(530,405);
	glVertex2i(530,396);
	glVertex2i(528,396);
	glVertex2i(528,404);
	glVertex2i(522,396);
	glVertex2i(512,396);
	glVertex2i(520,405);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(180,0,0);
	glVertex2i(550,405);
	glVertex2i(550,396);
	glVertex2i(552,396);
	glVertex2i(552,404);
	glVertex2i(558,396);
	glVertex2i(568,396);
	glVertex2i(560,405);
	glEnd();

}

void drawCar_D3(){
	glBegin(GL_POLYGON);
    glColor3ub(99, 0, 104);
    glVertex2i(30,45);
    glVertex2i(30,70);
    glColor3ub(99, 0, 104);
    glVertex2i(80,70);
    glVertex2i(80,45);
    glEnd();

    glColor3ub(123, 15, 127);
    glBegin(GL_POLYGON);
    glVertex2i(80,45);
    glVertex2i(80,70);
    glVertex2i(100,200);
    glVertex2i(100,175);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(83,90);
    glVertex2i(81,115);
    glVertex2i(86,160);
    glVertex2i(95,165);
    glEnd();

    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
    glVertex2f(84,100);
    glVertex2i(82,115);
    glVertex2i(84,131);
    glVertex2i(88,130);
    glEnd();

    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
    glVertex2i(88,131);
    glVertex2i(84,132);
    glVertex2f(88,158);
    glVertex2i(93,161);
    glEnd();

    glColor3ub(56, 5, 58);
    glBegin(GL_POLYGON);
    glVertex2i(30,70);
    glVertex2i(34,90);
    glVertex2f(83,90);
    glVertex2i(80,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(99, 0, 104);
    glVertex2i(34,90);
    glVertex2i(36,115);
    glVertex2i(81,115);
    glVertex2f(83,90);
    glEnd();

    glColor3ub(63, 5, 66);
    glBegin(GL_POLYGON);
    glVertex2i(36,115);
    glVertex2i(45,160);
    glVertex2i(87,160);
    glVertex2i(81,115);
    glEnd();

    glColor3ub(56, 5, 58);
    glBegin(GL_POLYGON);
    glVertex2i(50,165);
    glVertex2i(58,200);
    glVertex2i(100,200);
    glVertex2i(95,165);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(99, 0, 104);
    glVertex2i(87,160);
    glVertex2i(95,165);
    glVertex2i(50,165);
    glVertex2i(45,160);
    glEnd();



    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(90,80,0);
    glRotatef(85,0,1,0);
    DrawCircle(90,80,10,40);
    glTranslatef(-90,-80,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(78,39,0);
    glRotatef(85,0,1,0);
    DrawCircle(78,39,10,40);
    glTranslatef(-78,-39,0);
    glPopMatrix();
    glFlush();
    }
void drawCar3(){
    glPushMatrix();
    glScalef(0.2,0.2,0.51);
    glTranslatef(36+x_car3_position,-300+y_car3_position,0);
    drawCar_D3();
    glPopMatrix();
}
void drawCar_D4(){
glBegin(GL_POLYGON);
    glColor3ub(11, 34, 165);
    glVertex2i(30,45);
    glVertex2i(30,70);
    glColor3ub(6, 17, 81);
    glVertex2i(80,70);
    glVertex2i(80,45);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2i(80,45);
    glVertex2i(80,70);
    glVertex2i(100,200);
    glVertex2i(100,175);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(83,90);
    glVertex2i(81,115);
    glVertex2i(86,160);
    glVertex2i(95,165);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(30,70);
    glVertex2i(34,90);
    glVertex2f(83,90);
    glVertex2i(80,70);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(11, 34, 165);
    glVertex2i(34,90);
    glVertex2i(36,115);
    glVertex2i(81,115);
    glVertex2f(83,90);
    glEnd();

    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
    glVertex2f(84,100);
    glVertex2i(82,115);
    glVertex2i(84,131);
    glVertex2i(88,130);
    glEnd();

    glColor3ub(186, 184, 186);
    glBegin(GL_POLYGON);
    glVertex2i(88,131);
    glVertex2i(84,132);
    glVertex2f(88,158);
    glVertex2i(93,161);
    glEnd();

    glColor3ub(6, 17, 81);
    glBegin(GL_POLYGON);
    glVertex2i(36,115);
    glVertex2i(45,160);
    glVertex2i(86,160);
    glVertex2i(81,115);
    glEnd();

    glColor3ub(6, 17, 81);
    glBegin(GL_POLYGON);
    glVertex2i(50,165);
    glVertex2i(58,200);
    glVertex2i(100,200);
    glVertex2i(95,165);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(11, 34, 165);
    glVertex2i(87,160);
    glVertex2i(95,165);
    glVertex2i(50,165);
    glVertex2i(45,160);
    glEnd();



    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(90,80,0);
    glRotatef(85,0,1,0);
    DrawCircle(90,80,10,40);
    glTranslatef(-90,-80,0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(78,39,0);
    glRotatef(85,0,1,0);
    DrawCircle(78,39,10,40);
    glTranslatef(-78,-39,0);
    glPopMatrix();
    }
void drawCar4(){
    glPushMatrix();
    glScalef(0.2,0.2,0.51);
    glTranslatef(110+x_car4_position,-300+y_car4_position,0);
    drawCar_D4();
    glPopMatrix();
}

void man(){
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(1,10,100,90);
	glPopMatrix();
	glColor3ub(255,191,128);
    glPushMatrix();
	glTranslatef(540-220,495+76,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
 		glVertex2i(540-220,495+76);
 		glVertex2i(540-220,490+76); //nose
  		glVertex2i(531-220,500+76);
 		glVertex2i(537-220,500+76);//eyebrow
  		glVertex2i(543-220,500+76);
 		glVertex2i(549-220,500+76);//eyebrow
 	glEnd();
//ear right
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(540-14-220,494+1+76);
	glVertex2i(540-14-220,490+1+76);
	glVertex2i(538-14-220,489+1+76);
	glVertex2i(538-14-220,495+1+76);
	glEnd();
	//ear left
	glBegin(GL_POLYGON);
	glColor3ub(255,191,128);
	glVertex2i(554-220,495+76);
	glVertex2i(556-220,496+76);
	glVertex2i(556-220,491+76);
	glVertex2i(554-220,490+76);
	glEnd();
//hair
	glBegin(GL_POLYGON);
	  glColor3ub(0,0,0);
	  glVertex2i(527-220,503+76);
	  glVertex2i(553-220,503+76);
	  glVertex2i(547-220,509+76);
	  glVertex2i(533-220,509+76);
	glEnd();


	// eyes
 	glBegin(GL_POLYGON);
 		glVertex2i(533-220,498+76);
 		glVertex2i(535-220,498+76);
 		glVertex2i(535-220,496+76);
 		glVertex2i(533-220,496+76);
glEnd();
glBegin(GL_POLYGON);
 		glVertex2i(545-220,498+76);
 		glVertex2i(547-220,498+76);
 		glVertex2i(547-220,496+76);
 		glVertex2i(545-220,496+76);
glEnd();
 	// mouth
glBegin(GL_POLYGON);
 		glVertex2i(535-220,487+76);
 		glVertex2i(540-220,485+76);
 		glVertex2i(545-220,487+76);
 		glVertex2i(540-220,487+76);
glEnd();
//beard
glBegin(GL_POLYGON);
    glColor3ub(0,0,0);
    glVertex2i(538-220,480+76);
	glVertex2i(542-220,480+76);
	glVertex2i(542-220,484+76);
	glVertex2i(538-220,484+76);
glEnd();
//shirt
 	glBegin(GL_POLYGON);
 		glColor3ub(55,50,70);
	    glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(566-220,469+76);
 		glVertex2i(561-220,461+76);
 		glVertex2i(556-220,465+76);
        glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,465+76);
 		glVertex2i(519-220,460+76);
 		glVertex2i(514-220,469+76);
glEnd();
//hands
 	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
 		glVertex2i(565-220,468+76);
 		glVertex2i(575-220,453+76);
 		glVertex2i(567-220,454+76);
 		glVertex2i(562-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(575-220,453+76);
 		glVertex2i(556-220,438+76);
 		glVertex2i(556-220,445+76);
 		glVertex2i(567-220,454+76);
 	glEnd();
glBegin(GL_POLYGON);
	 	glVertex2i(515-220,468+76);
 		glVertex2i(505-220,453+76);
 		glVertex2i(513-220,454+76);
 		glVertex2i(518-220,462+76);
 	glEnd();
  	glBegin(GL_POLYGON);
		glVertex2i(505-220,453+76);
   		glVertex2i(524-220,438+76);
   		glVertex2i(524-220,445+76);
   		glVertex2i(513-220,454+76);
  	glEnd();
// belt
 	glBegin(GL_POLYGON);
		glColor3ub(150,12,30);
 		glVertex2i(556-220,445+76);
 		glVertex2i(524-220,445+76);
 		glVertex2i(524-220,440+76);
		glVertex2i(524-220,440+76);

 		glVertex2i(556-220,440+76);
glEnd();
// collar
 	glBegin(GL_POLYGON);
		glColor3ub(200,140,110+76);
 		glVertex2i(529-220,480+76);
 		glVertex2i(551-220,480+76);
 		glVertex2i(546-220,470+76);
 		glVertex2i(534-220,470+76);
glEnd();

 	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
 		glVertex2i(540-220,477+76);
  		glVertex2i(545-220,470+76);
 		glVertex2i(535-220,470+76);
glEnd();

// buttons
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(540-220,465+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,458+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540-220,451+76,0);
	glutSolidTorus(1,1,100,90);
	glPopMatrix();

	/// pant
glBegin(GL_POLYGON);
		glColor3ub(80,80,230);
glVertex2i(555-220,440+76);
glVertex2i(525-220,440+76);
glVertex2i(520-220,405+76);
glVertex2i(530-220,405+76);
glVertex2i(533-220,438+76);
glVertex2i(550-220,405+76);
glVertex2i(560-220,405+76);
	glEnd();
		//shoe left
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(530-220,405+76);
	glVertex2i(530-220,396+76);
	glVertex2i(512-220,396+76);
	glVertex2i(520-220,405+76);

	glEnd();
	//shoe right
	glBegin(GL_POLYGON);
	glColor3ub(100,10,10);
	glVertex2i(550-220,405+76);
	glVertex2i(550-220,396+76);
	glVertex2i(568-220,396+76);
	glVertex2i(560-220,405+76);
	glEnd();

}
void arc (void)
{
        glLineWidth(4);
        glColor3f(1,0,0);
        glBegin(GL_LINE_STRIP);
                glVertex2f(10,10);
                glVertex2f(30,35);
                glVertex2f(60,50);
                glVertex2f(140,50);
                glVertex2f(170,35);
                glVertex2f(195,10);
        glEnd();
}
void traffice_animate()
{
    int i;
    glPushMatrix();
    for(i=0;i<6;i++)
    {
        glBegin(GL_LINES);
        glVertex2f(48,6);
        glVertex2f(48,6.5);
        glEnd();
        glTranslatef(-5,2.75,0);
    }
    glPopMatrix();
    glPushMatrix();
    for(i=0;i<3;i++)
    {
        glBegin(GL_LINES);
        glVertex2f(24,6);
        glVertex2f(24,6.5);
        glEnd();
        glTranslatef(-5,6.5,0);
    }
    glPopMatrix();
}
void drawSensors(){
    glColor3f(0.3,0.2,0.1);
    DrawCircle(25,12,3.75,40);
    DrawCircleDash(25,12,4.25,15);
    DrawCircle(45,12,3.75,40);
    DrawCircleDash(45,12,4.25,15);
    DrawCircle(80,49,3,40);
    DrawCircleDash(80,49,3.5,15);
    DrawCircle(80,65,3,40);
    DrawCircleDash(80,65,3.5,15);
}
void traffic_animate()
{
    int i;
    glPushMatrix();
    for(i=0;i<6;i++)
    {
        glBegin(GL_LINES);
        glVertex2f(48,6);
        glVertex2f(48,6.5);
        glEnd();
        glTranslatef(-5,2.75,0);
    }
    glPopMatrix();
    glPushMatrix();
    for(i=0;i<3;i++)
    {
        glBegin(GL_LINES);
        glVertex2f(24,6);
        glVertex2f(24,6.5);
        glEnd();
        glTranslatef(-5,6.5,0);
    }
    glPopMatrix();
}
void centerfunc1(){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2fv(center1[0]);
    glVertex2fv(center1[1]);
    glVertex2fv(center1[2]);
    glVertex2fv(center1[3]);
    glEnd();

}
void centerfunc2(){
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2fv(center2[0]);
    glVertex2fv(center2[1]);
    glVertex2fv(center2[2]);
    glVertex2fv(center2[3]);
    glEnd();

}
void road_Lines(){
    glLineWidth(5.0);
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2iv(roadLines[0]);
    glVertex2iv(roadLines[1]);
    glVertex2iv(roadLines[1]);
    glVertex2iv(roadLines[2]);
    glVertex2iv(roadLines[3]);
    glVertex2iv(roadLines[4]);
    glVertex2iv(roadLines[4]);
    glVertex2iv(roadLines[5]);
    glVertex2iv(roadLines[6]);
    glVertex2iv(roadLines[7]);
    glVertex2iv(roadLines[7]);
    glVertex2iv(roadLines[8]);
    glVertex2iv(roadLines[9]);
    glVertex2iv(roadLines[10]);
    glVertex2iv(roadLines[10]);
    glVertex2iv(roadLines[11]);
    glEnd();


}
void bus_stop(){

/***********  ground   ***********/

glColor3ub(100,100,100);
glBegin(GL_POLYGON);
      glVertex3i(340-200,470,-110);
	glVertex3i(680-200,470,-110);
      glVertex3i(710-200,500,-240);
	glVertex3i(370-200,500,-240);
glEnd();
glColor3ub(100,100,100);
glBegin(GL_POLYGON);
      glVertex3i(340-200,470,-110);
	glVertex3i(680-200,470,-110);
	glVertex3i(680-200,450,-110);
	glVertex3i(340-200,450,-110);
glEnd();
glBegin(GL_POLYGON);
 	glVertex3i(680-200,470,-110);
      glVertex3i(710-200,500,-240);
	glVertex3i(710-200,480,-240);
	glVertex3i(680-200,450,-110);
glEnd();
glBegin(GL_POLYGON);
 	  glVertex3i(710-200,500,-240);
	  glVertex3i(710-200,480,-240);
	  glVertex3i(370-200,480,-240);
	  glVertex3i(370-200,500,-240);
glEnd();
glBegin(GL_POLYGON);
 	  glVertex3i(370-200,480,-240);
	  glVertex3i(370-200,500,-240);
 	  glVertex3i(340-200,470,-110);
	  glVertex3i(340-200,450,-110);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_STRIP);
   glVertex3i(340-200,470,-110);
   glVertex3i(680-200,470,-110);
   glVertex3i(710-200,500,-240);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_STRIP);
   glVertex3i(680-200,470,-110);
   glVertex3i(680-200,450,-110);
glEnd();


/************* left  ************/
glColor3ub(10,50,80);
glBegin(GL_POLYGON);
      glVertex3i(370-200,610,-140);
	glVertex3i(400-200,625,-200);
      glVertex3i(400-200,490,-200);
      glVertex3i(370-200,480,-140);
glEnd();
/************* mid  ************/

glColor3ub(10,170,80);
glBegin(GL_POLYGON);
      glVertex3i(395-200,580,-200);
	glVertex3i(690-200,580,-200);
      glVertex3i(690-200,520,-200);
	glVertex3i(395-200,520,-200);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
	glVertex3i(395-200,580,-200);
	glVertex3i(690-200,580,-200);
      glVertex3i(690-200,520,-200);
	glVertex3i(395-200,520,-200);
glEnd();
/************* right  ************/

glColor3ub(10,50,80);
glBegin(GL_POLYGON);
      glVertex3i(690-200,625,-200);
	glVertex3i(670-200,610,-140);
      glVertex3i(670-200,475,-140);
      glVertex3i(690-200,490,-200);
glEnd();


/***************** chair ******************/

glColor3ub(0,0,0);
glBegin(GL_POLYGON);
      glVertex3i(425-200,530,-180);
	glVertex3i(520-200,530,-180);
      glVertex3i(500-200,515,-150);
	glVertex3i(405-200,515,-150);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_LINES);
      glVertex3i(425-200,515,-160);
	glVertex3i(425-200,480,-160);
      glVertex3i(437-200,515,-170);
	glVertex3i(437-200,487,-170);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_LINES);
      glVertex3i(485-200,515,-163);
	glVertex3i(485-200,480,-163);
      glVertex3i(495-200,515,-170);
	glVertex3i(495-200,487,-170);
glEnd();

 /* *************   2nd  chair    *************** */

glColor3ub(0,10,20);
glBegin(GL_POLYGON);
      glVertex3i(560-200,530,-180);
	glVertex3i(655-200,530,-180);
      glVertex3i(635-200,515,-150);
	glVertex3i(540-200,515,-150);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_LINES);
      glVertex3i(560-200,515,-160);
	glVertex3i(560-200,480,-160);
      glVertex3i(572-200,515,-170);
	glVertex3i(572-200,487,-170);
glEnd();

glColor3ub(0,0,0);
glBegin(GL_LINES);
      glVertex3i(620-200,515,-163);
	glVertex3i(620-200,480,-163);
      glVertex3i(630-200,515,-170);
	glVertex3i(630-200,487,-170);
glEnd();
/********       upper       ********/
glColor3ub(10,50,80);
glBegin(GL_POLYGON);
      glVertex3i(350-200,620,-120);
	glVertex3i(700-200,620,-120);
      glVertex3i(700-200,600,-120);
      glVertex3i(350-200,600,-120);
glEnd();

glBegin(GL_POLYGON);
      glVertex3i(350-200,620,-120);
	glVertex3i(700-200,620,-120);
   	glVertex3i(720-200,640,-240);
      glVertex3i(380-200,640,-240);
glEnd();

glBegin(GL_POLYGON);
      glVertex3i(700-200,620,-120);
   	glVertex3i(720-200,640,-240);
      glVertex3i(720-200,620,-240);
      glVertex3i(700-200,600,-120);
glEnd();

glBegin(GL_POLYGON);
 	  glVertex3i(350-200,600,-120);
	  glVertex3i(350-200,620,-120);
 	  glVertex3i(380-200,640,-240);
	  glVertex3i(380-200,620,-240);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES);
      glVertex3i(350-200,620,-120);
	glVertex3i(700-200,620,-120);
	glVertex3i(700-200,620,-120);
   	glVertex3i(720-200,640,-240);
	glVertex3i(700-200,620,-120);
	glVertex3i(700-200,600,-120);
glEnd();
}
void road(){
    glLineWidth(10.0);
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2iv(roadDimen[0]);
    glVertex2iv(roadDimen[1]);
    glVertex2iv(roadDimen[2]);
    glVertex2iv(roadDimen[3]);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2iv(roadDimen[4]);
    glVertex2iv(roadDimen[5]);
    glVertex2iv(roadDimen[6]);
    glVertex2iv(roadDimen[7]);
    glEnd();


}
void init(){
    glClearColor(0,1,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,100,0,100,0,100);
    glMatrixMode(GL_MODELVIEW);
}
void Scene(){
    //draw_bus();
    drawTree();

    glPushMatrix();
    glTranslatef(-10,1,0);
    drawTree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(10,1,0);
    drawTree();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-20,1,0);
    drawTree();
    glPopMatrix();
    glPushMatrix();
        glRotatef(-10,0,0,1);
        road();
        road_Lines();
        if(state>6)
            drawSensors();
        centerfunc1();
        glPushMatrix();
            for(int i=1;i<5;i++){
                if(i==2)
                {
                    glTranslatef(0.0,22.0,0.0);
                }
                else{
                glTranslatef(0.0,22.0,0.0);
                centerfunc1();
                }
            }
        glPopMatrix();
        centerfunc2();
        glPushMatrix();
            for(int i=1;i<=7;i++){
                if(i==3||i==4){
                    glTranslatef(15.0,0.0,0.0);
                }
                else{
                glTranslatef(15.0,0.0,0.0);
                centerfunc2();
                }
            }
        glPopMatrix();
    glPopMatrix();
    if(state<6){
        drawCar3();

        glColor3f(1.0,0.5,0.25);
        drawCar2();
        draw_bus();
        glPushMatrix();
            glTranslatef(9,40,0);
            glScalef(0.7,0.7,0);
            draw_traffic_lights();
        glPopMatrix();
        drawCar1();
    }

    if(state>6&&state<=10){
        for(int k=0;k<5;k++)
        {
            glPushMatrix();
            glTranslatef(x_line_pos,y_line_pos,0);
            if(state==8){
                    glColor3f(0,0,0);
            traffice_animate();
            }
            glPopMatrix();
        }
        drawCar3();
        drawCar4();
        glColor3f(1.0,0.5,0.25);
        drawBox();
        draw_Truck();
        glPushMatrix();
            glTranslatef(9,40,0);
            glScalef(0.7,0.7,0);
            draw_traffic_lights();
        glPopMatrix();
        drawCar1();
        drawCar2();

    }


    if(state>10){
        for(int k=0;k<5;k++)
        {
            glPushMatrix();
            glTranslatef(x_line_pos,y_line_pos,0);
            if(state==13)
            {
                glColor3f(0,0,0);
                traffice_animate();
            }
            glPopMatrix();
        }
        drawCar3();
        drawCar4();
        glColor3f(1.0,0.5,0.25);
        drawBox();
        draw_Truck();
        glPushMatrix();
            glTranslatef(9,40,0);
            glScalef(0.7,0.7,0);
            draw_traffic_lights();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0,-12.5,0);
        draw_bus();
        glPopMatrix();
    }
    glPushMatrix();
        glTranslatef(60,35,0);
        glScalef(0.07,0.09,0.07);
        bus_stop();
        woman();
        man();
    glPopMatrix();
}
void scene_transition()
{
    switch(state)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:

        glPushMatrix();
        glScalef(0.8,0.8,1);
        glTranslatef(20,20,0);
        Scene();
        glPopMatrix();
        break;
    case 11:
    case 6:
    case 0:
    case -1:
    case 16:

        glPushMatrix();
        glScalef(0.1,0.1,1);
        frontscreen();
        glPopMatrix();
        break;
    }

}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glEnable(GL_LINE_SMOOTH);
    scene_transition();

    glFlush();
    glutSwapBuffers();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1350,650);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GL_DEPTH_BUFFER_BIT);
    glutCreateWindow("Project Demo");
    init();
    glutDisplayFunc(display);
   // glutTimerFunc(0,timer,0);

    glutMainLoop();

    return 0;
}
