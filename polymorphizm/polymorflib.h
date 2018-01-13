#include <iostream>

struct Render {
	int x, y, z;
	void(*submit)(struct Render *self, int x, int y, int z);
	void(*flush)(struct Render *self);
};
void submit2d(Render *self, int x, int y, int z) {
	self->x = x;
	self->y = y;
	self->z = z;
	printf("2D Submited Data: x - %d, y - %d\n", x, y);
}
void submitInit2d(Render *self) {
	self->submit = submit2d;
}
void flush2d(Render *self) {
	printf("2D Rendering Cordinates %d, %d\n", self->x, self->y);
}
void flushInit2d(Render *self) {
	self->flush = flush2d;
}
void submit3d(Render *self, int x, int y, int z) {
	self->x = x;
	self->y = y;
	self->z = z;
	printf("3D Submited Data: x - %d, y - %d, z - %d\n", x, y, z);
}
void submitInit3d(Render *self) {
	self->submit = submit3d;
}
void flush3d(Render *self) {
	printf("3D Rendering Cordinates %d, %d, %d\n", self->x, self->y, self->z);
}
void flushInit3d(Render *self) {
	self->flush = flush3d;
}

void polymorphizm() {
	Render render2d, render3d;
	submitInit2d(&render2d);
	submitInit3d(&render3d);
	flushInit2d(&render2d);
	flushInit3d(&render3d);
	render2d.submit(&render2d, 10, 15, 0);
	render3d.submit(&render3d, 30, 15, 10);
	render2d.flush(&render2d);
	render3d.flush(&render3d);
	std::cin.get();
}
