#include <math.h>
#include <GL/glut.h>

void DrawCircle(float cx, float cy, float r, int num_segments);
float x_position=0;
float y_position=0;
int state=1;
void drawBox();
void drawCar_D();
void drawTree();
void DrawCircleDash();
void drawSensors();
void draw_traffic_lights();
GLint roadDimen[8][2] = {{15,0},{25,150},{50,150},{55,0},{-50,40},{-50,75},{100,75},{100,40}};
GLint roadLines[][2] = {{17,0},{19,42},{-50,42},{-50,73},{21,73},{27,150},{49,150},{51,73},{100,73},{100,42},{52,42},{53,0}};
GLfloat center1[4][2] = {{35,0},{35,12},{36.5,12},{36.5,0}},center2[4][2] = {{-20,55},{-20,57},{-12,57},{-12,55}};
GLfloat traffic_lights[][2]={{50,10},{50,75},{52,75},{52,10},{52,70},{70,70},{70,58.5},{52,58.5},{36,56.5},{50,70},{50,58.5},{36,45}};

GLfloat box[][2]={{8,15},{8,30},{16,30},{16,15},{10,33},{18,33},{18,19}};
GLfloat tree[][2] = {{20,80},{20,87},{22,87},{22,80}};
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    y_position+=0.1;
    x_position-=1;
    if(x_position<-200)
    {
         x_position++;
         y_position-=0.5;
    }


}

void DrawCircle(float cx, float cy, float r, int num_segments)
{
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
void SemiCircle(float cx, float cy, float r, int num_segments)
{
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
void DrawCircleDash(float cx, float cy, float r, int num_segments)
{
    glVertex2i(0,0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta =(float) (2.0 * 3.1415926 * float(ii)) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void drawCar_D(){
//{{10,3},{5,20},{9,25},{16,20},{17,25},{19,36},{40,36},{42,25},{51,25},{43,20},{55,20},{50,3},{45,3},{40,3},{20,3},{15,3},{22,33},{29,33},{29,23},{20,23},{31,33},{38,33},{40,23},{31,23}};
//    0       1       2       3       4       5       6       7       8       9   10          11  12      13      14      15     16   17         18     19       20     21       22       23
    glColor3f(1,0,0);
    glLineWidth(5);
    glBegin(GL_POLYGON);
    glVertex2f(10+x_position,3+y_position);
    glVertex2f(5+x_position,20+y_position);
    glVertex2f(16+x_position,20+y_position);
    glVertex2f(17+x_position,25+y_position);
    glVertex2f(19+x_position,36+y_position);
    glVertex2f(40+x_position,36+y_position);
    glVertex2f(42+x_position,25+y_position);
    glVertex2f(43+x_position,20+y_position);
    glVertex2f(55+x_position,20+y_position);
    glVertex2f(50+x_position,3+y_position);
    glVertex2f(45+x_position,3+y_position);
    glVertex2f(40+x_position,3+y_position);
    glVertex2f(20+x_position,3+y_position);
    glVertex2f(22+x_position,33+y_position);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(5+x_position,20+y_position);
        glVertex2f(9+x_position,25+y_position);
        glVertex2f(17+x_position,25+y_position);
        glVertex2f(16+x_position,20+y_position);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(42+x_position,25+y_position);
        glVertex2f(51+x_position,25+y_position);
        glVertex2f(55+x_position,20+y_position);
        glVertex2f(43+x_position,20+y_position);
    glEnd();
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(22+x_position,33+y_position);
        glVertex2f(29+x_position,33+y_position);
        glVertex2f(29+x_position,23+y_position);
        glVertex2f(20+x_position,23+y_position);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2f(31+x_position,33+y_position);
        glVertex2f(38+x_position,33+y_position);
        glVertex2f(40+x_position,23+y_position);
        glVertex2f(31+x_position,23+y_position);
    glEnd();



    glColor3f(0,0,0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10+x_position,3+y_position);
    glVertex2f(5+x_position,20+y_position);
    glVertex2f(16+x_position,20+y_position);
    glVertex2f(17+x_position,25+y_position);
    glVertex2f(19+x_position,36+y_position);
    glVertex2f(40+x_position,36+y_position);
    glVertex2f(42+x_position,25+y_position);
    glVertex2f(43+x_position,20+y_position);
    glVertex2f(55+x_position,20+y_position);
    glVertex2f(50+x_position,3+y_position);
    glVertex2f(45+x_position,3+y_position);
    glVertex2f(40+x_position,3+y_position);
    glVertex2f(20+x_position,3+y_position);
    glVertex2f(22+x_position,3+y_position);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(5+x_position,20+y_position);
        glVertex2f(9+x_position,25+y_position);
        glVertex2f(17+x_position,25+y_position);
        glVertex2f(16+x_position,20+y_position);
    glEnd();
    glBegin(GL_LINE_LOOP);

        glVertex2f(42+x_position,25+y_position);
        glVertex2f(51+x_position,25+y_position);
        glVertex2f(55+x_position,20+y_position);
        glVertex2f(43+x_position,20+y_position);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(22+x_position,33+y_position);
        glVertex2f(29+x_position,33+y_position);
        glVertex2f(29+x_position,23+y_position);
        glVertex2f(20+x_position,23+y_position);
    glEnd();
    glBegin(GL_LINE_LOOP);
         glVertex2f(31+x_position,33+y_position);
        glVertex2f(38+x_position,33+y_position);
        glVertex2f(40+x_position,23+y_position);
        glVertex2f(31+x_position,23+y_position);
    glEnd();


    glColor3f(0,0,0);
    DrawCircle(19+x_position,3+y_position,5,40);
    DrawCircle(42+x_position,3+y_position,5,40);
}
void drawCar(){
    glPushMatrix();
    glScalef(0.40,0.40,0);
    glRotatef(-9,0,0,1);
    glTranslatef(130,115,0);
    drawCar_D();
    glPopMatrix();
}
void drawTree()
{

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

void draw_traffic_lights()
{
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

    glColor3ub(145, 22, 8);
    DrawCircle(55, 65, 2, 40);

    glColor3f(1.0,1.0,0.0);
    DrawCircle(60, 65, 2, 40);

    glColor3f(0.0,1.0,0.0);
    DrawCircle(65, 65, 2, 40);



    glColor3f(1.0,0.0,0.0);
    DrawCircle(39, 53, 2, 40);

    glColor3f(1.0,1.0,0.0);
    DrawCircle(43, 57, 2, 40);

    glColor3f(0.0,1.0,0.0);
    DrawCircle(47, 61.5, 2, 40);


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
