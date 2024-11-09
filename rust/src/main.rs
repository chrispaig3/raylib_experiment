use raylib::prelude::*;

const SCREEN_X: i32 = 1920;
const SCREEN_Y: i32 = 1080;

static TITLE: &'static str = "Box Man";

fn main() {
    let (mut rl, thread) = raylib::init()
        .size(SCREEN_X, SCREEN_Y)
        .title(TITLE)
        .vsync()
        .build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        d.draw_text("Hello, world!", 12, 12, 20, Color::BLACK);
    }
}
