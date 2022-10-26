#include <stdio.h>
typedef struct {float reel; float img;} complex;


void display(complex c){
	if(c.img>0){
	printf("%f+%f.i\r\n",c.reel,c.img);
	}else {
	printf("%f-%f.i\r\n",c.reel,c.img);
	}
}

complex  sommec(complex c1, complex c2){
	complex c3;
	c3.reel=c1.reel+c2.reel;
	c3.img=c1.img+c2.img;
	return c3;
}

complex produitc(complex c1, complex c2) {
	complex c3;
	float r=(c1.reel*c2.reel)-(c1.img*c2.img);
	float im=(c1.reel*c2.img)+(c1.img*c2.reel);
	c3.reel=r;
	c3.img=im;
	return c3;

}
