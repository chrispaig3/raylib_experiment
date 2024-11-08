#include <raylib.h>
#include <stdio.h>

#define X_WIN_CAP 1920
#define Y_WIN_CAP 1080

static char* WIN_TITLE = "Box Man";

const Vector3 CAM_POS = {0.0f, 10.0f, 10.0f};
const Vector3 CAM_TARGET = {0.0f, 0.0f, 0.0f};
const Vector3 CAM_UP = {0.0f, 1.0f, 0.0f};

typedef struct Player {
  Vector3 pos;
  int size;
  float speed;   
} Player;

int main(void) {
  InitWindow(X_WIN_CAP, Y_WIN_CAP, WIN_TITLE);

  Camera camera = {0};
  camera.position = CAM_POS;
  camera.target = CAM_TARGET;
  camera.up = CAM_UP;
  camera.fovy = 45.0f;
    
  Player player = {
      .pos = {0.0f, 1.0f, 0.0f},
      .size = 1.0f,
      .speed = 5.0f,
  };
  
  SetTargetFPS(160);      
   
  while (!WindowShouldClose()) 
  {
        
    if (IsKeyDown(KEY_RIGHT)) player.pos.x += player.speed * GetFrameTime();
    if (IsKeyDown(KEY_LEFT)) player.pos.x -= player.speed * GetFrameTime();
    if (IsKeyDown(KEY_UP)) player.pos.z -= player.speed * GetFrameTime();
    if (IsKeyDown(KEY_DOWN)) player.pos.z += player.speed * GetFrameTime();
     
    BeginDrawing();
      ClearBackground(RAYWHITE);
      BeginMode3D(camera);
      DrawCube(player.pos, player.size, player.size, player.size, PURPLE);
      DrawGrid(10, 1.0f);
      EndMode3D();
    EndDrawing();
  }
    
  CloseWindow();

  printf("Shutdown: success\n");
  return 0;
}
