#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;
using std::cout;
using std::endl;

const int H = 25;
const int W = 16;

int field[H][W] = { 0 };

struct Point {
	int x, y;
};

int figures[7][4] = {
	1, 3, 5, 7, // I
	2, 4, 5, 7, // Z
	3, 5, 4, 6, // S
	3, 5, 4, 7, // T
	2, 3, 5, 7, // L
	3, 5, 7, 6, // J
	2, 3, 4, 5, // O
};

class Tetromino {
private:

	Point tmp[4];
	int colorNum = 1;
	int n = 0;
	int(*field)[W];
public:
	Tetromino(int(*gameField)[W]) : field(gameField) { };

	void rotateTetromino() {
		Point p = tmp[1];
		for (int i = 0; i < 4; i++) {
			int y = tmp[i].x - p.x;
			int x = tmp[i].y - p.y;
			tmp[i].x = p.x - x;
			tmp[i].y = p.y + y;

			if (!check())
			{
				tmp[i].x = p.x + y;
				tmp[i].y = p.y - x;
			}
		}
	}

	void moveTetromino(int dx) {
		for (int i = 0; i < 4; i++) {
			tmp[i].x += dx;
		}

		if (!check()) {
			for (int i = 0; i < 4; i++) {
				tmp[i].x -= dx;
			}
		}
	}

	bool check() {
		for (int i = 0; i < 4; i++) {
			if (tmp[i].x < 0 || tmp[i].x >= W || tmp[i].y >= H) {
				return false;
			}
			if (field[tmp[i].y][tmp[i].x] != 0) {
				return false;
			}
		}
		return true;
	}

	Point* getTetrominoCoords() {
		return tmp;
	}

	int getColorNum() {
		return colorNum;
	}
};

class TetrisGame
{
private:
	Point a[4], b[4];
	int colorNum = 1;
	int n = 0;

	Texture texture, texture_background, texture_frame;
	Sprite sprite, sprite_background, sprite_frame;
	Clock clock;

	int score = 0;
	float timer = 0, delay = 0.3;
	int dx = 0;
	bool rotate = 0;
	bool beginGame = true;

public:
	TetrisGame() {
		texture.loadFromFile("D:/itStep/itstep_homework&class/C++/homework/TETRIS/images/blocks.png");
		texture_background.loadFromFile("D:/itStep/itstep_homework&class/C++/homework/TETRIS/images/background.png");

		sprite.setTexture(texture);
		sprite_background.setTexture(texture_background);
		sprite.setTextureRect(IntRect(0, 0, 18, 18));
	}
	int getScore() const {
		return score;
	}

	void increaseScore(int points) {
		score += points;
	}
	void run() {
		RenderWindow window(VideoMode(340, 500), ">> TETRIS <<");

		while (window.isOpen())
		{
			handleEvents(window);
			updateGame();
			drawGame(window);
			if (gameOver()) {
				window.close();
			}
		}
	}

private:
	void handleEvents(RenderWindow& window) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::Up)
					rotate = true;
				else if (event.key.code == Keyboard::Left)
					dx = -1;
				else if (event.key.code == Keyboard::Right)
					dx = 1;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
			delay = 0.05;
	}

	void moveBlock() {
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].x += dx;
		}

		if (!checkBorder()) {
			for (int i = 0; i < 4; i++) {
				a[i] = b[i];
			}
		}
	}

	void rotateBlock() {
		if (rotate) {
			Point p = a[1];
			for (int i = 0; i < 4; i++) {
				int x = a[i].y - p.y;
				int y = a[i].x - p.x;
				a[i].x = p.x - x;
				a[i].y = p.y + y;
			}

			if (!checkBorder()) {
				for (int i = 0; i < 4; i++) {
					int x = a[i].y - p.y;
					int y = a[i].x - p.x;
					a[i].x = p.x + y;
					a[i].y = p.y - x;
				}
			}
			rotate = false;
		}
	}

	void moveDown() {
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++) {
				b[i] = a[i];
				a[i].y += 1;
			}

			if (!checkBorder()) {
				for (int i = 0; i < 4; i++) {
					field[b[i].y][b[i].x] = colorNum;
				}
				colorNum = 1 + rand() % 7;
				n = rand() % 7;
				for (int i = 0; i < 4; i++) {
					a[i].x = figures[n][i] % 2;
					a[i].y = figures[n][i] / 2;
				}
			}
			timer = 0;
		}
	}

	void clearLines() {
		int k = H - 1;
		int deleted = 0;

		for (int i = H - 1; i > 0; i--) {
			int count = 0;
			for (int j = 0; j < W; j++) {
				if (field[i][j]) count++;
				field[k][j] = field[i][j];
			}
			if (count < W) k--;
			else deleted++;
		}
		if (deleted > 0) {
			increaseScore(deleted);
			cout << "Score: " << getScore() << endl;
		}
	}

	bool gameOver() {
		for (int i = 0; i < W; i++) {
			if (field[1][i] != 0) {
				cout << "\n\tGAME OVERRR . . ." << endl;
				return true;
			}
		}
		return false;
	}

	void updateGame() {
		clearLines();

		auto time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		moveBlock();
		rotateBlock();
		moveDown();
		if (beginGame)
		{
			beginGame = false;
			n = rand() % 7;
			for (int i = 0; i < 4; i++) {
				a[i].x = W / 3 + figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
			colorNum = 1 + rand() % 7;
		}
		dx = 0;
		rotate = false;
		delay = 0.3;
	}

	bool checkBorder() {
		for (int i = 0; i < 4; i++) {
			if (a[i].x < 0 || a[i].x >= W || a[i].y >= H)
				return false;
			if (field[a[i].y][a[i].x] != 0)
				return false;
		}
		return true;
	}

	void drawGame(RenderWindow& window) {
		window.clear(Color::White);
		window.draw(sprite_background);

		sprite_frame.setPosition(0, 0);
		sprite_frame.setTextureRect(IntRect(0, 0, (W * 18) + 10, (H * 18) + 8));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (field[i][j] == 0)
					continue;

				sprite.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
				sprite.setPosition(j * 18, i * 18);
				sprite.move(28, 31);
				window.draw(sprite);
			}
		}

		for (int i = 0; i < 4; i++) {
			sprite.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
			sprite.setPosition(a[i].x * 18, a[i].y * 18);
			sprite.move(28, 31);
			window.draw(sprite);
		}
		int frameX = 28, frameY = 31;
		int frameW = W * 18, frameH = H * 18;

		RectangleShape frame;
		frame.setSize(Vector2f(frameW, frameH));
		frame.setFillColor(Color::Transparent);
		frame.setOutlineThickness(2);
		frame.setOutlineColor(Color::Cyan);
		frame.setPosition(frameX, frameY);

		window.draw(frame);
		window.display();
	}
};


int main()
{
	srand(time(0));

	TetrisGame tetrisGame;
	tetrisGame.run();
}
