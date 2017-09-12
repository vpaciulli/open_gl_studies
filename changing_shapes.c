#include <GLUT/GLUT.h>

GLfloat angle, fAspect;
//TODO: Improve control flow for solid/wireframe changes. Made on a hurry.
int shapeNumber = 0;
int inView = 0;

void CheckAndDrawWireframe (int n) {
  switch (inView) {
    case 0:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutWireCube(50.0f);
      break;
    case 1:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutWireTeapot(50.0f);
      break;
    case 2:
      glColor3f(1.0f, 0.0f, 1.0f);
      glutWireSphere(50, 50, 50);
      break;
    case 3:
      glColor3f(1.0f, 1.0f, 0.0f);
      glutWireTorus (25.0 ,50.0, 10.0, 15.0);
      break;
    case 4:
      glColor3f(1.0f, 0.0f, 0.0f);
      glutWireCube(50.0f);
      break;
  }
}

void CheckAndDrawSolid (int n) {
  switch (inView) {
    case 0:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutSolidCube(50.0f);
      break;
    case 1:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutSolidTeapot(50.0f);
      break;
    case 2:
      glColor3f(1.0f, 0.0f, 1.0f);
      glutSolidSphere(50, 50, 50);
      break;
    case 3:
      glColor3f(1.0f, 1.0f, 0.0f);
      glutSolidTorus (25.0 ,50.0, 10.0, 15.0);
      break;
    case 4:
      glColor3f(1.0f, 0.0f, 0.0f);
      glutSolidCube(50.0f);
      break;
  }
}

void CheckAndDraw (int shapeNumber) {
  switch (shapeNumber) {
    case 0:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutWireCube(50.0f);
      break;
    case 1:
      glColor3f(0.0f, 0.0f, 1.0f);
      glutWireTeapot(50.0f);
      break;
    case 2:
      glColor3f(1.0f, 0.0f, 1.0f);
      glutWireSphere(50, 50, 50);
      break;

    case 3:
      glColor3f(1.0f, 1.0f, 0.0f);
      glutWireTorus (25.0 ,50.0, 10.0, 15.0);
      break;

    case 4:
      glColor3f(1.0f, 0.0f, 0.0f);
      glutWireCube(50.0f);
    break;

    case 5:
      CheckAndDrawWireframe(inView);
    break;

    case 6:
      CheckAndDrawSolid(inView);
    break;
  }
}

void Draw(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  CheckAndDraw(shapeNumber);
  glutSwapBuffers();
}

void Init (void) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  angle=45;
}

void Keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'T':
    case 't':
      shapeNumber = 1;
      glutPostRedisplay();
      break;
    case 'E':
    case 'e':
      shapeNumber = 2;
      glutPostRedisplay();
      break;
    case 'O':
    case 'o':
      shapeNumber = 3;
      glutPostRedisplay();
      break;
    case 'C':
    case 'c':
      shapeNumber = 4;
      glutPostRedisplay();
      break;
    case 'W':
    case 'w':
      shapeNumber = 5;
      glutPostRedisplay();
      break;
    case 'S':
    case 's':
      inView = shapeNumber;
      shapeNumber = 6;
      glutPostRedisplay();
      break;
  }
}

void ViewParameters(void) {
  // Especifica sistema de coordenadas de projeção
  glMatrixMode(GL_PROJECTION);
  // Inicializa sistema de coordenadas de projeção
  glLoadIdentity();

  // Especifica a projeção perspectiva
  gluPerspective(angle,fAspect,0.5,500);

  // Especifica sistema de coordenadas do modelo
  glMatrixMode(GL_MODELVIEW);
  // Inicializa sistema de coordenadas do modelo
  glLoadIdentity();

  // Especifica posição do observador e do alvo
  gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

void WindowSize(GLsizei w, GLsizei h) {
  // Para previnir uma divisão por zero
  if ( h == 0 ) h = 1;

  // Especifica o tamanho da viewport
  glViewport(0, 0, w, h);

  // Calcula a correção de aspecto
  fAspect = (GLfloat)w/(GLfloat)h;

  ViewParameters();
}


int main (int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(350,300);
  glutCreateWindow("Shapes Changes");
  glutDisplayFunc(Draw);
  glutReshapeFunc(WindowSize);
  glutKeyboardFunc(Keyboard);
  Init();
  glutMainLoop();
}
