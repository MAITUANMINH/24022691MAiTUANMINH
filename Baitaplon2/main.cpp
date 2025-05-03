#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Collision.h"
#include "graphics.h"
using namespace std;



int main(int argc, char *argv[]) {
    Graphics graphics;
    graphics.init();

    SDL_Texture* background = graphics.loadTexture("anh_vu_tru.JPG");

    Player player(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 150);
    vector<Bullet> bullets;
    vector<Enemy> enemies;

    Uint32 lastShot = 0;
    Uint32 lastSpawn = 0;
    int score = 0;
    bool running = true;
    SDL_Event event;

    srand(time(nullptr));

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        for (auto& e : enemies) {
            if (checkCollision(player.getRect(), e.getRect())) {
                cout << "GAME OVER !\n";
                running = false;
                break;
            }
        }

        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_LEFT]) player.move(-5);
        if (keystate[SDL_SCANCODE_RIGHT]) player.move(5);
        if (keystate[SDL_SCANCODE_SPACE]) {
            if (SDL_GetTicks() - lastShot > 250) {
                bullets.push_back(Bullet(player.getX() + 20, player.getY()));
                lastShot = SDL_GetTicks();
            }
        }

        if (SDL_GetTicks() - lastSpawn > 1000) {
            enemies.push_back(Enemy(rand() % (SCREEN_WIDTH - 40), -50));
            lastSpawn = SDL_GetTicks();
        }

        for (auto& b : bullets) b.update();
        for (auto& e : enemies) e.update();

        for (auto b = bullets.begin(); b != bullets.end();) {
            bool hit = false;
            for (auto e = enemies.begin(); e != enemies.end();) {
                if (checkCollision(b->getRect(), e->getRect())) {
                    b = bullets.erase(b);
                    e = enemies.erase(e);
                    score++;
                    hit = true;
                    break;
                } else {
                    ++e;
                }
            }
            if (!hit) ++b;
        }

        SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);
        SDL_RenderClear(graphics.renderer);

        graphics.renderTexture(background);

        player.draw(graphics.renderer);
        for (auto& b : bullets) b.draw(graphics.renderer);
        for (auto& e : enemies) e.draw(graphics.renderer);

        graphics.presentScene();
        SDL_Delay(16);
    }

    SDL_DestroyTexture(background); background= NULL;
    SDL_Quit();
    return 0;
}


