#include <gl/gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>


void yansit(float cisimMatrix[3][3], float yansitilmis[3][3]){
	
	float  t [3][3] = {
	 {1.0f,0.0f,0.0f},
	 {0.0f,-1.0f,0.0f},
     {0.0f,0.0f,1.0f}
};
	int i = 0;
	int j = 0;
	int k = 0;
	 for (i = 0; i < 3; ++i) {
      for (j = 0; j < 3; ++j) {
         for ( k = 0; k < 3; ++k) {
            yansitilmis[i][j] += cisimMatrix[i][k] * t[k][j];
         }
      }
   }
}  


void dondur(float cisimMatrix[3][3], float dondurulmus[3][3]){
	
	float t [3][3] = {
	 {cos(30.0f * (M_PI/180)),-sin(30.0f * (M_PI/180)),0},
	 {sin(30.0f * (M_PI/180)),cos(30.0f * (M_PI/180)),0},
     {0,0,1}
};

	int i = 0;
	int j = 0;
	int k = 0;
	 for (i = 0; i < 3; ++i) {
	 	
      for (j = 0; j < 3; ++j) {
      	
         for ( k = 0; k < 3; ++k) {
         	
            dondurulmus[i][j] += cisimMatrix[i][k] * t[k][j];
         }
      }
   }
}

void display(void){
	
	float  cisimMatix[3][3] = {
    	{2.0f,3.0f,1.0f},
	 	{7.0f,3.0f,1.0f},
     	{2.0f,6.0f,1.0f}
	};
	float  yansitilmis[3][3] = {
	 {0.0f,0.0f,0.0f},
	 {0.0f,0.0f,0.0f},
     {0.0f,0.0f,0.0f}
};
	float dondurulmus[3][3] = {
	 {0.0f,0.0f,0.0f},
	 {0.0f,0.0f,0.0f},
     {0.0f,0.0f,0.0f}
};
	
	
	
	glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0); // red x
    glBegin(GL_LINES);
    // x ekseni
    glVertex3f(-4.0f, GLUT_WINDOW_X/10.0, 0.0f);
    glVertex3f(GLUT_WINDOW_X, GLUT_WINDOW_X/10.0, 0.0f);
    glEnd();
    glFlush();
    // y ekseni
    glColor3f(0.0,1.0,0.0); // green y
    glBegin(GL_LINES);
    glVertex3f(GLUT_WINDOW_Y/10.0, -4.0f, 0.0f);
    glVertex3f(GLUT_WINDOW_Y/10.0, GLUT_WINDOW_Y, 0.0f);
    glEnd();
    glFlush();
    //Cisim
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
    // a - b çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[0][0],GLUT_WINDOW_Y/10.0 + cisimMatix[0][1], cisimMatix[0][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[1][0],GLUT_WINDOW_Y/10.0 + cisimMatix[1][1], cisimMatix[1][2]);
    // b - c çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[1][0],GLUT_WINDOW_Y/10.0 + cisimMatix[1][1], cisimMatix[1][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[2][0],GLUT_WINDOW_Y/10.0 + cisimMatix[2][1], cisimMatix[2][2]);
    // c - a çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[2][0],GLUT_WINDOW_Y/10.0 + cisimMatix[2][1], cisimMatix[2][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + cisimMatix[0][0],GLUT_WINDOW_Y/10.0 + cisimMatix[0][1], cisimMatix[0][2]);
    glEnd();
    glFlush();
    // Yansýtýlmýþ cisim
   
    glColor3f(0.0,1.0,1.0);
    yansit(cisimMatix,yansitilmis);
    glBegin(GL_LINES);
    // a - b çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[0][0],GLUT_WINDOW_Y/10.0 + yansitilmis[0][1], yansitilmis[0][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[1][0],GLUT_WINDOW_Y/10.0 + yansitilmis[1][1], yansitilmis[1][2]);
    // b - c çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[1][0],GLUT_WINDOW_Y/10.0 + yansitilmis[1][1], yansitilmis[1][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[2][0],GLUT_WINDOW_Y/10.0 + yansitilmis[2][1], yansitilmis[2][2]);
    // c - a çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[2][0],GLUT_WINDOW_Y/10.0 + yansitilmis[2][1], yansitilmis[2][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + yansitilmis[0][0],GLUT_WINDOW_Y/10.0 + yansitilmis[0][1], yansitilmis[0][2]);
    glEnd();
    glFlush();
    
    // Döndürülmüþ cisim
   
    glColor3f(1.0,1.0,0.0);
    dondur(cisimMatix,dondurulmus);
    glBegin(GL_LINES);
    // a - b çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[0][0],GLUT_WINDOW_Y/10.0 + dondurulmus[0][1], dondurulmus[0][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[1][0],GLUT_WINDOW_Y/10.0 + dondurulmus[1][1], dondurulmus[1][2]);
    // b - c çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[1][0],GLUT_WINDOW_Y/10.0 + dondurulmus[1][1], dondurulmus[1][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[2][0],GLUT_WINDOW_Y/10.0 + dondurulmus[2][1], dondurulmus[2][2]);
    // c - a çizgisi
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[2][0],GLUT_WINDOW_Y/10.0 + dondurulmus[2][1], dondurulmus[2][2]);
    glVertex3f(GLUT_WINDOW_X/10.0 + dondurulmus[0][0],GLUT_WINDOW_Y/10.0 + dondurulmus[0][1], dondurulmus[0][2]);
    glEnd();
    glFlush();
    
}

int main(int argc, char *argv[]) {
	 
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(480,540);
	glutCreateWindow("Odev");
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,20.0,0.0,20.0,-1.0,1.0);
	glutDisplayFunc(display);
	glutMainLoop();
	
    return 0;
}
