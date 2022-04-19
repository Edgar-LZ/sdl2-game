
typedef struct {
	SDL_Window * win;
	SDL_Renderer * rend;
	int up;
	int left;
	int down;
	int right;
	int close;

} App;

typedef struct {
	SDL_Texture * tex;
	int x;
	int y;
	int speed_x;
	int speed_y;
	int state;
	int frame;
	int flip;

} Entity;
