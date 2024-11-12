const std = @import("std");
const c = @cImport({
    @cInclude("raylib.h");
    @cInclude("stdio.h");
});

const screenHeight = 1920;
const screenWidth = 1080;
const title = "Hello, World!";

pub fn main() !void {
    // Prints to stderr (it's a shortcut based on `std.io.getStdErr()`)
    c.InitWindow(screenHeight, screenWidth, title);
    const vsync: c.ConfigFlags = c.FLAG_VSYNC_HINT;
    c.SetConfigFlags(vsync);

    while (!c.WindowShouldClose()) {
        c.BeginDrawing();
        c.ClearBackground(c.RAYWHITE);
        c.DrawText("Hello, World!", 300, 200, 100, c.PURPLE);
        c.EndDrawing();
    }
    c.CloseWindow();
    _ = c.printf("Shutdown: success\n");
}
