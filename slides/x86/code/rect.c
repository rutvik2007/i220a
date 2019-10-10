typedef struct {
  int x;	/** x-coordinate of lower-left corner */
  int y;	/** y-coordinate of lower-left corner */
  int color;	/** coding for color used to draw rectangle */
  int width;	/** width of rectange */
  int height;	/** height of rectangle */
} Rectangle;

int perimeter(const Rectangle *rectP) {
  return 2*(rectP->width + rectP->height);
}
