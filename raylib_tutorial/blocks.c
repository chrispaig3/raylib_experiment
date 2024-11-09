#include <raylib.h>

#define DELTA GetFrameTime()

// GameScreen State
typedef enum GameScreen {LOGO, TITLE, GAMEPLAY, ENDING} GameScreen;

// Screen Dimensions
static int SCREEN_X = 1000;
static int SCREEN_Y = 2000;
// Window Title
static char* WIN_TITLE = "The Blocks";

int main(void) {
  InitWindow(SCREEN_X, SCREEN_Y, WIN_TITLE);
  // Window Config
  ConfigFlags vsync = FLAG_VSYNC_HINT;
  SetConfigFlags(vsync);

  // Set intial GameScreen State  
  GameScreen screen = LOGO;
  
  int framesCounter = 0;  
  int gameResult = -1;
  bool gamePaused = false;

  // Main event loop
  while (!WindowShouldClose()) 
  {
   // Update
   switch(screen) 
   {
     case LOGO: 
     {
       framesCounter++;
       if (framesCounter > 180)
       {
         screen = TITLE;
         framesCounter = 0;
       }
     } break;
     case TITLE:
     {
       framesCounter++;
       if (IsKeyPressed(KEY_ENTER)) screen = GAMEPLAY;
     } break;
     case GAMEPLAY:
     {
       if (!gamePaused) 
       {
         // TODO: Gameplay Logic
       }
       if (IsKeyPressed(KEY_ENTER)) screen = ENDING;
     }  break;
     case ENDING:
     {
       framesCounter++;

       if (IsKeyPressed(KEY_ENTER)) screen = TITLE;
     } break;
     default: break;
   }
   // Draw
   BeginDrawing();
     
     switch(screen) 
     {
         case LOGO:
         {
           DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
           DrawText("WAIT for 3 SECONDS...", 290, 220, 20, GRAY);         
         } break;
         case TITLE: 
         {
           DrawRectangle(0, 0, SCREEN_X, SCREEN_Y, GREEN);
           DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
           DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
         } break;
         case GAMEPLAY:
         {
           DrawRectangle(0, 0, SCREEN_X, SCREEN_Y, PURPLE);
           DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
           DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
         } break;
         case ENDING:
         {
           DrawRectangle(0, 0, SCREEN_X, SCREEN_Y, BLUE);
           DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
           DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
         } break;
         default: break;
      }

   EndDrawing();
  }

  CloseWindow(); 
  return 0;
}
