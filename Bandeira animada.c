#include <windows.h>
#include <gl/glut.h>


// Parametro de posição e animação
GLfloat flagX = 100.0f;
GLfloat flagY = 150.0f;
GLfloat flagWidth = 50;

GLfloat xstep = 8.0f;
GLfloat ystep = 8.0f;

GLfloat windowWidth = 800;
GLfloat windowHeight = 600;

// função de desenho da Bandeira

void retangulo1() {
    // Desenhar o retângulo verde abaixo
    glColor3f(0, 0.655, 0);  // Verde
    glBegin(GL_QUADS);
    glVertex2f(flagX - 0.8 * flagWidth, flagY - 0.4 * flagWidth);  // baixo esquerda
    glVertex2f(flagX + 0.5 * flagWidth, flagY - 0.4 * flagWidth);  // baixo direita
    glVertex2f(flagX + 0.5 * flagWidth, flagY);  // cima direita
    glVertex2f(flagX - 0.3 * flagWidth, flagY);  // cima esquerda
    glEnd();
}

void retangulo2() {
    // Desenhar o retângulo AZUL acima
    glColor3f(0.135, 0.706, 0.735);  // AZUL
    glBegin(GL_QUADS);
    glVertex2f(flagX - 0.3 * flagWidth, flagY);  // baixo esquerda
    glVertex2f(flagX + 0.5 * flagWidth, flagY);  // baixo direita
    glVertex2f(flagX + 0.5 * flagWidth, flagY + 0.4 * flagWidth);  // cima direita
    glVertex2f(flagX - 0.8 * flagWidth, flagY + 0.4 * flagWidth);  // cima esquerda
    glEnd();
}

void triangulobranco() {
    // Desenhar o retângulo verde acima
    glColor3f(1, 1, 1);  // branco
    glBegin(GL_TRIANGLES);
    glVertex2f(flagX - 0.8 * flagWidth, flagY + 0.4 * flagWidth);  // p1
    glVertex2f(flagX - 0.2 * flagWidth, flagY);  // p2
    glVertex2f(flagX - 0.8 * flagWidth, flagY - 0.4 * flagWidth);  // p3
    glEnd();
}

void estrela1() {
    glColor3f(1, 0, 0);  // vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(flagX - 0.633 * flagWidth, flagY + 0.068 * flagWidth);  // p1
    glVertex2f(flagX - 0.58 * flagWidth, flagY - 0.011 * flagWidth);  // p2
    glVertex2f(flagX - 0.523 * flagWidth, flagY + 0.068 * flagWidth);  // p3
    glEnd();
}

void estrela2() {
    glColor3f(1, 0, 0);  // vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(flagX - 0.536 * flagWidth, flagY + 0.068 * flagWidth);  // p1
    glVertex2f(flagX - 0.59 * flagWidth, flagY + 0.068 * flagWidth);  // p2
    glVertex2f(flagX - 0.614 * flagWidth, flagY - 0.07 * flagWidth);  // p3
    glEnd();
}

void estrela3() {
    glColor3f(1, 0, 0);  // vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(flagX - 0.578 * flagWidth, flagY + 0.15 * flagWidth);  // p1
    glVertex2f(flagX - 0.60 * flagWidth, flagY + 0.03 * flagWidth);  // p2
    glVertex2f(flagX - 0.54 * flagWidth, flagY - 0.07 * flagWidth);  // p3
    glEnd();
}


void drawFlag() {
    glLoadIdentity();
	
	glTranslatef(-0.5, 0.0, 0.0); // ajuste de posição
    retangulo1();
    retangulo2();
    triangulobranco();
    estrela1();
    estrela2();
    estrela3();
}

// Função de animação
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Desenhar bandeira em sua posição local
    glPushMatrix();
    glTranslatef(flagX, flagY, 0);
    drawFlag();
    glPopMatrix();
    
    retangulo1();
    retangulo2();
	triangulobranco();
	estrela1();
	estrela2();
	estrela3();
	

    glutSwapBuffers();
}

//Timer de animação (Função)
void Timer(int value) {
    if (flagX > windowWidth - flagWidth || flagX < 0)
        xstep = -xstep;

    if (flagY > windowHeight - flagWidth || flagY < 0)
        ystep = -ystep;

    if (flagX > windowWidth - flagWidth)
        flagX = windowWidth - flagWidth - 1;

    if (flagY > windowHeight - flagWidth)
        flagY = windowHeight - flagWidth - 1;

    flagX += xstep;
    flagY += ystep;

    glutPostRedisplay();
    glutTimerFunc(33, Timer, 1);
}

// função de remodelar
void reshape(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        windowHeight = 250.0f * h / w;
        windowWidth = 250.0f;
    } else {
        windowWidth = 250.0f * w / h;
        windowHeight = 250.0f;
    }

    gluOrtho2D(0.0f, windowWidth=800, 0.0f, windowHeight=600);
}

// Main 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bandeira Animada");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(33, Timer, 1);

    // Initialize OpenGL settings
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();
    return 0;
}
